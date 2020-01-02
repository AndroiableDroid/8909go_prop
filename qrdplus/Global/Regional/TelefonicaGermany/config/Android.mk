LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

#################################################
PRE_LOAD_SPEC := .preloadspec
$(shell mkdir -p $(GENERATED_PACKAGE_PATH)/TelefonicaGermany)
$(shell cp -r $(LOCAL_PATH)/$(PRE_LOAD_SPEC) $(GENERATED_PACKAGE_PATH)/TelefonicaGermany/$(PRE_LOAD_SPEC))

#################################################
SPEC_PROP := vendor.prop
$(shell mkdir -p $(GENERATED_PACKAGE_PATH)/TelefonicaGermany/system/vendor/)
$(shell cp -r $(LOCAL_PATH)/$(SPEC_PROP) $(GENERATED_PACKAGE_PATH)/TelefonicaGermany/system/vendor/$(SPEC_PROP))
