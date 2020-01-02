PREBUILT_PATH := $(call my-dir)
LOCAL_PATH         := $(PREBUILT_PATH)

include $(CLEAR_VARS)
LOCAL_MODULE        := evt-sniff.cfg
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := DATA
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/data/evt-test/evt-sniff.cfg
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/data/evt-test
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/c2d2.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/c2dExt.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/CL/cl_egl.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/CL/cl_ext.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/CL/cl_ext_qcom.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/CL/cl_gl_ext.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/CL/cl_gl.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/CL/cl.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/CL/cl_platform.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/CL/opencl.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/EGL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/EGL/eglext.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/EGL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/EGL/eglextQCOM.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/EGL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/EGL/egl.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/EGL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/adreno/EGL/eglplatform.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := avenhancements
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/avenhancements/AVMetaData.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneCet.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneCom.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneConfigs.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneDefs.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/Cne.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneLog.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneMascInterface.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneMsg.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CnePermissions.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneQmi.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneResourceInfo.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneSrmDefs.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneSrm.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneSupplicantWrapper.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneTimer.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneUtils.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/CneWqeInterface.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/EventDispatcher.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/InetAddr.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/queue.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/SocketWrapperClient.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/SwimNetlinkSocket.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/common/inc/SwimSyncWrapperDefs.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/wqe/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/wqe/inc/IBitrateEstimator.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/wqe/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/wqe/inc/IWqeFactory.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/wqe/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/cne/wqe/inc/WqePolicyTypes.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := fastcv
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/fastcv/fastcvExt.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := fastcv
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/fastcv/fastcv.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := fastrpc/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/fastrpc/inc/AEEStdDef.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := fastrpc/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/fastrpc/inc/AEEStdErr.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := fastrpc/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/fastrpc/inc/remote.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := hdcp-mgr/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/hdcp-mgr/inc/hdcpmgr_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := imsvtext/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/imsvtext/include/qplog.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libDRPlugin
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libDRPlugin/DRPlugin.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libflp
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libflp/fused_location_extended.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libizat_core
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libizat_core/IzatAdapterBase.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libizat_core
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libizat_core/IzatApiBase.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libizat_core
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libizat_core/IzatApiRpc.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libizat_core
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libizat_core/IzatApiV02.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libizat_core
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libizat_core/IzatPcid.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := liblowi_client/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/liblowi_client/inc/lowi_client.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := liblowi_client/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/liblowi_client/inc/lowi_const.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := liblowi_client/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/liblowi_client/inc/lowi_defines.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := liblowi_client/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/liblowi_client/inc/lowi_mac_address.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := liblowi_client/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/liblowi_client/inc/lowi_request.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := liblowi_client/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/liblowi_client/inc/lowi_response.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := liblowi_client/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/liblowi_client/inc/lowi_scan_measurement.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := liblowi_client/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/liblowi_client/inc/lowi_ssid.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libperipheralclient/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libperipheralclient/inc/pm-service.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/qmislim_common_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/qmislim_provider_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/qmislim_qmi_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/qmislim_qmi_client_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/qmislim_qmi_dm_log_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/qmislim_qmi_monitor_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/qmislim_qmi_service_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/qmislim_task_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/sensor_location_interface_manager_v01.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/slim_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/slim_client_types.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/slim_core.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/slim_internal_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/slim_internal_client_types.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/slim_internal.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/slim_provider_conf.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/slim_provider_data.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/slim_service_status.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/slim_task.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/slim_timesync.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libslimcommon
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libslimcommon/slim_utils.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libvqzip
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libvqzip/VQZip.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libxtadapter
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/libxtadapter/XtAdapter.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-flac
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-audio/audio-flac/FLACDec_API.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-flac
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-audio/audio-flac/FLACDec_BitStream.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-flac
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-audio/audio-flac/FLACDec_MetaData.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-flac
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-audio/audio-flac/FLACDec_Struct.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-flac
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-audio/audio-flac/FLACDec_typedefs.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-flac
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-audio/audio-flac/FLACDec_Wrapper.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-listen
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-audio/audio-listen/ListenSoundModelLib.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-listen
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-audio/audio-listen/ListenSoundModelLib_types.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-listen
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-audio/audio-listen/ListenSoundModelLib_v2.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-src
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-audio/audio-src/QCT_Resampler.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/surround_sound_3mic
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-audio/surround_sound_3mic/surround_rec_interface.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-camera
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-camera/dmlrocorrection_bg_pca.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-camera
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-camera/dmlrocorrection.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-color-convertor
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-color-convertor/MMColorConvert.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-parser/include/DataSourcePort.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-parser/include/filesource.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-parser/include/filesourcetypes.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-parser/include/parserdatadef.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-parser/include/sidxparserdatatypes.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-parser/include/sidxparser.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-parser/include/SourceBase.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/fastcrc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-video/fastcrc/VideoCRCChecker.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/streamparser
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-video/streamparser/VideoStreamParser.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/swvdec
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-video/swvdec/swvdec_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/swvdec
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-video/swvdec/swvdec_types.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/swvenc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-video/swvenc/swvenc_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/swvenc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-video/swvenc/swvenc_types.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/ubwc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-video/ubwc/ubwc.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/utils
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-video/utils/list.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/utils
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/mm-video/utils/VideoComDef.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/pp/inc/aba_cabl.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/pp/inc/aba_core_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/pp/inc/aba_foss.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/pp/inc/aba_svi.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/pp/inc/aba_type.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/pp/inc/diagplatform.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/pp/inc/libmm-disp-apis.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := qdcm/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/qdcm/inc/disp_color_apis.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := qdcm/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/qdcm/inc/mode_manager.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := qdcm/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/qdcm/inc/utility.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := ui
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/ui/Blur.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := xmllib/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/xmllib/inc/xmllib_common.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := xmllib/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/xmllib/inc/xmllib_parser.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := xmllib/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909/obj/include/xmllib/inc/xmllib_tok.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdrmMinimalfs
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_SUFFIX := .a
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/obj/STATIC_LIBRARIES/libdrmMinimalfs_intermediates/libdrmMinimalfs.a
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libQSEEComAPIStatic
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_SUFFIX := .a
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/obj/STATIC_LIBRARIES/libQSEEComAPIStatic_intermediates/libQSEEComAPIStatic.a
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := librpmbStatic
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_SUFFIX := .a
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/obj/STATIC_LIBRARIES/librpmbStatic_intermediates/librpmbStatic.a
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libslimcommon
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_SUFFIX := .a
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/obj/STATIC_LIBRARIES/libslimcommon_intermediates/libslimcommon.a
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libssdStatic
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_SUFFIX := .a
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/obj/STATIC_LIBRARIES/libssdStatic_intermediates/libssdStatic.a
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := access-qcom-logkit
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/app/access-qcom-logkit/access-qcom-logkit.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := embms
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/app/embms/embms.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := EmbmsTestApp
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/app/EmbmsTestApp/EmbmsTestApp.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := FidoCryptoService
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/app/FidoCryptoService/FidoCryptoService.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := LteDirectDiscovery
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/app/LteDirectDiscovery/LteDirectDiscovery.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := ODLT
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/app/ODLT/ODLT.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := QTIDiagServices
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/app/QTIDiagServices/QTIDiagServices.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := remotesimlockservice
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/app/remotesimlockservice/remotesimlockservice.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := uimlpaservice
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/app/uimlpaservice/uimlpaservice.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := uimlpatest
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/app/uimlpatest/uimlpatest.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := dpmd
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/bin/dpmd
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/bin
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := mm-swvdec-test
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/bin/mm-swvdec-test
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/bin
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := mm-swvenc-test
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/bin/mm-swvenc-test
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/bin
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := remote_debug_agent
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/bin/remote_debug_agent
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/bin
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := andsfCne.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/cne/andsfCne.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/cne
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := SwimConfig.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/cne/SwimConfig.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/cne
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := dpm.conf
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/dpm/dpm.conf
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/dpm
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := NsrmConfiguration.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/dpm/nsrm/NsrmConfiguration.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/dpm/nsrm
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := dpmd.rc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/init/dpmd.rc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/init
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := cneapiclient.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/permissions/cneapiclient.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/permissions
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.qti.dpmframework.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/permissions/com.qti.dpmframework.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/permissions
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.qualcomm.qmapbridge.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/permissions/com.qualcomm.qmapbridge.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/permissions
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.qualcomm.qti.izattools.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/permissions/com.qualcomm.qti.izattools.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/permissions
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.quicinc.cne.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/permissions/com.quicinc.cne.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/permissions
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := dpmapi.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/permissions/dpmapi.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/permissions
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := embms.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/permissions/embms.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/permissions
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := izat.xt.srv.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/permissions/izat.xt.srv.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/permissions
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qcom_logkit.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/permissions/qcom_logkit.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/permissions
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := UimService.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/etc/permissions/UimService.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/permissions
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.qualcomm.qti.dpm.api@1.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/com.qualcomm.qti.dpm.api@1.0.so
include $(BUILD_PREBUILT)

