ifeq ($(call is-board-platform,msm8909),true)
ifeq ($(strip $(TARGET_BOARD_SUFFIX)),)
	VENDORLIBS := libbt
	VENDORLIBS += liblocation_gnss
	PRODUCT_PACKAGES += $(VENDORLIBS)
endif
endif



