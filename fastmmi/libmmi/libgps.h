#ifndef __MCAP_TOOL_H
#define __MCAP_TOOL_H
#include <stdio.h>
#include <android/log.h>
#include <inttypes.h>
#include <stdlib.h>
/*
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IBinder.h>
#include <binder/Binder.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
*/
    #define QUEC_DEBUG_ON 0

    #define LOGI(fmt,...)  do{\
                                if(1)\
                                    __android_log_print(ANDROID_LOG_INFO, "MMI","[%s-%u]:" fmt,__FUNCTION__,__LINE__,##__VA_ARGS__);\
                            }while(0)
    #define LOGW(fmt,...) __android_log_print(ANDROID_LOG_WARN, "MMI","[%s-%u]:" fmt,__FUNCTION__,__LINE__,##__VA_ARGS__)
    #define LOGE(fmt,...) __android_log_print(ANDROID_LOG_ERROR, "MMI","[%s-%u]:" fmt,__FUNCTION__,__LINE__,##__VA_ARGS__)
bool module_main(int argc, char* argv[]);
#endif