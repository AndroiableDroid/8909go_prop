/*
 * Copyright (c) 2015,2017 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Copyright (c) 2011-2012, The Linux Foundation. All rights reserved.
 */

#define LOG_TAG "ANDR-PERF-JNI"

#include "jni.h"
#include "JNIHelp.h"
#include "client.h"

#include <dlfcn.h>
#include <limits.h>
#include <pthread.h>
#include <string.h>
#include <vector>
#include <shared_mutex>

#include <cutils/properties.h>
#include <utils/Log.h>
#include <vendor/qti/hardware/iop/1.0/IIop.h>

using vendor::qti::hardware::iop::V1_0::IIop;

using android::hardware::Return;
using android::hardware::Void;
using android::hardware::hidl_death_recipient;
using android::hardware::hidl_vec;
using android::hardware::hidl_string;
using android::hidl::base::V1_0::IBase;
using ::android::sp;
using ::android::wp;
using std::unique_lock;
using std::shared_lock;
using std::shared_timed_mutex;

static sp<IIop> gIopHal = NULL;
static shared_timed_mutex gIop_lock;

struct IopDeathRecipient : virtual public hidl_death_recipient
{
    virtual void serviceDied(uint64_t /*cookie*/, const wp<IBase>& /*who*/) override {
        unique_lock<shared_timed_mutex> write_lock(gIop_lock);
        gIopHal = NULL;
        ALOGE("IIop serviceDied");
    }
};

static sp<IopDeathRecipient> iopDeathRecipient = NULL;

static void getIopServiceAndLinkToDeath() {
    shared_lock<shared_timed_mutex> read_lock(gIop_lock);
    if (gIopHal == NULL) {
        read_lock.unlock();
        {
            unique_lock<shared_timed_mutex> write_lock(gIop_lock);
            if (gIopHal == NULL) {
                gIopHal = IIop::tryGetService();
                if (gIopHal != NULL) {
                    iopDeathRecipient = new IopDeathRecipient();
                    android::hardware::Return<bool> linked = gIopHal->linkToDeath(iopDeathRecipient, 0);
                    if (!linked || !linked.isOk()) {
                        gIopHal = NULL;
                        ALOGE("Unable to link IOP-Hal death notification");
                    }
                } else {
                    ALOGE("Iop tryGetService failed");
                }
            }
        }
    }
}

static int processIntReturn(const Return<int32_t> &intReturn, const char* funcName) {
    int ret = -1;
    if (!intReturn.isOk()) {
        unique_lock<shared_timed_mutex> write_lock(gIop_lock);
        gIopHal = NULL;
        ALOGE(" %s failed: IOP HAL service not available", funcName);
    } else {
        ret = intReturn;
    }
    return ret;
}

static int processVoidReturn(const Return<void> &voidReturn, const char* funcName) {
    int ret = 0;
    if (!voidReturn.isOk()) {
        unique_lock<shared_timed_mutex> write_lock(gIop_lock);
        gIopHal = NULL;
        ret = -1;
        ALOGE(" %s failed: IOP HAL service not available", funcName);
    }
    return ret;
}

static jint
com_qualcomm_qtiperformance_native_perf_io_prefetch_start(JNIEnv *env, jobject clazz, jint pid, jstring j_pkg_name, jstring j_code_path)
{
    int rc = -1;
    const char * pkg_name;
    const char * code_path;

    if (j_pkg_name == NULL || j_code_path == NULL) {
        jniThrowNullPointerException(env, "pkg name or code path must not be null.");
        return rc;
    }

    pkg_name = env->GetStringUTFChars(j_pkg_name,0) ;
    code_path = env->GetStringUTFChars(j_code_path,0);
    getIopServiceAndLinkToDeath();
    {
        shared_lock<shared_timed_mutex> read_lock(gIop_lock);
        if (gIopHal != NULL)  {
            ALOGE("com_qualcomm_qtiperformance_native_perf_io_prefetch_start");
            Return<int32_t> intReturn = gIopHal->iopStart(pid,pkg_name,code_path);
            read_lock.unlock();
            rc = processIntReturn(intReturn, "io_prefetch_start");
        }
    }
    env->ReleaseStringUTFChars(j_pkg_name, pkg_name);
    env->ReleaseStringUTFChars(j_code_path, code_path);
    return rc;
}

