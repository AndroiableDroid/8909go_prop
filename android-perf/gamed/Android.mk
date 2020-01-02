LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    Config.cpp \
    Stats.cpp \
    ConfidenceValues.cpp \
    Input.cpp \
    WhiteLists.cpp \
    GameServer.cpp \
    GameDetection.cpp \
    GameComm.cpp

LOCAL_SHARED_LIBRARIES := \
        libcutils \
        libdl \
        liblog \
        libutils \
        libxml2 \
        libqti-util \
        libperfgluelayer

LOCAL_CFLAGS += \
    -Wall \
    -DQC_DEBUG=0

LOCAL_C_INCLUDES := external/connectivity/stlport/stlport \
                    external/libxml2/include \
                    external/icu/icu4c/source/common \
                    vendor/qcom/proprietary/android-perf/perf-util \
                    vendor/qcom/proprietary/android-perf/mp-ctl \
                    vendor/qcom/proprietary/android-perf/perf-hal

LOCAL_MODULE := libqti-gt-prop
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := GameDaemon.cpp

LOCAL_SHARED_LIBRARIES := libcutils liblog libthermalclient libqti-gt-prop libxml2

LOCAL_CFLAGS += \
        -DPERFD \

LOCAL_C_INCLUDES := external/connectivity/stlport/stlport \
                    external/libxml2/include \
                    external/icu/icu4c/source/common

LOCAL_MODULE := gamed

LOCAL_MODULE_TAGS := optional

LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_EXECUTABLE)
