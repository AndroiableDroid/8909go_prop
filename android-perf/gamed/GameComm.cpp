/******************************************************************************
  @file  GamedComm.cpp
  @brief Socket communication with gamed

  ---------------------------------------------------------------------------
  Copyright (c) 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
 ******************************************************************************/

#include <sys/socket.h>
#include <sys/un.h>
#include <cutils/properties.h>

#include "GameDetection.h"
#include "MpctlUtils.h"
#include "EventQueue.h"
#include "PerfGlueLayer.h"

#define LOG_TAG "ANDR-PERF-GAMECOMM"
#include <cutils/log.h>

#define GAME_SOCKET "/dev/socket/gamed"
#define MAX_MSG_APP_NAME_LEN 128
#define LOAD_LIB "libqti-gt-prop.so"

static pthread_t gamed_comm_thread;
static int sGameDetOn;
typedef struct gamedet_msg {
    int opcode;
    char name[MAX_MSG_APP_NAME_LEN];
}gamedet_msg;

char mPrevApp[MAX_MSG_APP_NAME_LEN];
char mCurrentApp[MAX_MSG_APP_NAME_LEN];

static void *Alloccb();
static void Dealloccb(void *mem);
static void *gamed_comm_loop(void *data);

//////////////////////////////////////////////////////////////////////////
///interface for perfmodule
//////////////////////////////////////////////////////////////////////////
static EventQueue gamedEvQ;
static int gamedEvents[] = {
   VENDOR_ACT_TRIGGER_HINT_BEGIN,
   VENDOR_ACT_TRIGGER_HINT_END,
};

static PerfGlueLayer gamedglue = {
   LOAD_LIB,
   gamedEvents,
   sizeof(gamedEvents)/sizeof(gamedEvents[0])
};

//interface implementation
int perfmodule_init() {
    int rc = 0, ret = SUCCESS;
    char property[PROPERTY_VALUE_MAX] = {0};

    property_get("debug.vendor.qti.enable.gamed", property,"0");
    sGameDetOn = atoi(property);
    gamedEvQ.GetDataPool().SetCBs(Alloccb, Dealloccb);

    rc = pthread_create(&gamed_comm_thread, NULL, gamed_comm_loop, NULL);
    if (rc != 0) {
        ret = FAILED;
    }

    return ret;
}

void perfmodule_exit() {
    pthread_join(gamed_comm_thread, NULL);
}

