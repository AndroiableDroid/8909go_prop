/******************************************************************************
  @file  ConfidenceValues.cpp
  @brief  algorithm to build the confidence into type of app

  algorithm to build the confidence into type of app

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#include <cstring>
#include "Config.h"
#include "ConfidenceValues.h"

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "ANDR-PERF-GAMEDET"
#include <cutils/log.h>

/* Bonus value to be added if consecutive window
  * periods have high or medium confidence  */
#define LOW_BONUS 5
#define MED_BONUS 10
#define HIGH_BONUS 15

using namespace GamingSustenance;

ConfidenceValues::ConfidenceValues() {
    memset(&mCurr, 0x00, sizeof(mCurr));
    memset(&mPrev, 0x00, sizeof(mPrev));
}

void ConfidenceValues::Update() {
    mPrev.gm_base_conf = mCurr.gm_base_conf;
    mPrev.gm_bonus = mCurr.gm_bonus;
    mPrev.gm_conf = mCurr.gm_conf;

    mPrev.bm_base_conf = mCurr.bm_base_conf;
    mPrev.bm_bonus = mCurr.bm_bonus;
    mPrev.bm_conf = mCurr.bm_conf;

    mPrev.app_base_conf = mCurr.app_base_conf;
    mPrev.app_bonus = mCurr.app_bonus;
    mPrev.app_conf = mCurr.app_conf;

    return;
}

int ConfidenceValues::UpdateBaseConf(int flag, int conf_value) {
    switch(flag) {
        case GAMEDET_IS_GAME:
            mCurr.gm_base_conf = conf_value;
            break;
        case GAMEDET_IS_BM:
            mCurr.bm_base_conf = conf_value;
            break;
        case GAMEDET_IS_APP:
            mCurr.app_base_conf = conf_value;
            break;
    }
    return flag;
}

void ConfidenceValues::CalculateGameBonus() {
    //consistent medium conf values - give low bonus
    if((mCurr.gm_base_conf >= MED_CONF) &&
       (mCurr.gm_base_conf < HIGH_CONF) &&
       (mPrev.gm_base_conf >= MED_CONF) &&
       (mPrev.gm_base_conf < MED_CONF)) {
            mCurr.gm_bonus = LOW_BONUS;
    }

    //transition from medium to high conf - give medium bonus
    if((mCurr.gm_base_conf >= HIGH_CONF) &&
       (mPrev.gm_base_conf >= MED_CONF)&&
       (mPrev.gm_base_conf < HIGH_CONF)) {
            mCurr.gm_bonus = MED_BONUS;
    }

    //consistent high conf values - give high bonus
    if((mCurr.gm_base_conf >= HIGH_CONF) &&
        (mPrev.gm_base_conf >= HIGH_CONF)) {
            mCurr.gm_bonus = HIGH_BONUS;
    }
}

void ConfidenceValues::CalculateBmBonus() {
    //don't accelerate to detect non game cases - give low bonus values
    //increase only if confidence values are consistently high
    if((mCurr.bm_base_conf >= HIGH_CONF) &&
       (mPrev.bm_base_conf >= HIGH_CONF)) {
         mCurr.bm_bonus = MED_BONUS;
    }
}

void ConfidenceValues::CalculateAppBonus() {
    //don't accelerate to detect non game cases - give low bonus values
    //increase only if confidence values are consistently high
    if((mCurr.app_base_conf >= HIGH_CONF) &&
       (mPrev.app_base_conf >= HIGH_CONF))
         mCurr.app_bonus = MED_BONUS;
}

int ConfidenceValues::Calculate(int winresult) {
    switch (winresult) {
        case GAMEDET_IS_GAME:
            CalculateGameBonus();
            break;
        case GAMEDET_IS_BM:
            CalculateBmBonus();
            break;
        case GAMEDET_IS_APP:
            CalculateAppBonus();
            break;
        case GAMEDET_IS_UNKNOWN:
            QLOGE("Error in calculating bonus values - unknown activity type");
            break;
    }
    return winresult;
}

int ConfidenceValues::Consolidate(int winresult) {
    int res = GAMEDET_IS_UNKNOWN;

    //consolidate confidence values
    switch (winresult) {
        case GAMEDET_IS_GAME:
            mCurr.gm_conf = mPrev.gm_conf + mCurr.gm_base_conf + mCurr.gm_bonus;
            if(mCurr.gm_conf >= 100) {
                res = GAMEDET_IS_GAME;
                mCurr.gm_conf = 100;
            }
            mCurr.bm_conf = mPrev.bm_conf - LOW_BONUS;
            if(mCurr.bm_conf < 0) mCurr.bm_conf = 0;
            mCurr.app_conf = mPrev.app_conf - LOW_BONUS;
            if(mCurr.app_conf < 0) mCurr.app_conf = 0;
            break;

        case GAMEDET_IS_BM:
            mCurr.bm_conf = mPrev.bm_conf + mCurr.bm_base_conf + mCurr.bm_bonus;
            if(mCurr.bm_conf >= 100) {
                res = GAMEDET_IS_BM;
                mCurr.bm_conf = 100;
            }
            mCurr.gm_conf = mPrev.gm_conf - LOW_BONUS;
            if(mCurr.gm_conf < 0) mCurr.gm_conf = 0;
            mCurr.app_conf = mPrev.app_conf - LOW_BONUS;
            if(mCurr.app_conf < 0) mCurr.app_conf = 0;
            break;

        case GAMEDET_IS_APP:
            mCurr.app_conf = mPrev.app_conf + mCurr.app_base_conf + mCurr.app_bonus;
            if(mCurr.app_conf >= 100) {
                res = GAMEDET_IS_APP;
                mCurr.app_conf = 100;
            }
            mCurr.gm_conf = mPrev.gm_conf - LOW_BONUS;
            if(mCurr.gm_conf < 0) mCurr.gm_conf = 0;
            mCurr.bm_conf = mPrev.bm_conf - LOW_BONUS;
            if(mCurr.bm_conf < 0) mCurr.bm_conf = 0;
            break;
    }
    return res;
}

void ConfidenceValues::Clear(int mask) {
    switch (mask) {
    case CLEAR_ALL:
    case CLEAR_PREV:
        mPrev.gm_base_conf = 0;
        mPrev.bm_base_conf = 0;
        mPrev.app_base_conf = 0;
        mPrev.gm_bonus = 0;
        mPrev.bm_bonus = 0;
        mPrev.app_bonus = 0;
        mPrev.gm_conf = 0;
        mPrev.bm_conf = 0;
        mPrev.app_conf = 0;

    case CLEAR_CURR:
        mCurr.gm_conf = 0;
        mCurr.bm_conf = 0;
        mCurr.app_conf = 0;

    case CLEAR_CURR_BASE_CONF_BONUS:
        mCurr.gm_base_conf = 0;
        mCurr.bm_base_conf = 0;
        mCurr.app_base_conf = 0;
        mCurr.gm_bonus = 0;
        mCurr.bm_bonus = 0;
        mCurr.app_bonus = 0;
        break;
    }
}

void ConfidenceValues::Print( ) {
    QLOGI("Confidence Values = %3d %3d %3d\n", mCurr.gm_conf, mCurr.bm_conf, mCurr.app_conf);
    return;
}
