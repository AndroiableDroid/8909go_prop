/*
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#define LOG_TAG "IrisDev"
#include <utils/Log.h>
#include <cutils/properties.h>
#include <errno.h>
#include <hardware/hw_auth_token.h>

#include "iris_dev.h"
#include "iris_task.h"
#include "iris_enroll_task.h"
#include "iris_auth_task.h"
#include "iris_remove_task.h"
#include "iris_camera_source.h"
#include "iris_tz_api.h"

static const int IRIS_AUTHENTICATE_TASK_TIME_OUT = 20;
static const int IRIS_REMOVE_TASK_TIME_OUT = 3;

class iris_device_callback : public iris_task_callback {
public:
	iris_device_callback(iris_device *device);
	virtual ~iris_device_callback();

	virtual void on_event(int event, void *data);
	virtual void on_err(int err);

	void set_notify(iris_notify_t notify, void *data);
	void set_groupId(uint32_t groupId);

private:
	iris_quality_t translate_frame_status(uint32_t status);
	uint32_t handle_frame_status(uint32_t status);
	void handle_camera_config(struct iris_frame_config *config);

private:
	iris_device *mDevice;
	iris_notify_t mNotify;
	void *mData;
	uint32_t mGroupId;
};

iris_device_callback::iris_device_callback(iris_device *device)
	:mDevice(device), mNotify(NULL), mData(NULL), mGroupId(0)
{
}

iris_device_callback::~iris_device_callback()
{
}

void iris_device_callback::set_notify(iris_notify_t notify, void *data)
{
	mNotify = notify;
	mData = data;
}

void iris_device_callback::set_groupId(uint32_t groupId)
{
	mGroupId = groupId;
}

uint32_t iris_device_callback::handle_frame_status(uint32_t status)
{
	uint32_t filtered_status = status;

	if (status & IRIS_FRAME_STATUS_EXPOSURE_UNDER)
		filtered_status &= ~IRIS_FRAME_STATUS_EXPOSURE_UNDER;
	else if (status & IRIS_FRAME_STATUS_EXPOSURE_OVER)
		filtered_status &= ~IRIS_FRAME_STATUS_EXPOSURE_OVER;

	if (status & IRIS_FRAME_STATUS_FOCUS_BLUR) {
		ALOGD("filter focus blur code");
		filtered_status &= ~IRIS_FRAME_STATUS_FOCUS_BLUR;
	}

	if (status & IRIS_FRAME_STATUS_BAD_EYE_DISTANCE) {
		ALOGD("filter bad eye distance code");
		filtered_status &= ~IRIS_FRAME_STATUS_BAD_EYE_DISTANCE;
	}

	ALOGE("frame status=%x, filtered status=%x", status, filtered_status);
	return filtered_status;
}

void iris_device_callback::handle_camera_config(struct iris_frame_config *config)
{
	if (config->exposure_ms) {
		ALOGE("exposure config=%d", config->exposure_ms);
		mDevice->adjust_camera_parameter(IRIS_CAMERA_PARAM_EXP_TIME, config->exposure_ms);
	}

	if (config->gain) {
		ALOGE("gain config=%d", config->gain);
		mDevice->adjust_camera_parameter(IRIS_CAMERA_PARAM_GAIN, config->gain);
	}
}

iris_quality_t iris_device_callback::translate_frame_status(uint32_t status)
{
	iris_quality_t quality;

	if (status & IRIS_FRAME_STATUS_EYE_POSITION) {
		uint32_t eye_position_code  = status & IRIS_FRAME_STATUS_EYE_POSITION;
		switch (eye_position_code) {
			case IRIS_FRAME_STATUS_EYE_NOT_FOUND:
				quality = IRIS_QUALITY_EYE_NOT_FOUND;
				break;
			case IRIS_FRAME_STATUS_EYE_TOO_CLOSE:
				quality = IRIS_QUALITY_EYE_TOO_CLOSE;
				break;
			case IRIS_FRAME_STATUS_EYE_TOO_FAR:
				quality = IRIS_QUALITY_EYE_TOO_FAR;
				break;
			case IRIS_FRAME_STATUS_EYE_TOO_UP:
				quality = IRIS_QUALITY_EYE_TOO_UP;
				break;
			case IRIS_FRAME_STATUS_EYE_TOO_DOWN:
				quality = IRIS_QUALITY_EYE_TOO_DOWN;
				break;
			case IRIS_FRAME_STATUS_EYE_TOO_LEFT:
				quality = IRIS_QUALITY_EYE_TOO_LEFT;
				break;
			case IRIS_FRAME_STATUS_EYE_TOO_RIGHT:
				quality = IRIS_QUALITY_EYE_TOO_RIGHT;
				break;
			default:
				quality = IRIS_QUALITY_BAD_IMAGE_QUALITY;
		}
		return quality;
	}

	if (status & IRIS_FRAME_STATUS_BAD_EYE_OPENNESS)
		return IRIS_QUALITY_BAD_EYE_OPENNESS;

	if (status & IRIS_FRAME_STATUS_MOTION_BLUR)
		return IRIS_QUALITY_MOTION_BLUR;

	if (status & IRIS_FRAME_STATUS_WITH_GLASS)
		return IRIS_QUALITY_WITH_GLASS;

	if (status & IRIS_FRAME_STATUS_BAD_IMAGE_QUALITY)
		return IRIS_QUALITY_BAD_IMAGE_QUALITY;

	if (status & IRIS_FRAME_STATUS_OUTDOOR)
		return IRIS_QUALITY_OUTDOOR;

	if (status & IRIS_FRAME_STATUS_LIVENESS_FAILED)
		return IRIS_QUALITY_LIVENESS_FAILED;

	if (status & IRIS_FRAME_STATUS_BLINK)
		return IRIS_QUALITY_BLINK;

	return IRIS_QUALITY_GOOD;
}

void iris_device_callback::on_event(int event, void *data)
{
	iris_msg_t msg;
	bool ignore = false;
	uint32_t filtered_status;
	struct iris_verify_status *auth_status;
	struct iris_verify_result *verify_result;

	if (!mNotify)
		return;

	switch (event) {
		case IRIS_TASK_EVENT_ENROLL_PROGRESS:
		case IRIS_TASK_EVENT_ENROLL_COLLECTION_DONE:
			struct iris_enroll_status *enroll_status;
			enroll_status = (struct iris_enroll_status *)data;
			msg.type = IRIS_ENROLLING;
			msg.data.enroll.progress = enroll_status->progress;
			filtered_status = handle_frame_status(enroll_status->status);
			msg.data.enroll.quality = translate_frame_status(filtered_status);
			if (event == IRIS_TASK_EVENT_ENROLL_COLLECTION_DONE)
				msg.data.enroll.quality = IRIS_QUALITY_IR_SENSOR_DONE;
			handle_camera_config(&enroll_status->frame_desc.camera_config);
			msg.data.enroll.frame_desc = &enroll_status->frame_desc;
			break;

		case IRIS_TASK_EVENT_ENROLL_DONE:
			struct iris_enroll_result *enroll_result;
			enroll_result = (struct iris_enroll_result *)data;
			msg.type = IRIS_ENROLLED;
			msg.data.enroll.id.irisId = enroll_result->iris_id;
			msg.data.enroll.id.gid = mGroupId;
			mDevice->destroy_frame_source();
			break;

		case IRIS_TASK_EVENT_AUTH_PROGRESS:
		case IRIS_TASK_EVENT_AUTH_COLLECTION_DONE:
			verify_result = (struct iris_verify_result *)data;
			auth_status = &verify_result->verify_status;
			msg.type = IRIS_AUTHENTICATING;
			filtered_status = handle_frame_status(auth_status->status);
			msg.data.authenticate.quality = translate_frame_status(filtered_status);
			if (event == IRIS_TASK_EVENT_ENROLL_COLLECTION_DONE)
				msg.data.authenticate.quality = IRIS_QUALITY_IR_SENSOR_DONE;
			handle_camera_config(&auth_status->frame_desc.camera_config);
			msg.data.authenticate.frame_desc = &auth_status->frame_desc;
			break;

		case IRIS_TASK_EVENT_AUTH_DONE:
			verify_result = (struct iris_verify_result *)data;
			auth_status = &verify_result->verify_status;
			msg.type = IRIS_AUTHENTICATED;
			if (auth_status->matched) {
				msg.data.authenticate.id.irisId = auth_status->iris_id;
				msg.data.authenticate.id.gid = mGroupId;
				msg.data.authenticate.hat = (hw_auth_token_t *)verify_result->token;
			} else {
				msg.data.authenticate.id.irisId = 0;
				msg.data.authenticate.id.gid = 0;
				msg.data.authenticate.hat = NULL;
			}
			msg.data.authenticate.quality = IRIS_QUALITY_GOOD;
			msg.data.authenticate.frame_desc = NULL;
			mDevice->destroy_frame_source();
			break;

		case IRIS_TASK_EVENT_REMOVE_PROGRESS:
			ignore = true;
			break;

		case IRIS_TASK_EVENT_REMOVE_DONE:
			msg.type = IRIS_REMOVED;
			msg.data.removed.id.irisId = (uint32_t)data;
			msg.data.removed.id.gid = mGroupId;
			break;

		default:
			ALOGW("Invalid event %d", event);
			ignore = true;
			break;
	}

	if (!ignore)
		mNotify(&msg, mData);
}

void iris_device_callback::on_err(int err)
{
	iris_msg_t msg;

	ALOGE("Iris device error=%d\n", err);

	if (!mNotify)
		return;

	msg.type = IRIS_ERROR;
	msg.data.error = IRIS_ERROR_GENERIC;

	if (err < 0) {
		switch (err) {
			case -ETIME:
				msg.data.error = IRIS_ERROR_TIMEOUT;
				break;
			case -EINTR:
				msg.data.error = IRIS_ERROR_CANCELED;
				break;
			case -EIO:
				msg.data.error = IRIS_ERROR_IR_SENSOR;
				break;
			default:
				msg.data.error = IRIS_ERROR_FATAL;
		}
	} else {
		switch (err) {
			case IRIS_STATUS_CONTINUE:
			case IRIS_STATUS_FRAME_COLLECTION_DONE:
			case IRIS_STATUS_NO_FRAME:
				msg.data.error = IRIS_ERROR_BAD_QUALITY;
				break;
			case IRIS_STATUS_NOT_FOUND:
				msg.data.error = IRIS_ERROR_NO_USER;
				break;
			case IRIS_STATUS_BAD_IMAGE_QUALITY:
				msg.data.error = IRIS_ERROR_BAD_QUALITY;
				break;
			case IRIS_STATUS_PERMISSION_DENIED:
				msg.data.error = IRIS_ERROR_PERMISSION_DENIED;
				break;
			case IRIS_STATUS_FAIL:
			case IRIS_STATUS_BAD_PARAMETER:
			case IRIS_STATUS_NOT_ENOUGH_MEMORY:
			case IRIS_STATUS_NOT_INITED:
			case IRIS_STATUS_NOT_SUPPORT:
			case IRIS_STATUS_OVERFLOW:
			case IRIS_STATUS_FILE_IO_FAIL:
				msg.data.error = IRIS_ERROR_GENERIC;
				break;
			default:
				msg.data.error = err;
		}
	}

	if (msg.data.error != IRIS_ERROR_CANCELED)
		mNotify(&msg, mData);
	mDevice->destroy_frame_source();

}

/* iris_device */
iris_device::iris_device()
	:mTZIntf(NULL), mTask(NULL), mTaskCallback(NULL), mFrameSource(NULL), mEnrollParamSize(0), mAuthParamSize(0), mCameraId(0)
{
}


