/**
 * Copyright (c) 2017 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
=============================================================

                          EDIT HISTORY FOR FILE

when       who     what, where, why
--------   ---     ------------------------------------------
04/12/17   gs      Initial version
=============================================================*/
#include <jni.h>
#include <stdlib.h>
#include <string>
#include <pthread.h>
#include "seccam_if.h"

#ifdef LOG_TAG
    #undef LOG_TAG
#endif
#define LOG_TAG "SECCAM-VENDOR-LIB-JNI"

typedef enum tz_app_vendor_if_cmd_id_t {
    TZ_APP_IF_CMD_VENDOR_EXCHANGE_TIMESTAMP = 2000,
    TZ_APP_IF_CMD_VENDOR_SIZE = 0x7FFFFFFF
} tz_app_vendor_if_cmd_id_t;

typedef enum tz_app_vendor_if_status_t {
    TZ_APP_IF_STATUS_VENDOR_SUCCESS = 0,
    TZ_APP_IF_STATUS_VENDOR_GENERAL_FAILURE = -1,
    TZ_APP_IF_STATUS_VENDOR_INVALID_INPUT_PARAMS = -2,
    TZ_APP_IF_STATUS_VENDOR_ERR_SIZE = 0x7FFFFFFF
} tz_app_vendor_if_status_t;

#pragma pack(push, tz_app_if, 1)

typedef struct tz_app_vendor_if_send_cmd_t {
    tz_app_vendor_if_cmd_id_t  cmd_id;
    uint64_t                   cmd_data;
} tz_app_vendor_if_send_cmd_t;

typedef struct tz_app_vendor_if_send_cmd_rsp_t {
    tz_app_vendor_if_status_t  ret;
    uint64_t                   ret_data;
} tz_app_vendor_if_send_cmd_rsp_t;

#pragma pack(pop, tz_app_if)

static pthread_mutex_t access_lock_ = PTHREAD_MUTEX_INITIALIZER;

//=========================================================================
inline void lock() {
    pthread_mutex_lock(&access_lock_);
}

//=========================================================================
inline void unlock() {
    pthread_mutex_unlock(&access_lock_);
}

//=========================================================================
extern "C" jlong Java_com_qualcomm_qti_seccamservice_SecCamServiceVendorHandler_exchangeTimestampWithTA(
    JNIEnv* env, jobject thiz, jlong hlosTimestamp) {

    jlong ret = 0;
    ALOGD("exchangeTimestampWithTA - Enter");

    lock();

    tz_app_vendor_if_send_cmd_t cmd_;
    tz_app_vendor_if_send_cmd_rsp_t cmd_rsp_;
    memset(&cmd_, 0, sizeof(tz_app_vendor_if_send_cmd_t));
    memset(&cmd_rsp_, 0, sizeof(tz_app_vendor_if_send_cmd_rsp_t));
    cmd_.cmd_id = TZ_APP_IF_CMD_VENDOR_EXCHANGE_TIMESTAMP;
    cmd_.cmd_data = hlosTimestamp;

    int retval = secCamSendCmd(&cmd_, sizeof(tz_app_vendor_if_send_cmd_t),
            &cmd_rsp_, sizeof(tz_app_vendor_if_send_cmd_rsp_t));
    if (retval) {
        ALOGE("exchangeTimestampWithTA - send command to TZ failed (%d)",
            retval);
    }

    ret = cmd_rsp_.ret_data;
    ALOGI("exchangeTimestampWithTA - ret_data is (%d)", ret);
    unlock();

    return ret;
}
