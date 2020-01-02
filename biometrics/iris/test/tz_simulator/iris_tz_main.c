/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#include "qcosal.h"
#include "iris_parser.h"
#include "iris_tz_api.h"
#include "iris_manager.h"

#define IRIS_TZ_APP_NAME 		"iris"
#define IRIZ_TZ_VERSION 0x100

// TrustZone application name
char TZ_APP_NAME[] = { IRIS_TZ_APP_NAME };
uint32_t g_mgr_inited;
/**
 * @brief
 * Application specific initialization code.
 * QSEE will call this function after secure app is loaded and authenticated.
 */
void tz_app_init(void)
{
    IRIS_OSAL_LOG_CRITICAL("tz_app_init\n");
}

/**
 * @brief
 * Application command handler.
 */
void tz_app_cmd_handler(void *request, uint32_t req_length, void *response, uint32_t rsp_length)
{
    int ret;
    struct iris_request req;
    struct iris_response result;
    uint32_t cmd = IRIS_CMD_INVALID;
    struct iris_meta_data meta_data;

    IRIS_OSAL_LOG_CRITICAL("tz_app_cmd_handler\n");

    ret = iris_response_init(&result, response, rsp_length);
    if (ret) {
        IRIS_OSAL_LOG_CRITICAL("invalid response buffer\n");
        return;
    }

    ret = iris_req_init(&req, request, req_length);
    if (ret) {
        IRIS_OSAL_LOG_CRITICAL("invalid request\n");
        iris_response_put_int32(&result, ret);
        return;
    }

    ret = iris_req_get_uint32(&req, &cmd);
    IRIS_OSAL_LOG_CRITICAL("command id=%d\n", cmd);
    if (ret) {
        iris_response_put_int32(&result, ret);
        return;
    }

    //todo: add a special command for update frame_info
    if (cmd != IRIS_CMD_TEST && !g_mgr_inited && cmd != IRIS_CMD_SET_META_DATA) {
        iris_osal_memset(&meta_data, 0, sizeof(struct iris_meta_data));
        meta_data.frame_info.width = 1920;
        meta_data.frame_info.height = 1920;
        meta_data.frame_info.stride = 1920;
        meta_data.frame_info.color_format = IRIS_COLOR_FORMAT_Y_ONLY;
        iris_manager_init(&meta_data, IRIS_IMG_SRC_T_CAM);
        g_mgr_inited = TRUE;
    }

    switch (cmd) {
    case IRIS_CMD_GET_VERSION:
        exec_get_version(&req, &result);
        break;

    case IRIS_CMD_PRE_ENROLL:
        exec_pre_enroll(&req, &result);
        break;

    case IRIS_CMD_POST_ENROLL:
        exec_post_enroll(&req, &result);
        break;

    case IRIS_CMD_ENROLL_BEGIN:
        exec_enroll_begin(&req, &result);
        break;

    case IRIS_CMD_ENROLL_CAPTURE:
        exec_enroll_capture(&req, &result);
        break;

    case IRIS_CMD_ENROLL_COMMIT:
        exec_enroll_commit(&req, &result);
        break;

    case IRIS_CMD_ENROLL_CANCEL:
        exec_enroll_cancel(&req, &result);
        break;

    case IRIS_CMD_RETRIEVE_ENROLLMENT:
        exec_retrieve_enrollee(&req, &result);
        break;

    case IRIS_CMD_DELETE_ENROLLMENT:
        exec_delete_enrollee(&req, &result);
        break;

    case IRIS_CMD_DELETE_ALL_ENROLLMENTS:
        exec_delete_all_enrollees(&req, &result);
        break;

    case IRIS_CMD_IDENTIFY_BEGIN:
        break;

    case IRIS_CMD_IDENTIFY_CAPTURE:
        break;

    case IRIS_CMD_IDENTIFY_END:
        break;

    case IRIS_CMD_VERIFY_BEGIN:
        exec_verify_begin(&req, &result);
        break;

    case IRIS_CMD_VERIFY_CAPTURE:
        exec_verify_capture(&req, &result);
        break;

    case IRIS_CMD_VERIFY_END:
        exec_verify_end(&req, &result);
        break;

    case IRIS_CMD_GET_AUTHENTICATOR_ID:
        exec_get_authenticator_id(&req, &result);
        break;

    case IRIS_CMD_VERIFY_TOKEN:
        exec_verify_token(&req, &result);
        break;

    case IRIS_CMD_GET_AUTH_TOKEN:
        exec_get_auth_token(&req, &result);
        break;

    case IRIS_CMD_SET_META_DATA:
        exec_set_meta_data(&req, &result);
        break;

    case IRIS_CMD_SET_TOKEN_KEY:
        exec_set_token_key(&req, &result);
        break;

    case IRIS_CMD_ENUMERATE_ENROLLMENT:
        exec_enumerate_enrollment(&req, &result);
        break;

    case IRIS_CMD_TEST:
        exec_test(&req, &result);
        break;

    case IRIS_CMD_PREPARE_FRAME:
        exec_prepare_frame(&req, &result);
        break;

    default:
        IRIS_OSAL_LOG_VERBOSE("unknown command: %d\n", cmd);
        iris_response_put_int32(&result, IRIS_STATUS_NOT_SUPPORT);
        break;
    }
}

/**
 * @brief
 * App specific shutdown
 * App will be given a chance to shutdown gracefully
 */
void tz_app_shutdown(void)
{
    IRIS_OSAL_LOG_VERBOSE("Shutting down...\n");
    iris_manager_deinit();
    return;
}
