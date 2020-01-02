/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifndef _IRIS_MANAGER_H_
#define _IRIS_MANAGER_H_

#include "iris_common.h"


struct iris_version {
	uint32_t version;
};

struct iris_enroll_begin_param {
    uint32_t enrollee_id;
    struct iris_frame_config frame_config; //Output: suggested frame config;
    uint32_t vendor_info_size;
    uint8_t vendor_info[IRIS_MAX_VENDOR_INFO_SIZE];
};

struct iris_enroll_status {
    uint32_t eng_status;
    uint32_t progress;
    struct iris_frame_desc frame_desc;
};

struct iris_enroll_result {
    int32_t iris_id;
};

struct iris_enrollee_info {
    uint32_t enrollee_id;
    uint64_t enrollment_date;
};

#define IRIS_MAX_HMAC_LEN   32 // HMAC length in auth token

struct hw_auth_token {
    uint8_t version;  // Current version is 0
    uint64_t challenge;
    uint64_t user_id;              // secure user ID, not Android user ID
    uint64_t authenticator_id;      // secure authenticator ID
    uint32_t authenticator_type;  // hw_authenticator_type_t, in network order
    uint64_t timestamp;           // in network order
    uint8_t hmac[IRIS_MAX_HMAC_LEN];
};

struct iris_verify_begin_param {
    uint64_t operation_id;
    uint32_t enrollee_id;
    struct iris_frame_config frame_config; //Output: suggested frame config;
    uint32_t vendor_info_size;
    uint8_t vendor_info[IRIS_MAX_VENDOR_INFO_SIZE];
};

struct iris_verify_result {
    uint32_t eng_status;
    int32_t iris_id;
    uint32_t matched;
    struct iris_frame_desc frame_desc;
};

struct iris_identifier {
    uint32_t irisId;
    uint32_t userId;
};

IRIS_API iris_status iris_manager_init(struct iris_meta_data *meta_data, enum iris_img_src_type src_type);
IRIS_API iris_status iris_manager_deinit(void);
IRIS_API iris_status iris_manager_pre_enroll(uint64_t *challenge);
IRIS_API iris_status iris_manager_post_enroll(void);
IRIS_API iris_status iris_manager_get_version(struct iris_version *version);
IRIS_API iris_status iris_manager_enroll_begin(struct iris_enroll_begin_param *enroll_begin_param);
IRIS_API iris_status iris_manager_add_frame(struct iris_frame *frame);
IRIS_API iris_status iris_manager_enroll_capture(struct iris_enroll_status *enroll_status);
IRIS_API iris_status iris_manager_enroll_commit(struct iris_enroll_result *enroll_result);
IRIS_API iris_status iris_manager_enroll_cancel(void);
IRIS_API iris_status iris_manager_verify_begin(struct iris_verify_begin_param *verify_begin_param);
IRIS_API iris_status iris_manager_verify_capture(struct iris_verify_result *verify_result);
IRIS_API iris_status iris_manager_verify_end(void);

IRIS_API iris_status iris_manager_retrieve_enrollee(uint32_t enrollee_id, struct iris_enrollee_info *enrollee_info);
IRIS_API iris_status iris_manager_delete_enrollee(uint32_t iris_id, uint32_t enrollee_id);
IRIS_API iris_status iris_manager_delete_all_enrollee(void);

IRIS_API iris_status iris_manager_get_authenticator_id(uint64_t *authenticator_id);

IRIS_API iris_status iris_manager_verify_token(struct hw_auth_token *token);
IRIS_API iris_status iris_manager_get_auth_token(struct hw_auth_token *token);

IRIS_API iris_status iris_manager_set_meta_data(struct iris_meta_data *meta);

IRIS_API iris_status iris_manager_set_token_key(uint8_t *token_key, uint32_t key_len);

IRIS_API iris_status iris_manager_enumerate_enrollment(int32_t *count, struct iris_identifier *ids);

#endif

