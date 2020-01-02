
PRODUCT_PACKAGES += \
    CmccPowerFrameworksRes \
    CmccPowerCamera2Res \
    CmccPowerSettingsProviderRes \
    CmccSettingsProviderRes \
    10086cn \
    CmccCustomerService \
    CmccDialerRes \
    ChinaMobileFrameworksRes \
    CmccGallery2Res \
    CmccMmsRes \
    CmccMusicRes \
    CmccBrowserRes \
    CmccSettingsRes \
    CmccCalculatorRes \
    CmccCalendarRes \
    CmccSystemUIRes \
    CmccDeskClockRes \
    CmccBluetoothRes \
    CmccEmailRes \
    CmccCamera2Res \
    CmccFM2Res \
    libdmjni \
    ExtWifi \
    Backup \
    CmccSnapdragonCameraRes \
    CmccQuickSearchBoxRes \
    CmccSimContactsRes \
    CmccCalLocalAccountRes \
    BatterySaver

LOCAL_PATH := vendor/qcom/proprietary/qrdplus/ChinaMobile

# include the BootAnimation's products
-include $(LOCAL_PATH)/apps/BootAnimation/products.mk
# include the modem configuration products
-include $(LOCAL_PATH)/config/modem_config/products.mk
