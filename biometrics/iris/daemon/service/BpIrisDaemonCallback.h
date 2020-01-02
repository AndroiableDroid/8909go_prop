/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifndef BPIRIS_DAEMON_CALLBACK_H_
#define BPIRIS_DAEMON_CALLBACK_H_

#include "IIrisDaemonCallback.h"

namespace android {

class BpIrisDaemonCallback : public BpInterface<IIrisDaemonCallback>
{
public:
	BpIrisDaemonCallback(const sp<IBinder>& impl);
	virtual status_t onError(int64_t devId, int32_t error);
	virtual status_t onEnrollStatus(int64_t devId, IrisOperationStatus& status);
	virtual status_t onEnrollResult(int64_t devId, int32_t irisId, int32_t groupId);
	virtual status_t onAuthStatus(int64_t devId, IrisOperationStatus& status);
	virtual status_t onAuthResult(int64_t devId, bool matched, int32_t irisId, int32_t groupId);
	virtual status_t onRemoved(int64_t devId, int32_t irisId, int32_t groupId);
private:
	void writeOperationStatus(Parcel& data, IrisOperationStatus &status);
	void writeEyeDescriptor(Parcel& data, IrisEyeDesc &desc);

};

}; // namespace android

#endif // BPIRIS_DAEMON_CALLBACK_H_

