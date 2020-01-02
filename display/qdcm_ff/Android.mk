#/******************************************************************************
#*@file Android.mk
#*brief Rules for compiling the source files
#*******************************************************************************/

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := $(call all-subdir-java-files)

LOCAL_PACKAGE_NAME := QDCM_FF_App
LOCAL_CERTIFICATE := platform
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := qti

include $(BUILD_PACKAGE)
