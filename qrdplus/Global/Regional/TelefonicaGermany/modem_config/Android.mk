LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

#################################################
#LOCAL_MODULE := mcfg_sw.mbn
#LOCAL_SRC_FILES := $(LOCAL_MODULE)
#LOCAL_MODULE_CLASS := TelefonicaGermany
#LOCAL_MODULE_PATH := $(GENERATED_PACKAGE_PATH)/TelefonicaGermany/data/modem_config

include $(CLEAR_VARS)
MODEM_CONFIG_FILE := mcfg_sw.mbn
MODEM_CONFIG_FOLDER := $(GENERATED_PACKAGE_PATH)/TelefonicaGermany/data/modem_config/msm8998
$(shell mkdir -p $(MODEM_CONFIG_FOLDER))
$(shell cp -r $(LOCAL_PATH)/msm8998/$(MODEM_CONFIG_FILE) $(MODEM_CONFIG_FOLDER)/$(MODEM_CONFIG_FILE))
