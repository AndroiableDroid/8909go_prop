ifeq ($(TARGET_NO_RPC),true)

LOCAL_PATH:=$(call my-dir)
include $(CLEAR_VARS)

LOC_API_APP_PATH:=$(LOCAL_PATH)

LOC_API_DEBUG:=false

LOCAL_SRC_FILES:= \
    GardenAPIClient.cpp \
    garden_app_session_tracker.cpp \
    test_android_gps.cpp \

LOCAL_CFLAGS:= \
    -DDEBUG \
    -D_ANDROID_ \
    -DTEST_POSITION \
    -DTEST_DELETE_ASSISTANCE \
    -DTEST_POSITION \
    -DTEST_ULP

LOCAL_C_INCLUDES:= \
    $(LOCAL_PATH) \
    $(TARGET_OUT_HEADERS)/libizat_core \
    $(TARGET_OUT_HEADERS)/qmi-framework/inc \
    $(TARGET_OUT_HEADERS)/qmi/inc
LOCAL_HEADER_LIBRARIES := \
    libgps.utils_headers \
    libloc_core_headers \
    libevent_observer_headers \
    liblocationservice_headers \
    libloc_pla_headers \
    liblocation_api_headers

LOCAL_SHARED_LIBRARIES := \
    libgps.utils \
    libcutils \
    libqmi_cci \
    libqmi_csi \
    liblocationservice \
    libulp2 \
    liblog \
    libevent_observer \
    libloc_pla \
    libloc_core \
    liblocation_api \

LOCAL_PRELINK_MODULE:=false

LOCAL_MODULE:=garden_app
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := qti
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)

endif # TARGET_NO_RPC
