/******************************************************************************
  @file  Stats.h
  @brief   header for collecting stats for game detection module

  header for collecting stats for game detection module

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#ifndef __GM_STATS_H__
#define __GM_STATS_H__

#include <sys/time.h>
#include "Config.h"

namespace GamingSustenance {

class GameDetection;
class Input;

class Stats {
    friend class GameDetection;
    friend class Input;
    private:
        //array to store samples
        int *mGld;
        int *mTchcnt;
        int *mIafc;
        int mTch_cum_sum;
        int mIafc_cum_sum;

        //final result
        int mResult;

        //book keeping varaibles
        int mNcumsamples;
        int mNsamples;
        int mIdx;

        char mAppName[MAX_MSG_APP_NAME_LEN];
        bool mXmlChecked;

        struct timeval mStarttime;
        struct timeval mEndtime;

        //list for window statistics
        //statistics for every window period
        struct WinStats {
            float gld_avg;
            float gld_sd;
            int tch_sum;
            int iafc_sum;
        } mWstats;
        int mWin_cnt;
        int mWinresult;

    private:
        bool Init(int nsamples);
        void Clear();

        int GetResult() {
            return mResult;
        }

        void SetResult(int result) {
            mResult = result;
            return;
        }

        double GetDetectionTime() {
            gettimeofday(&mEndtime, NULL);
            double etime = (double)(mEndtime.tv_sec + (mEndtime.tv_usec/1000000.0)) -
                    (double)(mStarttime.tv_sec + (mStarttime.tv_usec/1000000.0));
            return etime;
        }

        void StartDetectionTime() {
            gettimeofday(&mStarttime, NULL);
            return;
        }

        char *GetAppName() {
            return mAppName;
        }

        void UpdateXmlChecked(bool val) {
            mXmlChecked = val;
        }

        bool wasXmlChecked(){
            return mXmlChecked;
        }

        void SetAppName(const char *appname) {
            if (NULL != appname) {
                strlcpy(mAppName, appname, MAX_MSG_APP_NAME_LEN);
            }
        }

        bool IsItNewWindowStart() {
            return (mIdx == 0);
        }

        bool IsItNewSampleStart() {
            return (mNcumsamples == 0);
        }

        int Calculate();
        void Store(int gload, int iafc, int tcnt);

        WinStats &GetWStats() {
            return mWstats;
        }

        void Print();
    public:
        ~Stats();
};

} //namespace

#endif
