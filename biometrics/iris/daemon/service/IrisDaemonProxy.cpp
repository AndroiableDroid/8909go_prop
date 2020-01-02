/*
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Not a Contribution.
 * Apache license notifications and license are retained
 * for attribution purposes only.
 */

/**
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#define LOG_TAG "IrisDaemonProxy"

#include <cutils/properties.h>
#include <binder/IServiceManager.h>
#include <hardware/hw_auth_token.h>
#include <keystore/IKeystoreService.h>
#include <keystore/keystore.h> // for error codes
#include <utils/Log.h>
#include <binder/PermissionCache.h>

#include "iris_dev.h"
#include "IrisDaemonProxy.h"

namespace android {

#define IRIS_MAX_IDENTIFIER 5

IrisDaemonProxy* IrisDaemonProxy::sInstance = NULL;

IrisDaemonProxy* IrisDaemonProxy::getInstance() {
	if (sInstance == NULL) {
		sInstance = new IrisDaemonProxy();
	}
	return sInstance;
}

IrisDaemonProxy::IrisDaemonProxy()
	:mDevice(NULL), mCallback(NULL) {
}

IrisDaemonProxy::~IrisDaemonProxy() {
	closeHal();
}

void IrisDaemonProxy::copy_enroll_status(IIrisDaemonCallback::IrisOperationStatus& status, const iris_enroll_t& enroll_status)
{
	status.progress = enroll_status.progress;
	status.quality = enroll_status.quality;
	copy_frame_desc(status.desc, enroll_status.frame_desc);
}

void IrisDaemonProxy::copy_auth_status(IIrisDaemonCallback::IrisOperationStatus& status, const iris_authenticate_t& auth_status)
{
	status.progress = 0;
	status.quality = auth_status.quality;
	copy_frame_desc(status.desc, auth_status.frame_desc);
}

void IrisDaemonProxy::copy_frame_desc(IIrisDaemonCallback::IrisFrameDesc& desc ,const struct iris_frame_desc *frame_desc)
{
	if (!frame_desc)
		return;

	memcpy(&desc.left_eye_desc, &frame_desc->left_eye_desc, sizeof(struct IIrisDaemonCallback::IrisEyeDesc));
	memcpy(&desc.right_eye_desc, &frame_desc->right_eye_desc, sizeof(struct IIrisDaemonCallback::IrisEyeDesc));
	desc.vendor_info_size = frame_desc->vendor_info_size;
	if (frame_desc->vendor_info_size > 0)
		memcpy(desc.vendor_info, frame_desc->vendor_info, frame_desc->vendor_info_size);
}

void IrisDaemonProxy::hal_notify_callback(const iris_msg_t *msg, void *data) {
	IrisDaemonProxy* instance = static_cast<IrisDaemonProxy *>(data);
	const sp<IIrisDaemonCallback> callback = instance->mCallback;
	bool matched = false;
	IIrisDaemonCallback::IrisOperationStatus operationStatus;

	memset(&operationStatus, 0, sizeof(operationStatus));

	if (callback == NULL) {
		ALOGE("Invalid callback object");
		return;
	}
	const int64_t device = reinterpret_cast<int64_t>(instance->mDevice);
	switch (msg->type) {
		case IRIS_ERROR:
			ALOGD("onError(%d)", msg->data.error);
			callback->onError(device, msg->data.error);
			break;

		case IRIS_ENROLLING:
			ALOGD("onEnrollResult progress=%d",msg->data.enroll.progress);
			copy_enroll_status(operationStatus, msg->data.enroll);
			callback->onEnrollStatus(device, operationStatus);
			break;

		case IRIS_ENROLLED:
			ALOGD("onEnrollResult(irisId=%d, gid=%d)",
				msg->data.enroll.id.irisId,
				msg->data.enroll.id.gid);
			callback->onEnrollResult(device,
				msg->data.enroll.id.irisId,
				msg->data.enroll.id.gid);
			break;

		case IRIS_AUTHENTICATING:
			ALOGD("onAuthenticating (quality %d)",
				msg->data.authenticate.quality);
			copy_auth_status(operationStatus, msg->data.authenticate);
			callback->onAuthStatus(device, operationStatus);
			break;

		case IRIS_AUTHENTICATED:
			ALOGD("onAuthenticated(irisid=%d)",
				msg->data.authenticate.id.irisId);
			if (msg->data.authenticate.hat) {
				const uint8_t* hat = reinterpret_cast<const uint8_t *>(msg->data.authenticate.hat);
				instance->notifyKeystore(hat, sizeof(*msg->data.authenticate.hat));
				matched = true;
			}
			callback->onAuthResult(device, matched, msg->data.authenticate.id.irisId, msg->data.authenticate.id.gid);
			break;

		case IRIS_REMOVED:
			ALOGD("onRemove(gid=%d)",
				msg->data.removed.id.gid);
			callback->onRemoved(device,
				msg->data.removed.id.irisId,
				msg->data.removed.id.gid);
			break;

		default:
			ALOGE("invalid msg type: %d", msg->type);
			return;
	}
}

void IrisDaemonProxy::notifyKeystore(const uint8_t *auth_token, const size_t auth_token_length) {
	if (auth_token != NULL && auth_token_length > 0) {
		sp<IServiceManager> sm = defaultServiceManager();
		sp<IBinder> binder = sm->getService(String16("android.security.keystore"));
		sp<IKeystoreService > service = interface_cast <IKeystoreService>(binder);
		if (service != NULL) {
			status_t ret = service->addAuthToken(auth_token, auth_token_length);
			if (ret != ResponseCode::NO_ERROR)
				ALOGE("Falure sending auth token to KeyStore: %d", ret);
			else
				ALOGD("token added to the key store\n");
		} else {
			ALOGE("Unable to communicate with KeyStore");
		}
	}
}

void IrisDaemonProxy::init(const sp<IIrisDaemonCallback>& callback) {
	if (mCallback != NULL && IInterface::asBinder(callback) != IInterface::asBinder(mCallback)) {
		IInterface::asBinder(mCallback)->unlinkToDeath(this);
	}

	IInterface::asBinder(callback)->linkToDeath(this);
	mCallback = callback;
}

int32_t IrisDaemonProxy::enroll(const uint8_t* token, ssize_t tokenSize, int32_t groupId,
		int32_t timeout, int32_t userId) {
	const hw_auth_token_t* authToken;
	String16 packageName;

	ALOG(LOG_VERBOSE, LOG_TAG, "enroll(id=%d, timeout=%d)\n", groupId, timeout);

	if (tokenSize != sizeof(hw_auth_token_t) ) {
		ALOG(LOG_VERBOSE, LOG_TAG, "enroll() : invalid token size %zu\n", tokenSize);
		return -1;
	}

	authToken = reinterpret_cast<const hw_auth_token_t*>(token);
	packageName = getPackageName(userId);
	return mDevice->enroll(authToken, groupId, timeout, userId, packageName);
}

uint64_t IrisDaemonProxy::preEnroll() {
	if (!mDevice)
		return 0;

	return mDevice->pre_enroll();
}

int32_t IrisDaemonProxy::postEnroll() {
	if (!mDevice)
		return -ENODEV;

	return mDevice->post_enroll();
}

int32_t IrisDaemonProxy::stopEnrollment() {
	ALOG(LOG_VERBOSE, LOG_TAG, "stopEnrollment()\n");
	if (!mDevice)
		return -ENODEV;

	return mDevice->cancel();
}

int32_t IrisDaemonProxy::authenticate(uint64_t sessionId, int32_t groupId, int32_t userId) {
	String16 packageName;

	ALOG(LOG_VERBOSE, LOG_TAG, "authenticate(sid=%" PRId64 ", gid=%d)\n", sessionId, groupId);
	if (!mDevice)
		return -ENODEV;

	packageName = getPackageName(userId);
	return mDevice->authenticate(sessionId, groupId, userId, packageName);
}

int32_t IrisDaemonProxy::stopAuthentication() {
	ALOG(LOG_VERBOSE, LOG_TAG, "stopAuthentication()\n");
	if (!mDevice)
		return -ENODEV;

	return mDevice->cancel();
}

int32_t IrisDaemonProxy::remove(int32_t irisId, int32_t groupId) {
	iris_identifier_t id = {(uint32_t)irisId, (uint32_t)groupId};

	ALOG(LOG_VERBOSE, LOG_TAG, "remove(gid=%d)\n", groupId);
	if (!mDevice)
		return -ENODEV;
	return mDevice->remove(id);
}

uint64_t IrisDaemonProxy::getAuthenticatorId() {
	if (!mDevice)
		return 0;

	return mDevice->get_authenticator_id();
}

int32_t IrisDaemonProxy::setActiveGroup(int32_t groupId, const uint8_t* path,
		ssize_t pathlen) {
	char path_name[PATH_MAX];

	if (!mDevice)
		return -ENODEV;

	if (pathlen >= PATH_MAX || pathlen <= 0) {
		ALOGE("Bad path length: %zd", pathlen);
		return -1;
	}
    // Convert to null-terminated string
	memcpy(path_name, path, pathlen);
	path_name[pathlen] = '\0';
	ALOG(LOG_VERBOSE, LOG_TAG, "setActiveGroup(%d, %s, %zu)", groupId, path_name, pathlen);
	return mDevice->set_active_group(groupId, path_name);
}

int64_t IrisDaemonProxy::openHal() {
	int err;
	bool tz = true;
	char pval[PROPERTY_VALUE_MAX];
	int property_val;

	ALOG(LOG_VERBOSE, LOG_TAG, "openHal()");
 
	property_get("persist.iris.tz.enable", pval, "1");
	property_val = atoi(pval);
	if (property_val == 0)
		tz = false;

	if (mDevice) {
		ALOG(LOG_VERBOSE, LOG_TAG, "recover: delete previous device");
		delete mDevice;
		mDevice = NULL;
	}

	mDevice = new iris_device();
	if (!mDevice) {
		ALOGE("Failed to create iris device");
		return 0;
	}

	err = mDevice->open(tz);
	if (err < 0) {
		ALOGE("Failed to open iris device(%s), err=%d", tz ? "tz" : "socket", err);
		closeHal();
		return 0;
	}

	err = mDevice->set_notify(hal_notify_callback, this);
	if (err < 0) {
		closeHal();
		ALOGE("Failed in call to set_notify(), err=%d", err);
		return 0;
	}

	ALOG(LOG_VERBOSE, LOG_TAG, "iris HAL successfully initialized, %p", mDevice);
	return reinterpret_cast<int64_t>(mDevice);
}

int32_t IrisDaemonProxy::closeHal() {
	ALOG(LOG_VERBOSE, LOG_TAG, "closeHal()");
	if (mDevice) {
		mDevice->close();
		delete mDevice;
		mDevice = NULL;
	}

	return 0;
}

int32_t IrisDaemonProxy::enumerateEnrollment(uint32_t *maxSize, iris_id *ids) {
	int err;
	struct iris_identifier results[IRIS_MAX_IDENTIFIER];
	uint32_t i, size = IRIS_MAX_IDENTIFIER;

	ALOG(LOG_VERBOSE, LOG_TAG, "enumerateEnrollment()");
	if (!mDevice)
		return -ENODEV;

	err = mDevice->enumerate(results, &size);
	if (err) {
		ALOGE("Fail to enmuerate enumerate enrollment ret=%d", err);
		return err;
	}

	if (*maxSize < size)
		size = *maxSize;

	for (i = 0; i < size; i++) {
		ids[i].irisId = results[i].irisId;
		ids[i].gid = results[i].gid;
	}

	*maxSize = size;

	return 0;
}

int32_t IrisDaemonProxy::setPreviewSurface(const sp<IGraphicBufferProducer>& bufferProducer) {
	if (!mDevice)
		return -ENODEV;
       return mDevice->set_preview_surface(bufferProducer);
}

int32_t IrisDaemonProxy::configure(int32_t param_id, const uint8_t *param, int32_t param_size)
{
	int result = 0;

	if (!mDevice)
		return -ENODEV;

	switch (param_id) {
		case CONFIGURE_PARAM_ENROLL:
			result = mDevice->configure_enroll(param, param_size);
			break;
		case CONFIGURE_PARAM_AUTH:
			result = mDevice->configure_auth(param, param_size);
			break;
		case CONFIGURE_PARAM_ORIENTATION:
			if (param_size == 4) {
				int orientation = param[3] << 24 | param[2] << 16 | param[1] << 8 | param[0];
				result = mDevice->configure_orientation(orientation);
			}
		default:
			result = -EINVAL;
	}

	return result;
}

int32_t IrisDaemonProxy::getPreviewSize(int use_case, int32_t *width, int32_t *height)
{
	if (!mDevice)
		return -ENODEV;

	return mDevice->getPreviewSize(use_case, width, height);
}

void IrisDaemonProxy::binderDied(const wp<IBinder>& who) {
	ALOGD("binder died");
	int err;
	if (0 != (err = closeHal())) {
		ALOGE("Can't close iris device, error: %d", err);
	}
	if (IInterface::asBinder(mCallback) == who) {
		mCallback = NULL;
	}
}

String16 IrisDaemonProxy::getPackageName(int32_t uid) {
	ALOG(LOG_VERBOSE, LOG_TAG, "getPackageName() uid=%d", uid);

	sp<IServiceManager> sm = defaultServiceManager();
	sp<IBinder> binder = sm->getService(String16("permission"));
	if (binder == 0) {
		ALOGE("Cannot get permission service");
		return String16("");
	}

	sp<IPermissionController> permCtrl = interface_cast<IPermissionController>(binder);
	Vector<String16> packages;
	permCtrl->getPackagesForUid(uid, packages);

	if (packages.isEmpty()) {
		ALOGE("No packages for calling uid %d", uid);
		return String16("");
	}
	ALOGE("packages for calling uid %d, pakcage=%s", uid, (char *)packages[0].string());
	return packages[0];
}

}

