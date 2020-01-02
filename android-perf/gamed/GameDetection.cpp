/******************************************************************************
  @file   GameDetection.cpp
  @brief   Implementation of game detection logic

  DESCRIPTION
  - Collect and store samples every sample period.
  - Calculate statistics (Average, standard deviation of GPU load, input event count etc..)
     at the end of chunk.
  - Based on Algorithm, find out if the activity is of type Game/Benchmark/App/Unknown, then
    associate a confidence value for that type.
  - In addition to confidence value, give some bonus if consecutive chunks
    are same type of activity.
 - Calculate cumulative confidence till that chunk.
 - If the confidence is greater than 100, declare the result and stop the process.
   else Repeat the steps above.

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/

#include <errno.h>
#include "Config.h"
#include "GameServer.h"
#include "GameDetection.h"

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "ANDR-PERF-GAMEDET"
#include <cutils/log.h>
#include <cutils/properties.h>

#define TOUCH_DEV_PATH "/dev/input/event0"
#define OUTPUT_PATH "/storage/sdcard1/gamedet.txt"

#define CONVERT_TO_USEC 1000
#define DEFAULT_SLEEP_TIME_MSEC 500
#define FOUND_IN_BLACK_LIST 1
#define FOUND_IN_ROGAME_LIST 2
#define FOUND_IN_WHITE_LIST 3
#define NOT_FOUND_IN_LISTS -1
/* default thresholds/configuration params */


#define GAMDET_RESULT_STR(res) \
        ((res == GAMEDET_IS_GAME) ? "GAME" : \
        (res == GAMEDET_IS_BM) ? "Benchmark" : \
        (res == GAMEDET_IS_APP) ? "App" : "UNKNOWN")

using namespace GamingSustenance;

GameDetection *GameDetection::mGameDetection = NULL;

void *gamedet_poll(void * data);

GameDetection::GameDetection() {
    mIsProfileApplied = 0;
    Init();
}

GameDetection::~GameDetection() {
    if (mXmlLists) {
        delete mXmlLists;
        mXmlLists = NULL;
    }
}

static int sGameDetOn;

bool GameDetection::Init() {
    bool ret = true;
    int rc = 0;
    int nsamples = 0;
    char property[PROPERTY_VALUE_MAX] = {0};

    //read config params, we do not want to incur overhead, so keeping
    //it as a single time affair
    if (mConfig.Read() < 0) {
        QLOGE("Error while reading config paramters\n");
        return -1;
    }

    //init input
    mInput.Init(&mStats, mConfig.GetTouchInterruptLine());

    //allocate memory for stats
    nsamples = (mConfig.GetWindowSize() * 1000) / mConfig.GetSamplingPeriod();
    ret = mStats.Init(nsamples);

    if (!ret) {
        return ret;
    }

    //read xml file, parse and store it
    mXmlLists =  GamingSustenance::XmlData::getInstance();
    if (NULL == mXmlLists) {
        QLOGW("Unable to parse Xml");
    }

    property_get("debug.vendor.qti.enable.gamed", property,"0");
    sGameDetOn = atoi(property);

    //create the gaming detection thread
    rc = pthread_create(&mThrdId, NULL, gamedet_poll, this);
    if (rc != 0) {
        QLOGE("ERR: Unable to create Game detection Thread\n");
        ret = false;
        return ret;
    }

    return ret;
}

