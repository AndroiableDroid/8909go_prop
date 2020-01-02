#include $(call all-subdir-makefiles)
BASE_PATH := $(call my-dir)
include $(BASE_PATH)/Mms/Android.mk
include $(BASE_PATH)/SystemUI/Android.mk
include $(BASE_PATH)/SettingsProvider/Android.mk
include $(BASE_PATH)/NetworkSetting/Android.mk