iris_device::~iris_device()
{
	close();
}

int iris_device::open(bool tz_comm)
{
	char pval[PROPERTY_VALUE_MAX];
	int property_val, ret;

	ret = init_meta_data(mMetaData);
	if (ret) {
		ALOGE("fail to get camera meta data");
		return ret;
	}


	mTZIntf = create_iris_tzee_obj(tz_comm, mMetaData);
	if (!mTZIntf) {
		ALOGE("Iris device open fail to create tzee object");
		return -ENOMEM;
	}



	mTaskCallback = new iris_device_callback(this);
	if (!mTaskCallback) {
		delete mTZIntf;
		mTZIntf = NULL;
		ALOGE("Iris device open fail to create iris_device_callback object");
		return -ENOMEM;
	}

	return 0;
}

void iris_device::close()
{
	if (mTask) {
		mTask->cancel();
		delete mTask;
		mTask = NULL;
	}

	if (mTZIntf) {
		delete mTZIntf;
		mTZIntf = NULL;
	}

	if (mTaskCallback) {
		delete mTaskCallback;
		mTaskCallback = NULL;
	}

	destroy_frame_source();
}

int iris_device::set_notify(iris_notify_t notify, void *data)
{
	if (!mTaskCallback)
		return -1;

	mTaskCallback->set_notify(notify, data);
	return 0;
}

