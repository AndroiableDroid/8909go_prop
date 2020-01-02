/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#define LOG_TAG "BpIrisDaemonCallback"
#include <stdint.h>
#include <sys/types.h>
#include <utils/Log.h>
#include <binder/Parcel.h>

#include "BpIrisDaemonCallback.h"

namespace android {

BpIrisDaemonCallback::BpIrisDaemonCallback(const sp<IBinder>& impl) :
		BpInterface<IIrisDaemonCallback>(impl) {
}

void BpIrisDaemonCallback::writeEyeDescriptor(Parcel& data, IrisEyeDesc& desc) {
	data.writeUint32(desc.pupil_x);
	data.writeUint32(desc.pupil_y);
	data.writeUint32(desc.pupil_radius);
	data.writeUint32(desc.iris_x);
	data.writeUint32(desc.iris_y);
	data.writeUint32(desc.iris_radius);
}

void BpIrisDaemonCallback::writeOperationStatus(Parcel& data, IrisOperationStatus& status) {
	data.writeUint32(1);
	data.writeUint32(status.progress);
	data.writeUint32(status.quality);
	writeEyeDescriptor(data, status.desc.left_eye_desc);
	writeEyeDescriptor(data, status.desc.right_eye_desc);
	ALOGD("vendor info size %d", status.desc.vendor_info_size);
	if ( status.desc.vendor_info_size > 0)
		ALOGD("vendor info[0]=%d", status.desc.vendor_info[0]);
	data.writeByteArray(status.desc.vendor_info_size, status.desc.vendor_info);
}

status_t BpIrisDaemonCallback::onError(int64_t devId, int32_t error) {
	Parcel data, reply;
	data.writeInterfaceToken(IIrisDaemonCallback::getInterfaceDescriptor());
	data.writeInt64(devId);
	data.writeInt32(error);
	return remote()->transact(ON_ERROR, data, &reply, IBinder::FLAG_ONEWAY);
}

status_t BpIrisDaemonCallback::onEnrollStatus(int64_t devId, IrisOperationStatus& status) {
	Parcel data, reply;
	data.writeInterfaceToken(IIrisDaemonCallback::getInterfaceDescriptor());
	data.writeInt64(devId);
	writeOperationStatus(data, status);
	return remote()->transact(ON_ENROLL_STATUS, data, &reply, IBinder::FLAG_ONEWAY);
}

status_t BpIrisDaemonCallback::onEnrollResult(int64_t devId, int32_t irisId, int32_t groupId) {
	Parcel data, reply;
	data.writeInterfaceToken(IIrisDaemonCallback::getInterfaceDescriptor());
	data.writeInt64(devId);
	data.writeInt32(irisId);
	data.writeInt32(groupId);
	return remote()->transact(ON_ENROLL_RESULT, data, &reply, IBinder::FLAG_ONEWAY);
}

status_t BpIrisDaemonCallback::onAuthStatus(int64_t devId, IrisOperationStatus& status) {
	Parcel data, reply;
	data.writeInterfaceToken(IIrisDaemonCallback::getInterfaceDescriptor());
	data.writeInt64(devId);
	writeOperationStatus(data, status);
	return remote()->transact(ON_AUTH_STATUS, data, &reply, IBinder::FLAG_ONEWAY);
}

status_t BpIrisDaemonCallback::onAuthResult(int64_t devId, bool matched, int32_t irisId, int32_t gpId) {
	Parcel data, reply;
	data.writeInterfaceToken(IIrisDaemonCallback::getInterfaceDescriptor());
	data.writeInt64(devId);
	data.writeInt32(matched);
	data.writeInt32(irisId);
	data.writeInt32(gpId);
	return remote()->transact(ON_AUTH_RESULT, data, &reply, IBinder::FLAG_ONEWAY);
}

status_t BpIrisDaemonCallback::onRemoved(int64_t devId, int32_t irisId, int32_t gpId) {
	Parcel data, reply;
	data.writeInterfaceToken(IIrisDaemonCallback::getInterfaceDescriptor());
	data.writeInt64(devId);
	data.writeInt32(irisId);
	data.writeInt32(gpId);
	return remote()->transact(ON_REMOVED, data, &reply, IBinder::FLAG_ONEWAY);
}


IMPLEMENT_META_INTERFACE(IrisDaemonCallback,
		"android.hardware.iris.IIrisDaemonCallback");

}; // namespace android

