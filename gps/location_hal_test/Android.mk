
LOCAL_PATH:=$(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    location_hal_test.cpp

LOCAL_CFLAGS:= \
    -DDEBUG \
    -D_ANDROID_ \

LOCAL_HEADER_LIBRARIES := \
    libgps.utils_headers

LOCAL_SHARED_LIBRARIES := \
    libutils \
    libcutils \
    liblog \
    libgps.utils \
    libhardware

LOCAL_MODULE:=location_hal_test
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_EXECUTABLE)

