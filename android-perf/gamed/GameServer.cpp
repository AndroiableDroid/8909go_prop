/******************************************************************************
  @file  GameServer.cpp
  @brief  gameserver which is responsible to talking to clients

  gameserver which is responsible to talking to clients

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#include <cutils/properties.h>
#include <dlfcn.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <private/android_filesystem_config.h>
#include "GameServer.h"
#include "GameDetection.h"
#include <cutils/sockets.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "ANDR-PERF-GAMEDET"
#include <cutils/log.h>

using namespace GamingSustenance;

struct perlockHandler {
    void *dlhandle;
    int (*useprofile)(int, int);
    int handle;
    int prof_in_use;
};
static struct perlockHandler perfhandler;

GameServer *GameServer::mGameServer = NULL;

GameServer::GameServer() {
    gamesrvsoc_id = -1;
}

GameServer::~GameServer() {
}

int GameServer::get_server_socket_id(){
    return gamesrvsoc_id;
}

int GameServer::game_server_init() {
    int rc = 0, stage = 0;
    int on = 1;
    GamingSustenance::GameDetection *gdObj = NULL;

    QLOGI("GAME server demon starting");
    /*Below function will open the socket and bind*/
    gamesrvsoc_id = android_get_control_socket("gamed");
    if (gamesrvsoc_id < 0) {
        stage = 1;
        QLOGE("Server socket creation failed");
        goto error;
    }
    QLOGI("Make the socket non-blocking");
    /* Make the socket non-blocking*/
    rc = ioctl(gamesrvsoc_id, FIONBIO, (char *)&on);
    if (rc < 0) {
        stage = 2;
        QLOGE("ioctl() for nonblocking socket failed");
        close(gamesrvsoc_id);
        goto error;
    }
    QLOGI("listen on socket \n");
    rc = listen(gamesrvsoc_id, SOMAXCONN);
    if (rc != 0) {
        stage = 3;
        QLOGE("server listen creation failed");
        goto error;
    }

    gdObj = GamingSustenance::GameDetection::getInstance();
    if(gdObj == NULL) {
        QLOGE("Could not initiate gamedetection ");
        goto error;
    }
    /*Load library for applying profile and disable it */
    if( NULL == perfhandler.useprofile || NULL == perfhandler.dlhandle)
    {
        open_perf_lock();
    }
    gdObj->ApplyGameProfile(DISABLE_GAME_PROFILE);

    QLOGI("Return from server_init");
    /* Seperate server thread to handle client requests */
    return 1;

error:
    QLOGE("Error while game server demon initialization : %d",stage);
    if (gamesrvsoc_id != -1) {
        close(gamesrvsoc_id);
        gamesrvsoc_id = -1;
        // Delete socket file
        unlink(addr.sun_path);
    }
    return 0;
}

int GameServer::game_server_exit() {
    pthread_t thrd_id;
    struct sockaddr_un addr;

    GameDetection *gdObj = GamingSustenance::GameDetection::getInstance();
    if (gdObj) {
        if((unsigned long)(thrd_id = gdObj->get_gamedetection_thr_id()) > 0UL) {
           QLOGI("waiting on pthread_join");
           pthread_join(thrd_id, NULL);
           gdObj->ApplyGameProfile(DISABLE_GAME_PROFILE);
        } else {
            QLOGE("Gamedetection thrd_id not found");
        }
        delete gdObj;
        gdObj = NULL;
    } else {
        QLOGE("Gamedetection object not found");
    }
    //close perf_lock library
    close_perf_lock();

    if (gamesrvsoc_id != -1) {
        close(gamesrvsoc_id);
        gamesrvsoc_id = -1;
        // Delete socket file
        unlink(addr.sun_path);
    }

    QLOGI("Exit from game_server");
    return 0;
}

void GameServer::apply_game_profile(int profile_num) {
    if (NULL == perfhandler.useprofile) {
        ALOGE("perfhandler.useprofile is NULL. No function to apply profile");
    }
    if (perfhandler.useprofile && perfhandler.prof_in_use && (profile_num == -1)) {
        perfhandler.handle = perfhandler.useprofile(perfhandler.handle, -1);
        perfhandler.handle = 0;
        perfhandler.prof_in_use = 0;
        //ALOGD_IF(sEnableGTLogs, "Profile Removed\n");
    } else if (perfhandler.useprofile && !perfhandler.prof_in_use && (profile_num != -1)) {
        perfhandler.handle = perfhandler.useprofile(perfhandler.handle, profile_num);
        perfhandler.prof_in_use = 1;
    }
}

void GameServer::open_perf_lock(void)
{
    const char *rc = NULL;
    static int opened = 0;
    char buf[PROPERTY_VALUE_MAX];

    if (!opened) {
         /* Retrieve name of vendor extension library */
         if (property_get("ro.vendor.extension_library", buf, NULL) <= 0) {
             ALOGE("%sperflock path not found\n", __func__);
             return;
         }

         /* Sanity check - ensure */
         buf[PROPERTY_VALUE_MAX-1] = '\0';
         if (strstr(buf, "/") != NULL) {
              ALOGE("%sInvalid perf lock extn lib\n", __func__);
              return;
         }

         /*
          * Clear error and load lib.
          */
         dlerror();
         perfhandler.dlhandle = dlopen(buf, RTLD_NOW | RTLD_LOCAL);
          if (perfhandler.dlhandle == NULL) {
              ALOGE("%s Failed to (dl)open perf lock\n", __func__);
              return;
          }

          *(void **) (&perfhandler.useprofile) = dlsym(perfhandler.dlhandle, "perf_lock_use_profile");
          if ((rc = dlerror()) != NULL) {
              ALOGE("%s Failed to get user_profile perf lock\n", __func__);
              dlclose(perfhandler.dlhandle);
              return;
          }
          perfhandler.handle = 0;
          opened = 1;
  }
}

void GameServer::close_perf_lock(void) {
    if(perfhandler.dlhandle) {
        if(perfhandler.useprofile) {
            perfhandler.useprofile = NULL;
        }
        dlclose(perfhandler.dlhandle);
        perfhandler.dlhandle = NULL;
    }
}
