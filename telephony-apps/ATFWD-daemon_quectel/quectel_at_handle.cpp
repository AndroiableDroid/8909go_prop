/*!
  @file
  sendcmd.cpp

  @brief
  Places a Remote Procedure Call (RPC) to Android's AtCmdFwd Service

*/

/*===========================================================================

  Copyright (c) 2011 Qualcomm Technologies, Inc. All Rights Reserved

  Qualcomm Technologies Proprietary

  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.

  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of Qualcomm Technologies, Inc.

  ===========================================================================*/

/*===========================================================================

  EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


  when       who     what, where, why
  --------   ---     ----------------------------------------------------------
  2018/11/17   geoff   First cut.


  ===========================================================================*/

/*===========================================================================
 *							NOTE
 *
 * return the devinfo  results for AT Command(AT+QDEVINFO?)
 * need add driver file:\kernel\drivers\qdevinfo\quectel_devinfo.c
 * chmod 444 for /sys/kernel/debug/mmc0/mmc0:0001/ext_csd
 * modify code:\kernel\drivers\platform\msm\qpnp-revid.c for get pmic information
 * maybe it also need add semiux permision
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
//#include <binder/BpBinder.h>
//#include <binder/IServiceManager.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "quectel_at_handle.h"
#define MAX_KEYS 57

//#include <binder/IPCThreadState.h>
//#include <binder/ProcessState.h>
namespace android {

#ifdef QUECTEL_QGMR_CMD
#define ATFWD_DATA_PROP_QUEC_VER            "ro.build.quectelversion.release"
#define ATFWD_DATA_PROP_ANDROID_VER			 "ro.build.version.release"
#define QGMR_RESP_BUF_SIZE (380) // RESP_BUF_SIZE msut less than the QMI_ATCOP_AT_RESP_MAX_LEN in the file vendor/qcom/proprietary/qmi/inc/qmi_atcop_srvc.h,
    // Maybe you should change QMI_ATCOP_AT_RESP_MAX_LEN for your requirement

extern "C" void quec_qgmr_handle( const AtCmd *cmd ,AtCmdResponse *response)
{
    int ret=0;
    char target[128] = {0}; // Stores target info      
    char *resp_buf=NULL;
    char *ptr=NULL;
    if(NULL == resp_buf)
    {
        resp_buf = (char *)malloc(QGMR_RESP_BUF_SIZE);
        if(resp_buf == NULL)
        {
            LOGE("%s:%d No Memory\n", __func__, __LINE__);
            return; // error
        }
        memset(resp_buf, 0, QGMR_RESP_BUF_SIZE);
    }

    ret = property_get(ATFWD_DATA_PROP_ANDROID_VER, target, "");
    LOGI("qgmr_modem:%s",cmd->tokens[0]);
    LOGI("qgmr_andorid:%s",target);

    ret = 60;
    ptr = strstr(cmd->tokens[0], "SC");
    if (ptr) {
        sscanf(ptr + 2, "%d%*s", &ret);
    }
    sprintf(resp_buf,"Quectel\nSC%d\nRevision: ", ret);

    if(cmd->ntokens == 2) {
        if (strlen(target) == 1)
            sprintf(resp_buf,"%s%s%s_Android%s.0.0",resp_buf, cmd->tokens[0], cmd->tokens[1], target);
        else
            sprintf(resp_buf,"%s%s%s_Android%s",resp_buf, cmd->tokens[0], cmd->tokens[1], target);
    } else {
        if (strlen(target) == 1)
            sprintf(resp_buf,"%s%s_Android%s.0.0",resp_buf, cmd->tokens[0], target);
        else
            sprintf(resp_buf,"%s%s_Android%s",resp_buf, cmd->tokens[0], target);
    }
    memset(target,0,64);
    ret = property_get(ATFWD_DATA_PROP_QUEC_VER, target, "");
    LOGI("qgmr_quectel:%s",target);
    LOGI("Line[%d]: resp_buf:%s", __LINE__, resp_buf);
    // remove V01
    if((ptr=strchr(target,'V'))!=NULL)
    {
        *ptr='\0';  // 'V' -> '\0'
    }
    sprintf(resp_buf,"%s.%s",resp_buf,target);
    LOGI("Line[%d]: resp_buf:%s", __LINE__, resp_buf);
    if((response->response = resp_buf) == NULL )
    {
        response->result = 0; // error
        LOGE("QGMR_AT error");
    }
    response->result = 1;
    LOGI("Line[%d]: resp_buf:%s", __LINE__, resp_buf);

    return;
}
#endif

#ifdef QUECTEL_QAPSUB_CMD
#define QUECTEL_ANDROID_VERSION            "ro.build.quectelversion.release"
#define Q_RESP_BUF_SIZE 390

extern "C" void quec_qapsub_handle(const AtCmd *cmd, AtCmdResponse *response)
{
    int ret = 0;
    char target[PROPERTY_VALUE_MAX] = {0};
    char *resp_buf=NULL;
    char *ptr=NULL;
    //char apsub[8] = {0};

    if (cmd->ntokens <= 0) {
        LOGW("%s:%d ntokens is 0!", __func__, __LINE__);
    }

    if(NULL == resp_buf)
    {
        resp_buf = (char *)malloc(Q_RESP_BUF_SIZE);
        if(resp_buf == NULL)
        {
            LOGE("%s:%d No Memory.\n", __func__, __LINE__);
            return; // error
        }
        memset(resp_buf, 0, Q_RESP_BUF_SIZE);
    }
    ret = property_get(QUECTEL_ANDROID_VERSION, target, ""); //sample: 01.001V01
    LOGI("andorid version:%s",target);
    if(ret<=0)
    {
        free(resp_buf);
        LOGE("%s:%d Get property error.\n", __func__, __LINE__);
        return; // get property of android version error.
    }
    // get sub version from android version, 01.001V01 -> V01
    if((ptr=strchr(target,'V'))==NULL)
    {
        free(resp_buf);
        LOGE("%s:%d Get apsubversion error.\n", __func__, __LINE__);
        return; // get property of android version error.
    }

    //strncpy(resp_buf, ptr, RESP_BUF_SIZE);
    snprintf(resp_buf, Q_RESP_BUF_SIZE, "APSubEdition: %s",ptr);
    response->response = resp_buf;
    LOGI("resp buf:%s",resp_buf);
    response->result = 1;
    return;
}
#endif // QUECTEL_AT_QAPSUB_FEATURE

#ifdef QUECTEL_QDEVINFO_CMD
#define QUEC_EMCP_INFO 	"/proc/quec_emcp_info"
#define QUEC_PMU_INFO 	"/proc/quec_pmu_info"
#define QUEC_CPU_INFO 	"/proc/cpuinfo"
#define QUEC_EMCP_NAME  "/sys/class/mmc_host/mmc0/mmc0:0001/name"
#define QUEC_EMCP_MEMINFO  "/proc/meminfo"
#define QUEC_EMMC_SIZE   "/sys/block/mmcblk0/size"
#define QUEC_INFO_LEN 128
#define RESULT_BUF_SIZE 256
#define RESP_BUF_SIZE (150) // RESP_BUF_SIZE msut less than the QMI_ATCOP_AT_RESP_MAX_LEN in the file vendor/qcom/proprietary/qmi/inc/qmi_atcop_srvc.h,
// Maybe you should change QMI_ATCOP_AT_RESP_MAX_LEN for your requirement
extern "C" int quectel_search_str( char *str1,char *str2)
{
    int i;//,j;
    char *buf;
    char str_Hardware[]="Qualcomm Technologies, Inc ";
    buf=strstr(str1,str_Hardware)+strlen(str_Hardware);
    for(i=0;buf[i] != '\0';i++) {
        if(buf[i] == '\n') {
            buf[i]='\0';
            break;
        }
    }
    if((buf != NULL) && (strlen(buf) < QUEC_INFO_LEN))
        snprintf(str2,strlen(buf)+1,"%s",buf);
    else
        sprintf(str2,"get cpuinfo error!!");
    return 0;
}

extern "C" void get_cpu_info( char *info)
{
    char buf[4096]={'\0'};
    char cpu_str[QUEC_INFO_LEN]={'\0'};
    FILE *fp = NULL;
    if((fp=fopen(QUEC_CPU_INFO, "r")) != NULL)
    {
        fread(buf,4096,1,fp);
        if(fp)
            fclose(fp);
        quectel_search_str(buf,cpu_str);
        sprintf(info,"%s",cpu_str);
        return;
    }
}

extern "C" void get_file_info( const char *file,char *info)
{
    int i;
    char devinfo_str[QUEC_INFO_LEN]={'\0'};
    FILE *fp = NULL;
    if((fp=fopen(file, "r")) != NULL)
    {
        fread(devinfo_str,QUEC_INFO_LEN,1,fp);
        if(fp)
            fclose(fp);
        for(i=0;devinfo_str[i]!='\0';i++)
        {
            if(devinfo_str[i]=='\n')
            {
                devinfo_str[i]='\0';
                break;
            }
        }
        sprintf(info,"%s",devinfo_str);
        return;
    }
}

extern "C" int get_flash_info(char *buf)
{
    FILE *fp = NULL;
    size_t filesize = 0;
    ssize_t readsize = 0;
    int totlesize = 0;
    int offset = 0;
    char *line = NULL;
    char buffer[50] = {0};
    char *ptr;

    //LOGI("%s:%d  Peeta I'm here", __func__, __LINE__);

    if (buf == NULL) {
        LOGI("%s:%d buf is NULL", __func__, __LINE__);
        return -1;
    }

    /* EMCP name */
    fp = fopen(QUEC_EMCP_NAME, "r");
    if (fp == 0) {
        LOGE("%s: unable to open %s", __func__, QUEC_EMCP_NAME);
        return -1;
    }

    readsize = getline(&line, &filesize, fp);
    if (readsize < 0) {
        LOGE("%s:%d failed to getline ", __func__, __LINE__);
        return -1;
    }

    offset += snprintf(buf, readsize, "%s", line);

    if (line)
        free(line);
    line = NULL;

    fclose(fp);

    /* EMMC size */
    fp = fopen(QUEC_EMMC_SIZE, "r");
    if (fp == 0) {
        LOGE("%s: unable to open %s", __func__, QUEC_EMMC_SIZE);
        return -1;
    }

    readsize = getline(&line, &filesize, fp);
    if (readsize < 0) {
        LOGE("%s:%d failed to getline ", __func__, __LINE__);
        return -1;
    }

    //LOGI("%s:%d  line:%s", __func__, __LINE__, line);

    sscanf(line, "%d", &totlesize); //MB

    if (line)
        free(line);
    line = NULL;

    fclose(fp);

    totlesize /= 2048;
    if (totlesize % 4096 == 0)
        totlesize = (totlesize/4096) * 4; //GB
    else
        totlesize = (totlesize/4096 + 1) * 4; //GB
    //LOGI("%s:%d totlesize = %d, buf is:%s. offset = %d", __func__, __LINE__, totlesize, buf, offset);
    offset += sprintf(buf + offset - 1, ",%dG", totlesize);
    //LOGI("%s:%d totlesize = %d, buf is:%s. offset = %d", __func__, __LINE__, totlesize, buf, offset);

    /* size */
    fp = fopen(QUEC_EMCP_MEMINFO, "r");
    if (fp == 0) {
        LOGE("%s: unable to open %s", __func__, QUEC_EMCP_MEMINFO);
        return -1;
    }

    while(fgets(buffer, sizeof(buffer) - 1, fp) != NULL) {
        ptr = strchr(buffer, ':');
        if (!strncmp(buffer, "MemTotal", ptr - buffer)) {
            sscanf(ptr + 1, "%d%*s", &totlesize);
            totlesize = totlesize/1024;

            //LOGI("%s:%d  memTotal size: %dMB", __func__, __LINE__, totlesize);

            if (totlesize <= 512)
                offset += sprintf(buf + offset - 1, ",512M");
            else {
                totlesize = totlesize/1024 + 1;
                offset += sprintf(buf + offset - 1, ",%dG", totlesize);
            }
            LOGI("%s:%d totlesize = %d, buf is:%s", __func__, __LINE__, totlesize, buf);
            break;
        }
        memset(buffer, 0, sizeof(buffer));
    }

    fclose(fp);

    return 0;
}

