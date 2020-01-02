/******************************************************************************
  @file    service.cpp
  @brief   Android IOP HAL service

  DESCRIPTION

  ---------------------------------------------------------------------------

  Copyright (c) 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/

#define LOG_TAG "vendor.qti.hardware.iop@1.0-service"

#include <vendor/qti/hardware/iop/1.0/IIop.h>
#include <hidl/LegacySupport.h>

using vendor::qti::hardware::iop::V1_0::IIop;
using android::hardware::defaultPassthroughServiceImplementation;

int main() {
    return defaultPassthroughServiceImplementation<IIop>();
}
