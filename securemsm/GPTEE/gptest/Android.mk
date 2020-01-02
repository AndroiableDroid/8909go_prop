LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/../inc \
    $(TARGET_OUT_HEADERS)/common/inc

LOCAL_SHARED_LIBRARIES := \
        libc \
        libcutils \
        libutils \
        liblog \
        libGPTEE_system

LOCAL_MODULE         := gptest
LOCAL_SRC_FILES      := gptest.c
LOCAL_MODULE_TAGS    := tests
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_OWNER   := qti
LOCAL_32_BIT_ONLY    := true

include $(BUILD_NATIVE_TEST)
