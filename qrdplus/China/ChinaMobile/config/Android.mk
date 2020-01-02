# Disable this makefile, After verify all commands can work, please remove the ifeq condition
ifeq (1,1)
CURRENT_PATH := $(call my-dir)

PRE_LOAD_SPEC := .preloadspec
$(shell mkdir -p $(GENERATED_PACKAGE_PATH)/ChinaMobile)
$(shell cp -r $(CURRENT_PATH)/$(PRE_LOAD_SPEC) $(GENERATED_PACKAGE_PATH)/ChinaMobile/$(PRE_LOAD_SPEC))

#################################################
EXCLUDE_LIST := exclude.list
$(shell mkdir -p $(GENERATED_PACKAGE_PATH)/ChinaMobile)
$(shell cp -r $(CURRENT_PATH)/$(EXCLUDE_LIST) $(GENERATED_PACKAGE_PATH)/ChinaMobile/$(EXCLUDE_LIST))

include $(call all-subdir-makefiles)
endif