extern "C" void quec_qdevinfo_handle(const AtCmd *cmd, AtCmdResponse *response)
{
    int i;
    char *resp_buf=NULL;
    char devinfo[QUEC_INFO_LEN]={'\0'};
    int offset=0;

    resp_buf = (char *)malloc(RESP_BUF_SIZE);
    if(resp_buf == NULL) {
        LOGE("%s:%d  No Memory", __func__, __LINE__);
        return; // error
    }
    memset(resp_buf, 0, RESP_BUF_SIZE);

    response->result = 1;
    response->response = resp_buf;

    if (cmd->ntokens <= 0) {
        LOGW("%s:%d ntokens is 0!", __func__, __LINE__);
        free(resp_buf);
        response->response = NULL;
        response->result = 0;
        return;
    }

    for (i = 0; i < cmd->ntokens; i++) {
        //LOGI("%s:%d Peeta:tokens[%d] = %s", __func__, __LINE__, i, cmd->tokens[i]);
        if (cmd->tokens[i] == NULL) {
            LOGE("%s:%d tokens is NULL", __func__, __LINE__);
            free(resp_buf);
            response->response = NULL;
            response->result = 0; // failure
            return;
        }
    }

    if(strcasecmp(cmd->tokens[0], "FLASH") == 0) {
        //LOGI("%s:%d  Peeta I'm here", __func__, __LINE__);
        //get_file_info(QUEC_EMCP_INFO,devinfo);
        if (get_flash_info(devinfo) == 0) {
            offset += sprintf(resp_buf + offset, "+QDEVINFO:\"Flash\",%s", devinfo);
            response->result = 1;
        } else {
            offset += sprintf(resp_buf + offset, "+QDEVINFO:\"Flash\",NULL");
            response->result = 1;
        }
    } else if(strcasecmp(cmd->tokens[0], "BB") == 0) {
        get_cpu_info(devinfo);
        offset += sprintf(resp_buf+offset, "+QDEVINFO:\"BB\",%s",devinfo);
    } else if(strcasecmp(cmd->tokens[0], "PA")==0) {

        if(cmd->tokens[1] && cmd->tokens[2])
            offset += sprintf(resp_buf+offset, "+QDEVINFO:\"PA\",%s,%s", cmd->tokens[1], cmd->tokens[2]);//PA
        else if (cmd->tokens[1])
            offset += sprintf(resp_buf+offset, "+QDEVINFO:\"PA\",%s", cmd->tokens[1]);//PA
        else
            offset += sprintf(resp_buf+offset, "+QDEVINFO:\"PA\",NULL");
    } else if (strcasecmp(cmd->tokens[0], "PMIC") == 0) {
        get_file_info(QUEC_PMU_INFO,devinfo);
        offset += sprintf(resp_buf+offset, "+QDEVINFO:\"PMIC\",%s", devinfo);
    } else if (strcasecmp(cmd->tokens[0], "CHECK") == 0) {
        //LOGI("%s:%d Peeta:I'm here!", __func__, __LINE__);
        offset += sprintf(resp_buf+offset, "+QDEVINFO:\"BB\"\n");//bb
        offset += sprintf(resp_buf + offset, "+QDEVINFO:\"Flash\"\n");
        offset += sprintf(resp_buf + offset, "+QDEVINFO:\"PMIC\"\n");//pmic
        offset += sprintf(resp_buf+offset, "+QDEVINFO:\"PA\"");//PA
    } else if(strcasecmp(cmd->tokens[0], "ALL") == 0) {
        memset(devinfo, 0, QUEC_INFO_LEN);
        get_cpu_info(devinfo);
        offset += sprintf(resp_buf+offset, "+QDEVINFO:\"BB\",%s\n", devinfo);//bb

        memset(devinfo, 0, QUEC_INFO_LEN);
        if (get_flash_info(devinfo) == 0) {
            offset += sprintf(resp_buf + offset, "+QDEVINFO:\"Flash\",%s\n", devinfo);
        } else
            offset += sprintf(resp_buf + offset, "+QDEVINFO:\"Flash\",NULL\n");

        memset(devinfo, 0, QUEC_INFO_LEN);
        get_file_info(QUEC_PMU_INFO,devinfo);
        offset += sprintf(resp_buf + offset, "+QDEVINFO:\"PMIC\",%s\n", devinfo);//pmic
        if(cmd->tokens[1] && cmd->tokens[2])
            offset += sprintf(resp_buf+offset, "+QDEVINFO:\"PA\",%s,%s", cmd->tokens[1], cmd->tokens[2]);//PA
        else if (cmd->tokens[1])
            offset += sprintf(resp_buf+offset, "+QDEVINFO:\"PA\",%s", cmd->tokens[1]);//PA
        else
            offset += sprintf(resp_buf+offset, "+QDEVINFO:\"PA\",NULL");
        //LOGI("%s:%d length = %ld, resp_buf: %s", __func__, __LINE__, strlen(resp_buf), resp_buf);
    } else {
        LOGW("%s:%d something is wrong!", __func__, __LINE__);
        response->result = 0;
        free(response->response);
        response->response = NULL;
    }

    return;
}
#endif

