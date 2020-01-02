/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#define LOG_TAG "BnIrisDaemonCallback"
#include <stdint.h>
#include <sys/types.h>
#include <utils/Log.h>
#include <binder/Parcel.h>

#include "BnIrisDaemonCallback.h"

namespace android {

status_t BnIrisDaemonCallback::readEyeDesc(const Parcel& data, IrisEyeDesc& desc)
{
	desc.pupil_x = data.readUint32();
	desc.pupil_y = data.readUint32();
	desc.pupil_radius = data.readUint32();
	desc.iris_x = data.readUint32();
	desc.iris_y = data.readUint32();
	desc.iris_radius = data.readUint32();
	return NO_ERROR;
}

status_t BnIrisDaemonCallback::readOperationStatus(const Parcel& data, IrisOperationStatus& status)
{
	status_t ret = NO_ERROR;
	data.readUint32();
	status.progress = data.readUint32();
	status.quality = data.readUint32();
	readEyeDesc(data, status.desc.left_eye_desc);
	readEyeDesc(data, status.desc.right_eye_desc);
	status.desc.vendor_info_size = data.readInt32();
	if (status.desc.vendor_info_size > 0)
		ret = data.read(status.desc.vendor_info, status.desc.vendor_info_size);
	return ret;
}

status_t BnIrisDaemonCallback::onTransact(uint32_t code, const Parcel& data, Parcel* reply,
			uint32_t flags)
{
	IrisOperationStatus operationStatus;

	switch(code) {
		case ON_ERROR: {
			CHECK_INTERFACE(IIrisDaemonCallback, data, reply);
			const int64_t devId = data.readInt64();
			const int32_t err = data.readInt32();
			onError(devId, err);
			return NO_ERROR;
		}

		case ON_ENROLL_STATUS: {
			ALOGD("ON_ENROLL_STATUS");
			CHECK_INTERFACE(IIrisDaemonCallback, data, reply);
			const int64_t devId = data.readInt64();
			readOperationStatus(data, operationStatus);
			onEnrollStatus(devId, operationStatus);
			return NO_ERROR;
		}

		case ON_ENROLL_RESULT: {
			ALOGD("ON_ENROLL_RESULT");
			CHECK_INTERFACE(IIrisDaemonCallback, data, reply);
			const int64_t devId = data.readInt64();
			const int32_t irisId = data.readInt32();
			const int32_t groupId = data.readInt32();
			onEnrollResult(devId, irisId, groupId);
			return NO_ERROR;
		}

		case ON_AUTH_STATUS: {
			ALOGD("ON_AUTHENTICATING");
			CHECK_INTERFACE(IIrisDaemonCallback, data, reply);
			const int64_t devId = data.readInt64();
			readOperationStatus(data, operationStatus);
			onAuthStatus(devId, operationStatus);
			return NO_ERROR;
		}

		case ON_AUTH_RESULT: {
			ALOGD("ON_AUTHENTICATED");
			CHECK_INTERFACE(IIrisDaemonCallback, data, reply);
			const int64_t devId = data.readInt64();
			const bool matched = data.readInt32();
			const int32_t irisId = data.readInt32();
			const int32_t groupId = data.readInt32();
			onAuthResult(devId, matched, irisId, groupId);
			return NO_ERROR;
		}

		case ON_REMOVED: {
			ALOGD("ON_AUTHENTICATED");
			CHECK_INTERFACE(IIrisDaemonCallback, data, reply);
			const int64_t devId = data.readInt64();
			const int32_t irisId = data.readInt32();
			const int32_t groupId = data.readInt32();
			onRemoved(devId, irisId, groupId);
			return NO_ERROR;
		}

		default:
			return -EINVAL;
	}
}

}; // namespace android

