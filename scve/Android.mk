
#########################################################
# Make sure SCVE is enabled for msm8998 msm8953_64 sdm660
# Override that in ../common/msm8998/BoardConfigVendor.mk
# Override that in ../common/msm8953_64/BoardConfigVendor.mk
# Override that in ../common/sdm660_64/BoardConfigVendor.mk
########################################################
ifeq ($(call is-board-platform-in-list,msm8998),true)
   TARGET_SCVE_DISABLED := false
endif
ifeq ($(call is-board-platform-in-list,msm8996),true)
   TARGET_SCVE_DISABLED := false
endif
ifeq ($(call is-board-platform-in-list,msm8953),true)
   TARGET_SCVE_DISABLED := false
endif
ifeq ($(call is-board-platform-in-list,msm8937),true)
   TARGET_SCVE_DISABLED := false
endif
ifeq ($(call is-board-platform-in-list,sdm660),true)
   TARGET_SCVE_DISABLED := false
endif
ifeq ($(call is-board-platform-in-list,sdm845),true)
   TARGET_SCVE_DISABLED := false
endif

ifneq ($(TARGET_SCVE_DISABLED),true)
   include $(call all-subdir-makefiles)
endif

