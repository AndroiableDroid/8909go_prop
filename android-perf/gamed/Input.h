/******************************************************************************
  @file  Input.h
  @brief   header for collecting inputs like gpuload, touchcount, etc

  Header for collecting inputs like gpuload, touchcount, etc

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#ifndef __GM_INPUT_H__
#define __GM_INPUT_H__

namespace GamingSustenance {
class Stats;

class Input {
    friend class GameDetection;
    private:
        int mGpuLoad;
        int mTouchCount;
        int mInactivityFrameCount;
        int mPrevIntCount;

        int mTchIntline;
        Stats *mStatsPtr;

    private:
        Input();
        Input(Input const& rh);
        Input& operator=(Input const& rh);

    private:
        void Init(Stats *sptr, int interuptNo);

        void Read();
        int ReadTevents();

        int GetLoad() {
            return mGpuLoad;
        }

        int GetTouchCount() {
            return mTouchCount;
        }

        int GetInactivityFrameCount() {
            return mInactivityFrameCount;
        }
};

} //namespace

#endif