#ifdef QUECTEL_QAPCMD_CMD

#define QUEC_CHGE_INFO  "/sys/class/power_supply/battery/charging_enabled"

extern "C" void quec_qapcmd_handle( const AtCmd *cmd ,AtCmdResponse *response)
{
    int i;
    int offset=0;
    FILE *fp = NULL;
    char *resp_buf=NULL;
    char buf[10] = {0};

    resp_buf = (char *)malloc(RESP_BUF_SIZE);
    if(resp_buf == NULL) {
        LOGE("%s:%d  No Memory\n", __func__, __LINE__);
        return; // error
    }
    memset(resp_buf, 0, RESP_BUF_SIZE);

    response->result = 1;
    response->response = resp_buf;

    if (cmd->ntokens <= 0) {
        LOGW("%s:%d ntokens is 0!", __func__, __LINE__);
        free(response->response);
        response->response = NULL;
        response->result = 0;
        return;
    }

    for (i = 0; i < cmd->ntokens; i++) {
        LOGI("%s:%d tokens[%d]:(%s)", __func__, __LINE__, i, cmd->tokens[i]);
        if (cmd->tokens[i] == NULL) {
            LOGE("%s:%d failed to remove quotation", __func__, __LINE__);
            free(response->response);
            response->response = NULL;
            response->result = 0; // failure
            return;
        }
    }

    if(strcasecmp(cmd->tokens[0], "CHGENABLE")==0) {
        if(cmd->ntokens==1) {
            fp = fopen(QUEC_CHGE_INFO, "r");
            if (fp == NULL) {
                LOGE("%s: unable to open %s", __func__, QUEC_CHGE_INFO);
                return;
            }

            while (fgets(buf, sizeof(buf), fp) != NULL);

            fclose(fp);

            //sscanf(buf, "%d", &i);
            //offset += sprintf(resp_buf + offset, "+QAPCMD:CHGENABLE,%d", !i);
            offset += sprintf(resp_buf + offset, "+QAPCMD:CHGENABLE,%s", buf);

            LOGI("+QAPCMD:CHGENABLE get: %s", buf);
            response->result = 1;
        }else if((cmd->ntokens == 2)&&((strcasecmp(cmd->tokens[1], "0")==0)
                    ||(strcasecmp(cmd->tokens[1], "1")==0))) {
            fp = fopen(QUEC_CHGE_INFO, "w");
            if (fp == NULL) {
                LOGE("%s: unable to open %s", __func__, QUEC_CHGE_INFO);
                return;
            }

#if 0
            if (strcasecmp(cmd->tokens[1], "0") == 0) {
                if (fputs("1", fp) < 0) {
                    LOGE("%s: failed to write %s to %s", __func__, cmd->tokens[1], QUEC_CHGE_INFO);
                    return;
                }
            } else {
                if (fputs("0", fp) < 0) {
                    LOGE("%s: failed to write %s to %s", __func__, cmd->tokens[1], QUEC_CHGE_INFO);
                    return;
                }
            }
#endif
            if (fputs(cmd->tokens[1], fp) < 0) {
                LOGE("%s: failed to write %s to %s", __func__, cmd->tokens[1], QUEC_CHGE_INFO);
                return;
            }

            fclose(fp);

            //no response
            LOGI("+QAPCMD:CHGENABLE set: %s", cmd->tokens[1]);
            response->result = 1;
        }else{
            free(response->response);
            response->response = NULL;
            response->result = 0; // error
            LOGE("QAPCMD_AT CHGENABLE error");
            return;
        }
    } else if((strcasecmp(cmd->tokens[0], "CHECK")==0) && (cmd->ntokens==1)) {
        offset += snprintf(resp_buf+offset, (RESP_BUF_SIZE-offset), "+QAPCMD:version1.1\n");
        offset += snprintf(resp_buf+offset, (RESP_BUF_SIZE-offset), "+QAPCMD:CHGENABLE");
        //offset += snprintf(resp_buf+offset, (RESP_BUF_SIZE-offset), "+QAPCMD:CHANGESIM\n");
    } else if((strcasecmp(cmd->tokens[0], "ALL")==0) && (cmd->ntokens==1)) {
        fp = fopen(QUEC_CHGE_INFO, "r");
        if (fp == NULL) {
            LOGE("%s: unable to open %s", __func__, QUEC_CHGE_INFO);
            return;
        }

        while (fgets(buf, sizeof(buf), fp) != NULL);

        fclose(fp);

#if 0
        sscanf(buf, "%d", &i);
        offset += sprintf(resp_buf + offset, "+QAPCMD:CHGENABLE,%d", !i);
        LOGI("+QAPCMD:CHGENABLE get: %d", !i);
#else
        offset += sprintf(resp_buf + offset, "+QAPCMD:CHGENABLE,%s", buf);
        LOGI("+QAPCMD:CHGENABLE get: %s", buf);
#endif

        response->result = 1;
    } else {
        LOGW("%s:%d something is wrong!", __func__, __LINE__);
        free(response->response);
        response->response = NULL;
        response->result = 0;
    }

    return;
}
#endif
};  /* namespace android */