ifeq ($(wildcard vendor/qcom/proprietary/wfd-framework),)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.qualcomm.qti.wifidisplayhal@1.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/com.qualcomm.qti.wifidisplayhal@1.0.so
include $(BUILD_PREBUILT)
endif

include $(CLEAR_VARS)
LOCAL_MODULE        := libadsprpc_system
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libadsprpc_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libavenhancements
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libavenhancements.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libcdsprpc_system
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libcdsprpc_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libDiagService
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libDiagService.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdpmctmgr
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libdpmctmgr.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdpmfdmgr
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libdpmfdmgr.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdpmframework
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libdpmframework.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdpmnsrm
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libdpmnsrm.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdpmtcm
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libdpmtcm.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        :=  libfastcvadsp_stub_system
LOCAL_INSTALLED_MODULE_STEM := libfastcvadsp_stub.so
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libfastcvadsp_stub.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        :=  libfastcvopt_system
LOCAL_INSTALLED_MODULE_STEM := libfastcvopt.so
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libfastcvopt.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libGPTEE_system
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libGPTEE_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-imsvtextutils
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/lib-imsvtextutils.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-imsvt
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/lib-imsvt.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-imsvtutils
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/lib-imsvtutils.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := liblistensoundmodel2
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/liblistensoundmodel2.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmdsprpc_system
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libmdsprpc_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmparser_lite
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libmmparser_lite.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libqct_resampler
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libqct_resampler.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libQTEEConnector_system
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libQTEEConnector_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := librcc
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/librcc.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsdm-disp-apis
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libsdm-disp-apis.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsdsprpc_system
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libsdsprpc_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsecureuisvc_jni
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libsecureuisvc_jni.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsecureui_svcsock_system
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libsecureui_svcsock_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libvendorconn
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libvendorconn.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libvr_amb_engine
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libvr_amb_engine.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libvraudio
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libvraudio.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libvr_object_engine
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libvr_object_engine.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libvr_sam_wrapper
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libvr_sam_wrapper.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libxt_native
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/libxt_native.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        :=  libapps_mem_heap_system
LOCAL_INSTALLED_MODULE_STEM := libapps_mem_heap.so
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/rfsa/adsp/libapps_mem_heap.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        :=  libdspCV_skel_system
LOCAL_INSTALLED_MODULE_STEM := libdspCV_skel.so
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/rfsa/adsp/libdspCV_skel.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        :=  libfastcvadsp_skel_system
LOCAL_INSTALLED_MODULE_STEM := libfastcvadsp_skel.so
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/rfsa/adsp/libfastcvadsp_skel.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        :=  libfastcvadsp_system
LOCAL_INSTALLED_MODULE_STEM := libfastcvadsp.so
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/rfsa/adsp/libfastcvadsp.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.improvetouch.blobmanager@1.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/vendor.qti.hardware.improvetouch.blobmanager@1.0.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.improvetouch.gesturemanager@1.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/vendor.qti.hardware.improvetouch.gesturemanager@1.0.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.improvetouch.touchcompanion@1.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/vendor.qti.hardware.improvetouch.touchcompanion@1.0.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.imsrtpservice@1.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/lib/vendor.qti.imsrtpservice@1.0.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := CNEService
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/priv-app/CNEService/CNEService.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/priv-app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := dpmserviceapp
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/priv-app/dpmserviceapp/dpmserviceapp.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/priv-app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := xtra_t_app
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/system/priv-app/xtra_t_app/xtra_t_app.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/priv-app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := CABLService
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/app/CABLService/CABLService.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := improveTouchStudio
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/app/improveTouchStudio/improveTouchStudio.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := QDMA
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/app/QDMA/QDMA.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := QDMA-UI
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/app/QDMA-UI/QDMA-UI.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qti-logkit
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/app/qti-logkit/qti-logkit.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := SVIService
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/app/SVIService/SVIService.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := adsprpcd
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/adsprpcd
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := audioflacapp
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/audioflacapp
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := cnd
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/cnd
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := dpmQmiMgr
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/dpmQmiMgr
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := DR_AP_Service
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/DR_AP_Service
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := hbtp_daemon
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/hbtp_daemon
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := hdcp1prov
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/hdcp1prov
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := hdcp2p2prov
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/hdcp2p2prov
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := hvdcp_opti
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/hvdcp_opti
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := android.hardware.gatekeeper@1.0-service-qti
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/hw/android.hardware.gatekeeper@1.0-service-qti
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin/hw
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := android.hardware.keymaster@3.0-service-qti
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/hw/android.hardware.keymaster@3.0-service-qti
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin/hw
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.display.color@1.0-service
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/hw/vendor.display.color@1.0-service
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin/hw
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.qteeconnector@1.0-service
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/hw/vendor.qti.hardware.qteeconnector@1.0-service
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin/hw
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := imsdatadaemon
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/imsdatadaemon
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := imsqmidaemon
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/imsqmidaemon
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := imsrcsd
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/imsrcsd
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := ims_rtp_daemon
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/ims_rtp_daemon
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := LKCore
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/LKCore
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lowi-server
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/lowi-server
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lowi_test
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/lowi_test
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := pm-proxy
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/pm-proxy
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := pm-service
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/pm-service
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qcom-system-daemon
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/qcom-system-daemon
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := tftp_server
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/tftp_server
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vm_bms
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/vm_bms
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := xtra-daemon
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/xtra-daemon
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := xtwifi-client
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/xtwifi-client
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := xtwifi-inet-agent
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/bin/xtwifi-inet-agent
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := cacert_location.pem
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/cacert_location.pem
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := drc_cfg_5.1.txt
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/drc/drc_cfg_5.1.txt
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/drc
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := drc_cfg_AZ.txt
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/drc/drc_cfg_AZ.txt
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/drc
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := hbtpcfg_8917.dat
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/hbtp/hbtpcfg_8917.dat
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/hbtp
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := hbtpcfg.dat
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/hbtp/hbtpcfg.dat
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/hbtp
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qtc800s_dsp.bin
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/hbtp/qtc800s_dsp.bin
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/hbtp
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := android.hardware.gatekeeper@1.0-service-qti.rc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/init/android.hardware.gatekeeper@1.0-service-qti.rc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/init
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := android.hardware.keymaster@3.0-service-qti.rc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/init/android.hardware.keymaster@3.0-service-qti.rc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/init
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.display.color@1.0-service.rc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/init/vendor.display.color@1.0-service.rc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/init
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.qteeconnector@1.0-service.rc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/init/vendor.qti.hardware.qteeconnector@1.0-service.rc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/init
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lowi.conf
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/lowi.conf
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := audiobasic.dmc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/qti-logkit/audiobasic.dmc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := gnsslocationlogging.dmc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/qti-logkit/gnsslocationlogging.dmc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := goldenlogmask.dmc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/qti-logkit/goldenlogmask.dmc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := IMS.dmc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/qti-logkit/IMS.dmc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qti_logkit_command.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/qti-logkit/qti_logkit_command.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qti_logkit_config.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/qti-logkit/qti_logkit_config.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := bluetooth.png
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/qti-logkit/scenarios/bluetooth.png
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit/scenarios
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := default.png
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/qti-logkit/scenarios/default.png
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit/scenarios
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := IMS.png
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/qti-logkit/scenarios/IMS.png
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit/scenarios
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qvrservice_6dof_config.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/qvr/qvrservice_6dof_config.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qvr
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qvrservice_config.txt
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/qvr/qvrservice_config.txt
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qvr
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := surround_sound_rec_5.1.cfg
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/surround_sound_3mic/surround_sound_rec_5.1.cfg
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/surround_sound_3mic
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := surround_sound_rec_AZ.cfg
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/surround_sound_3mic/surround_sound_rec_AZ.cfg
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/surround_sound_3mic
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := xtra_root_cert.pem
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/xtra_root_cert.pem
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := xtwifi.conf
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/etc/xtwifi.conf
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a225p5_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a225p5_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a225_pfp.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a225_pfp.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a225_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a225_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a300_pfp.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a300_pfp.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a300_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a300_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a330_pfp.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a330_pfp.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a330_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a330_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a420_pfp.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a420_pfp.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a420_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a420_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530_gpmu.fw2
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a530_gpmu.fw2
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530_pfp.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a530_pfp.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a530_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530v1_pfp.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a530v1_pfp.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530v1_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a530v1_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530v2_seq.fw2
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a530v2_seq.fw2
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530v3_gpmu.fw2
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a530v3_gpmu.fw2
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530v3_seq.fw2
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a530v3_seq.fw2
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a540_gpmu.fw2
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/a540_gpmu.fw2
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := leia_pfp_470.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/leia_pfp_470.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := leia_pm4_470.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/leia_pm4_470.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := venus.b00
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/venus.b00
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := venus.b01
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/venus.b01
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := venus.b02
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/venus.b02
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := venus.b03
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/venus.b03
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := venus.b04
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/venus.b04
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := venus.mbn
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/venus.mbn
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := venus.mdt
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/firmware/venus.mdt
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.qualcomm.qti.dpm.api@1.0_vendor
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/com.qualcomm.qti.dpm.api@1.0_vendor.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

