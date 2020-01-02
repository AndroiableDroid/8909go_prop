/******************************************************************************
  @file    Iop.h
  @brief   Android IOP HAL module

  DESCRIPTION

  ---------------------------------------------------------------------------

  Copyright (c) 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/


#ifndef VENDOR_QTI_HARDWARE_IOP_V1_0_PERF_H
#define VENDOR_QTI_HARDWARE_IOP_V1_0_PERF_H

#include <vendor/qti/hardware/iop/1.0/IIop.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

#include "io-p.h"

namespace vendor {
namespace qti {
namespace hardware {
namespace iop {
namespace V1_0 {
namespace implementation {

using ::android::hidl::base::V1_0::DebugInfo;
using ::android::hidl::base::V1_0::IBase;
using ::vendor::qti::hardware::iop::V1_0::IIop;
using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

class Iop : public IIop {
    typedef struct IopInfo {
    bool is_opened;
    void *dlhandle;
    int  (*iop_server_init)(void);
    void (*iop_server_exit)(void);
    int (*iop_server_submit_request)(iop_msg_t*);
    } IopInfo;
    pthread_mutex_t mMutex;
    ~Iop();

 public:
    IopInfo mHandle;
    Iop();
    void LoadIopLib();

    Return<int32_t> iopStart(int32_t pid, const hidl_string& pkg_name, const hidl_string& code_path) override;
    Return<void> iopStop() override;
};

extern "C" IIop* HIDL_FETCH_IIop(const char* name);

}  // namespace implementation
}  // namespace V1_0
}  // namespace iop
}  // namespace hardware
}  // namespace qti
}  // namespace vendor

#endif  // VENDOR_QTI_HARDWARE_IOP_V1_0_PERF_H
