/*!
  @file
  sendcmd.cpp

  @brief
  Places a Remote Procedure Call (RPC) to Android's AtCmdFwd Service

*/

/*===========================================================================

Copyright (c) 2015, Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ----------------------------------------------------------
04/11/11   jaimel   First cut.


===========================================================================*/


/*===========================================================================

                           INCLUDE FILES

===========================================================================*/

#define LOG_NDEBUG 0
#define LOG_NIDEBUG 0
#define LOG_NDDEBUG 0
#define LOG_TAG "Atfwd_Sendcmd"
#include <utils/Log.h>
#include "common_log.h"
#include <cutils/properties.h>
#include "IAtCmdFwdService.h"
#include <binder/BpBinder.h>
#include <binder/IServiceManager.h>
#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include "sendcmd.h"
#include "quectel_at_handle.h"
#define MAX_KEYS 57

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>

namespace android {

/*===========================================================================

                           Global Variables

===========================================================================*/

sp<IAtCmdFwdService> gAtCmdFwdService; //At Command forwarding sevice object
sp<DeathNotifier> mDeathNotifier;

/*===========================================================================

                          Extern functions invoked from CKPD daemon

===========================================================================*/

extern "C" int initializeAtFwdService();
extern "C" int pressit(char key, int keyPressTime, int timeBetweenKeyPresses);
extern "C" void millisecondSleep(int milliseconds);

/*
#define QUEC_DEBUG_ON 0
#ifdef LOGI
#undef LOGI
#define LOGI(fmt,...)  do{\
                                if(QUEC_DEBUG_ON)\
                                    __android_log_print(ANDROID_LOG_INFO, "QuecS","[%s-%u]:" fmt,__FUNCTION__,__LINE__,##__VA_ARGS__);\
                            }while(0)
#endif  */ 
/*===========================================================================
  FUNCTION  initializeAtFwdService
===========================================================================*/
/*!
@brief
     Initializes the connection with the Window Manager service
@return
  Returns 0 if service intialization was successful; -1 otherwise

@note
  None.
*/
/*=========================================================================*/

extern "C" int initializeAtFwdService()
{
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder;
    int retryCnt = 1;
    if(sm == 0) {
        LOGE("Could not obtain IServiceManager \n");
        return -1;
    }

    do {
        binder = sm->getService(String16("AtCmdFwd"));
        if (binder == 0) {
            LOGW("AtCmdFwd service not published, waiting... retryCnt : %d", retryCnt);
            /*
             * Retry after (retryCnt * 5)s and yield in the cases when AtCmdFwd service is
             * is about to be published
             */
            sleep(retryCnt * ATFWD_RETRY_DELAY);
            ++retryCnt;
            continue;
        }

        break;
    } while(retryCnt <= ATFWD_MAX_RETRY_ATTEMPTS);

    if (binder == 0) {
        LOGI("AtCmdFwd service not ready - Exhausted retry attempts - :%d",retryCnt);
        //property_set("ctl.stop", "atfwd");
        return -1;
    }
    if (mDeathNotifier == NULL) {
        mDeathNotifier = new DeathNotifier();
    }
    binder->linkToDeath(mDeathNotifier);

    gAtCmdFwdService = interface_cast<IAtCmdFwdService>(binder);
    if (gAtCmdFwdService == 0)
    {
        LOGE("Could not obtain AtCmdFwd service\n");
        return -1;
    }

    // Start a Binder thread pool to receive Death notification callbacks
    sp<ProcessState> proc(ProcessState::self());
    ProcessState::self()->startThreadPool();
    return 0;
}

#define QUECTEL_FCT_TEST  
#ifdef QUECTEL_FCT_TEST

#define ARRARY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define RESP_BUF_SIZE (380*2) // RESP_BUF_SIZE msut less than the QMI_ATCOP_AT_RESP_MAX_LEN in the file vendor/qcom/proprietary/qmi/inc/qmi_atcop_srvc.h,
			  // Maybe you should change QMI_ATCOP_AT_RESP_MAX_LEN for your requirement

//#define QUECTEL_FCT_TEST_DEBUG // for print debug log info
#ifdef QUECTEL_FCT_TEST_DEBUG
#define DGprintf(fmt,args...) printf(fmt,##args) 
#else
#define DGprintf(fmt, args...) 
#endif 
typedef struct{
	const char *name; // item name
	int result; // -1: fail  0: none  1: success
}fct_item_type;
fct_item_type fct_items_all[]=
//fct_item_type fct_items[]=
{
        {"FLASHLIGHT",0},
	{"KEY", 0},
        {"VIBRATOR",0},
	{"HANDSET PLAY", 0},
	{"CAMERA MAIN", 0},
	{"HEADSET LOOP", 0},
	{"CAMERA FRONT",0},
	{"SPEAKER LOOP", 0},
        {"LIGHT SENSOR",0},
	{"SDCARD", 0},
	{"STORAGE", 0},
        {"SIMCARD1",0},
        {"SIMCARD2",0},
	{"WIFI", 0},
	{"BLUETOOTH", 0},
        {"GPS",0},
};
fct_item_type fct_items_auto_all[]=
//fct_item_type fct_items[]=
{
        {"L HEADSET",0},
	{"R HEADSET", 0},
        {"VIBRATOR",0},
	{"LOUDSPEAKER", 0},
	{"CAMERA BACK", 0},
	{"CAMERA FRONT", 0},
	{"HANDSET",0},
	{"SDCARD", 0},
        {"EMMC",0},
	{"SIMCARD1", 0},
	{"SIMCARD2", 0},
};

extern "C" char* set_response_buf(fct_item_type *fct_items, int num)
{
	int i,offset=0;
	int test_num=0, success_num=0;
	char *resp_buf=NULL;
	if(NULL == resp_buf)
	{
		resp_buf = (char *)malloc(RESP_BUF_SIZE);
		if(resp_buf == NULL)
		{
			LOGE("%s:%d No Memory\n", __func__, __LINE__);
			return resp_buf; // error
		}
		memset(resp_buf, 0, RESP_BUF_SIZE);
	}
	for(i=0; i<num; i++)
	{
		if(fct_items[i].result !=0 )
			test_num ++;
		if(fct_items[i].result == 1)
			success_num ++;
	}
	offset += snprintf(resp_buf+offset, (RESP_BUF_SIZE-offset), "+QFCT: %d,%d,%d",(success_num==num)?1:0, num, test_num );
	if((success_num==num) || (test_num == 0))
	{
		return resp_buf; // all fct items pass or not test
	}
	offset += snprintf(resp_buf+offset, (RESP_BUF_SIZE-offset), "\r\n");
	for(i=0; i<num; i++)
	{
		if(offset+32>RESP_BUF_SIZE)
		{
			LOGE("There is no space to store results. offset=%d RESP_BUF_SIZE=%d\r\n", offset, RESP_BUF_SIZE);
			break;
		}
		offset += snprintf(resp_buf+offset, (RESP_BUF_SIZE-offset), "+QFCT: %s,", fct_items[i].name);
		LOGE("[%s] %d\n", fct_items[i].name, fct_items[i].result);
		switch(fct_items[i].result)
		{
			case -1:
				offset += snprintf(resp_buf+offset, (RESP_BUF_SIZE-offset), "fail");
				break;
			case 0:
				offset += snprintf(resp_buf+offset, (RESP_BUF_SIZE-offset), "null");
				break;
				
			case 1:
				offset += snprintf(resp_buf+offset, (RESP_BUF_SIZE-offset), "pass");
				break;
		}
		if(i<num-1)
		{
			offset += snprintf(resp_buf+offset, (RESP_BUF_SIZE-offset), "\r\n");
		}
		
	}
	printf("%s:%d: RESP_BUF_SIZE:%d offset:%d \n", __FILE__, __LINE__,RESP_BUF_SIZE, offset);
	LOGE("%s:%d: RESP_BUF_SIZE:%d offset:%d \n", __FILE__, __LINE__,RESP_BUF_SIZE, offset);
#if  1// for debug
	DGprintf("<<<<<<<<<<<< respbuf >>>>>>>>>>>>>>\n");
	DGprintf("%s", resp_buf);
	DGprintf("<<<<<<<<<<<< respbuf end >>>>>>>>>>>>>>\n");
#endif

	return resp_buf;
}
extern "C" char* get_string_from_two_char(char *src, char *dest, int size, char start, char end)
{
	char *p=NULL;
	char *q=NULL;
	int i=0;
	if(NULL==src || NULL==dest)
		return NULL;
	memset(dest, 0, size);
	if((p=strchr(src,start)) && (q=strchr(src,end)))
	{
		p++; // skip start char, from next char
		for(i=0;i<size&&p!=q;i++)
		{
			*dest++=*p;
			p++;
			
		}
	}
	else
	{
		return NULL;
	}
	return dest;
	
}

int read_file(const char *filepath, char *buf, int size){
    int fd, len;

    fd = open(filepath, O_RDONLY);
    if(fd == -1){
        LOGE("[%s]:file(%s) open fail, error=%s\n", __FUNCTION__, filepath, strerror(errno));
        return -1;
    }

    len = read(fd, buf, size - 1);
    if(len > 0){
        if(buf[len - 1] == '\n')
            buf[len - 1] = '\0';
        else
            buf[len] = '\0';
    }

    close(fd);
    return 0;
}

bool is_msm8917(void){
    bool is_msm8917_support = false;
    char soc_name[32];
    int soc_id = 0;
    memset(soc_name, 0x00, sizeof(soc_name));

    if(!read_file("/sys/devices/soc0/soc_id", soc_name, sizeof(soc_name))) {
        soc_id = atoi(soc_name);
    }   
    LOGE("[%s]:Current Platform Target Soc_id is %d", __FUNCTION__, soc_id);
    if(soc_id == 303 || soc_id == 245){//303 is msm8917,294 is msm8937
        LOGE("[%s]:Current Platform Target is MSM8917", __FUNCTION__);
        is_msm8917_support = true;
    }else{
        LOGE("[%s]:Current Platform Target is MSM8937", __FUNCTION__);
        is_msm8917_support = false;
    }

    return is_msm8917_support;
}

extern "C" void quec_qfct_handle(AtCmdResponse *response)
{
//	#define FCT_RESULT_FILE	 "/persist/FTM_AP/mmi.res"
	char FCT_RESULT_FILE[64] = {0};
	int total_items;
	char line_text[64] = {0};
	FILE *fp = NULL;
	char mmi_res_name[32] = {0};
	int  i,check_num=0,offset=-1;
	int  sim_type=-1;
	int fct_arrary_type = 0;
  int items_length = 0;//ARRARY_SIZE(fct_items_all);
  
	LOGE("quec_qfct_handle start\n");
	if((fp=fopen("/persist/FTM_AP/mmi-check","r"))!=NULL){
			while(fgets(line_text,64,fp)!=NULL){
					if(strstr(line_text, "mmi-auto.res")){
							//char* FCT_RESULT_FILE	= "/persist/FTM_AP/mmi-auto.res"
							snprintf(FCT_RESULT_FILE,64,"/persist/FTM_AP/mmi-auto.res");
							fct_arrary_type = 1;
					}else if(strstr(line_text, "mmi.res")){
							//char* FCT_RESULT_FILE	="/persist/FTM_AP/mmi.res"
							snprintf(FCT_RESULT_FILE,64,"/persist/FTM_AP/mmi.res");
							fct_arrary_type = 0;
					}
			}
	}else{
			snprintf(FCT_RESULT_FILE,64,"/persist/FTM_AP/mmi.res");
			//char* FCT_RESULT_FILE="/persist/FTM_AP/mmi.res"
	}
	
	
	if(fct_arrary_type == 0){
			items_length = ARRARY_SIZE(fct_items_all);      
	}else{
			items_length = ARRARY_SIZE(fct_items_auto_all);   
	}
	
  total_items = items_length;

  fct_item_type fct_items[total_items];        
	fct_item_type fct_items_check[total_items];  


	if(fct_arrary_type == 0){      
		  for(i=0; i<total_items; i++) {
		      fct_items[i].name = fct_items_all[i].name;
		      fct_items[i].result = 0;
		  }
	}else{
		  for(i=0; i<total_items; i++) {
		      fct_items[i].name = fct_items_auto_all[i].name;
		      fct_items[i].result = 0;
		  }		
	}
	
	
	if((fp=fopen(FCT_RESULT_FILE, "r")) == NULL)
	{
		LOGE("open file:%s failed!\n", FCT_RESULT_FILE);
		
		if((response->response = set_response_buf(fct_items, total_items)) == NULL )
		{
			response->result = 0; // error
			LOGE("%s:%d open file %s failed!\n", __func__, __LINE__, FCT_RESULT_FILE);
			//printf("%s:%d open file %s failed!\n", __func__, __LINE__, FCT_RESULT_FILE);
		}
		response->result = 1;
		return;
	}
	// get line from file
	while(fgets(line_text, 64, fp)!=NULL)	
	{
	LOGE("Line: %s \n",line_text);
		if(strchr(line_text, '[') && strchr(line_text, ']')) // [name]
		{
			offset = -1;
			if(get_string_from_two_char(line_text, mmi_res_name, 32, '[',']') == NULL)
			{
				LOGE("error!\n");
				continue;
			}
			else
			{
				LOGE("get name:%s\n", mmi_res_name);
			}
			for(i=0; i<total_items; i++)
			{
				LOGE("fct_item.name:%s\n",fct_items[i].name);
				//if(strstr(line_text, fct_items[i].name))
				if(strcasecmp(mmi_res_name, fct_items[i].name)==0)
				{
					LOGE("Match\n");
					offset = i;
					break;
				}
				else
				{
					LOGE("Not Match.\n");
				}
			}
			
		}
		else if(strstr(line_text, "Result"))  // item result
		{
			if(strcasecmp(mmi_res_name,"SIM_TYPE")==0 && strstr(line_text, "w_version"))
			{
				sim_type=0;
			}
			if(strcasecmp(mmi_res_name,"SIM_TYPE")==0 && strstr(line_text, "ssss"))
			{
				sim_type=1;
			}
			if(strcasecmp(mmi_res_name,"SIM_TYPE")==0 && strstr(line_text, "dsds"))
			{
				sim_type=2;
			}
			if(offset>=0)
			{
				if(strstr(line_text, "pass"))
					fct_items[offset].result = 1;
				else if(strstr(line_text, "fail"))
					fct_items[offset].result = -1;
			}
		}
	}
	if(fp)
		fclose(fp);
	
	if(sim_type == 0)
	{
				for(i=0;i<total_items;i++)
				{
					if((strcasecmp(fct_items[i].name,"SIMCARD1")==0)|| (strcasecmp(fct_items[i].name,"SIMCARD2")==0) ||(strcasecmp(fct_items[i].name,"GPS")==0))
						fct_items[i].result = -2 ;
				}
	}
	if(sim_type == 1)
	{
				for(i=0;i<total_items;i++)
				{
					if((strcasecmp(fct_items[i].name,"SIMCARD2")==0))
						fct_items[i].result = -2 ;
				}
	}

	for (i = 0; i < total_items; i++) {
			if(fct_items[i].result !=-2){
        fct_items_check[check_num].name = fct_items[i].name;
        fct_items_check[check_num].result = fct_items[i].result;
        LOGI("fct_items[%d] =%s result=%d\n",check_num,fct_items_check[check_num].name,fct_items_check[check_num].result);
        check_num++;
      }
   }
	
	if((response->response = set_response_buf(fct_items_check, check_num)) == NULL)
	{
		response->result = 0;
		return;
	}
	response->result = 1; // success
	return;
	
}

#endif



/*===========================================================================
  FUNCTION  sendit
===========================================================================*/
/*!
@brief
     Invokes a Remote Procedure Call (RPC) to Android's Window Manager Service
     Window Manager service returns 0 if the call is successful
@return
  Returns 1 if the key press operation was successful; 0 otherwise

@note
  None.
*/
/*=========================================================================*/

extern "C" AtCmdResponse *sendit(const AtCmd *cmd)
{
	AtCmdResponse *result;
	result = new AtCmdResponse;
	result->response = NULL;
	if (!cmd) return NULL;
	LOGE("ques cmd->name : %s",cmd->name);
#ifdef QUECTEL_FCT_TEST
	if(strcasecmp(cmd->name, "+QFCT")==0)
	{
		LOGE("ques QFCT cmd");
		LOGI("ATFWD AtCmdFwd QFCT");
		if(NULL != cmd->tokens) {
			LOGI("ATFWD AtCmdFwd Tokens Not NULL ntokens=%d",cmd->ntokens);
			if(cmd->ntokens == 0 || cmd->tokens[0] == NULL){
				LOGI("ATFWD AtCmdFwd Tokens[0] is NULL");
				quec_qfct_handle(result);
				/*	}else if(0 == strncmp("wifi-kill",cmd->tokens[0],strlen("wifi-kill"))){
					LOGI("ATFWD AtCmdFwd:%s",cmd->tokens[0]);
					property_set("wifi.ptt_socket_app", "false");
					property_set("wifi.p_socket_app", "true");*/
		}else if(0 == strncmp("wifi-start",cmd->tokens[0],strlen("wifi-start"))){
			LOGI("ATFWD AtCmdFwd:%s",cmd->tokens[0]);
			//	char *args[5] = { PTT_SOCKET_BIN, "-v", "-d", "-f", NULL };
			//do_handle(result,args,true);
			property_set("wifi.p_socket_app", "true");
			result->result = 1; // success
		}else if(0 == strncmp("wifi-end",cmd->tokens[0],strlen("wifi-end"))){
			LOGI("ATFWD AtCmdFwd:%s",cmd->tokens[0]);
			//	char *args[5] = { PTT_SOCKET_BIN, "-f", "-d", "-v", NULL };
			//do_handle(result,args,false);
			property_set("wifi.p_socket_app", "false");
			result->result = 1; // success
		}else if(0 == strncmp("ble-start",cmd->tokens[0],strlen("ble-start"))){
			//	const char *args[3] = { FTMDAEMON_BIN, "-n", NULL };
			LOGE("ATFWD AtCmdFwd:%s",cmd->tokens[0]);
			property_set("bt.start", "true");
			result->result = 1; // success
		}else if(0 == strncmp("ble-end",cmd->tokens[0],strlen("ble-end"))){
			//	const char *args[3] = { FTMDAEMON_BIN, "-n", NULL };
			LOGE("ATFWD AtCmdFwd:%s",cmd->tokens[0]);
			property_set("bt.start", "false");
			result->result = 1; // success
		}else{
			LOGI("ATFWD AtCmdFwd Default Handle");
			quec_qfct_handle(result);
		}
		}else{
			LOGI("ATFWD AtCmdFwd Tokens is NULL");
			quec_qfct_handle(result);		
		}
#ifdef QUECTEL_QGMR_CMD
	} else if(strcasecmp(cmd->name, "+QGMR") == 0) {

        quec_qgmr_handle(cmd, result);

#endif /* QUECTEL_QGMR_CMD */
#ifdef QUECTEL_QAPSUB_CMD
    } else if( strcasecmp(cmd->name, "+QAPSUB") == 0 ) {

		quec_qapsub_handle(cmd, result);

#endif /* QUECTEL_QAPSUB_CMD */
#ifdef QUECTEL_QDEVINFO_CMD
    } else if (strcasecmp(cmd->name, "+QDEVINFO") == 0) {

        quec_qdevinfo_handle(cmd, result);
#endif /* QUECTEL_QDEVINFO_CMD */
#ifdef QUECTEL_QAPCMD_CMD
	} else if (strcasecmp(cmd->name, "+QAPCMD") == 0) {
        quec_qapcmd_handle(cmd, result);
#endif /* QUECTEL_QAPCMD_CMD */
	}
#else
	result = gAtCmdFwdService->processCommand(*cmd);
#endif

	return result;
}

void DeathNotifier::binderDied(const wp<IBinder>& who) {
	QCRIL_NOTUSED(who);
	LOGI("AtCmdFwd : binderDied");
	initializeAtFwdService();
}

};  /* namespace android */
