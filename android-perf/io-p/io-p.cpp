/******************************************************************************
  @file    io-p.c
  @brief   Implementation of performance server module

  DESCRIPTION

  ---------------------------------------------------------------------------
  Copyright (c) 2011-2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/

#define ATRACE_TAG ATRACE_TAG_ALWAYS

#include "io-p.h"

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <signal.h>
#include <private/android_filesystem_config.h>
#include <cutils/properties.h>
#include <cutils/trace.h>
#include <io-prefetch/list_capture.h>
#include <cutils/sockets.h>
#include "EventQueue.h"

#include <dlfcn.h>

#define LOG_TAG           "ANDR-IOP"
#include <cutils/log.h>

static pthread_mutex_t perf_veri_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t subm_req_mutex = PTHREAD_MUTEX_INITIALIZER;
static EventQueue IOPevqueue;

#define BILLION             1000000000L

#define SOCID_8939        239
#define SOCID_8994        207
#define SOCID_8992        251
#define SOCID_8092        252
#define SOCID_8996        246
#define SOCID_8996PRO     305
#define SOCID_8096PRO     312
#define SOCID_8096        291
#define SOCID_8998        292
#define SOCID_SDM845      321

#define MIN_FREQ_REQ      0
#define MAX_FREQ_REQ      1
#define PKG_LEN           1024

#ifdef SERVER

#define IOP_NO_RECENT_APP 7
char recent_list[IOP_NO_RECENT_APP][PKG_LEN];
int recent_list_cnt = 0;

static pthread_t iop_server_thread;
static iop_msg_t msg;

extern int create_database();
extern void start_playback(char *pkg_name);
extern void stop_playback();

uint64_t time_delta;

static int get_soc_id()
{
  int fd;
  int soc = -1;
  if (!access("/sys/devices/soc0/soc_id", F_OK)) {
       fd = open("/sys/devices/soc0/soc_id", O_RDONLY);
  } else {
       fd = open("/sys/devices/system/soc/soc0/id", O_RDONLY);
  }
  if (fd != -1)
  {
      char raw_buf[5];
      read(fd, raw_buf,4);
      raw_buf[4] = 0;
      soc = atoi(raw_buf);
      close(fd);
  }
  else
      close(fd);
  return soc;
}

int is_boot_complete() {
    char boot_completed[PROPERTY_VALUE_MAX];
    char property[PROPERTY_VALUE_MAX];
    int value = 0;
    if (property_get("sys.boot_completed", boot_completed, "0")) {
        value = atoi(boot_completed);
    }

    if (value) {
        return 1;
    } else {
        return 0;
    }
}

static int soc_id;

/*=========================================================================================================================*/

static void *iop_server(void *data)
{
    int rc, cmd;
    iop_msg_t *msg = NULL;
    (void)data;
    bool is_db_init = false;

    /* Main loop */
    for (;;) {
       //wait for perflock commands
        EventData *evData = IOPevqueue.Wait();

        if (!evData || !evData->mEvData) {
            continue;
        }
        if(!is_boot_complete())
        {
            QLOGE("io prefetch is disabled waiting for boot_completed");
            continue;
        }
        if(is_db_init == false)
        {
            if(create_database() == 0)
            {
                //Success
                is_db_init = true;
            }
        }

        cmd = evData->mEvType;
        msg = (iop_msg_t *)evData->mEvData;

        switch (cmd) {
            case IOP_CMD_PERFLOCK_IOPREFETCH_START:
            {
                static bool is_in_recent_list = false;
                char property[PROPERTY_VALUE_MAX];
                int enable_prefetcher = 0;

                property_get("enable_prefetch", property, "1");
                enable_prefetcher = atoi(property);

                if(!enable_prefetcher)
                {
                    QLOGE("io prefetch is disabled");
                    break;
                }
                // if PID < 0 consider it as playback operation
                if(msg->pid < 0)
                {
                    int ittr = 0;
                    is_in_recent_list = false;
                    //Check app is in recent list
                    for(ittr = 0; ittr < IOP_NO_RECENT_APP; ittr++)
                    {
                        if(0 == strcmp(msg->pkg_name,recent_list[ittr]))
                        {
                            is_in_recent_list = true;
                            QLOGE("is_in_recent_list is TRUE");
                            break;
                        }
                    }
                    // IF Application is in recent list, return
                    if(true == is_in_recent_list)
                    {
                        QLOGE("io prefetch is deactivate");
                        break;
                    }

                    if(recent_list_cnt == IOP_NO_RECENT_APP)
                        recent_list_cnt = 0;

                    //Copy the package name to recent list
                    strlcpy(recent_list[recent_list_cnt],msg->pkg_name,PKG_LEN);
                    recent_list_cnt++;

                    stop_capture();
                    stop_playback();
                    start_playback(msg->pkg_name);
                }
                // if PID > 0 then consider as capture operation
                if(msg->pid > 0)
                {
                    if(true == is_in_recent_list)
                    {
                        QLOGE("io prefetch Capture is deactivated ");
                        break;
                    }
                    stop_capture();
                    start_capture(msg->pid,msg->pkg_name,msg->code_path);
                }

                break;
            }

            case IOP_CMD_PERFLOCK_IOPREFETCH_STOP:
            {
                stop_capture();
                break;
            }

            default:
                QLOGE("Unknown command %d", cmd);
        }
        IOPevqueue.GetDataPool().Return(evData);
    }

    QLOGI("IOP server thread exit due to rc=%d", rc);
    return NULL;
}

