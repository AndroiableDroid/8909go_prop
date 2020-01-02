LOCAL_PATH := $(call my-dir)
PREBUILT_DIR_PATH := $(LOCAL_PATH)

ifeq ($(call is-board-platform,msm8909),true)
ifeq ($(strip $(TARGET_BOARD_SUFFIX)),)
  -include $(LOCAL_PATH)/target/product/msm8909/Android.mk
endif
endif

ifeq ($(call is-board-platform,msm8909),true)
  -include $(LOCAL_PATH)/target/product/msm8909go/Android.mk
endif

-include $(sort $(wildcard $(PREBUILT_DIR_PATH)/*/*/Android.mk))