static jint
com_qualcomm_qtiperformance_native_perf_io_prefetch_stop(JNIEnv *env, jobject clazz)
{
    int rc = -1;
    getIopServiceAndLinkToDeath();
    {
        shared_lock<shared_timed_mutex> read_lock(gIop_lock);
        if (gIopHal != NULL)  {
            Return<void> voidReturn = gIopHal->iopStop();
            read_lock.unlock();
            rc = processVoidReturn(voidReturn, "iopStop");
        }
    }
    return rc;
}

static jint
com_qualcomm_qti_performance_native_perf_lock_acq(JNIEnv *env, jobject clazz, jint handle, jint duration, jintArray list)
{
    jint listlen = env->GetArrayLength(list);
    jint buf[listlen];
    int i=0;
    int ret = 0;
    env->GetIntArrayRegion(list, 0, listlen, buf);

    ret = perf_lock_acq(handle, duration, buf, listlen);
    return ret;
}

static jint
com_qualcomm_qti_performance_native_perf_lock_rel(JNIEnv *env, jobject clazz, jint handle)
{
    int ret = 0;
    perf_lock_rel(handle);
    ret = 1;

    return ret;
}

static jint
com_qualcomm_qti_performance_native_perf_hint(JNIEnv *env, jobject clazz, jint hint, jstring j_pkg_name, jint duration, jint type)
{
    int ret = 0;
    const char * pkg_name;

    pkg_name = (j_pkg_name) ? env->GetStringUTFChars(j_pkg_name,0) : "";
    ret = perf_hint(hint, pkg_name, duration, type);
    if (j_pkg_name) env->ReleaseStringUTFChars(j_pkg_name, pkg_name);
    return ret;
}

// ----------------------------------------------------------------------------

static JNINativeMethod gMethods[] = {
    {"native_perf_lock_acq",  "(II[I)I",               (int *)com_qualcomm_qti_performance_native_perf_lock_acq},
    {"native_perf_lock_rel",  "(I)I",                  (int *)com_qualcomm_qti_performance_native_perf_lock_rel},
    {"native_perf_hint",  "(ILjava/lang/String;II)I", (int *)com_qualcomm_qti_performance_native_perf_hint},
    {"native_perf_io_prefetch_start",    "(ILjava/lang/String;Ljava/lang/String;)I",         (int *)com_qualcomm_qtiperformance_native_perf_io_prefetch_start},
    {"native_perf_io_prefetch_stop",    "()I",         (int *)com_qualcomm_qtiperformance_native_perf_io_prefetch_stop},
#if 0
    {"native_deinit",         "()V",                   (void *)com_qualcomm_qti_performance_native_deinit},
#endif
};


int register_com_qualcomm_qti_Performance(JNIEnv *env)
{
    return jniRegisterNativeMethods(env, "com/qualcomm/qti/Performance", gMethods, NELEM(gMethods));
}


/*
 * JNI Initialization
 */
jint JNI_OnLoad(JavaVM *jvm, void *reserved)
{
    JNIEnv *e;
    int status;

    ALOGV("com.qualcomm.qti.Performance: loading JNI\n");

    // Check JNI version
    if (jvm->GetEnv((void **)&e, JNI_VERSION_1_6)) {
        ALOGE("com.qualcomm.qti.Performance: JNI version mismatch error");
        return JNI_ERR;
    }

    if ((status = register_com_qualcomm_qti_Performance(e)) < 0) {
        ALOGE("com.qualcomm.qti.Performance: jni registration failure: %d", status);
        return JNI_ERR;
    }

    return JNI_VERSION_1_6;
}

