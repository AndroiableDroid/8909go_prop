/*
 * Copyright (c) 2017 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifndef KEYMASTER_UTILS_KEYMASTERUTILS_H_
#define KEYMASTER_UTILS_KEYMASTERUTILS_H_

#include <hardware/keymaster_defs.h>
#include <QSEEComAPI.h>
#include <cstdlib>
#include <UniquePtr.h>


#define KEYMASTER_MODULE_API_VERSION_3_0 (3)
#define KEYMASTER_MODULE_HAL_MINOR_VERSION (1)

namespace keymasterutils {

#define GUARD(code)                \
    do {                           \
       ret = (code);               \
       if (ret != 0) {             \
          return ret;              \
       };                          \
    }while(0)

#define GUARD_BAIL(code, status)                   \
    do {                                           \
        if ((code) || (status != KM_ERROR_OK)) {   \
            ALOGE("%s", __func__);                 \
            ALOGE("ret: %d", code);                \
            ALOGE("resp->status: %d", status);     \
            if (ret)                               \
                return ret;                        \
            else                                   \
                ret = (keymaster_error_t) status;  \
            return ret;                            \
        }                                          \
    }while(0)

class KeymasterUtils {

typedef struct {
    uint32_t major_version;
    uint32_t minor_version;
    uint32_t ta_major_version;
    uint32_t ta_minor_version;
    struct QSEECom_handle *qseecom;
}QseecomHandle;

public:
    KeymasterUtils();
    virtual ~KeymasterUtils();

    size_t km_memscpy(void *dst, size_t dst_size, const void *src, size_t src_size);

    keymaster_error_t initialize(size_t size);
    keymaster_error_t gk_initialize(size_t size);
    uint32_t getKeymasterVersion(void);
    uint32_t getKeymasterTaMinorVersion(void);
    uint32_t getKeymasterHalMinorVersion(void);
    void* qseecom_dev_init(void);
    keymaster_error_t send_cmd(void *send_buf,
            uint32_t sbuf_len, void *resp_buf, uint32_t rbuf_len);

private:
    QseecomHandle kmHandle;
};

}
#endif /* KEYMASTER_UTILS_KEYMASTERUTILS_H_ */
