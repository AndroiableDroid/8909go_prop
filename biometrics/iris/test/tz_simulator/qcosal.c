/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
 
#include "qcosal.h"
#include <malloc.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LOG_TAG "irisTA"
#include <utils/Log.h>
#include <sys/mman.h>

static void osal_time_sum_start(void);
static void osal_time_sum_end(void);

static uint32_t g_log_base_level = IRIS_OSAL_LOG_LEVEL_CRITICAL;

//#define MEM_DEBUG 1

#ifdef MEM_DEBUG
static uint32_t g_mem_debug = 1;
#define MAX_CACHE_MEM_P 600000
static void *g_mem_p[MAX_CACHE_MEM_P];
static size_t g_mem_size[MAX_CACHE_MEM_P];
static uint8_t g_mem_id[MAX_CACHE_MEM_P];
static uint32_t g_mem_cnt;
static uint32_t g_mem_cnt_without_file;
static size_t g_totoal_size;
static size_t g_mem_peak;
static uint32_t g_hit_cnt;
static uint32_t g_mem_peak_cnt;

#define DETECT_SIZE 183636
#define DETECT_INDEX 14
#define HIT_CNT 12
static void os_alloc_mem_prof(void *p, size_t size, uint32_t id)
{
    int32_t i;
    if (!g_mem_debug || !p)
        return;
    for (i = g_mem_cnt - 1; i >= 0; i--) {
        if (g_mem_p[i] == 0) {
            if (i == DETECT_INDEX && size == DETECT_SIZE) {
                g_mem_id[i] = id;
                g_hit_cnt++;
                if (g_hit_cnt == HIT_CNT) {
                    g_mem_id[i] = id;
                }
            }
            g_mem_p[i] = p;
            g_mem_size[i] = size;
            g_mem_id[i] = id;
            break;
        }
    }

    if (i < 0) {
            if (size == DETECT_SIZE) {
                g_mem_id[g_mem_cnt] = id;
                g_hit_cnt++;
                if (g_hit_cnt == HIT_CNT) {
                    g_mem_id[g_mem_cnt] = id;
                }
            }
        g_mem_p[g_mem_cnt] = p;
        g_mem_size[g_mem_cnt] = size;
        g_mem_id[g_mem_cnt] = id;
        if (g_mem_cnt < (MAX_CACHE_MEM_P - 1)) {
            g_mem_cnt++;
        } else {
            IRIS_OSAL_LOG_CRITICAL("Over the memory limit! %d", g_mem_cnt);
        }
    }
    g_totoal_size += size;
    if (g_mem_peak < g_totoal_size)
        g_mem_peak = g_totoal_size;
    if (id != IRIS_OSAL_MEM_FILE_HEADER)
        g_mem_cnt_without_file++;
    if (g_mem_cnt > g_mem_peak_cnt)
        g_mem_peak_cnt = g_mem_cnt;
}

static void os_free_mem_prof(void *p)
{
    int32_t i;
    if (!g_mem_debug || !p)
        return;
    for (i = g_mem_cnt - 1; i >= 0; i--) {
        if (g_mem_p[i] == p) {
            if (i == 5621) {
                i = i;
            }
            g_mem_p[i] = 0;
            g_totoal_size -= g_mem_size[i];
            if ((int32_t)g_mem_cnt > i + 1) {
                iris_osal_memscpy(&g_mem_p[i], MAX_CACHE_MEM_P * sizeof(void *), &g_mem_p[i+1], ((int32_t)g_mem_cnt - i - 1) * sizeof(void *));
                iris_osal_memscpy(&g_mem_size[i], MAX_CACHE_MEM_P * sizeof(uint32_t), &g_mem_size[i+1], ((int32_t)g_mem_cnt - i - 1) * sizeof(uint32_t));
                iris_osal_memscpy(&g_mem_id[i], MAX_CACHE_MEM_P * sizeof(uint8_t), &g_mem_id[i+1], ((int32_t)g_mem_cnt - i - 1) * sizeof(uint8_t));
            }
            g_mem_cnt--;
            break;
        }
    }
}

