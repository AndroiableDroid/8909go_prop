/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
#include <stdio.h>
#include "iris_tz_api.h"
#include "iris_manager.h"
#include "iris_parser.h"
#include "iris_common.h"
#include "qcosal.h"

void exec_get_version(struct iris_request *req, struct iris_response *response)
{
    int ret;
    struct iris_version version;
    ret = iris_manager_get_version(&version);
    iris_response_put_int32(response, ret);
    iris_response_put_uint32(response, version.version);
}

void exec_pre_enroll(struct iris_request *req, struct iris_response *response)
{
    int ret;
    uint64_t challenge;

    ret = iris_manager_pre_enroll(&challenge);
    iris_response_put_int32(response, ret);
    iris_response_put_uint64(response, challenge);
}

void exec_post_enroll(struct iris_request *req, struct iris_response *response)
{
    int ret;

    ret = iris_manager_post_enroll();
    iris_response_put_int32(response, ret);
}


void exec_enroll_begin(struct iris_request *req, struct iris_response *response)
{
    int ret;
    uint32_t enrollee_id = 0;
    struct iris_enroll_begin_param enroll_begin;

    iris_osal_memset(&enroll_begin, 0, sizeof(enroll_begin));

    ret = iris_req_get_uint32(req, &enrollee_id);
    if (ret) {
        iris_response_put_int32(response, ret);
        return;
    }
    enroll_begin.vendor_info_size = sizeof(enroll_begin.vendor_info);
    ret = iris_req_get_data(req, enroll_begin.vendor_info, &enroll_begin.vendor_info_size);

    enroll_begin.enrollee_id = enrollee_id;

    ret = iris_manager_enroll_begin(&enroll_begin);

    iris_response_put_int32(response, ret);
    iris_response_put_struct(response, &enroll_begin.frame_config, sizeof(struct iris_frame_config));
    if (enroll_begin.vendor_info_size)
        iris_response_put_data(response, enroll_begin.vendor_info, enroll_begin.vendor_info_size);
}

void exec_enroll_capture(struct iris_request *req, struct iris_response *response)
{
    struct iris_enroll_status enroll_status;
    struct iris_frame frame;
    int ret;

    iris_osal_memset(&enroll_status, 0, sizeof(enroll_status));
    ret = iris_req_get_struct(req, &frame, sizeof(struct iris_frame));
    if (ret) {
        iris_response_put_int32(response, ret);
        return;
    }

    IRIS_OSAL_LOG_CRITICAL("Width: %d, Height: %d, Stride: %d Format: %d\n", frame.info.width,
                           frame.info.height, frame.info.stride, frame.info.color_format);
    IRIS_OSAL_LOG_CRITICAL("Len: %d, Buffer: %d\n", frame.frame_len, frame.frame_data);

    /*todo parse the frame buffer to iris manager */
    //iris_manager_add_frame(&frame);
    IRIS_OSAL_LOG_CRITICAL("Add frame successes\n");
    enroll_status.frame_desc.frame_config = frame.info.frame_config;

    ret = iris_manager_enroll_capture(&enroll_status);

    IRIS_OSAL_LOG_CRITICAL("Return Code: %d\n", ret);
    iris_response_put_int32(response, ret);
    iris_response_put_int32(response, enroll_status.eng_status);
    iris_response_put_uint32(response, enroll_status.progress);
    iris_response_put_struct(response, &enroll_status.frame_desc, sizeof(struct iris_frame_desc));
}

void exec_enroll_commit(struct iris_request *req, struct iris_response *response)
{
    int ret;
    struct iris_enroll_result enroll_result;

    ret = iris_manager_enroll_commit(&enroll_result);
    iris_response_put_int32(response, ret);
    iris_response_put_uint32(response, enroll_result.iris_id);
}

void exec_enroll_cancel(struct iris_request *req, struct iris_response *response)
{
    int ret;

    ret = iris_manager_enroll_cancel();
    iris_response_put_int32(response, ret);
}

void exec_retrieve_enrollee(struct iris_request *req, struct iris_response *response)
{
    int ret;
    uint32_t enrollee_id;
    struct iris_enrollee_info info;

    ret = iris_req_get_uint32(req, &enrollee_id);
    if (ret) {
        iris_response_put_int32(response, ret);
        return;
    }

    ret = iris_manager_retrieve_enrollee(enrollee_id, &info);

    iris_response_put_int32(response, ret);
    iris_response_put_uint32(response, info.enrollee_id);
    iris_response_put_uint64(response, info.enrollment_date);
}

