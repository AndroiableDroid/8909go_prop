/******************************************************************************
  @file  GameDaemon.cpp
  @brief  gameserver which is responsible to talking to clients

  gameserver which is responsible to talking to clients

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#include "Config.h"
#include "GameServer.h"

#define LOG_TAG "ANDR-PERF-GAME-D"
#include <cutils/log.h>
#if defined(ANDROID_JELLYBEAN)
#include "common_log.h"
#endif

using namespace GamingSustenance;
/* Main entry to game-daemon
   * argc - number of command-line arguments
   * argv - command-line argument array
   Return value - 0 if successful, negative otherwise */

int main(int argc, char *argv[])
{
    GamingSustenance::GameServer *gdObj = GamingSustenance::GameServer::getInstance();
    if (gdObj) {
        gdObj->game_server_init();
        gdObj->game_server_exit();
        delete gdObj;
        gdObj = NULL;
    } else {
        QLOGE("Could not find the object for Gamed-server");
        return -1;
    }
    /*suppress warning*/
    argc;
    argv;

    return 0;
}