uint64_t iris_device::pre_enroll()
{
	uint64_t challenge = 0;

	if (!mTZIntf) {
		ALOGE("Iris device not ready");
		return -ENODEV;
	}

	if (is_busy()) {
		ALOGE("Iris device is busy");
	}
	cancel();

	mTZIntf->pre_enroll(challenge);
	return challenge;
}

int iris_device::enroll(const hw_auth_token_t *hat,  uint32_t gid, uint32_t timeout_sec,
	int32_t uid, String16 &package)
{
	int ret = 0;
	iris_enroll_task *enroll_task = NULL;

	if (!hat) {
		ALOGE("invalid auth token");
		return -EINVAL;
	}

	if (!mTZIntf) {
		ALOGE("Iris device not ready");
		return -ENODEV;
	}

	if (is_busy()) {
		ALOGE("Iris device is busy");
	}

	ret = create_frame_source(0);
	if ( ret < 0) {
		ALOGE("Create iris camera failed");
		return ret;
	}

	mTaskCallback->set_groupId(gid);
	enroll_task = new iris_enroll_task(*mTZIntf, *mTaskCallback, *hat, gid, timeout_sec);
	if (!enroll_task) {
		ALOGE("Create enroll task failed");
		destroy_frame_source();
		return -ENOMEM;
	}

	enroll_task->set_frame_source(mFrameSource);
	if (mEnrollParamSize)
		enroll_task->set_param((uint8_t *)&mEnrollParam, mEnrollParamSize);
	mEnrollParamSize = 0;
	mTask = enroll_task;
	return mTask->start();
}

