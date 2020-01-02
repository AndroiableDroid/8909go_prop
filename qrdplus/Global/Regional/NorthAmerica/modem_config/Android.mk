LOCAL_PATH := $(call my-dir)

ifeq ($(TARGET_BOARD_PLATFORM),msm8937)

include $(CLEAR_VARS)
MODEM_CONFIG_FILE := mcfg_sw.mbn
MODEM_CONFIG_FOLDER := $(TARGET_OUT)/vendor/NorthAmerica/data/modem_config/msm8917
$(shell mkdir -p $(MODEM_CONFIG_FOLDER))
$(shell cp -r $(LOCAL_PATH)/msm8917/$(MODEM_CONFIG_FILE) $(MODEM_CONFIG_FOLDER)/$(MODEM_CONFIG_FILE))

include $(CLEAR_VARS)
MODEM_CONFIG_FILE := mcfg_sw.mbn
MODEM_CONFIG_FOLDER := $(TARGET_OUT)/vendor/NorthAmerica/data/modem_config/msm8937
$(shell mkdir -p $(MODEM_CONFIG_FOLDER))
$(shell cp -r $(LOCAL_PATH)/msm8937/$(MODEM_CONFIG_FILE) $(MODEM_CONFIG_FOLDER)/$(MODEM_CONFIG_FILE))

include $(CLEAR_VARS)
MODEM_CONFIG_FILE := mcfg_sw.mbn
MODEM_CONFIG_FOLDER := $(TARGET_OUT)/vendor/NorthAmerica/data/modem_config/msm8940
$(shell mkdir -p $(MODEM_CONFIG_FOLDER))
$(shell cp -r $(LOCAL_PATH)/msm8940/$(MODEM_CONFIG_FILE) $(MODEM_CONFIG_FOLDER)/$(MODEM_CONFIG_FILE))

endif