void GameDetection::RunCoreAlgorithm()
{
    Stats::WinStats &wstats = mStats.GetWStats();
    float gld_avg = wstats.gld_avg;
    float gld_sd = wstats.gld_sd;
    int iafc_cnt = wstats.iafc_sum;
    int tch_cnt = wstats.tch_sum;
    int tch_win_thr = mConfig.GetTouchCountThreshold() * mConfig.GetWindowSize() / 60;
    int iafc_win_thr = mConfig.GetInactivityFrameCount() * mConfig.GetWindowSize() / 60;
    int res = 0;

    //QLOGE("perf:: run Core Alogarithm");
    mCv.Clear(ConfidenceValues::CLEAR_CURR_BASE_CONF_BONUS);

    do {

        /* process high likely game or bm case . not considering standard deviation */
        if( (gld_avg > mConfig.GetGpuLoadHighThreshold()) && (iafc_cnt <  (2 *iafc_win_thr)) ) {
            if(tch_cnt > tch_win_thr)
                /* it is a game with high confidence */
                res = mCv.UpdateBaseConf(GAMEDET_IS_GAME, HIGH_CONF);
            else
               /* it is a bench mark with high confidence */
               res = mCv.UpdateBaseConf(GAMEDET_IS_BM, HIGH_CONF);
            break;
        }

        if( (gld_avg > mConfig.GetGpuLoadHighThreshold()) && (iafc_cnt >  (2 *iafc_win_thr)) ) {
           res = mCv.UpdateBaseConf(GAMEDET_IS_APP, LOW_CONF); /* low confidence app*/
           break;
        }


        //process medium sustained gpu load with low standard deviation
        if( (gld_avg < mConfig.GetGpuLoadHighThreshold()) &&
            (gld_avg > mConfig.GetGpuLoadLOwThreshold()) && (gld_sd  < 10 ) ) {
               if(iafc_cnt < (2 * iafc_win_thr)) {
                   if(tch_cnt > tch_win_thr)
                        //it is a game with medium confidence
                        res = mCv.UpdateBaseConf(GAMEDET_IS_GAME, MED_CONF);
                   else
                        //it is a bench mark with medium confidence
                        res = mCv.UpdateBaseConf(GAMEDET_IS_BM, MED_CONF);
              } else
                   res = mCv.UpdateBaseConf(GAMEDET_IS_APP, LOW_CONF);
              break;
        }


        //process medium sustained gpu load with high sd
        if((gld_avg < mConfig.GetGpuLoadHighThreshold()) &&
           (gld_avg > mConfig.GetGpuLoadLOwThreshold()) && (gld_sd  > 10 )) {
            if(iafc_cnt < (2 * iafc_win_thr)) {
                if(tch_cnt > tch_win_thr)
                    //it is a game with low confidence
                    res = mCv.UpdateBaseConf(GAMEDET_IS_GAME, LOW_CONF);
                else
                    //it is a bench mark with low confidence
                    res = mCv.UpdateBaseConf(GAMEDET_IS_BM, LOW_CONF);
            } else
                //it is high confidence app
                res = mCv.UpdateBaseConf(GAMEDET_IS_APP, LOW_CONF);
            break;
        }

        res = mCv.UpdateBaseConf(GAMEDET_IS_APP, LOW_CONF);

    } while(0);


    res = mCv.Calculate(res);
    res = mCv.Consolidate(res);

    mStats.SetResult(res);

    mCv.Print();
    mCv.Update();

    return;
}

void GameDetection::ClearStats()
{
    mStats.Clear();
    mCv.Clear();
}

void GameDetection::ApplyGameProfile(int enable) {
    GamingSustenance::GameServer *gsObj = GamingSustenance::GameServer::getInstance();
    if(enable) {
        if(mIsProfileApplied) {
            QLOGI("perf:: req for set game profile, system already in game profile, just ignore");
            return;
        } else {
            if(mConfig.GetGameProfile() == -1) {
                QLOGE("perf:: game profile number not set by system property");
                return;
            } else {
                QLOGI("perf:: req for set game profile, system in normal profile, Applying game profile");
                gsObj->apply_game_profile(mConfig.GetGameProfile());
                mIsProfileApplied = true;
            }
        }
    } else {
        if(!mIsProfileApplied) {
           QLOGI("perf:: req for set normal profile, system already in normal profile, just ignore");
           return;
        } else {
            QLOGI("perf:: req for set Normal profile, system in game profile, Applying Normal profile");
            gsObj->apply_game_profile(REMOVE_GAME_PROFILE);
            mIsProfileApplied = false;
        }
    }
}

int GameDetection::ProcessFgAppchange(gamedet_msg &msg) {
    /*if ((mStats.GetResult() != GAMEDET_IS_GAME) &&
         strcmp(mStats.GetAppName(), "")) {
        double etime = mStats.GetDetectionTime();
        QLOGE("Time taken (%.2lf) - %s Detected as %s",
              etime, mStats.GetAppName(), GAMDET_RESULT_STR(mStats.GetResult()));
    }*/

    /* Disable game profile */
    QLOGI("Disable game profile");
    ApplyGameProfile(DISABLE_GAME_PROFILE);

    QLOGI("App %s started", msg.name);

    ClearStats();

    mStats.SetAppName(msg.name);
    mStats.StartDetectionTime();
    mStats.UpdateXmlChecked(false);

    return 1;
}

pthread_t GameDetection::get_gamedetection_thr_id() {
    return mThrdId;
}

