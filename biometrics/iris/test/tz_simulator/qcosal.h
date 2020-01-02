/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifndef _QC_OSAL_H_
#define _QC_OSAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TZ_BUILD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#endif

#include <stdarg.h> // For vargs
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h> // for INT_MAX/etc
#include <math.h>
#include <float.h>

#include "iris_common.h"

// Log
enum iris_osal_log_level {
    IRIS_OSAL_LOG_LEVEL_VERBOSE = 1,
    IRIS_OSAL_LOG_LEVEL_HIGH,
    IRIS_OSAL_LOG_LEVEL_CRITICAL,
    IRIS_OSAL_LOG_LEVEL_MAX,
    IRIS_OSAL_LOG_LEVEL_FORCE_32BIT = 0x7FFFFFFF
};
#define IRIS_OSAL_LOG_VERBOSE(...) iris_osal_log(IRIS_OSAL_LOG_LEVEL_VERBOSE, __FUNCTION__, __LINE__, __VA_ARGS__)
#define IRIS_OSAL_LOG_HIGH(...) iris_osal_log(IRIS_OSAL_LOG_LEVEL_HIGH, __FUNCTION__, __LINE__, __VA_ARGS__)
#define IRIS_OSAL_LOG_CRITICAL(...) iris_osal_log(IRIS_OSAL_LOG_LEVEL_CRITICAL, __FUNCTION__, __LINE__, __VA_ARGS__)
#define IRIS_DEBUG_LOG_CRITICAL(ENABLE, ...) \
    { if (ENABLE) iris_osal_log(IRIS_OSAL_LOG_LEVEL_CRITICAL, __FUNCTION__, __LINE__, __VA_ARGS__); }

IRIS_API void iris_osal_log(uint32_t level, const char *funcName, uint32_t lineNum, char *format, ...);
IRIS_API void iris_osal_set_log_level(uint32_t level);

// example: iris_osal_log_f(IRIS_OSAL_LOG_LEVEL_CRITICAL, "value = ", 2.1234f);
IRIS_API void iris_osal_log_f(uint32_t level, char *name, float value);

// Memory
enum iris_osal_mem_id {
    IRIS_OSAL_MEM_UNKNOWN = 0,
    IRIS_OSAL_MEM_TEST,
    IRIS_OSAL_MEM_MANAMER,
    IRIS_OSAL_MEM_IMG_DATA,
    IRIS_OSAL_MEM_ENGINE,
    IRIS_OSAL_MEM_ALGO,
    IRIS_OSAL_MEM_FILE_HEADER,
    IRIS_OSAL_MEM_MAX,
    IRIS_OSAL_MEM_FORCE_32BIT = 0x7FFFFFFF
};

IRIS_API void *iris_osal_malloc(size_t size);
IRIS_API void *iris_osal_calloc(size_t size);
IRIS_API void iris_osal_free(void *ptr);
IRIS_API void *iris_osal_malloc_with_id(size_t size, uint32_t id);
IRIS_API void iris_osal_memscpy(void *dst, size_t dst_size, void *src, size_t copy_size);
IRIS_API void *iris_osal_memset(void *ptr, uint8_t value, size_t size);
IRIS_API void iris_osal_check_mem_prof(const char *name);
IRIS_API void iris_osal_reset_mem_prof(void);

IRIS_API void *iris_osal_map(uint32_t fd, uint32_t data, size_t length);
IRIS_API void iris_osal_unmap(void *ptr, size_t length);
IRIS_API void iris_osal_close(uint32_t fd);

#define IRIS_OSAL_MEMCPY(d, s, size) iris_osal_memscpy(d, size, s, size)



// Time
IRIS_API uint32_t iris_osal_get_time_ms(void);

// String related
IRIS_API size_t iris_osal_strlen(const char *str);
IRIS_API int32_t iris_osal_strncmp(const char *str1, const char *str2, uint32_t num);
IRIS_API int32_t iris_osal_atoi(const char *str);
IRIS_API void iris_osal_strlcpy(char *dst, const char *src, size_t dstsize);

#if WIN32
#ifndef snprintf
#define snprintf sprintf_s
#endif
#endif

// Rand
IRIS_API int32_t iris_osal_rand(void);
IRIS_API void iris_osal_srand(uint32_t seed);
IRIS_API void iris_osal_rand_init(void);
IRIS_API void iris_osal_rand_deinit(void);
IRIS_API void iris_osal_rand_reset(void);
IRIS_API int64_t iris_osal_rand64(void);

// Misc
#ifdef TZ_BUILD
#define IRIS_OSAL_ASSERT(...)
#else
#define IRIS_OSAL_ASSERT(...) assert(__VA_ARGS__)
#endif

#ifdef WIN32
#define IRIS_OSAL_MEMORY_ALIGNMENT __declspec(align(0x8))
#else
#define IRIS_OSAL_MEMORY_ALIGNMENT __attribute__((aligned(0x8)))
#endif

#ifdef WIN32
#define INLINE __inline
#else
#define INLINE inline
#endif

#define IRIS_OSAL_SAVE_CUR_TIME(enable) iris_osal_save_timestamp(__FUNCTION__, __LINE__, enable);
#define IRIS_OSAL_LOG_TIME_SPENT(enable) iris_osal_log_timestamps(__FUNCTION__, __LINE__, enable);

#ifdef __cplusplus
}
#endif

#endif//_QC_OSAL_H_
