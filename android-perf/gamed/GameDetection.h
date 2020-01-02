/******************************************************************************
  @file  GameDetection.h
  @brief   game detection logic header

  Game detection logic header class

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#ifndef __GM_DET_H__
#define __GM_DET_H__

#include <cstring>
#include <pthread.h>
#include "Config.h"
#include "Stats.h"
#include "ConfidenceValues.h"
#include "Input.h"
#include "WhiteLists.h"
#include "mp-ctl.h"

namespace GamingSustenance {

#define GAMED_VERSION             1
#define GAMED_SHIFT_BIT_VERSION   4

#define GAMEDET_EVENT_FGAPPCHANGE 1
#define GAMEDET_EVENT_EXIT 2

typedef struct gamedet_msg {
    int opcode;
    char name[MAX_MSG_APP_NAME_LEN];
}gamedet_msg;

class GameDetection {
    friend class GameServer;
    private:
        static GameDetection *mGameDetection;

    private:
        //config params
        Config mConfig;

        //calculates & holds stats
        Stats mStats;

        //builds confidence values
        ConfidenceValues mCv;

        //feeds input values
        Input mInput;

        //thread id
        pthread_t mThrdId;

        bool mIsGame_poll_Thr_Running;

        bool mIsProfileApplied;

        XmlData *mXmlLists;
    private:
        GameDetection();
        GameDetection(GameDetection const& rh);
        GameDetection& operator=(GameDetection const& rh);

    private:
        //helper functions
        void ApplyGameProfile(int enable);
        int ProcessFgAppchange(gamedet_msg &msg);
        void RunCoreAlgorithm();
        void ClearStats();

     public:
        bool CheckInLists(char *name, int &found, int &type);
        int ProcessCommands(struct gamedet_msg &msg, struct timeval *timeout, int &exit);
        void ProcessData(struct timeval *timeout, int &exit);
        pthread_t get_gamedetection_thr_id();
        //pthread_mutex_t lock;

    public:
        ~GameDetection();
        bool Init();
        static GameDetection *getInstance() {
            if (NULL == mGameDetection) {
                mGameDetection = new GameDetection();
            }
            return mGameDetection;
        }
};

} //namespace

#endif
