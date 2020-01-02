/******************************************************************************
  @file  Config.h
  @brief   header for configuration data of game detection module

  header for configuration data of game detection module

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#ifndef __GM_CONFIG_H__
#define __GM_CONFIG_H__

#define MAX_MSG_APP_NAME_LEN 128

#define QC_DEBUG_ERRORS 1
#ifdef QC_DEBUG_ERRORS
#define QLOGE(...)    ALOGE(__VA_ARGS__)
#else
#define QLOGE(...)
#endif

#if QC_DEBUG
#define QLOGW(...)    ALOGW(__VA_ARGS__)
#define QLOGI(...)    ALOGI(__VA_ARGS__)
#define QLOGV(...)    ALOGV(__VA_ARGS__)
#define QCLOGE(...)   ALOGE(__VA_ARGS__)
#else
#define QLOGW(...)
#define QLOGI(...)
#define QLOGV(...)
#define QCLOGE(...)
#endif

#define MAX_LINE_SIZE 128
#define FAILED -1

/* Result definition */
#define GAMEDET_IS_GAME 1
#define GAMEDET_IS_BM 2
#define GAMEDET_IS_APP 3
#define GAMEDET_IS_UNKNOWN 4

#define GAMEDET_IS_GAME_STR "1"
#define GAMEDET_IS_BM_STR "2"
#define GAMEDET_IS_APP_STR "3"
#define GAMEDET_IS_UNKNOWN_STR "4"

#define APPLY_GAME_PROFILE 1
#define REMOVE_GAME_PROFILE -1
#define DISABLE_GAME_PROFILE 0

namespace GamingSustenance {

class Config {
    friend class GameDetection;
    private:
        int mGameProfile;
        int mWp;
        float mGldLowthr;
        float mGldHighthr;
        int mTchcntThr;
        int mIafcThr;
        float mGldSdThr;
        int mGldSp;
        int mTchIntline;

    private:
        Config();
        Config(Config const& rh);
        Config& operator=(Config const& rh);

    private:
        void Init();
        int Read();
        int SetSamplingPeriod();

        int GetSamplingPeriod() {
            return mGldSp;
        }
        int GetTouchCountThreshold() {
            return mTchcntThr;
        }
        int GetInactivityFrameCount() {
            return mIafcThr;
        }
        int GetWindowSize() {
            return mWp;
        }

        int GetGpuLoadHighThreshold() {
            return mGldHighthr;
        }

        int GetGpuLoadLOwThreshold() {
            return mGldLowthr;
        }

        int GetGameProfile() {
            return mGameProfile;
        }

        int GetTouchInterruptLine() {
            return mTchIntline;
        }
};

} //namespace

#endif
