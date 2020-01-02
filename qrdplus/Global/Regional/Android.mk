GENERATED_PACKAGE_PATH := $(TARGET_OUT_VENDOR)/package
ifeq (0,1)
ifneq ($(strip $(USES_REGIONALIZATION_PARTITIONS)),)
ifneq ($(strip $(USES_REGIONALIZATION_PARTITIONS)),system)
ifneq ($(strip $(USES_REGIONALIZATION_PARTITIONS)),vendor)
$(warning "Start to backup Android.mk  ")

REGIONAL_PATH := $(ANDROID_BUILD_TOP)/vendor/qcom/proprietary/qrdplus/Global/Regional

$(shell mv $(REGIONAL_PATH)/OrangeBelgium/res/Frameworks/Android.mk $(REGIONAL_PATH)/OrangeBelgium/res/Frameworks/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/OrangeMoldavia/res/Frameworks/Android.mk $(REGIONAL_PATH)/OrangeMoldavia/res/Frameworks/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/TelecomItaliaMobile/res/Frameworks/Android.mk $(REGIONAL_PATH)/TelecomItaliaMobile/res/Frameworks/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/LatamAMX/res/Frameworks/Android.mk $(REGIONAL_PATH)/LatamAMX/res/Frameworks/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/LatamTelcelMexico/res/Frameworks/Android.mk $(REGIONAL_PATH)/LatamTelcelMexico/res/Frameworks/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/CherryPhilippines/res/Frameworks/Android.mk $(REGIONAL_PATH)/CherryPhilippines/res/Frameworks/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/CherryPhilippines/res/Browser/Android.mk $(REGIONAL_PATH)/CherryPhilippines/res/Browser/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/CherryThailand/res/Frameworks/Android.mk $(REGIONAL_PATH)/CherryThailand/res/Frameworks/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/CherryThailand/res/Browser/Android.mk $(REGIONAL_PATH)/CherryThailand/res/Browser/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/CherryMyanmar/res/Frameworks/Android.mk $(REGIONAL_PATH)/CherryMyanmar/res/Frameworks/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/CherryMyanmar/res/Browser/Android.mk $(REGIONAL_PATH)/CherryMyanmar/res/Browser/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/CherryLaos/res/Frameworks/Android.mk $(REGIONAL_PATH)/CherryLaos/res/Frameworks/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/CherryLaos/res/Browser/Android.mk $(REGIONAL_PATH)/CherryLaos/res/Browser/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/CherryCambodia/res/Frameworks/Android.mk $(REGIONAL_PATH)/CherryCambodia/res/Frameworks/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/CherryCambodia/res/Browser/Android.mk $(REGIONAL_PATH)/CherryCambodia/res/Browser/Android.mk.bak)
$(shell mv $(REGIONAL_PATH)/CherryCommon/res/WallpaperPicker/Android.mk $(REGIONAL_PATH)/CherryCommon/res/WallpaperPicker/Android.mk.bak)