int perfmodule_submit_request(mpctl_msg_t *msg) {
    EventData *evData;
    int ret = FAILED;

    if (NULL == msg) {
        return ret;
    }

    evData = gamedEvQ.GetDataPool().Get();
    if (NULL == evData) {
        QLOGE("event data pool ran empty");
        return ret;
    }

    QLOGI("Received data=%d, hint_id=0x%x, hint_type=%d, package:%s",
          msg->data, msg->hint_id, msg->hint_type, msg->usrdata_str) ;

    mpctl_msg_t *pMsg = (mpctl_msg_t *)evData->mEvData;
    if (pMsg) {
        pMsg->client_pid = msg->client_pid;
        pMsg->client_tid = msg->client_tid;
        pMsg->data = msg->data;
        pMsg->pl_handle = msg->pl_handle;
        pMsg->pl_time = msg->pl_time;
        pMsg->profile = msg->profile;
        pMsg->hint_id = msg->hint_id;
        pMsg->hint_type = msg->hint_type;
        strlcpy(pMsg->usrdata_str, msg->usrdata_str, MAX_MSG_APP_NAME_LEN);
    }
    evData->mEvData = (void *) pMsg;

    //here hint_type var holds return value fro game trigger
    //if the event is not processed by game trigger then hand it over to gamed
    //this is to avoid concurrency in profilemgr
    if (pMsg && (pMsg->hint_type < 0)) {
        gamedEvQ.Wakeup(evData);
        ret = SUCCESS;
    } else{
        gamedEvQ.GetDataPool().Return(evData);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////
///support functions
/////////////////////////////////////////////////////////////////////////
int game_client_send_cmd(struct gamedet_msg msg);

int notify_fg_app_change(unsigned int state, const char *name) {
    const char *ptr = NULL;
    struct gamedet_msg msg = {0, "\0"};
    unsigned int strSize = 0;

    ptr = strchr(name, '/');
    if(NULL == ptr) {
        QLOGE("didn't find '/' in the app name");
        return -1;
    }

    strSize = (ptr - name)+1;
    if (strSize > MAX_MSG_APP_NAME_LEN) {
        QLOGE("App name too big truncating it");
        strSize = MAX_MSG_APP_NAME_LEN;
    }
    /* store the current notified app */
    strlcpy(mCurrentApp, name, strSize);
    QLOGI("perf: Notif-FG-App-Change previous:%s and current:%s and state:%d",mPrevApp,mCurrentApp,state);
    /* Prepare message for sending */
    switch (state) {
        case VENDOR_HINT_ACTIVITY_START:
        case VENDOR_HINT_ACTIVITY_RESUME:
            break;
        case VENDOR_HINT_ACTIVITY_PAUSE:
        case VENDOR_HINT_ACTIVITY_STOP:
            if((strncmp(mPrevApp, mCurrentApp, strSize))) {
                QLOGI("PAUSE or STOP received for the previous app : %s , just return",mCurrentApp);
                return -1;
            } else {
                QLOGI("PAUSE or STOP received for the previous app : %s ,which is already started",mPrevApp);
            }
            break;
        default:
            QLOGE("Bad parameter to gamed_send %d", state);
            return -1;
    }

    strlcpy(msg.name, mCurrentApp, strSize);
    msg.opcode = ((0x0F) & GAMED_VERSION) << GAMED_SHIFT_BIT_VERSION;
    msg.opcode = (msg.opcode |((0x0F)&state));
    QLOGI("Client sending msg.name is %s and msg.opcode is: %d ", msg.name,msg.opcode);
    game_client_send_cmd(msg);
    strlcpy(mPrevApp, name, strSize);
    return 0;
}

int game_client_send_cmd(struct gamedet_msg msg) {
    int rc, len;
    int client_comsoc = -1;
    struct sockaddr_un client_addr;

    client_comsoc = socket(PF_UNIX,SOCK_SEQPACKET, 0);
    if (client_comsoc < 0) {
        QLOGE("game client socket creation Failed");
    }

    fcntl(client_comsoc, F_SETFL, O_NONBLOCK);

    memset(&client_addr, 0, sizeof(struct sockaddr_un));
    client_addr.sun_family = AF_UNIX;
    snprintf(client_addr.sun_path, UNIX_PATH_MAX, GAME_SOCKET);

    len = sizeof(struct sockaddr_un);
    rc = connect(client_comsoc, (struct sockaddr *) &client_addr, len);
    if (rc == -1) {
        QLOGE("Failed in connect to socket: errno=%d (%s)", rc, strerror(rc));
        goto error;
    }
    ALOGE("sending msg to gamed server");
    rc = send(client_comsoc, &msg, sizeof(gamedet_msg), 0);
    if (rc == -1) {
        QLOGE("Failed in send game cmd: errno=%d (%s)", rc, strerror(rc));
        goto error;
    }
    close(client_comsoc);
    return rc;
error:
    if (client_comsoc >= 0) {
        close(client_comsoc);
    }
    return 0;
}

static void *gamed_comm_loop(void *data) {
    mpctl_msg_t *msg = NULL;
    (void)data;

    /* Main loop */
    for (;;) {
        EventData *evData = gamedEvQ.Wait();

        if (!evData || !evData->mEvData) {
            continue;
        }
        msg = (mpctl_msg_t *)evData->mEvData;

        QLOGI("Received time=%d, data=%d, hint_id=0x%x, hint_type=%d handle=%d package:%s",
                msg->pl_time, msg->data, msg->hint_id, msg->hint_type, msg->pl_handle, msg->usrdata_str) ;

        //Check for game detection feature to be enable
        if (sGameDetOn) {
            notify_fg_app_change(msg->hint_id, msg->usrdata_str);
        }
        //give the event data back to memory pool
        gamedEvQ.GetDataPool().Return(evData);
    }

    return NULL;
}

//callbacks for eventqueue
static void *Alloccb() {
    void *mem = (void *) new mpctl_msg_t;
    if (NULL ==  mem)
        QLOGE("memory not allocated");
    return mem;
}

static void Dealloccb(void *mem) {
    if (NULL != mem) {
        delete (mpctl_msg_t *)mem;
    }
}