/* main loop function */
void *gamedet_poll(void * data) {
    int ret=0;
    int  exit = 0, nbytes =-1;
    int gamesoc = -1, max_fd = -1, conn_socket = -1;
    fd_set master_set;
    struct timeval timeoutval;
    struct timeval *timeout = NULL; /*initial poll on select with infinite timeout*/
    struct gamedet_msg msg;
    struct sockaddr_un addr;
    socklen_t len = 0;

    GameDetection *gdObj = NULL;
    gdObj = (GameDetection *) data;

    if (NULL == gdObj) {
        QLOGE("Gamedetection class pointer is NULL");
        return NULL;
    }

    QLOGI("Spawning thread to run game detection task");
    GamingSustenance::GameServer *gsObj = GamingSustenance::GameServer::getInstance();
    if (NULL == gsObj) {
        QLOGE("Gameserver class instance not found Cannot access socket");
        return NULL;
    }

    gamesoc = gsObj->get_server_socket_id();
    if(gamesoc < 0) {
        QLOGE("Error gamesrvsoc_id < 0");
        return NULL;
    }

    //Initialize for select call
    FD_ZERO(&master_set);
    max_fd = gamesoc;

    timeoutval.tv_sec = 0;
    timeoutval.tv_usec = 0;


    while(1) {
        //select may modify master_set
        FD_SET(gamesoc, &master_set);
        ret = select(max_fd + 1, &master_set, NULL, NULL, timeout);

        //timeout expired
        if(ret == 0) {
            timeout = &timeoutval;
            gdObj->ProcessData(timeout, exit);
            if (exit == 1) {
                if (timeout) {
                    timeout->tv_sec = 0;
                    timeout->tv_usec = 0;
                }
                timeout = NULL;
            }
        } else if (ret < 0) {
            QLOGE("Error in select() system call. Sleep.");
            //Sleep here for timeout period to check if the select
            //error is recoverable
            usleep(DEFAULT_SLEEP_TIME_MSEC * CONVERT_TO_USEC);
        } else { // ret is because of cnnection
            len = sizeof(struct sockaddr_un);
            conn_socket = accept(gamesoc, (struct sockaddr *) &addr, &len);
            if (conn_socket == -1) {
                QLOGI("GAME server %s: accept failed, errno=%d (%s)",
                        __func__, errno, strerror(errno));
                close(conn_socket);
                return 0;
            }
            // handle data from a client
            nbytes = recv(conn_socket, &msg, sizeof(gamedet_msg), 0);
            if (nbytes < 0) {
                // got error or connection closed by client
                QLOGE("Error in recieve");
                close(conn_socket); // bye!
            } else {
                QLOGI("recvied message %d nbytes, msg.opcode = %d, msg.name =%s", nbytes, msg.opcode, msg.name);
                // we got some data from a client
                /* Process commands */
                timeout = &timeoutval;
                gdObj->ProcessCommands(msg, timeout, exit);
                gdObj->ProcessData(timeout, exit);
                if (exit == 1) {
                    //clean up
                    if (timeout) {
                        timeout->tv_sec = 0;
                        timeout->tv_usec = 0;
                    }
                    timeout = NULL; // wait indefinetely for the APP to change
                }
            }//else
        } // END handle connection
    } //end of while loop

    return NULL;
}

bool GameDetection::CheckInLists(char *name, int &found, int &type) {

    found = NOT_FOUND_IN_LISTS;
    type = GAMEDET_IS_UNKNOWN;

    if(mXmlLists->ExistsInList(name, mXmlLists->GetBlackList())) {
        //Exists in black list. don't apply game profile
        QLOGI("Exists in black list return from the algo");
        found = FOUND_IN_BLACK_LIST;
        type = GAMEDET_IS_APP;
        return true;
    }
    if (mXmlLists->ExistsInList(name, mXmlLists->GetROGameList())) {
        //Exists in black list. don't apply game profile
        QLOGI("Exists in read-only game list return from the algo");
        found = FOUND_IN_ROGAME_LIST;
        type = GAMEDET_IS_GAME;
        return true;
    }
    type = mXmlLists->CheckInListAndGetType(name, mXmlLists->GetWhiteList());
    if (type != GAMEDET_IS_UNKNOWN) {
        QLOGI("Exists in white list and type is %s", GAMDET_RESULT_STR(type));
        found = FOUND_IN_WHITE_LIST;
        return true;
    } else {
        QLOGI("NOT found in any list");
        return false;
    }
    return false;
}

