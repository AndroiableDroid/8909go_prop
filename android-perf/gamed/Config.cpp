/******************************************************************************
  @file  Config.cpp
  @brief   configuration data of game detection module

  configuration data of game detection module

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <cutils/properties.h>
#include "Config.h"

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "ANDR-PERF-GD-CONFIG"
#include <cutils/log.h>

/* window period in secs */
#define C_WP (10)

/* % of load w.r.t. TURBO */
#define C_GLD_LOWTHR (30.0)
#define C_GLD_HIGHTHR (60.0)

/* touch events per minute */
#define C_TCHCNT_THR (120)

/* No. of frames GPU slept in a minute assuming 60 fps frame rate*/
#define C_IAFC_THR (180)

/* Standard deviation of GPU Load */
#define C_GLD_SD_THR (10.0)

/* samplig period */
#define C_GLD_SP (500)

/* Interrupt line number of touch input device */
#define C_TCH_INTLINE (402)

using namespace GamingSustenance;

Config::Config() {
    Init();
}

void Config::Init() {
    mGameProfile = 1;
    mWp = C_WP;
    mGldLowthr = C_GLD_LOWTHR;
    mGldHighthr = C_GLD_HIGHTHR;
    mTchcntThr = C_TCHCNT_THR;
    mIafcThr = C_IAFC_THR;
    mGldSdThr = C_GLD_SD_THR;
    mGldSp = C_GLD_SP;
    mTchIntline = C_TCH_INTLINE;
}

int Config::Read() {
    char prop[PROPERTY_VALUE_MAX];

    if (property_get("sys.games.gt.prof", prop, NULL) <= 0) {
        QLOGI("Error while reading CPU profile number for games (sys.games.gt.prof)");
    } else {
        mGameProfile = atoi(prop);
    }

    if (property_get("persist.gamedet.window_size", prop, NULL) <= 0) {
        QLOGI("Error while reading window period config param (persist.gamedet.window_size)");
    } else {
        mWp = atoi(prop);
    }

    if (property_get("persist.gamedet.sampling_period", prop, NULL) <= 0) {
        QLOGI("Error while reading gpuload sampling_period config param(persist.gamedet.sampling_period)");
    } else {
        mGldSp = atoi(prop);
    }

    if (property_get("persist.gamedet.tchint", prop, NULL) <= 0) {
        QLOGI("Error while reading touch interrupt number config param(persist.gamedet.tchint)");
    } else {
        mTchIntline = atoi(prop);
    }

    if (property_get("persist.gamedet.gld_lowthr", prop, NULL) <= 0) {
        QLOGI("Error while reading gpuload lower threshold config param(persist.gamedet.gld_lowthr)");
    } else {
        mGldLowthr = (float)atoi(prop);
    }

    if (property_get("persist.gamedet.gld_highthr", prop, NULL) <= 0) {
        QLOGI("Error while reading gpuload higher threshold config param(persist.gamedet.gld_highthr)");
    } else {
        mGldHighthr = (float)atoi(prop);
    }

    if (property_get("persist.gamedet.gld_sd_thr", prop, NULL) <= 0) {
        QLOGI("Error while reading GPU load standard deviation threshold config param(persist.gamedet.gld_sd_thr)");
    } else {
        mGldSdThr = (float)atoi(prop);
    }

    if (property_get("persist.gamedet.tch_thr", prop, NULL) <= 0) {
        QLOGI("Error while reading touch input count threshold config param(persist.gamedet.tch_thr)");
    } else {
        mTchcntThr = atoi(prop);
    }

    if (property_get("persist.gamedet.iafc_thr", prop, NULL) <= 0) {
        QLOGI("Error while reading IAFC threshold config param(persist.gamedet.iafc_thr)");
    } else {
        mIafcThr = atoi(prop);
    }

    QLOGI("perf: gamed config params: ");
    QLOGI("\n\n\t\tConfiguration Parameters");
    QLOGI("CPU profile for games(sys.games.gt.prof) - %d",mGameProfile);
    QLOGI("Window period(persist.gamedet.window_size) - %d",mWp);
    QLOGI("Touch device interrupt number(persist.gamedet.tchint) - %d", mTchIntline);
    QLOGI("Gpu load sampling period(persist.gamedet.sampling_period) - %d\n", mGldSp);
    QLOGI("Gpu load lower threshold(persist.gamedet.gld_lowthr) - %.2lf", mGldLowthr);
    QLOGI("Gpu load higher threshold(persist.gamedet.gld_highthr) - %.2lf", mGldHighthr);
    QLOGI("Touch count threshold(persist.gamedet.tch_thr) - %d", mTchcntThr);
    QLOGI("GPU load standard deviation threshold(persist.gamedet.gld_sd_thr) - %.2lf", mGldSdThr);
    QLOGI("IAFC threshold(persist.gamedet.iafc_thr) - %d\n\n", mIafcThr);

    return 0;
}
