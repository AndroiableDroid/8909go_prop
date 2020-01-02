/******************************************************************************
  @file  GameServer.h
  @brief header for gameserver which is responsible to talking to clients

  header for gameserver which is responsible to talking to clients

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#ifndef __GM_GAMEDSERVER_H__
#define __GM_GAMEDSERVER_H__

#include <pthread.h>
#include <sys/socket.h>
#include <sys/un.h>

namespace GamingSustenance {

class GameServer {
    private:
        static GameServer *mGameServer;
        pthread_t game_server_thread_id;
        int gamesrvsoc_id;
        struct sockaddr_un addr;
        GameServer();
        GameServer(GameServer const& rh);
        GameServer& operator=(GameServer const& rh);

    public:
        ~GameServer();
        static GameServer *getInstance() {
            if (NULL == mGameServer) {
                mGameServer = new GameServer();
            }
            return mGameServer;
        }
    public:
        int game_server_init();
        int game_server_exit();
        int get_server_socket_id();
        void apply_game_profile(int profile_num);
        void open_perf_lock(void);
        void close_perf_lock(void);
};

} //namespace

#endif