# For Clean
CleanPollution: InstallCarrier
	@echo "#### Start to clean backup Android.mk! ####"
	@if [ -f "$(REGIONAL_PATH)/OrangeBelgium/res/Frameworks/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/OrangeBelgium/res/Frameworks/Android.mk.bak $(REGIONAL_PATH)/OrangeBelgium/res/Frameworks/Android.mk ;\
    fi
	@if [ -f "$(REGIONAL_PATH)/OrangeMoldavia/res/Frameworks/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/OrangeMoldavia/res/Frameworks/Android.mk.bak $(REGIONAL_PATH)/OrangeMoldavia/res/Frameworks/Android.mk ;\
    fi
	@if [ -f "$(REGIONAL_PATH)/TelecomItaliaMobile/res/Frameworks/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/TelecomItaliaMobile/res/Frameworks/Android.mk.bak $(REGIONAL_PATH)/TelecomItaliaMobile/res/Frameworks/Android.mk ;\
    fi
	@if [ -f "$(REGIONAL_PATH)/CherryPhilippines/res/Frameworks/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/CherryPhilippines/res/Frameworks/Android.mk.bak $(REGIONAL_PATH)/CherryPhilippines/res/Frameworks/Android.mk ;\
    fi
	@if [ -f "$(REGIONAL_PATH)/CherryPhilippines/res/Browser/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/CherryPhilippines/res/Browser/Android.mk.bak $(REGIONAL_PATH)/CherryPhilippines/res/Browser/Android.mk ;\
    fi
	@if [ -f "$(REGIONAL_PATH)/CherryThailand/res/Frameworks/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/CherryThailand/res/Frameworks/Android.mk.bak $(REGIONAL_PATH)/CherryThailand/res/Frameworks/Android.mk ;\
    fi
	@if [ -f "$(REGIONAL_PATH)/CherryThailand/res/Browser/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/CherryThailand/res/Browser/Android.mk.bak $(REGIONAL_PATH)/CherryThailand/res/Browser/Android.mk ;\
    fi
	@if [ -f "$(REGIONAL_PATH)/CherryMyanmar/res/Frameworks/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/CherryMyanmar/res/Frameworks/Android.mk.bak $(REGIONAL_PATH)/CherryMyanmar/res/Frameworks/Android.mk ;\
    fi
	@if [ -f "$(REGIONAL_PATH)/CherryMyanmar/res/Browser/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/CherryMyanmar/res/Browser/Android.mk.bak $(REGIONAL_PATH)/CherryMyanmar/res/Browser/Android.mk ;\
    fi
	@if [ -f "$(REGIONAL_PATH)/CherryLaos/res/Frameworks/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/CherryLaos/res/Frameworks/Android.mk.bak $(REGIONAL_PATH)/CherryLaos/res/Frameworks/Android.mk ;\
    fi
	@if [ -f "$(REGIONAL_PATH)/CherryLaos/res/Browser/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/CherryLaos/res/Browser/Android.mk.bak $(REGIONAL_PATH)/CherryLaos/res/Browser/Android.mk ;\
    fi
	@if [ -f "$(REGIONAL_PATH)/CherryCambodia/res/Frameworks/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/CherryCambodia/res/Frameworks/Android.mk.bak $(REGIONAL_PATH)/CherryCambodia/res/Frameworks/Android.mk ;\
    fi
	@if [ -f "$(REGIONAL_PATH)/CherryCambodia/res/Browser/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/CherryCambodia/res/Browser/Android.mk.bak $(REGIONAL_PATH)/CherryCambodia/res/Browser/Android.mk ;\
    fi
	@if [ -f "$(REGIONAL_PATH)/CherryCommon/res/WallpaperPicker/Android.mk.bak" ] ; then \
        mv $(REGIONAL_PATH)/CherryCommon/res/WallpaperPicker/Android.mk.bak $(REGIONAL_PATH)/CherryCommon/res/WallpaperPicker/Android.mk ;\
    fi
systemimage: CleanPollution
endif
endif
endif
endif

ifeq ($(strip $(TARGET_USES_QTIC_REGIONAL)),true)
REGIONAL_PATH := $(call my-dir)
$(warning $(shell $(REGIONAL_PATH)/carrier_spec_config_parser.py -nl))
#include $(call all-subdir-makefiles)
include $(REGIONAL_PATH)/EUCommon/Android.mk
include $(REGIONAL_PATH)/VodafoneGroup/Android.mk
include $(REGIONAL_PATH)/VodafoneUK/Android.mk
include $(REGIONAL_PATH)/TelefonicaGermany/Android.mk
endif

#PresetPackList := Default ChinaUnicom ChinaTelecom ChinaMobile CmccPower CTA Cambodia DTAustria DTCommon DTCroazia DTCzech DTGermany DTGreece DTHungary DTMacedonia DTMontenegro DTNetherlands DTPoland DTRomania DTSlovakia EEUK EUCommon IndonesiaOpenmarket Laos LatamBrazil LatamTelefonica LatamTelefonicaArgentina LatamTelefonicaBrazil LatamTelefonicaChile LatamTelefonicaColombia LatamTelefonicaCostaRica LatamTelefonicaEcuador LatamTelefonicaElSalvador LatamTelefonicaGuatemala LatamTelefonicaMexico LatamTelefonicaNicaragua LatamTelefonicaPanama LatamTelefonicaPeru LatamTelefonicaUruguay LatamTelefonicaVenezuela MalaysiaOpenMarket NorthAmerica PhilippinesOpenMarket RussiaOpen TelefonicaGermany TelefonicaSpain ThailandOpenMarket TurkeyOpen VodafoneGermany VodafoneUK
PresetPackList := Default ChinaMobile ChinaUnicom ChinaTelecom CTA EUCommon VodafoneUK VodafoneGroup TelefonicaGermany

#Preset Regional packs for perf build
PresetPacksToPerf: $(INTERNAL_BOOTIMAGE_FILES)
	@for path in `find $(GENERATED_PACKAGE_PATH) -name ".preloadspec"` ; do \
       tmp="$${path%\/.preloadspec}" ;\
       pack="$${tmp##*\/}" ;\
       if [ "$$pack" != "" ] ; then \
         flag="del" ;\
         for presetpack in $(PresetPackList) ; do \
           if [ "$$presetpack" == "$$pack" ] ; then \
             echo "Keep $(GENERATED_PACKAGE_PATH)/$$pack for perf ..." ;\
             flag="keep" ;\
             break ;\
           fi ;\
         done ;\
         if [ "$$flag" != "keep" ] ; then \
           echo "Remove $(GENERATED_PACKAGE_PATH)/$$pack for perf ..." ;\
           rm -rvf $(GENERATED_PACKAGE_PATH)/$$pack ;\
        fi ;\
       fi ;\
     done

ifneq ($(strip $(filter %perf_defconfig,$(KERNEL_DEFCONFIG))),)
bootimage: PresetPacksToPerf
endif