//callbacks for eventqueue
static void *Alloccb() {
    void *mem = (void *) new iop_msg_t;
    if (NULL ==  mem)
        QLOGE("memory not allocated");
    return mem;
}

static void Dealloccb(void *mem) {
    if (NULL != mem) {
        delete (iop_msg_t *)mem;
    }
}

//interface implementation
int iop_server_init() {
    int rc = 0, stage = 0;

    QLOGI("IOP server starting");

    soc_id = get_soc_id();
    switch(soc_id)
    {
         case SOCID_8994:
         case SOCID_8092:
         case SOCID_8992:
         case SOCID_8996:
         case SOCID_8996PRO:
         case SOCID_8096PRO:
         case SOCID_8096:
         case SOCID_8998:
         case SOCID_8939:
         case SOCID_SDM845:
             break;
         default:
             QLOGI("Fail to init IOP Server");
             return 0;
    }

    IOPevqueue.GetDataPool().SetCBs(Alloccb, Dealloccb);
    rc = pthread_create(&iop_server_thread, NULL, iop_server, NULL);
    if (rc != 0) {
        stage = 3;
        goto error;
    }
    return 1;

error:
    QLOGE("Unable to create control service (stage=%d, rc=%d)", stage, rc);
    return 0;
}

void iop_server_exit()
{
    pthread_join(iop_server_thread, NULL);
}

#endif /* SERVER */


int iop_server_submit_request(iop_msg_t *msg) {
    int size = 0;
    int handle = -1;
    EventData *evData;
    int *pl_args = NULL;
    int ret = SUCCESS, cmd = 0;
    bool bootComplete = false;

    //boot complete check
    if (NULL == msg) {
        return handle;
    }

    cmd = msg->cmd;

    QLOGE("IOP HAL: Received pkg_name = %s pid = %d", msg->pkg_name,msg->pid) ;

    pthread_mutex_lock(&subm_req_mutex);
    evData = IOPevqueue.GetDataPool().Get();
    if ((NULL == evData) || (NULL == evData->mEvData)) {
        QLOGE("event data pool ran empty");
        pthread_mutex_unlock(&subm_req_mutex);
        return handle;
    }
    iop_msg_t *pMsg = (iop_msg_t *)evData->mEvData;
    memset(pMsg, 0x00, sizeof(iop_msg_t));

    if(IOP_CMD_PERFLOCK_IOPREFETCH_START==cmd)
    {
        pMsg->pid = msg->pid;
        strlcpy(pMsg->pkg_name, msg->pkg_name, PKG_LEN);
        strlcpy(pMsg->code_path, msg->code_path, PKG_LEN);
    }

    if (ret == FAILED) {
        pthread_mutex_unlock(&subm_req_mutex);
        return FAILED;
    }
    if (NULL != evData) {
        evData->mEvType = cmd;
        IOPevqueue.Wakeup(evData);
    }

    pthread_mutex_unlock(&subm_req_mutex);
    return handle;
}
