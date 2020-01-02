LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

#################################################
SPEC_PROP := vendor.prop
$(shell mkdir -p $(GENERATED_PACKAGE_PATH)/ChinaMobile/system/vendor/)
$(shell cp -r $(LOCAL_PATH)/$(SPEC_PROP) $(GENERATED_PACKAGE_PATH)/ChinaMobile/system/vendor/$(SPEC_PROP))
