ifneq ($(TARGET_NO_TELEPHONY), true)
ifneq ($(TARGET_HAS_LOW_RAM),true)

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional eng

# Only compile source java files in this apk.
LOCAL_SRC_FILES := $(call all-java-files-under, src)

LOCAL_PACKAGE_NAME := CtRoamingSettings

LOCAL_CERTIFICATE := platform

LOCAL_JAVA_LIBRARIES += telephony-common qcrilhook telephony-ext

LOCAL_MODULE_OWNER := qti

include $(BUILD_PACKAGE)

endif

endif # TARGET_NO_TELEPHONY
