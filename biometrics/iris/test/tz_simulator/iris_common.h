/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifndef __IRIS_COMMON_H__
#define __IRIS_COMMON_H__

#ifdef WIN32
#define IRIS_API __declspec(dllexport)
#else
#define IRIS_API
#endif

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifndef TRUE
#define TRUE   1   /* Boolean true value. */
#endif

#ifndef FALSE
#define FALSE  0   /* Boolean false value. */
#endif

#ifndef NULL
#define NULL   0
#endif

typedef void* iris_handle;

/*===== enum and structures =====*/

typedef enum {
    IRIS_STATUS_SUCCESS,
    IRIS_STATUS_CONTINUE,
    IRIS_STATUS_FRAME_COLLECTION_DONE,
    IRIS_STATUS_NO_FRAME,
    IRIS_STATUS_NOT_FOUND,
    IRIS_STATUS_BAD_IMAGE_QUALITY,
    IRIS_STATUS_FAIL = 0x100,
    IRIS_STATUS_BAD_PARAMETER,
    IRIS_STATUS_NOT_ENOUGH_MEMORY,
    IRIS_STATUS_NOT_INITED,
    IRIS_STATUS_NOT_SUPPORT,
    IRIS_STATUS_OVERFLOW,
    IRIS_STATUS_FILE_IO_FAIL,
    IRIS_STATUS_MAX,
    IRIS_STATUS_FORCE_32BIT = 0x7FFFFFFF
} iris_status;



#define IRIS_MAX_VENDOR_INFO_SIZE   128

typedef enum {
    IRIS_FRAME_STATUS_BAD_IMAGE_QUALITY = 1 << 0,
    IRIS_FRAME_STATUS_EYE_NOT_FOUND = 1 << 1,
    IRIS_FRAME_STATUS_EYE_TOO_CLOSE = 1 << 2,
    IRIS_FRAME_STATUS_EYE_TOO_FAR = 1 << 3,
    IRIS_FRAME_STATUS_EYE_TOO_UP = 1 << 4,
    IRIS_FRAME_STATUS_EYE_TOO_DOWN = 1 << 5,
    IRIS_FRAME_STATUS_EYE_TOO_LEFT = 1 << 6,
    IRIS_FRAME_STATUS_EYE_TOO_RIGHT = 1 << 7,
    IRIS_FRAME_STATUS_MOTION_BLUR = 1 << 8,
    IRIS_FRAME_STATUS_FOCUS_BLUR = 1 << 9,
    IRIS_FRAME_STATUS_BAD_EYE_OPENNESS = 1 << 10,
    IRIS_FRAME_STATUS_BAD_EYE_DISTANCE = 1 << 11,
    IRIS_FRAME_STATUS_EXPOSURE_UNDER = 1 << 12,
    IRIS_FRAME_STATUS_EXPOSURE_OVER = 1 << 13,
    IRIS_FRAME_STATUS_WITH_GLASS = 1 << 14,
} iris_frame_status;

typedef enum {
    IRIS_COLOR_FORMAT_RGB888,
    IRIS_COLOR_FORMAT_YCBCR_420SP,
    IRIS_COLOR_FORMAT_YCRCB_420SP,
    IRIS_COLOR_FORMAT_Y_ONLY,
    IRIS_COLOR_FORMAT_MAX,
    IRIS_COLOR_FORMAT_FORCE_32BIT = 0x7FFFFFFF
} iris_color_format;

struct iris_frame_config {
    int32_t flash;
    int32_t focus;
    int32_t gain;
    int32_t exposure_ms;
};

struct iris_frame_info {
    uint32_t width;
    uint32_t height;
    uint32_t stride;
    uint32_t color_format;
    struct iris_frame_config frame_config;
};

struct iris_frame_buffer {
    struct iris_frame_info meta;
    uint32_t buffer_length;
    void *buffer;
};

struct iris_frame {
    struct iris_frame_info info;
    uint32_t frame_handle;
    uint32_t frame_data;
    uint32_t frame_len;
};

struct iris_rect {
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
};

struct iris_meta_data {
    struct iris_frame_info frame_info;
    struct iris_frame_config frame_config_min;
    struct iris_frame_config frame_config_max;
    uint32_t auto_exposure;
    uint32_t orientation;
};

enum iris_img_src_type {
    IRIS_IMG_SRC_T_FILE = 0,
    IRIS_IMG_SRC_T_CAM,
    IRIS_IMG_SRC_T_SEC_CAM,
    IRIS_IMG_SRC__FORCE_32BIT = 0x7FFFFFFF
};

struct __attribute__((__packed__)) iris_eye_desc {
    uint32_t pupil_x;
    uint32_t pupil_y;
    uint32_t pupil_radius;
    uint32_t iris_x;
    uint32_t iris_y;
    uint32_t iris_radius;
};

struct __attribute__((__packed__)) iris_frame_desc {
	struct iris_frame_config frame_config;
    struct iris_eye_desc left_eye_desc;
    struct iris_eye_desc right_eye_desc;
    uint32_t vendor_info_size;
    uint8_t vendor_info[IRIS_MAX_VENDOR_INFO_SIZE];
};

#ifdef __cplusplus
}
#endif

#endif