int iris_device::post_enroll()
{
	int ret = 0;

	if (!mTZIntf) {
		ALOGE("Iris device not ready");
		return -ENODEV;
	}

	if (is_busy()) {
		ALOGE("Iris post enroll device is busy");
	}
	cancel();

	ret = mTZIntf->post_enroll();

	return ret;
}

uint64_t iris_device::get_authenticator_id()
{
	uint64_t id = 0;

	if (!mTZIntf) {
		ALOGE("Iris device not ready");
		return id;
	}

	if (is_busy()) {
		ALOGE("Iris device is busy");
	}
	cancel();

	mTZIntf->get_authenticator_id(id);
	return id;
}

int iris_device::cancel()
{
	if (mTask) {
		mTask->cancel();
		delete mTask;
		mTask = NULL;
	}

	destroy_frame_source();
	return 0;
}

int iris_device::enumerate(iris_identifier_t *results,uint32_t *max_size)
{
	int ret = 0;
	uint32_t i, count;
	struct iris_enrollment_list enrollment_list;

	if (!mTZIntf) {
		ALOGE("Iris device not ready");
		return -ENODEV;
	}

	if (is_busy()) {
		ALOGE("Iris device is busy");
	}
	cancel();

	ret =  mTZIntf->enumerate_enrollment(enrollment_list);
	if (ret) {
		ALOGE("fail to enumerate ret=%d", ret);
		return ret;
	}

	count = *max_size;
	if (enrollment_list.count < count)
		count = enrollment_list.count;

	*max_size = count;
	for (i = 0; i < count; i++) {
		results[i].gid = enrollment_list.data[i].user_id;
		results[i].irisId = enrollment_list.data[i].iris_id;
	}

	return ret;
}