void exec_delete_enrollee(struct iris_request *req, struct iris_response *response)
{
    int ret;
    uint32_t enrollee_id;
    uint32_t iris_id = 0;

    ret = iris_req_get_uint32(req, &iris_id);
    if (ret) {
        iris_response_put_int32(response, ret);
        return;
    }

    ret = iris_req_get_uint32(req, &enrollee_id);
    if (ret) {
        iris_response_put_int32(response, ret);
        return;
    }

    ret = iris_manager_delete_enrollee(iris_id, enrollee_id);
    iris_response_put_int32(response, ret);
}

void exec_delete_all_enrollees(struct iris_request *req, struct iris_response *response)
{
    int ret;

    ret = iris_manager_delete_all_enrollee();
    iris_response_put_int32(response, ret);
}

void exec_verify_begin(struct iris_request *req, struct iris_response *response)
{
    int ret;
    uint32_t enrollee_id;
    uint64_t operationId;
    struct iris_verify_begin_param verify_begin;

    iris_osal_memset(&verify_begin, 0, sizeof(verify_begin));

    ret = iris_req_get_uint64(req, &operationId);
    if (ret) {
        iris_response_put_int32(response, ret);
        return;
    }

    ret = iris_req_get_uint32(req, &enrollee_id);
    if (ret) {
        iris_response_put_int32(response, ret);
        return;
    }
    verify_begin.vendor_info_size = sizeof(verify_begin.vendor_info);
    ret = iris_req_get_data(req, verify_begin.vendor_info, &verify_begin.vendor_info_size);
    verify_begin.operation_id = operationId;
    verify_begin.enrollee_id = enrollee_id;


    ret = iris_manager_verify_begin(&verify_begin);
    iris_response_put_int32(response, ret);
    iris_response_put_struct(response, &verify_begin.frame_config, sizeof(struct iris_frame_config));
    if (verify_begin.vendor_info_size)
        iris_response_put_data(response, verify_begin.vendor_info, verify_begin.vendor_info_size);
}

void exec_verify_capture(struct iris_request *req, struct iris_response *response)
{
    int ret;
    struct iris_verify_result verify_result;
    struct iris_frame frame;

    iris_osal_memset(&verify_result, 0, sizeof(verify_result));
    ret = iris_req_get_struct(req, &frame, sizeof(struct iris_frame));
    if (ret) {
        iris_response_put_int32(response, ret);
        return;
    }

    IRIS_OSAL_LOG_CRITICAL("Width: %d, Height: %d, Stride: %d Format: %d\n", frame.info.width,
                           frame.info.height, frame.info.stride, frame.info.color_format);
    IRIS_OSAL_LOG_CRITICAL("Len: %d, Buffer: %d\n", frame.frame_len, frame.frame_data);

    /*todo parse the frame buffer to iris manager */
    //iris_manager_add_frame(&frame);
    IRIS_OSAL_LOG_CRITICAL("Add frame successes\n");
    verify_result.frame_desc.frame_config = frame.info.frame_config;
    ret = iris_manager_verify_capture(&verify_result);

    iris_response_put_int32(response, ret);
    iris_response_put_int32(response, verify_result.eng_status);
    iris_response_put_uint32(response, verify_result.iris_id);
    iris_response_put_int32(response, verify_result.matched);
    iris_response_put_struct(response, &verify_result.frame_desc, sizeof(struct iris_frame_desc));
}

void exec_verify_end(struct iris_request *req, struct iris_response *response)
{
    int ret;

    ret = iris_manager_verify_end();
    iris_response_put_int32(response, ret);
}

void exec_get_authenticator_id(struct iris_request *req, struct iris_response *response)
{
    int ret;
    uint64_t id;

    ret = iris_manager_get_authenticator_id(&id);
    iris_response_put_int32(response, ret);
    iris_response_put_uint64(response, id);
}

void exec_verify_token(struct iris_request *req, struct iris_response *response)
{
    int ret;
    struct hw_auth_token token;

    ret = iris_req_get_token(req, &token);
    if (ret) {
        iris_response_put_int32(response, ret);
        return;
    }

    ret = iris_manager_verify_token(&token);
    iris_response_put_int32(response, ret);
}

void exec_get_auth_token(struct iris_request *req, struct iris_response *response)
{
    int ret;
    struct hw_auth_token token;

    (void)req;
    ret = iris_manager_get_auth_token(&token);
    iris_response_put_int32(response, ret);
    if (!ret)
        iris_response_put_token(response, &token);
}

void exec_set_meta_data(struct iris_request *req, struct iris_response *response)
{
    int ret;
    struct iris_meta_data meta;

    ret = iris_req_get_struct(req, &meta, sizeof(struct iris_meta_data));
    if (ret) {
        iris_response_put_int32(response, ret);
        return;
    }

    iris_manager_init(&meta, IRIS_IMG_SRC_T_CAM);
    ret = iris_manager_set_meta_data(&meta);
    iris_response_put_int32(response, ret);
}

