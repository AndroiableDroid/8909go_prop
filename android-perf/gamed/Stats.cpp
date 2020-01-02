/******************************************************************************
  @file  Stats.cpp
  @brief   collecting stats for game detection module

  collecting stats for game detection module

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#include <cstring>
#include <cmath>
#include "Stats.h"

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "ANDR-PERF-GAMEDET"
#include <cutils/log.h>

using namespace GamingSustenance;

Stats::~Stats(void) {
    if (mGld) {
        delete mGld;
        mGld = NULL;
    }
    if (mTchcnt) {
        delete mTchcnt;
        mTchcnt = NULL;
    }
    if (mIafc) {
        delete mIafc;
        mIafc = NULL;
    }
}

bool Stats::Init(int nsamples) {
    mNsamples = nsamples;
    //allocate memory for stats
    mGld = new int[mNsamples];
    if (NULL == mGld) {
        return false;
    }
    mTchcnt = new int[mNsamples];
    if (NULL == mTchcnt) {
        delete[] mGld;
        return false;
    }
    mIafc = new int[mNsamples];
    if (NULL == mIafc) {
        delete[] mGld;
        delete[] mTchcnt;
        return false;
    }
    mXmlChecked = false;
    return true;
}

void Stats::Print() {
    QLOGI("Window#%2d-Stats-GL_AVG,GL_SD,IAFC,TCH  %5.2lf %5.2lf %4d %4d",
          mWin_cnt, mWstats.gld_avg, mWstats.gld_sd, mWstats.iafc_sum, mWstats.tch_sum);
}

int Stats::Calculate() {
    int gld_sum, tch_sum, iafc_sum, i;
    float gld_avg, gld_sd, sum_dev;
    int ret = 0;

    if (!mGld || !mTchcnt || !mIafc) {
        return FAILED;
    }

    /* Calculate GPU load average, touch input count, IAFC count */
    gld_sum = tch_sum = iafc_sum = 0;
    for(i=0; i<mNsamples; ++i) {
        gld_sum += mGld[i];
        tch_sum += mTchcnt[i];
        iafc_sum += mIafc[i];
    }
    gld_avg = gld_sum * 1.0 / mNsamples;

    /* calculate standard deviation */
    sum_dev = 0.0;
    for(i=0; i<mNsamples; ++i)
        sum_dev += (mGld[i] - gld_avg) * (mGld[i] - gld_avg);
    gld_sd = sqrt(sum_dev/mNsamples);

    mWstats.gld_avg = gld_avg;
    mWstats.gld_sd = gld_sd;
    mWstats.iafc_sum = iafc_sum;
    mWstats.tch_sum = tch_sum;

    Print();

    return ret;
}

void Stats::Store(int gload, int iafc, int tcnt) {
    if (!mGld || !mTchcnt || !mIafc) {
        return;
    }

    mGld[mIdx] = gload;
    mTchcnt[mIdx] = tcnt;
    mIafc[mIdx] = iafc;

    ++mIdx;
    if(mIdx >= mNsamples) {
        mIdx = 0;
        ++mWin_cnt;
    }

    ++mNcumsamples;
    mTch_cum_sum += tcnt;
    mIafc_cum_sum += iafc;
    return;
}

void Stats::Clear() {
    if (!mGld || !mTchcnt || !mIafc) {
        return;
    }

    memset(mGld, 0x00, mNsamples);
    memset(mIafc, 0x00, mNsamples);
    memset(mTchcnt, 0x00, mNsamples);

    mNcumsamples = 0;
    mWin_cnt = 0;
    mIdx = 0;

    mTch_cum_sum = 0;
    mIafc_cum_sum = 0;

    mAppName[0] = '\0';

    memset(&mWstats, 0x00, sizeof(mWstats));
    mResult = GAMEDET_IS_UNKNOWN;
    return;
}
