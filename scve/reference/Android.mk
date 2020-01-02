REFERENCE_ROOT := $(call my-dir)

#include $(REFERENCE_ROOT)/CleverCapture/Android.mk
#include $(REFERENCE_ROOT)/ImageStudio/Android.mk
include $(REFERENCE_ROOT)/ObjectTracker/Android.mk
include $(REFERENCE_ROOT)/Panorama/Android.mk

SCVE_NO_SOCIALCAMERA_APK_TARGET := msm8937 msm8953 msm8996 sdm845
ifneq ($(call is-board-platform-in-list,$(SCVE_NO_SOCIALCAMERA_APK_TARGET)),true)
	include $(REFERENCE_ROOT)/SocialCamera/Android.mk
endif

#include $(REFERENCE_ROOT)/TextReco/Android.mk

#SCVE_VIDEOSUMMARY_APK_TARGET := msm8998 sdm660 sdm845
#ifeq ($(call is-board-platform-in-list,$(SCVE_VIDEOSUMMARY_APK_TARGET)),true)
#   include $(REFERENCE_ROOT)/VideoSummary/Android.mk
#endif

#ifeq ($(call is-board-platform-in-list,sdm845),true)
#   include $(REFERENCE_ROOT)/3DScanner/Android.mk
#endif