void exec_set_token_key(struct iris_request *req, struct iris_response *response)
{
    int ret;
    uint32_t key_len;

    ret = iris_req_get_uint32(req, &key_len);
    if (ret) {
        iris_response_put_int32(response, ret);
        return;
    }

    if (!key_len || req->index + key_len > req->len) {
        IRIS_OSAL_LOG_CRITICAL("Size doesn't match: req index = %d req len = %d key_len = %d\n",
                                req->index, req->len, key_len);
        return;
    }

    ret = iris_manager_set_token_key((uint8_t *)req->buf + req->index, key_len);
    iris_response_put_int32(response, ret);
}

void exec_enumerate_enrollment(struct iris_request *req, struct iris_response *response)
{
    int ret;
    int i, count;
    struct iris_identifier ids[5];

    ret = iris_manager_enumerate_enrollment(&count, ids);
    iris_response_put_int32(response, ret);
    if (!ret) {
        iris_response_put_uint32(response, count);
        for (i = 0; i < count; i++) {
            iris_response_put_uint32(response, ids[i].userId);
            iris_response_put_uint32(response, ids[i].irisId);
        }
    }
}

void exec_prepare_frame(struct iris_request *req, struct iris_response *response)
{
    struct iris_frame frame;
    int ret;
    uint8_t *buf;
    uint32_t y_size;
    ret = iris_req_get_struct(req, &frame, sizeof(struct iris_frame));
    if (ret) {
        iris_response_put_int32(response, ret);
        return;
    }
    buf = iris_osal_map(frame.frame_handle, frame.frame_data,frame.frame_len);
    if (buf == NULL) {
        iris_response_put_int32(response, IRIS_STATUS_FAIL);
        return;
    }
    y_size = (frame.info.width * frame.info.height + 1) & ~0x1;
    if (y_size < frame.frame_len && frame.frame_len > y_size) {
        iris_osal_memset(buf + y_size, 0x80, frame.frame_len - y_size);
        ret = IRIS_STATUS_SUCCESS;
    } else {
        ret = IRIS_STATUS_OVERFLOW;
    }
    iris_osal_unmap(buf, frame.frame_len);
    iris_response_put_int32(response, ret);
}

#ifdef TZ_BUILD
extern uint8_t *g_external_buf;
#define MAX_INPUT_ARG 10
void exec_test(struct iris_request *req, struct iris_response *response)
{
    int ret;
    uint32_t i, number_input;
    uint8_t *input;
    int32_t cmd = IRIS_TEST_SUB_MGR_TEST;
    int32_t arg[MAX_INPUT_ARG];
    struct iris_frame frame;

    ret = iris_req_get_uint32(req, &number_input);
    if (ret)
        goto exit;

    if (number_input > 0) {
        ret = iris_req_get_string(req, &input);
        if (ret)
            goto exit;
        IRIS_OSAL_LOG_CRITICAL("input: %s", input);
        cmd = iris_osal_atoi((char *)input);
    }

    if (IRIS_TEST_SUB_MGR_TEST == cmd) {
        ret = iris_req_get_struct(req, &frame, sizeof(struct iris_frame));
    }
    for (i = 0; i < number_input - 1; i++) {
        ret = iris_req_get_string(req, &input);
        if (ret)
            break;
        IRIS_OSAL_LOG_CRITICAL("input: %d %s", i, input);
        if (i < MAX_INPUT_ARG) {
            arg[i] = iris_osal_atoi((char *)input);
        }
    }

    if (IRIS_TEST_SUB_MGR_TEST == cmd) {
        g_external_buf = iris_osal_map(frame.frame_handle, frame.frame_data,frame.frame_len);
        ret = iris_mgr_test(0, NULL);
        iris_osal_unmap(g_external_buf, frame.frame_len);
        g_external_buf = NULL;
    } else if (IRIS_TEST_SUB_OSAL_TEST == cmd) {
        ret = iris_osal_test(0, NULL);
    } else if (IRIS_TEST_SUB_MODULE_TEST == cmd) {
        IRIS_OSAL_LOG_CRITICAL("iris_module_test is disabled");
        // ret = iris_module_test(0, NULL);
    } else if (IRIS_TEST_SUB_CV_TEST == cmd) {
        IRIS_OSAL_LOG_CRITICAL("iris_cv_test is disabled");
        //ret = iris_cv_test(0, NULL);
    }

exit:
    iris_response_put_int32(response, ret);
}
#else
void exec_test(struct iris_request *req __unused, struct iris_response *response __unused)
{
}
#endif
