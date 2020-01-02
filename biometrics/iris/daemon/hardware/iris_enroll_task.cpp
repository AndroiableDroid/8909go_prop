/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#define LOG_TAG "IrisEnrollTask"
#include <utils/Log.h>
#include <unistd.h>
#include <hardware/hw_auth_token.h>

#include "iris_enroll_task.h"
#include "iris_frame_source.h"

#define IRIS_ENROLL_GET_FRAME_DELAY 5000 //in microseconds

iris_enroll_task::iris_enroll_task(iris_interface &intf, iris_task_callback &cb,
				const hw_auth_token_t &token, uint32_t gid, int timeout)
	:mIntf(intf), mCallback(cb), mToken(token),mGroupId(gid),
	mTimeout(timeout), mSource(NULL), mSourceStarted(false)
{
}

iris_enroll_task::~iris_enroll_task()
{
}

void iris_enroll_task::set_frame_source(iris_frame_source *source)
{
	mSource = source;
}

int iris_enroll_task::start_frame_source()
{
	int ret = 0, buf_index;
	bool need_tz_init = false;
	iris_frame frame;

	if (mSource && !mSourceStarted) {
		ret = mSource->start();
		if (!ret)
			mSourceStarted = true;
	}
	if (ret)
		return -EIO;
	else
		return ret;
}

void iris_enroll_task::stop_frame_source()
{
	if (mSource && mSourceStarted) {
		mSource->stop();
		mSourceStarted = false;
	}
}

int iris_enroll_task::verify_token()
{
	int ret;
	ret = mIntf.verify_token(mToken);
	return ret;
}

bool iris_enroll_task::continue_running(int status)
{
	return (status == IRIS_STATUS_CONTINUE ||
			status == IRIS_STATUS_NO_FRAME ||
			status == IRIS_STATUS_FRAME_COLLECTION_DONE);
}


int iris_enroll_task::run()
{
	int ret = 0;
	struct iris_enroll_status enroll_status;
	struct iris_enroll_result enroll_result;
	struct iris_frame buffer, preview_buffer;
	bool buffer_valid = false;
	int64_t startTimeMs, loopTimeMs;
	struct iris_enroll_begin_param param;
	struct iris_frame_config camera_config;

	startTimeMs = getTimeMs();

	ret = verify_token();
	if (ret) {
		ALOGE("fail to verify token for enroll ret=%d", ret);
		mCallback.on_err(ret);
		return ret;
	}

	ret = start_frame_source();
	if (ret) {
		mCallback.on_err(ret);
		return ret;
	}

	param.enrollee_id = mGroupId;
	param.vendor_info_size = mParamSize;
	if (mParamSize)
		memcpy(param.vendor_info, mParam, mParamSize);

	ret = mIntf.enroll_begin(&param, &camera_config);
	if (ret != IRIS_STATUS_SUCCESS) {
		stop_frame_source();
		mCallback.on_err(ret);
		ALOGE("enroll_begin fail ret=%d", ret);
		return ret;
	}

	if (camera_config.exposure_ms != 0) {
		ALOGD("last good exposure %d", camera_config.exposure_ms);
		mSource->set_sensor_exposure_time(camera_config.exposure_ms);
	}
	if (camera_config.gain != 0) {
		ALOGD("last good gain %d", camera_config.gain);
		mSource->set_sensor_gain(camera_config.gain);
	}


	ret = IRIS_STATUS_NO_FRAME;
	while (mState == IRIS_TASK_STATE_RUNNING && continue_running(ret)) {
		loopTimeMs = getTimeMs() - startTimeMs;
		if (loopTimeMs >= mTimeout * 1000) {
			ret = -ETIME;
			break;
		}

		//get frame
		buffer_valid = false;
		if (mSourceStarted && ret == IRIS_STATUS_NO_FRAME) {
			if (mSource->wait_for_frame_available(IRIS_ENROLL_GET_FRAME_DELAY) != OK) {
				ALOGE("No frame available");
				continue;
			} else {
				if (mSource->get_frame(buffer, preview_buffer) != OK) {
					ALOGE("no frame, try again %d", ret);
					usleep(1);
					continue;
				}

				ALOGD("buffer exposure=%d", buffer.info.frame_config.exposure_ms);
				buffer_valid = true;
			}

		}

		//continuous enroll
		ret = mIntf.enroll_capture(buffer_valid ? &buffer : NULL, &preview_buffer, enroll_status);
		ALOGD("enroll_capture ret=%d, status=%d, progress=%d", ret, enroll_status.status, enroll_status.progress);

		switch (ret) {
			case IRIS_STATUS_SUCCESS:
				break;
			case IRIS_STATUS_CONTINUE:
			case IRIS_STATUS_NO_FRAME:
				mCallback.on_event(IRIS_TASK_EVENT_ENROLL_PROGRESS, &enroll_status);
				break;
			case IRIS_STATUS_FRAME_COLLECTION_DONE:
				stop_frame_source();
				mCallback.on_event(IRIS_TASK_EVENT_ENROLL_COLLECTION_DONE, &enroll_status);
				break;
			default:
				break;
		}

		//release frame
		if (buffer_valid)
			mSource->put_frame(buffer, preview_buffer);
	}

	if (mState != IRIS_TASK_STATE_RUNNING)
		ret = -EINTR;

	if (ret == IRIS_STATUS_SUCCESS)
		ret = mIntf.enroll_commit(enroll_result);

	stop_frame_source();
	mState = IRIS_TASK_STATE_STOP;

	if (ret != IRIS_STATUS_SUCCESS) {
		mIntf.enroll_cancel();
		mCallback.on_err(ret);
		ALOGE("enroll fail ret=%d", ret);
	} else {
		mCallback.on_event(IRIS_TASK_EVENT_ENROLL_DONE, &enroll_result);
	}
	return ret;
}