ifeq ($(wildcard vendor/qcom/proprietary/wfd-framework),)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.qualcomm.qti.wifidisplayhal@1.0-impl
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/com.qualcomm.qti.wifidisplayhal@1.0-impl.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)
endif

ifeq ($(wildcard vendor/qcom/proprietary/wfd-framework),)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.qualcomm.qti.wifidisplayhal@1.0_vendor
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/com.qualcomm.qti.wifidisplayhal@1.0_vendor.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)
endif

include $(CLEAR_VARS)
LOCAL_MODULE        := com.quicinc.cne.api@1.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/com.quicinc.cne.api@1.0.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.quicinc.cne.constants@1.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/com.quicinc.cne.constants@1.0.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.quicinc.cne.constants@2.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/com.quicinc.cne.constants@2.0.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.quicinc.cne.server@1.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/com.quicinc.cne.server@1.0.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.quicinc.cne.server@2.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/com.quicinc.cne.server@2.0.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := eglsubAndroid
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/egl/eglsubAndroid.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/egl
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libEGL_adreno
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/egl/libEGL_adreno.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/egl
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libGLESv1_CM_adreno
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/egl/libGLESv1_CM_adreno.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/egl
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libGLESv2_adreno
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/egl/libGLESv2_adreno.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/egl
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libq3dtools_adreno
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/egl/libq3dtools_adreno.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/egl
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := android.hardware.gatekeeper@1.0-impl-qti
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/hw/android.hardware.gatekeeper@1.0-impl-qti.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/hw
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := android.hardware.keymaster@3.0-impl-qti
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/hw/android.hardware.keymaster@3.0-impl-qti.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/hw
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := gatekeeper.msm8909
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/hw/gatekeeper.msm8909.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/hw
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := keystore.msm8909
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/hw/keystore.msm8909.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/hw
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.qteeconnector@1.0-impl
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/hw/vendor.qti.hardware.qteeconnector@1.0-impl.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/hw
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libadm
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libadm.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libadpcmdec
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libadpcmdec.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libadreno_utils
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libadreno_utils.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libadsp_default_listener
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libadsp_default_listener.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libadsprpc
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libadsprpc.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libAlacSwDec
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libAlacSwDec.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libalarmservice_jni
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libalarmservice_jni.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libApeSwDec
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libApeSwDec.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libbccQTI
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libbccQTI.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libC2D2
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libC2D2.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libc2d30-a3xx
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libc2d30-a3xx.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libc2d30-a4xx
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libc2d30-a4xx.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libc2d30-a5xx
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libc2d30-a5xx.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libCB
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libCB.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libcdsprpc
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libcdsprpc.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libchromaflash
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libchromaflash.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libcneapiclient
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libcneapiclient.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libcne
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libcne.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdiagbridge
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libdiagbridge.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdisp-aba
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libdisp-aba.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdme_main
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libdme_main.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-dplmedia
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib-dplmedia.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdpmqmihal
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libdpmqmihal.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdrc
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libdrc.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdrmfs
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libdrmfs.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdrmtime
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libdrmtime.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdrplugin_client
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libdrplugin_client.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib_drplugin_server
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib_drplugin_server.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libDRPlugin
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libDRPlugin.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdsd2pcm
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libdsd2pcm.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libfastcrc
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libfastcrc.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libfastcvadsp_stub
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libfastcvadsp_stub.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libfastcvopt
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libfastcvopt.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libfastrpc_utf_stub
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libfastrpc_utf_stub.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libFIDOKeyProvisioning
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libFIDOKeyProvisioning.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libFlacSwDec
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libFlacSwDec.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libflp
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libflp.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libgdtap
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libgdtap.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libgeofence
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libgeofence.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libGPreqcancel
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libGPreqcancel.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libGPreqcancel_svc
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libGPreqcancel_svc.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libGPTEE_vendor
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libGPTEE_vendor.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libgsl
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libgsl.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libhbtpclient
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libhbtpclient.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libhbtpdsp
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libhbtpdsp.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libhbtpfrmwk
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libhbtpfrmwk.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libhdcp1prov
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libhdcp1prov.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libhdcp2p2prov
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libhdcp2p2prov.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libhdr_tm
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libhdr_tm.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libI420colorconvert
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libI420colorconvert.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-imscmservice
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib-imscmservice.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-imsdpl
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib-imsdpl.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-imsqimf
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib-imsqimf.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-imsrcs-v2
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib-imsrcs-v2.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-imsSDP
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib-imsSDP.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-imsxml
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib-imsxml.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libizat_core
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libizat_core.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libkeymasterdeviceutils
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libkeymasterdeviceutils.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libkeymasterprovision
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libkeymasterprovision.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libllvm-qcom
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libllvm-qcom.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libloc2jnibridge
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libloc2jnibridge.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libloc_externalDr
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libloc_externalDr.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := liblowi_client
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/liblowi_client.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := liblowi_wifihal
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/liblowi_wifihal.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmdsprpc
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmdsprpc.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera2_frame_algorithm
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera2_frame_algorithm.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera2_is
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera2_is.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera2_q3a_core
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera2_q3a_core.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera2_stats_algorithm
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera2_stats_algorithm.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera_chromaflash_lib
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera_chromaflash_lib.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera_hdr_gb_lib
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera_hdr_gb_lib.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libQuecService
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../../.././quec-server/libQuecService.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/vendor/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera_hdr_lib
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera_hdr_lib.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera_optizoom_lib
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera_optizoom_lib.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera_pdafcamif
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera_pdafcamif.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera_pdaf
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera_pdaf.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera_tintless_algo
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera_tintless_algo.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera_tintless_bg_pca_algo
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera_tintless_bg_pca_algo.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera_trueportrait_lib
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera_trueportrait_lib.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera_ubifocus_lib
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera_ubifocus_lib.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmcamera_wavelet_lib
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmmcamera_wavelet_lib.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmm-color-convertor
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmm-color-convertor.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmm-disp-apis
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmm-disp-apis.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmm-hdcpmgr
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmm-hdcpmgr.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmm-qdcm
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libmm-qdcm.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libMpeg4SwEncoder
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libMpeg4SwEncoder.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libOmxAlacDecSw
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libOmxAlacDecSw.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libOmxApeDecSw
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libOmxApeDecSw.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libOmxDsdDec
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libOmxDsdDec.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libOmxEvrcDec
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libOmxEvrcDec.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libOmxQcelp13Dec
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libOmxQcelp13Dec.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libOpenCL
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libOpenCL.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := liboptizoom
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/liboptizoom.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libperipheral_client
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libperipheral_client.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libpvr
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libpvr.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libqisl
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libqisl.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libQSEEComAPI
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libQSEEComAPI.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libQTEEConnector_vendor
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libQTEEConnector_vendor.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libquipc_os_api
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libquipc_os_api.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libqvrservice_client
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libqvrservice_client.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := librmp
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/librmp.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := librpmb
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/librpmb.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := librs_adreno_sha1
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/librs_adreno_sha1.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := librs_adreno
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/librs_adreno.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libRSDriver_adreno
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libRSDriver_adreno.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-rtpcommon
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib-rtpcommon.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-rtpcore
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib-rtpcore.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-rtpdaemoninterface
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib-rtpdaemoninterface.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-rtpsl
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib-rtpsl.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsc-a2xx
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libsc-a2xx.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsc-a3xx
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libsc-a3xx.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libscalar
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libscalar.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsdm-color
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libsdm-color.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsdm-diag
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libsdm-diag.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsdm-disp-vndapis
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libsdm-disp-vndapis.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsdmextension
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libsdmextension.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsdsprpc
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libsdsprpc.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libSecureUILib
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libSecureUILib.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsecureui
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libsecureui.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsecureui_svcsock
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libsecureui_svcsock.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-siputility
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib-siputility.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libssd
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libssd.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libstreamparser
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libstreamparser.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsubsystem_control
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libsubsystem_control.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libSubSystemShutdown
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libSubSystemShutdown.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsurround_3mic_proc
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libsurround_3mic_proc.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libswvdec
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libswvdec.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libtinyxml2_1
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libtinyxml2_1.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libtrueportrait
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libtrueportrait.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libubifocus
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libubifocus.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libUBWC
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libUBWC.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-uceservice
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/lib-uceservice.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libUserAgent
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libUserAgent.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libvideoutils
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libvideoutils.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libvqzip
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libvqzip.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libwms
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libwms.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libwqe
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libwqe.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libxml
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libxml.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libxtadapter
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libxtadapter.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libxtwifi_ulp_adaptor
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/libxtwifi_ulp_adaptor.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libapps_mem_heap
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/rfsa/adsp/libapps_mem_heap.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/rfsa/adsp
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdspCV_skel
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/rfsa/adsp/libdspCV_skel.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/rfsa/adsp
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libfastcvadsp_skel
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/rfsa/adsp/libfastcvadsp_skel.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/rfsa/adsp
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libfastcvadsp
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/rfsa/adsp/libfastcvadsp.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/rfsa/adsp
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libFastRPC_AUE_Forward_skel
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/rfsa/adsp/libFastRPC_AUE_Forward_skel.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/rfsa/adsp
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libFastRPC_UTF_Forward_skel
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/rfsa/adsp/libFastRPC_UTF_Forward_skel.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/rfsa/adsp
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libqcbassboost
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/soundfx/libqcbassboost.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/soundfx
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libqcreverb
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/soundfx/libqcreverb.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/soundfx
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libqcvirt
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/soundfx/libqcvirt.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib/soundfx
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.improvetouch.blobmanager@1.0-service
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/vendor.qti.hardware.improvetouch.blobmanager@1.0-service.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.improvetouch.blobmanager@1.0_vendor
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/vendor.qti.hardware.improvetouch.blobmanager@1.0_vendor.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.improvetouch.gesturemanager@1.0-service
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/vendor.qti.hardware.improvetouch.gesturemanager@1.0-service.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.improvetouch.gesturemanager@1.0_vendor
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/vendor.qti.hardware.improvetouch.gesturemanager@1.0_vendor.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.improvetouch.touchcompanion@1.0-service
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/vendor.qti.hardware.improvetouch.touchcompanion@1.0-service.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.improvetouch.touchcompanion@1.0_vendor
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/vendor.qti.hardware.improvetouch.touchcompanion@1.0_vendor.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.imsrtpservice@1.0-service-Impl
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/vendor.qti.imsrtpservice@1.0-service-Impl.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.imsrtpservice@1.0_vendor
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909/vendor/lib/vendor.qti.imsrtpservice@1.0_vendor.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)
LOCAL_PATH         := $(PREBUILT_PATH)