int iris_device::remove(iris_identifier_t id)
{
	iris_remove_task *remove_task = NULL;

	if (!mTZIntf) {
		ALOGE("Iris device not ready");
		return -ENODEV;
	}

	if (is_busy()) {
		ALOGE("Iris device is busy");
	}

	cancel();

	mTaskCallback->set_groupId(id.gid);
	remove_task = new iris_remove_task(*mTZIntf, *mTaskCallback,
						id, IRIS_REMOVE_TASK_TIME_OUT);
	if (!remove_task) {
		ALOGE("Create remove task failed");
		return -ENOMEM;
	}

	mTask = remove_task;
	return mTask->start();
}

int iris_device::set_active_group(uint32_t gid, const char *store_path)
{
	if (!mTZIntf) {
		ALOGE("Iris device not ready");
		return -ENODEV;
	}

	if (is_busy()) {
		ALOGE("Iris device is busy");
	}

	cancel();

	return -EINVAL;
}

int iris_device::authenticate(uint64_t operation_id, uint32_t gid,
	int32_t uid, String16 &package)
{
	int ret = 0;
	iris_auth_task *auth_task = NULL;

	if (!mTZIntf) {
		ALOGE("Iris device not ready");
		return -ENODEV;
	}

	if (is_busy()) {
		ALOGE("Iris device is busy");
	}

	ret = create_frame_source(1);
	if ( ret < 0) {
		ALOGE("Create iris camera failed");
		return ret;
	}

	mTaskCallback->set_groupId(gid);
	auth_task = new iris_auth_task(*mTZIntf, *mTaskCallback,
					operation_id, gid, IRIS_AUTHENTICATE_TASK_TIME_OUT);
	if (!auth_task) {
		ALOGE("Create enroll task failed");
		destroy_frame_source();
		return -ENOMEM;
	}
	
	auth_task->set_frame_source(mFrameSource);
	if (mAuthParamSize)
		auth_task->set_param((uint8_t *)&mAuthParam, mAuthParamSize);
	mAuthParamSize = 0;
	mTask = auth_task;
	return mTask->start();
}

bool iris_device::is_busy()
{
	if (mTask && mTask->is_running())
		return true;

	return false;
}

int iris_device::create_camera(uint32_t cam_id, int use_case)
{
    IrisCameraSource  *camera = NULL;
    Size sensor_output_size, preview_size;
    char pval[PROPERTY_VALUE_MAX];
    int property_val;
    uint32_t cam_op_mode = IRIS_CAMERA_OP_MODE_SECURE_RDI;

    Mutex::Autolock autoLock(mLock);

    sensor_output_size.width = mMetaData.frame_info.width;
    sensor_output_size.height = mMetaData.frame_info.height;

    //set default camera mode to secure rdi mode
    property_get("persist.iris.cam_mode", pval, "2");
    property_val = atoi(pval);
    switch (property_val) {
        case 0:
            cam_op_mode = IRIS_CAMERA_OP_MODE_PREVIEW;
            break;
        case 1:
            cam_op_mode = IRIS_CAMERA_OP_MODE_RDI;
            break;
        case 2:
        default:
            cam_op_mode = IRIS_CAMERA_OP_MODE_SECURE_RDI;
            break;
    }

    ALOGD("iris camera mode %d op_mode %d", property_val, cam_op_mode);

    if (use_case == 0) {
        preview_size.width = mMetaData.enroll_preview_size.width;
        preview_size.height = mMetaData.enroll_preview_size.height;
    } else {
        preview_size.width = mMetaData.verify_preview_size.width;
        preview_size.height = mMetaData.verify_preview_size.height;
    }

    camera = new IrisCameraSource(cam_id);
    if (camera == NULL) {
        ALOGE("Camera init failed\n");
        return -ENOMEM;
    }

    // Start camera data flow
    if (camera->open() != OK) {
        ALOGE("Cannot open camera!");
        delete camera;
        return  -ENOMEM;
    }

    camera->set_op_mode(cam_op_mode);
    camera->set_op_size(cam_op_mode, sensor_output_size);
    camera->set_display_size(preview_size);
    camera->set_preview_surface(mBufferProducer);
    camera->set_frame_orientation(mOrientation);
    mFrameSource = camera;

    return 0;
}