void GameDetection::ProcessData(struct timeval *timeout, int &exit) {
    mInput.Read();

    mStats.Store(mInput.GetLoad(),
                 mInput.GetInactivityFrameCount(),
                 mInput.GetTouchCount());

    /* wasXmlChecked is set to true if the app is not found in any of
     * the lists. This is to avoid repeated list checking that
     * may happen because of sampling period at every window of
     * the algorithm.
     * */
    if((mXmlLists) && !(mStats.wasXmlChecked())) {
        int actType = GAMEDET_IS_UNKNOWN;
        int found = NOT_FOUND_IN_LISTS;
        /* Steps for the list checking.
         * 1. check in blacklist.
         * 2. check in ReadOnly list.
         * 3. check in whitelist
         *
         * Also set timeout and exit properly. Once a decision to wether to apply
         * profile or not is made. Set Exit = 1, which will ensure a infinite
         * timeout val, and will wait in select call accordingly.
         * If algorithm is still running then timeout should be set to sampling
         * period.
         */
        if (CheckInLists(mStats.GetAppName(),found,actType)) {
            switch(found) {
                case FOUND_IN_BLACK_LIST:
                    exit = 1;
                    return;
                    break;
                case FOUND_IN_ROGAME_LIST:
                    ApplyGameProfile(APPLY_GAME_PROFILE);
                    exit  =1;
                    return;
                    break;
                case FOUND_IN_WHITE_LIST:
                    if(actType == GAMEDET_IS_GAME) {
                        ApplyGameProfile(APPLY_GAME_PROFILE);
                        exit = 1;
                        return;
                    } else if (actType == GAMEDET_IS_BM || actType == GAMEDET_IS_APP) {
                        exit = 1;
                        return;
                    }
                    break;
                default:
                    //not found continue with the algorithm
                    break;
            }
        }
        mStats.UpdateXmlChecked(true);
    }

    //calculate stats for every window period
    if(mStats.IsItNewWindowStart() && sGameDetOn) {
        mStats.Calculate();
        RunCoreAlgorithm();
        if((mStats.GetResult() == GAMEDET_IS_GAME) ||
                (mStats.GetResult() == GAMEDET_IS_BM) ||
                ( mStats.GetResult()== GAMEDET_IS_APP)) {

            double etime = 0.0;
            etime = mStats.GetDetectionTime();
            QLOGI("Time taken (%.2lf) - %s Detected as %s",
              etime, mStats.GetAppName(), GAMDET_RESULT_STR(mStats.GetResult()));
            //write in our local xml structure
            if (!(mXmlLists->AddElementInList(mStats.GetAppName(),
                            mStats.GetResult(), mXmlLists->GetWhiteList()))) {
                QLOGE("Could not update internal structure with app info");
            }
            /*clean up timeout and set it to NULL for inifinite polling */
            exit = 1;
        } else {
            //set the next time out period
           if (timeout) {
               timeout->tv_sec = 0;
               timeout->tv_usec = mConfig.GetSamplingPeriod() * CONVERT_TO_USEC;
               exit = 0;
           }
        }

        if (mStats.GetResult() == GAMEDET_IS_GAME) {
            //we have already set time-period to NULL in previous loop
            //by setting exit as 1
            ApplyGameProfile(APPLY_GAME_PROFILE);
        }
    } else {
        //set the next time out period
        if (timeout) {
            timeout->tv_sec = 0;
            timeout->tv_usec = mConfig.GetSamplingPeriod() * CONVERT_TO_USEC;
            exit = 0;
        }
    }
}

int GameDetection::ProcessCommands(struct gamedet_msg &msg, struct timeval *timeout, int &exit) {
    int version = 0;
    int app_state = 0;

    if (timeout == NULL) {
        QLOGE("Error: timeout structure cannot be null");
        exit = 1;
        return 0;
    }
    version = (msg.opcode & 0xF0) >> GAMED_SHIFT_BIT_VERSION;
    if (version == GAMED_VERSION)
    {
        app_state = msg.opcode & 0x0F;
        switch (app_state) {
            case VENDOR_HINT_ACTIVITY_START:
            case VENDOR_HINT_ACTIVITY_RESUME:
                if(ProcessFgAppchange(msg) < 0 ) {
                    exit = 1;
                } else {
                    //update timeout value based on sample
                    timeout->tv_sec = 0;
                    timeout->tv_usec = mConfig.GetSamplingPeriod() * CONVERT_TO_USEC;
                    exit = 0;
                }
                break;
            case VENDOR_HINT_ACTIVITY_PAUSE:
            case VENDOR_HINT_ACTIVITY_STOP:
                ProcessFgAppchange(msg);
                ClearStats();
                exit = 1;
                break;
        }
    } else {
        QLOGE("Gamed Version not supported");
        exit = 1;
    } /* Version mismatch*/
    /* As of now we are not handling return value,in future we may handle
     Then we will treat this as success case */
    return exit;
}