include $(CLEAR_VARS)
LOCAL_MODULE               := izat.xt.srv
LOCAL_MODULE_OWNER         := qcom
LOCAL_MODULE_TAGS          := optional
LOCAL_MODULE_CLASS         := JAVA_LIBRARIES
LOCAL_MODULE_SUFFIX        := $(COMMON_JAVA_PACKAGE_SUFFIX)
LOCAL_SRC_FILES            := ../../.././target/common/obj/JAVA_LIBRARIES/izat.xt.srv_intermediates/classes.jack
LOCAL_UNINSTALLABLE_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE               := cneapiclient
LOCAL_MODULE_OWNER         := qcom
LOCAL_MODULE_TAGS          := optional
LOCAL_MODULE_CLASS         := JAVA_LIBRARIES
LOCAL_MODULE_SUFFIX        := $(COMMON_JAVA_PACKAGE_SUFFIX)
LOCAL_SRC_FILES            := ../../.././target/common/obj/JAVA_LIBRARIES/cneapiclient_intermediates/classes.jack
LOCAL_UNINSTALLABLE_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE               := oem-services
LOCAL_MODULE_OWNER         := qcom
LOCAL_MODULE_TAGS          := optional
LOCAL_MODULE_CLASS         := JAVA_LIBRARIES
LOCAL_MODULE_SUFFIX        := $(COMMON_JAVA_PACKAGE_SUFFIX)
LOCAL_SRC_FILES            := ../../.././target/common/obj/JAVA_LIBRARIES/oem-services_intermediates/javalib.jar
LOCAL_UNINSTALLABLE_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE               := com.qti.dpmframework
LOCAL_MODULE_OWNER         := qcom
LOCAL_MODULE_TAGS          := optional
LOCAL_MODULE_CLASS         := JAVA_LIBRARIES
LOCAL_MODULE_SUFFIX        := $(COMMON_JAVA_PACKAGE_SUFFIX)
LOCAL_SRC_FILES            := ../../.././target/common/obj/JAVA_LIBRARIES/com.qti.dpmframework_intermediates/classes.jack
LOCAL_UNINSTALLABLE_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE               := dpmapi
LOCAL_MODULE_OWNER         := qcom
LOCAL_MODULE_TAGS          := optional
LOCAL_MODULE_CLASS         := JAVA_LIBRARIES
LOCAL_MODULE_SUFFIX        := $(COMMON_JAVA_PACKAGE_SUFFIX)
LOCAL_SRC_FILES            := ../../.././target/common/obj/JAVA_LIBRARIES/dpmapi_intermediates/classes.jack
LOCAL_UNINSTALLABLE_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE               := com.quicinc.cne.server-V2.0-java-static
LOCAL_MODULE_OWNER         := qcom
LOCAL_MODULE_TAGS          := optional
LOCAL_MODULE_CLASS         := JAVA_LIBRARIES
LOCAL_MODULE_SUFFIX        := $(COMMON_JAVA_PACKAGE_SUFFIX)
LOCAL_SRC_FILES            := ../../.././target/common/obj/JAVA_LIBRARIES/com.quicinc.cne.server-V2.0-java-static_intermediates/classes.jack
LOCAL_UNINSTALLABLE_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE               := tcmclient
LOCAL_MODULE_OWNER         := qcom
LOCAL_MODULE_TAGS          := optional
LOCAL_MODULE_CLASS         := JAVA_LIBRARIES
LOCAL_MODULE_SUFFIX        := $(COMMON_JAVA_PACKAGE_SUFFIX)
LOCAL_SRC_FILES            := ../../.././target/common/obj/JAVA_LIBRARIES/tcmclient_intermediates/classes.jack
LOCAL_UNINSTALLABLE_MODULE := true
include $(BUILD_PREBUILT)
