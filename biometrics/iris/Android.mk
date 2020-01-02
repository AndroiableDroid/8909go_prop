ifeq ($(call is-vendor-board-platform,QCOM),true)
ifeq ($(call is-board-platform-in-list,msm8998),true)

include $(call all-subdir-makefiles)

endif
endif

