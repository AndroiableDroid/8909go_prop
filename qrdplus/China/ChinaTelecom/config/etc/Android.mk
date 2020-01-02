LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

#################################################
SPEC_HOSTS := hosts
$(shell mkdir -p $(GENERATED_PACKAGE_PATH)/ChinaTelecom/system/vendor/)
$(shell cp -r $(LOCAL_PATH)/$(SPEC_PROP) $(GENERATED_PACKAGE_PATH)/ChinaTelecom/system/vendor/$(SPEC_HOSTS))
