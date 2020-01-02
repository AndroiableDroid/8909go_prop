LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
MODEM_ROW_CONFIG_FILE := mcfg_sw.mbn
MODEM_ROW_CONFIG_FOLDER := $(GENERATED_PACKAGE_PATH)/TelefonicaGermany/data/modem_row_config/msm8998
$(shell mkdir -p $(MODEM_ROW_CONFIG_FOLDER))
$(shell cp -r $(LOCAL_PATH)/msm8998/$(MODEM_ROW_CONFIG_FILE) $(MODEM_ROW_CONFIG_FOLDER)/$(MODEM_ROW_CONFIG_FILE))
#########################################################################################################