void iris_osal_check_mem_prof(const char *name)
{
    int32_t i, log_cnt = 0;
	size_t total = 0;
    if (!g_mem_debug)
        return;
    IRIS_OSAL_LOG_CRITICAL("%s cnt in cache: %d total cnt: %d totoal_size: %d mem peak = %d hit cnt=%d\n",
                           name, g_mem_cnt, g_mem_cnt_without_file, g_totoal_size, g_mem_peak, g_hit_cnt);
    for (i = g_mem_cnt - 1; i >= 0; i--) {
        if (g_mem_p[i]) {
            if (log_cnt < 10)
                IRIS_OSAL_LOG_CRITICAL("mem leak: index=%d p=%p size=%d id=%d", i, g_mem_p[i], g_mem_size[i], g_mem_id[i]);
            log_cnt++;
            total += g_mem_size[i];
        }
    }
    IRIS_OSAL_LOG_CRITICAL("In use: cnt:%d mem:%d peak_cnt:%d", log_cnt, total, g_mem_peak_cnt);

}

IRIS_API void iris_osal_reset_mem_prof(void)
{
    iris_osal_memset(g_mem_p, 0, sizeof(uint32_t) * MAX_CACHE_MEM_P);
    iris_osal_memset(g_mem_size, 0, sizeof(uint32_t) * MAX_CACHE_MEM_P);
    iris_osal_memset(g_mem_id, 0, sizeof(uint8_t) * MAX_CACHE_MEM_P);
    g_mem_cnt = 0;
    g_mem_cnt_without_file = 0;
    g_totoal_size = 0;
    g_mem_peak = 0;
    g_hit_cnt = 0;
    g_mem_peak_cnt = 0;
}
#else
static void os_alloc_mem_prof(void *p __unused, size_t size __unused, uint32_t id __unused) { }
static void os_free_mem_prof(void *p __unused) { }
IRIS_API void iris_osal_check_mem_prof(const char *name __unused) { }
IRIS_API void iris_osal_reset_mem_prof() { }
#endif

// Generic function for both WIN32 and Linux
IRIS_API void iris_osal_set_log_level(uint32_t base_level)
{
    g_log_base_level = base_level;
}

#ifdef WIN32
IRIS_API void iris_osal_log(uint32_t level, const char *funcName, uint32_t lineNum, char *format, ...)
{
    va_list argptr;

    if (level < g_log_base_level)
        return;
    if (level >= IRIS_OSAL_LOG_LEVEL_CRITICAL && funcName)
        printf("\n Func: %s, Line: %d: ", funcName, lineNum);

    va_start(argptr, format);
    vprintf(format, argptr);
    va_end(argptr);
}
#else
IRIS_API void iris_osal_log(uint32_t level, const char *funcName, uint32_t lineNum, char *format, ...)
{
    char buf[1024];
    int32_t str_len = 0;
    va_list argptr;

    if (level < g_log_base_level)
        return;
    if (level >= IRIS_OSAL_LOG_LEVEL_CRITICAL && funcName) {
        snprintf(buf, 1024, "Func: %s, Line: %d: ", funcName, lineNum);
        str_len = strlen(buf);
    }
    va_start(argptr, format);
    vsnprintf(&buf[str_len], (size_t )(1024 - str_len), format, argptr);
    va_end(argptr);
    ALOGE("%s", buf);
}
#endif

IRIS_API void iris_osal_log_f(uint32_t level, char *name, float value)
{
    uint8_t temp_buf[20];
    int32_t n = (int32_t) value;
    float remain = value - n;

    if (level < g_log_base_level)
        return;

    // account for negative values of d
    if (remain < 0)
        remain = -remain;
    snprintf((char *)temp_buf, sizeof(temp_buf), "%d.%06d", n, (int32_t) (remain * 1000000.00));
    iris_osal_log(level, NULL, 0, "\n%s %s", name, temp_buf);
}

