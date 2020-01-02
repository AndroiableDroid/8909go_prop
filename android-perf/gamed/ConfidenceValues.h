/******************************************************************************
  @file  ConfidenceValues.h
  @brief  header for algorithm to build the confidence into type of app

  header for algorithm to build the confidence into type of app

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#ifndef __GM_CONFIDENCEVALUES_H__
#define __GM_CONFIDENCEVALUES_H__

namespace GamingSustenance {

/* base confidence values */
#define LOW_CONF 5
#define MED_CONF 10
#define HIGH_CONF 15

// confidence values
class ConfidenceValues {
    friend class GameDetection;
    private:
        enum {
            CLEAR_ALL,
            CLEAR_PREV,
            CLEAR_CURR,
            CLEAR_CURR_BASE_CONF_BONUS
        };

        struct ConfidenceValuesPOD {
            // base confidence values
            int gm_base_conf;
            int bm_base_conf;
            int app_base_conf;

            // bonus for time
            int gm_bonus;
            int bm_bonus;
            int app_bonus;

            // consolidated confidence values
            int gm_conf;
            int bm_conf;
            int app_conf;
        };

        ConfidenceValuesPOD mPrev;
        ConfidenceValuesPOD mCurr;

    private:
        ConfidenceValues();
        ConfidenceValues(ConfidenceValues const& rh);
        ConfidenceValues& operator=(ConfidenceValues const& rh);

        void CalculateGameBonus();
        void CalculateBmBonus();
        void CalculateAppBonus();

    private:
        int UpdateBaseConf(int flag, int conf_value);
        void Update();
        int Calculate(int winresult);
        int Consolidate(int winresult);
        void Clear(int mask = 0);
        void Print();
};

} //namespace

#endif
