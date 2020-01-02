/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#include <stdio.h>
#define LOG_TAG "Iris_Manager_Dummy"
#include <utils/Log.h>
#include "qcosal.h"
#include "iris_manager.h"

#define IRIS_MANGER_VERSION 0x10000001


static uint64_t challenge_magic_id = 0x10102020;
static uint64_t verify_operationId = 0;
static uint32_t irisId = 0x1020;
static int progress = 0;

IRIS_API iris_status iris_manager_init(struct iris_meta_data *meta_data, enum iris_img_src_type src_type)
{
	progress = 0;
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_deinit(void)
{
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_pre_enroll(uint64_t *challenge)
{
	*challenge = challenge_magic_id;
	progress = 0;
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_post_enroll(void)
{
	progress = 0;
	return IRIS_STATUS_SUCCESS;
}


IRIS_API iris_status iris_manager_get_version(struct iris_version *version)
{
	printf("get version\n");
	version->version = IRIS_MANGER_VERSION;
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_enroll_begin(struct iris_enroll_begin_param *enroll_begin_param)
{
	uint32_t i;
	
	ALOGD("enroll begin, param size=%d", enroll_begin_param->vendor_info_size);
	progress = 0;
	iris_osal_memset(&enroll_begin_param->frame_config, 0, sizeof(enroll_begin_param->frame_config));

	for (i = 0; i < enroll_begin_param->vendor_info_size; i++)
		ALOGD("enroll param[%d]=%d", i, enroll_begin_param->vendor_info[i]);

	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_enroll_capture(struct iris_enroll_status *enroll_status)
{
	progress += 1;
	usleep(100000);
	enroll_status->progress = progress;
	if (progress == 30)
		enroll_status->eng_status = IRIS_FRAME_STATUS_BAD_EYE_DISTANCE;
	else
		enroll_status->eng_status = IRIS_FRAME_STATUS_BAD_EYE_OPENNESS;
	ALOGD("progres=%d\n", progress);

	enroll_status->frame_desc.frame_config.flash = 0;
	enroll_status->frame_desc.frame_config.focus = 1;
	enroll_status->frame_desc.frame_config.gain = 0;
	enroll_status->frame_desc.frame_config.exposure_ms = 0;

	enroll_status->frame_desc.vendor_info_size = 2;
	enroll_status->frame_desc.vendor_info[0] = 8;
	enroll_status->frame_desc.vendor_info[1] = 9;

	return (progress == 100) ? IRIS_STATUS_SUCCESS : IRIS_STATUS_NO_FRAME;
}

IRIS_API iris_status iris_manager_enroll_commit(struct iris_enroll_result *enroll_result)
{
	enroll_result->iris_id = irisId++;
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_enroll_cancel(void)
{
	progress = 0;
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_verify_begin(struct iris_verify_begin_param *verify_begin_param)
{
	uint32_t i;
	ALOGD("verify begin, param size=%d", verify_begin_param->vendor_info_size);

	for (i = 0; i < verify_begin_param->vendor_info_size; i++)
		ALOGD("verify param[%d]=%d", i, verify_begin_param->vendor_info[i]);

	progress = 0;
	iris_osal_memset(&verify_begin_param->frame_config, 0, sizeof(verify_begin_param->frame_config));
	verify_operationId = verify_begin_param->operation_id;
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_verify_capture(struct iris_verify_result *verify_result)
{
	progress += 10;
	usleep(300000);
	if (progress == 20)
		verify_result->eng_status = IRIS_FRAME_STATUS_BAD_EYE_OPENNESS;
	if (progress == 100) {
		verify_result->iris_id = irisId - 1;
		verify_result->matched = 1;
	}
	else
		verify_result->iris_id = 0;

	verify_result->frame_desc.left_eye_desc.pupil_x = 1;
	verify_result->frame_desc.left_eye_desc.pupil_y = 2;
	verify_result->frame_desc.left_eye_desc.pupil_radius = 3;
	verify_result->frame_desc.left_eye_desc.iris_x = 4;
	verify_result->frame_desc.left_eye_desc.iris_y = 5;
	verify_result->frame_desc.left_eye_desc.iris_radius = 6;

	verify_result->frame_desc.right_eye_desc.pupil_x = 1;
	verify_result->frame_desc.right_eye_desc.pupil_y = 2;
	verify_result->frame_desc.right_eye_desc.pupil_radius = 3;
	verify_result->frame_desc.right_eye_desc.iris_x = 4;
	verify_result->frame_desc.right_eye_desc.iris_y = 5;
	verify_result->frame_desc.right_eye_desc.iris_radius = 6;

	verify_result->frame_desc.frame_config.flash = 0;
	verify_result->frame_desc.frame_config.focus = 1;
	verify_result->frame_desc.frame_config.gain = 0;
	verify_result->frame_desc.frame_config.exposure_ms = 0;

	verify_result->frame_desc.vendor_info_size = 2;
	verify_result->frame_desc.vendor_info[0] = 8;
	verify_result->frame_desc.vendor_info[1] = 9;


	ALOGD("verify progres=%d\n, iris_id=%d", progress, verify_result->iris_id);
	return (progress == 100) ? IRIS_STATUS_SUCCESS : IRIS_STATUS_NO_FRAME;
}

IRIS_API iris_status iris_manager_verify_end()
{
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_retrieve_enrollee(uint32_t user_id, struct iris_enrollee_info *enrollee_info)
{
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_delete_enrollee(uint32_t irisId, uint32_t user_id)
{
	ALOGD("enrollee irisId = %u, id %u\n", (unsigned int)irisId, user_id);
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_delete_all_enrollee(void)
{
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_get_authenticator_id(uint64_t *id)
{
	*id = 0x101010;
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_verify_token(struct hw_auth_token *token)
{
	ALOGD("token challenge =%llx\n", (long long unsigned int)token->challenge);

	if (token->challenge == challenge_magic_id) {
		ALOGD("token verified\n");
		return IRIS_STATUS_SUCCESS;
	} 

	return IRIS_STATUS_FAIL;
}

IRIS_API iris_status iris_manager_get_auth_token(struct hw_auth_token *token)
{
	token->version = 1;
	token->challenge == verify_operationId;
	printf("token challenge =%llx\n", (long long unsigned int)token->challenge);
	token->authenticator_type = 1 << 3;
	token->authenticator_id = 2020;
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_set_meta_data(struct iris_meta_data *meta)
{
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_set_token_key(uint8_t *token_key, uint32_t key_len)
{
	ALOGD("token key length=%d", (int)key_len);
	return IRIS_STATUS_SUCCESS;
}

IRIS_API iris_status iris_manager_enumerate_enrollment(int32_t *count, struct iris_identifier *ids)
{
	int i;
	*count = 3;

	ALOGD("enumeration enrollment");
	for (i = 0; i < *count; i++) {
		ids[i].irisId = i+1;
		ids[i].userId = 0;
	}
	return IRIS_STATUS_SUCCESS;

}