/*========================================================================
 Function Definitions - Memory
 ======================================================================== */
IRIS_API void *iris_osal_memset(void *ptr, uint8_t value, size_t num)
{
    return memset(ptr, value, num);
}

IRIS_API void iris_osal_memscpy(void *dst, size_t dst_size, void *src, size_t copy_size)
{
#if WIN32
    memcpy_s(dst, dst_size, src, copy_size);
#else
    memcpy(dst, src, (dst_size < copy_size) ? dst_size : copy_size);
#endif
}

IRIS_API void *iris_osal_malloc(size_t size)
{
    return iris_osal_malloc_with_id(size, IRIS_OSAL_MEM_UNKNOWN);
}

IRIS_API void *iris_osal_calloc(size_t size)
{
    void *p;
    p = iris_osal_malloc_with_id(size, IRIS_OSAL_MEM_UNKNOWN);
    if (p)
        iris_osal_memset(p, 0, size);
    return p;
}
IRIS_API void *iris_osal_malloc_with_id(size_t size, uint32_t id)
{
    void *mem_ptr;

    mem_ptr = malloc(size);
    os_alloc_mem_prof(mem_ptr, size, id);
    return mem_ptr;
}

IRIS_API void iris_osal_free(void *ptr)
{
    os_free_mem_prof(ptr);
    free(ptr);
}

IRIS_API void *iris_os_memcpy(void *dest, const void *src, uint32_t size)
{
    return memcpy(dest, src, size);
}


#ifdef WIN32
// Windows Only
#include <sys/timeb.h>

/*========================================================================
 Function Definitions - Timer
 ======================================================================== */

IRIS_API uint32_t iris_osal_get_time_ms(void)
{
    struct timeb t;

    ftime(&t);
    return (uint32_t)(t.time * 1000.00 + t.millitm);
}

#else
// Linux Only
IRIS_API uint32_t iris_osal_get_time_ms(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (uint32_t)((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}
#endif

/*========================================================================
 Function Definitions - String
 ======================================================================== */
IRIS_API void iris_osal_strlcpy(char *dst, const char *src, size_t dstsize)
{
    //No strlcpy support
    strncpy(dst, src, dstsize);
}


IRIS_API size_t iris_osal_strlen(const char *str)
{
    return strlen(str);
}

IRIS_API int32_t iris_osal_strncmp(const char *str1, const char *str2, uint32_t num)
{
    while (num--) {
        if (*(str1++) != *(str2)++) {
            return (int32_t) (*(unsigned char *)(str1 - 1) - *(unsigned char *)(str2 - 1));
        }
    }
    return 0;
}

IRIS_API int32_t iris_osal_atoi(const char *str)
{
    return atoi(str);
}

/*========================================================================
 Function Definitions - File IO
 ======================================================================== */

#if WIN32
IRIS_API void *iris_osal_map(uint32_t fd, uint32_t data, size_t length)
{
    IRIS_OSAL_LOG_VERBOSE("Dummy function: %d %x %d", fd, data, length);
    return NULL;
}

IRIS_API void iris_osal_unmap(void *ptr, size_t length)
{
    IRIS_OSAL_LOG_VERBOSE("Dummy function: %p %d", ptr, length);
}

IRIS_API void iris_osal_close(uint32_t fd)
{
    (void)fd;
}

#else
IRIS_API void *iris_osal_map(uint32_t fd, uint32_t data, size_t length)
{
    IRIS_OSAL_LOG_VERBOSE("%d %x %d", fd, data, length);
    return mmap(NULL, length, PROT_READ  | PROT_WRITE,
            MAP_SHARED, fd, 0);
}

IRIS_API void iris_osal_unmap(void *ptr, size_t length)
{
    munmap(ptr, length);
}

IRIS_API void iris_osal_close(uint32_t fd)
{
    close(fd);
}

#endif


