/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifndef IIRIS_DAEMON_CALLBACK_H_
#define IIRIS_DAEMON_CALLBACK_H_

#include <inttypes.h>
#include <utils/Errors.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android {

/*
* Communication channel back to IrisService.java
*/
class IIrisDaemonCallback : public IInterface {
public:
	// must be kept in sync with IIrisService.aidl
	enum {
		ON_ERROR = IBinder::FIRST_CALL_TRANSACTION + 0,
		ON_ENROLL_STATUS = IBinder::FIRST_CALL_TRANSACTION + 1,
		ON_ENROLL_RESULT = IBinder::FIRST_CALL_TRANSACTION + 2,
		ON_AUTH_STATUS = IBinder::FIRST_CALL_TRANSACTION + 3,
		ON_AUTH_RESULT = IBinder::FIRST_CALL_TRANSACTION + 4,
		ON_REMOVED = IBinder::FIRST_CALL_TRANSACTION + 5,
	};

	struct IrisEyeDesc {
		uint32_t pupil_x;
		uint32_t pupil_y;
		uint32_t pupil_radius;
		uint32_t iris_x;
		uint32_t iris_y;
		uint32_t iris_radius;
	};
	
	struct IrisFrameDesc {
		IrisEyeDesc left_eye_desc;
		IrisEyeDesc right_eye_desc;
		uint32_t vendor_info_size;
		uint8_t vendor_info[128];
	};

	struct IrisOperationStatus {
		uint32_t progress;
		uint32_t quality;
		IrisFrameDesc desc;
	};

	virtual status_t onError(int64_t devId, int32_t error) = 0;
	virtual status_t onEnrollStatus(int64_t devId, IrisOperationStatus& status) = 0;
	virtual status_t onEnrollResult(int64_t devId, int32_t irisId, int32_t groupId) = 0;
	virtual status_t onAuthStatus(int64_t devId, IrisOperationStatus& status) = 0;
	virtual status_t onAuthResult(int64_t devId,  bool matched, int32_t irisId, int32_t groupId) = 0;
	virtual status_t onRemoved(int64_t devId, int32_t irisId, int32_t groupId) = 0;

	DECLARE_META_INTERFACE(IrisDaemonCallback);
};

}; // namespace android

#endif // IIRIS_DAEMON_CALLBACK_H_

