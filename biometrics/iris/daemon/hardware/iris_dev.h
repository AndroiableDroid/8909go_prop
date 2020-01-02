/*
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifndef IRIS_DEV_H
#define IRIS_DEV_H

#include "iris_tz_api.h"
#include "iris_task.h"

#include <stdint.h>
#include <utils/String16.h>
#include <hardware/hw_auth_token.h>
#include <utils/RefBase.h>
#include <utils/Mutex.h>
#include <gui/IGraphicBufferProducer.h>

#define IRIS_MODULE_API_VERSION_1_0 HARDWARE_MODULE_API_VERSION(1, 0)
#define IRIS_HARDWARE_MODULE_ID "iris"



using namespace android;

typedef enum iris_msg_type {
	IRIS_ERROR = -1,
	IRIS_ENROLLING = 1,
	IRIS_ENROLLED = 2,
	IRIS_REMOVED = 3,
	IRIS_AUTHENTICATING = 4,
	IRIS_AUTHENTICATED = 5,
} iris_msg_type_t;

typedef enum iris_error {
	IRIS_ERROR_HW_UNAVAILABLE = 1,
	IRIS_ERROR_TIMEOUT = 2,
	IRIS_ERROR_CANCELED = 3,
	IRIS_ERROR_NO_SPACE = 4,
	IRIS_ERROR_NO_USER = 5,
	IRIS_ERROR_NO_IRIS = 6,
	IRIS_ERROR_GENERIC = 7,
	IRIS_ERROR_FATAL = 8,
	IRIS_ERROR_IR_SENSOR = 9,
	IRIS_ERROR_BAD_QUALITY = 10,
	IRIS_ERROR_PERMISSION_DENIED = 11,

	IRIS_ERROR_VENDOR_BASE = 1000,
} iris_error_t;

typedef enum iris_quality {
	IRIS_QUALITY_GOOD = 0,
	IRIS_QUALITY_BAD_IMAGE_QUALITY = 1,
	IRIS_QUALITY_EYE_NOT_FOUND = 2,
	IRIS_QUALITY_EYE_TOO_CLOSE = 3,
	IRIS_QUALITY_EYE_TOO_FAR = 4,
	IRIS_QUALITY_EYE_TOO_UP = 5,
	IRIS_QUALITY_EYE_TOO_DOWN = 6,
	IRIS_QUALITY_EYE_TOO_LEFT = 7,
	IRIS_QUALITY_EYE_TOO_RIGHT = 8,
	IRIS_QUALITY_MOTION_BLUR = 9,
	IRIS_QUALITY_FOCUS_BLUR = 10,
	IRIS_QUALITY_BAD_EYE_OPENNESS = 11,
	IRIS_QUALITY_BAD_EYE_DISTANCE = 12,
	IRIS_QUALITY_WITH_GLASS = 13,
	IRIS_QUALITY_IR_SENSOR_DONE = 14,
	IRIS_QUALITY_OUTDOOR = 15,
	IRIS_QUALITY_LIVENESS_FAILED = 16,
	IRIS_QUALITY_BLINK = 17,
} iris_quality_t;

typedef enum iris_camera_param {
	IRIS_CAMERA_PARAM_GAIN = 0,
	IRIS_CAMERA_PARAM_EXP_TIME
} iris_camera_param_t;

typedef struct iris_identifier {
	uint32_t irisId;
	uint32_t gid;
} iris_identifier_t;

typedef struct iris_enroll {
	uint32_t progress;
	iris_quality_t quality;
	struct iris_frame_desc *frame_desc;
	iris_identifier_t id;
} iris_enroll_t;

typedef struct iris_removed {
	iris_identifier_t id;
} iris_removed_t;

typedef struct iris_authenticate {
	uint32_t progress;
	iris_quality_t quality;
	struct iris_frame_desc *frame_desc;
	iris_identifier_t id;
	hw_auth_token_t *hat;
} iris_authenticate_t;

typedef struct iris_msg {
	iris_msg_type_t type;
	union {
		int error;
		iris_enroll_t enroll;
		iris_removed_t removed;
		iris_authenticate_t authenticate;
	} data;
} iris_msg_t;

/* Callback function type */
typedef void (*iris_notify_t)(const iris_msg_t *msg, void *data);

//forward declaration
class iris_frame_source;
class iris_device_callback;
class iris_interface;

class iris_device {
public:
	iris_device();
	virtual ~iris_device();

	int open(bool tz_comm);
	void close();
	uint64_t pre_enroll();
	int enroll( const hw_auth_token_t *hat, uint32_t gid, uint32_t timeout_sec, int32_t uid, String16 &package);
	int post_enroll();
	uint64_t get_authenticator_id();
	int cancel();
	int enumerate(iris_identifier_t *results, uint32_t *max_size);
	int remove(iris_identifier_t id);
	int set_active_group(uint32_t gid, const char *store_path);
	int authenticate(uint64_t operation_id, uint32_t gid, int32_t uid, String16 &package);

	int set_notify(iris_notify_t notify, void *data);

	int create_frame_source(int use_case);
	void destroy_frame_source();

	int adjust_camera_parameter(iris_camera_param_t param, int adjust);

	int set_preview_surface(const sp<IGraphicBufferProducer>& bufferProducer);
	int configure_enroll(const uint8_t *param, int32_t param_size);
	int configure_auth(const uint8_t *param, int32_t param_size);
	int configure_orientation(int orientation);

	int getPreviewSize(int use_case, int32_t *width, int32_t *height);

private:
	bool is_busy();

	int create_camera(uint32_t cam_id, int use_case);
	int init_meta_data(struct iris_meta_data& meta_data);

private:
	Mutex mLock;
	iris_interface *mTZIntf;
	iris_task *mTask;
	iris_device_callback *mTaskCallback;

	iris_frame_source *mFrameSource;
	sp<IGraphicBufferProducer> mBufferProducer;

	int32_t mEnrollParamSize;
	uint8_t mEnrollParam[IRIS_MAX_VENDOR_INFO_SIZE];

	int32_t mAuthParamSize;
	uint8_t mAuthParam[IRIS_MAX_VENDOR_INFO_SIZE];

	int32_t mPreviewWidth;
	int32_t mPreviewHeight;

	struct iris_meta_data mMetaData;
	uint32_t mCameraId;

	int32_t mOrientation;
};

#endif  /* IRIS_DEV_H */

