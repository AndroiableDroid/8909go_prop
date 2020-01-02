ifeq ($(call is-board-platform-in-list, msm8998 sdm845 msm8953 msm8937 sdm660 msm8996),true)

ifeq ($(KMGK_USE_QTI_SERVICE),true)
LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include \
                    $(TARGET_OUT_HEADERS)/common/inc \
                    $(TOP)/vendor/qcom/proprietary/securemsm/keymaster_utils \
                    $(TOP)/hardware/libhardware/include/hardware \
                    $(TOP)/vendor/qcom/proprietary/securemsm/QSEEComAPI \

LOCAL_SHARED_LIBRARIES := \
        libc \
        liblog \
        libcutils \
        libutils \
        libdl \
        libhardware \
        libkeymasterprovision \
        libkeymasterutils \
        libkeymasterdeviceutils \

LOCAL_MODULE := SoterProvisioningTool
LOCAL_SRC_FILES := SoterProvisioningTool.cpp
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_OWNER := qti

LOCAL_PROPRIETARY_MODULE := true
LOCAL_ADDITIONAL_DEPENDENCIES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr
include $(BUILD_EXECUTABLE)
endif #ifeq ($(KMGK_USE_QTI_SERVICE),true)

endif #end filter