int iris_device::create_frame_source(int use_case)
{
	return create_camera(mCameraId, use_case);
}

void iris_device::destroy_frame_source()
{
	Mutex::Autolock autoLock(mLock);

	ALOGD("Destroy frame source\n");
	if (mFrameSource) {
		delete mFrameSource;
		mFrameSource = NULL;
	}

	//remove previous used surface
	mBufferProducer = NULL;
}

int iris_device::adjust_camera_parameter(iris_camera_param_t param, int adjust)
{
	ALOGD("Adjust camera param %d", adjust);

	switch(param) {
	case IRIS_CAMERA_PARAM_GAIN:
		mFrameSource->set_sensor_gain(adjust);
		break;
	case IRIS_CAMERA_PARAM_EXP_TIME:
		mFrameSource->set_sensor_exposure_time(adjust);
		break;
	default:
		ALOGE("Invalid camera parameter");
		return -EINVAL;
	}

	return 0;
}

int iris_device::configure_enroll(const uint8_t *param, int32_t param_size)
{
	if (param_size > IRIS_MAX_VENDOR_INFO_SIZE)
		return -EINVAL;

	mEnrollParamSize = param_size;
	memcpy(mEnrollParam, param, param_size);
	return 0;
}

int iris_device::configure_auth(const uint8_t *param, int32_t param_size)
{
	if (param_size > IRIS_MAX_VENDOR_INFO_SIZE)
		return -EINVAL;
	
	mAuthParamSize = param_size;
	memcpy(mAuthParam, param, param_size);
	return 0;
}

int iris_device::configure_orientation(int orientation)
{
	mOrientation = orientation;
	if (mFrameSource)
		mFrameSource->set_frame_orientation(orientation);
	return 0;
}

int iris_device::init_meta_data(struct iris_meta_data& meta_data)
{
	iris_camera_caps_t camera_caps;

	if (create_frame_source(0) < 0) {
		ALOGE("Failed to open camera");
		return -ENODEV;
	}

	mFrameSource->get_sensor_caps(camera_caps);
	memset(&meta_data, 0, sizeof(meta_data));
	meta_data.frame_info.format = IRIS_COLOR_FORMAT_Y_ONLY;
	meta_data.frame_info.width = camera_caps.width;
	meta_data.frame_info.height = camera_caps.height;
	meta_data.frame_info.stride = camera_caps.width;

	meta_data.frame_config_min.exposure_ms = camera_caps.min_exp_time_ns/1000000;
	meta_data.frame_config_max.exposure_ms = camera_caps.max_exp_time_ns/1000000;
	meta_data.frame_config_min.gain = camera_caps.min_gain;
	meta_data.frame_config_max.gain = camera_caps.max_gain;

	ALOGD("Camera caps: width %d height %d min_gain %d max_gain %d min_exp %d max_exp %d",
		camera_caps.width, camera_caps.height, camera_caps.min_gain, camera_caps.max_gain,
		meta_data.frame_config_min.exposure_ms, meta_data.frame_config_max.exposure_ms);

	destroy_frame_source();

	return 0;
}

int iris_device::set_preview_surface(const sp<IGraphicBufferProducer>& bufferProducer)
{
    if (!mTZIntf) {
        ALOGE("Iris device not ready");
        return -ENODEV;
    }

    mBufferProducer = bufferProducer;
    ALOGD("Set preview surface");

    Mutex::Autolock autoLock(mLock);
    if (is_busy() && mFrameSource) {
        ALOGD("Set preview surface on the fly");
        mFrameSource->set_preview_surface(mBufferProducer);
    }

    return 0;
}

int iris_device::getPreviewSize(int use_case, int32_t *width, int32_t *height)
{
	if (use_case == 0) {
		*width = mMetaData.enroll_preview_size.width;
		*height = mMetaData.enroll_preview_size.height;
	} else {
		*width = mMetaData.verify_preview_size.width;
		*height = mMetaData.verify_preview_size.height;
	}
	return 0;
}


