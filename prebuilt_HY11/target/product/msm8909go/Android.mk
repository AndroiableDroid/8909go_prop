PREBUILT_PATH := $(call my-dir)
LOCAL_PATH         := $(PREBUILT_PATH)

include $(CLEAR_VARS)
LOCAL_MODULE        := evt-sniff.cfg
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := DATA
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/data/evt-test/evt-sniff.cfg
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/data/evt-test
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/c2d2.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/c2dExt.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/CL/cl_egl.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/CL/cl_ext.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/CL/cl_ext_qcom.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/CL/cl_gl_ext.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/CL/cl_gl.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/CL/cl.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/CL/cl_platform.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/CL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/CL/opencl.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/EGL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/EGL/eglext.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/EGL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/EGL/eglextQCOM.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/EGL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/EGL/egl.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := adreno/EGL
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/adreno/EGL/eglplatform.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := avenhancements
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/avenhancements/AVMetaData.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneCet.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneCom.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneConfigs.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneDefs.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/Cne.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneLog.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneMascInterface.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneMsg.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CnePermissions.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneQmi.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneResourceInfo.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneSrmDefs.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneSrm.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneSupplicantWrapper.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneTimer.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneUtils.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/CneWqeInterface.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/EventDispatcher.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/InetAddr.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/queue.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/SocketWrapperClient.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/SwimNetlinkSocket.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/common/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/common/inc/SwimSyncWrapperDefs.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/wqe/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/wqe/inc/IBitrateEstimator.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/wqe/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/wqe/inc/IWqeFactory.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := cne/wqe/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/cne/wqe/inc/WqePolicyTypes.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := fastcv
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/fastcv/fastcvExt.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := fastcv
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/fastcv/fastcv.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := fastrpc/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/fastrpc/inc/AEEStdDef.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := fastrpc/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/fastrpc/inc/AEEStdErr.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := fastrpc/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/fastrpc/inc/remote.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := hdcp-mgr/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/hdcp-mgr/inc/hdcpmgr_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := imsvtext/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/imsvtext/include/qplog.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libflp
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/libflp/fused_location_extended.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libizat_core
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/libizat_core/IzatAdapterBase.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libizat_core
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/libizat_core/IzatApiBase.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libizat_core
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/libizat_core/IzatApiRpc.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libizat_core
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/libizat_core/IzatApiV02.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libizat_core
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/libizat_core/IzatPcid.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libperipheralclient/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/libperipheralclient/inc/pm-service.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := libvqzip
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/libvqzip/VQZip.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-flac
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-audio/audio-flac/FLACDec_API.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-flac
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-audio/audio-flac/FLACDec_BitStream.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-flac
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-audio/audio-flac/FLACDec_MetaData.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-flac
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-audio/audio-flac/FLACDec_Struct.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-flac
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-audio/audio-flac/FLACDec_typedefs.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-flac
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-audio/audio-flac/FLACDec_Wrapper.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-listen
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-audio/audio-listen/ListenSoundModelLib.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-listen
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-audio/audio-listen/ListenSoundModelLib_types.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-listen
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-audio/audio-listen/ListenSoundModelLib_v2.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/audio-src
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-audio/audio-src/QCT_Resampler.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-audio/surround_sound_3mic
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-audio/surround_sound_3mic/surround_rec_interface.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-camera
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-camera/dmlrocorrection_bg_pca.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-camera
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-camera/dmlrocorrection.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-color-convertor
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-color-convertor/MMColorConvert.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-parser/include/DataSourcePort.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-parser/include/filesource.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-parser/include/filesourcetypes.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-parser/include/parserdatadef.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-parser/include/sidxparserdatatypes.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-parser/include/sidxparser.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-parser/include
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-parser/include/SourceBase.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/fastcrc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-video/fastcrc/VideoCRCChecker.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/streamparser
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-video/streamparser/VideoStreamParser.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/swvdec
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-video/swvdec/swvdec_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/swvdec
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-video/swvdec/swvdec_types.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/swvenc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-video/swvenc/swvenc_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/swvenc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-video/swvenc/swvenc_types.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/ubwc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-video/ubwc/ubwc.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/utils
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-video/utils/list.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := mm-video/utils
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/mm-video/utils/VideoComDef.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/pp/inc/aba_cabl.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/pp/inc/aba_core_api.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/pp/inc/aba_foss.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/pp/inc/aba_svi.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/pp/inc/aba_type.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/pp/inc/diagplatform.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := pp/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/pp/inc/libmm-disp-apis.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := qdcm/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/qdcm/inc/disp_color_apis.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := qdcm/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/qdcm/inc/mode_manager.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := qdcm/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/qdcm/inc/utility.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := ui
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/ui/Blur.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := xmllib/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/xmllib/inc/xmllib_common.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := xmllib/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/xmllib/inc/xmllib_parser.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_COPY_HEADERS_TO := xmllib/inc
LOCAL_COPY_HEADERS    := ../../.././target/product/msm8909go/obj/include/xmllib/inc/xmllib_tok.h
include $(BUILD_COPY_HEADERS)

include $(CLEAR_VARS)
LOCAL_MODULE        := libdrmMinimalfs
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_SUFFIX := .a
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/obj/STATIC_LIBRARIES/libdrmMinimalfs_intermediates/libdrmMinimalfs.a
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libQSEEComAPIStatic
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_SUFFIX := .a
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/obj/STATIC_LIBRARIES/libQSEEComAPIStatic_intermediates/libQSEEComAPIStatic.a
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := librpmbStatic
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_SUFFIX := .a
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/obj/STATIC_LIBRARIES/librpmbStatic_intermediates/librpmbStatic.a
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libssdStatic
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_SUFFIX := .a
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/obj/STATIC_LIBRARIES/libssdStatic_intermediates/libssdStatic.a
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := embms
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/app/embms/embms.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := QTIDiagServices
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/app/QTIDiagServices/QTIDiagServices.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := mm-swvdec-test
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/bin/mm-swvdec-test
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/bin
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := mm-swvenc-test
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/bin/mm-swvenc-test
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/bin
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := remote_debug_agent
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/bin/remote_debug_agent
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/bin
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := andsfCne.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/etc/cne/andsfCne.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/cne
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := SwimConfig.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/etc/cne/SwimConfig.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/cne
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := cneapiclient.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/etc/permissions/cneapiclient.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/permissions
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := com.quicinc.cne.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/etc/permissions/com.quicinc.cne.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/etc/permissions
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := embms.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/etc/permissions/embms.xml
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/com.qualcomm.qti.dpm.api@1.0.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/com.qualcomm.qti.wifidisplayhal@1.0.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libadsprpc_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libavenhancements
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libavenhancements.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libcdsprpc_system
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libcdsprpc_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libDiagService
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libDiagService.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libfastcvadsp_stub.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libfastcvopt.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libGPTEE_system
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libGPTEE_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-imsvtextutils
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/lib-imsvtextutils.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-imsvt
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/lib-imsvt.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := lib-imsvtutils
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/lib-imsvtutils.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := liblistensoundmodel2
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/liblistensoundmodel2.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmdsprpc_system
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libmdsprpc_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libmmparser_lite
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libmmparser_lite.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libqct_resampler
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libqct_resampler.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libQTEEConnector_system
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libQTEEConnector_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := librcc
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/librcc.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsdm-disp-apis
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libsdm-disp-apis.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsdsprpc_system
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libsdsprpc_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsecureuisvc_jni
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libsecureuisvc_jni.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libsecureui_svcsock_system
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libsecureui_svcsock_system.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libvendorconn
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libvendorconn.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libvr_amb_engine
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libvr_amb_engine.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libvraudio
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libvraudio.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libvr_object_engine
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libvr_object_engine.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := libvr_sam_wrapper
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/libvr_sam_wrapper.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/rfsa/adsp/libapps_mem_heap.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/rfsa/adsp/libdspCV_skel.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/rfsa/adsp/libfastcvadsp_skel.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/rfsa/adsp/libfastcvadsp.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.improvetouch.blobmanager@1.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/vendor.qti.hardware.improvetouch.blobmanager@1.0.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.improvetouch.gesturemanager@1.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/vendor.qti.hardware.improvetouch.gesturemanager@1.0.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.improvetouch.touchcompanion@1.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/vendor.qti.hardware.improvetouch.touchcompanion@1.0.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.imsrtpservice@1.0
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_MODULE_SUFFIX := .so
LOCAL_STRIP_MODULE  := false
LOCAL_MULTILIB      := 32
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/lib/vendor.qti.imsrtpservice@1.0.so
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := CNEService
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := APPS
LOCAL_CERTIFICATE   := platform
LOCAL_MODULE_SUFFIX := .apk
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/system/priv-app/CNEService/CNEService.apk
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/system/priv-app
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := adsprpcd
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/adsprpcd
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := audioflacapp
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/audioflacapp
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := cnd
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/cnd
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := hbtp_daemon
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/hbtp_daemon
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := hdcp1prov
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/hdcp1prov
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := hdcp2p2prov
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/hdcp2p2prov
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := hvdcp_opti
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/hvdcp_opti
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := android.hardware.gatekeeper@1.0-service-qti
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/hw/android.hardware.gatekeeper@1.0-service-qti
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin/hw
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := android.hardware.keymaster@3.0-service-qti
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/hw/android.hardware.keymaster@3.0-service-qti
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin/hw
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.qteeconnector@1.0-service
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/hw/vendor.qti.hardware.qteeconnector@1.0-service
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin/hw
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := imsdatadaemon
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/imsdatadaemon
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := imsqmidaemon
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/imsqmidaemon
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := imsrcsd
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/imsrcsd
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := ims_rtp_daemon
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/ims_rtp_daemon
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := LKCore
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/LKCore
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := pm-proxy
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/pm-proxy
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := pm-service
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/pm-service
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qcom-system-daemon
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/qcom-system-daemon
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := tftp_server
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/tftp_server
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vm_bms
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/vm_bms
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := xtra-daemon
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := EXECUTABLES
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/bin/xtra-daemon
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/bin
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := drc_cfg_5.1.txt
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/drc/drc_cfg_5.1.txt
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/drc
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := drc_cfg_AZ.txt
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/drc/drc_cfg_AZ.txt
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/drc
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := hbtpcfg_8917.dat
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/hbtp/hbtpcfg_8917.dat
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/hbtp
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := hbtpcfg.dat
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/hbtp/hbtpcfg.dat
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/hbtp
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qtc800s_dsp.bin
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/hbtp/qtc800s_dsp.bin
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/hbtp
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := android.hardware.gatekeeper@1.0-service-qti.rc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/init/android.hardware.gatekeeper@1.0-service-qti.rc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/init
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := android.hardware.keymaster@3.0-service-qti.rc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/init/android.hardware.keymaster@3.0-service-qti.rc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/init
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := vendor.qti.hardware.qteeconnector@1.0-service.rc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/init/vendor.qti.hardware.qteeconnector@1.0-service.rc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/init
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := audiobasic.dmc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/qti-logkit/audiobasic.dmc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := gnsslocationlogging.dmc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/qti-logkit/gnsslocationlogging.dmc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := goldenlogmask.dmc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/qti-logkit/goldenlogmask.dmc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := IMS.dmc
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/qti-logkit/IMS.dmc
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qti_logkit_command.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/qti-logkit/qti_logkit_command.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qti_logkit_config.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/qti-logkit/qti_logkit_config.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := bluetooth.png
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/qti-logkit/scenarios/bluetooth.png
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit/scenarios
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := default.png
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/qti-logkit/scenarios/default.png
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit/scenarios
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := IMS.png
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/qti-logkit/scenarios/IMS.png
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qti-logkit/scenarios
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qvrservice_6dof_config.xml
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/qvr/qvrservice_6dof_config.xml
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qvr
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := qvrservice_config.txt
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/qvr/qvrservice_config.txt
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/qvr
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := surround_sound_rec_5.1.cfg
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/surround_sound_3mic/surround_sound_rec_5.1.cfg
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/surround_sound_3mic
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := surround_sound_rec_AZ.cfg
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/etc/surround_sound_3mic/surround_sound_rec_AZ.cfg
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/etc/surround_sound_3mic
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a225p5_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a225p5_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a225_pfp.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a225_pfp.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a225_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a225_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a300_pfp.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a300_pfp.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a300_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a300_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a330_pfp.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a330_pfp.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a330_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a330_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a420_pfp.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a420_pfp.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a420_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a420_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530_gpmu.fw2
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a530_gpmu.fw2
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530_pfp.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a530_pfp.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a530_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530v1_pfp.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a530v1_pfp.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530v1_pm4.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a530v1_pm4.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530v2_seq.fw2
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a530v2_seq.fw2
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530v3_gpmu.fw2
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a530v3_gpmu.fw2
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a530v3_seq.fw2
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a530v3_seq.fw2
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := a540_gpmu.fw2
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/a540_gpmu.fw2
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := leia_pfp_470.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/leia_pfp_470.fw
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/firmware
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE        := leia_pm4_470.fw
LOCAL_MODULE_OWNER  := qcom
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := ETC
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/firmware/leia_pm4_470.fw
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/com.qualcomm.qti.dpm.api@1.0_vendor.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/com.qualcomm.qti.wifidisplayhal@1.0-impl.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/com.qualcomm.qti.wifidisplayhal@1.0_vendor.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/com.quicinc.cne.api@1.0.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/com.quicinc.cne.constants@1.0.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/com.quicinc.cne.constants@2.0.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/com.quicinc.cne.server@1.0.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/com.quicinc.cne.server@2.0.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/egl/eglsubAndroid.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/egl/libEGL_adreno.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/egl/libGLESv1_CM_adreno.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/egl/libGLESv2_adreno.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/egl/libq3dtools_adreno.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/hw/android.hardware.gatekeeper@1.0-impl-qti.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/hw/android.hardware.keymaster@3.0-impl-qti.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/hw/gatekeeper.msm8909.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/hw/keystore.msm8909.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/hw/vendor.qti.hardware.qteeconnector@1.0-impl.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libadm.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libadpcmdec.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libadreno_utils.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libadsp_default_listener.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libadsprpc.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libAlacSwDec.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libApeSwDec.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libbccQTI.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libC2D2.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libc2d30-a3xx.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libc2d30-a4xx.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libc2d30-a5xx.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libCB.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libcdsprpc.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libchromaflash.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libcneapiclient.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libcne.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libdme_main.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/lib-dplmedia.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libdrc.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libdrmfs.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libdrmtime.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libdsd2pcm.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libfastcrc.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libfastcvadsp_stub.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libfastcvopt.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libfastrpc_utf_stub.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libFlacSwDec.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libflp.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libgeofence.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libGPreqcancel.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libGPreqcancel_svc.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libGPTEE_vendor.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libgsl.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libhbtpclient.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libhbtpdsp.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libhbtpfrmwk.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libhdcp1prov.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libhdcp2p2prov.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libhdr_tm.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libI420colorconvert.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/lib-imscmservice.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/lib-imsdpl.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/lib-imsqimf.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/lib-imsrcs-v2.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/lib-imsSDP.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/lib-imsxml.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libizat_core.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libkeymasterdeviceutils.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libkeymasterprovision.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libllvm-qcom.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmdsprpc.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera2_frame_algorithm.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera2_is.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera2_q3a_core.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera2_stats_algorithm.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera_chromaflash_lib.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera_hdr_gb_lib.so
LOCAL_MODULE_PATH   := $(PRODUCT_OUT)/$(TARGET_COPY_OUT_VENDOR)/lib
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera_hdr_lib.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera_optizoom_lib.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera_pdafcamif.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera_pdaf.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera_tintless_algo.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera_tintless_bg_pca_algo.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera_trueportrait_lib.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera_ubifocus_lib.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmmcamera_wavelet_lib.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmm-color-convertor.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmm-disp-apis.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libmm-hdcpmgr.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libMpeg4SwEncoder.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libOmxAlacDecSw.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libOmxApeDecSw.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libOmxDsdDec.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libOmxEvrcDec.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libOmxQcelp13Dec.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libOpenCL.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/liboptizoom.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libperipheral_client.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libpvr.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libqisl.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libQSEEComAPI.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libQTEEConnector_vendor.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libqvrservice_client.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/librmp.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/librpmb.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/librs_adreno_sha1.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/librs_adreno.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libRSDriver_adreno.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/lib-rtpcommon.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/lib-rtpcore.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/lib-rtpdaemoninterface.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/lib-rtpsl.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libsc-a2xx.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libsc-a3xx.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libscalar.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libsdm-color.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libsdm-disp-vndapis.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libsdmextension.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libsdsprpc.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libSecureUILib.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libsecureui.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libsecureui_svcsock.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/lib-siputility.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libssd.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libstreamparser.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libsubsystem_control.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libSubSystemShutdown.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libsurround_3mic_proc.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libswvdec.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libtinyxml2_1.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libtrueportrait.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libubifocus.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libUBWC.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/lib-uceservice.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libvideoutils.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libvqzip.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libwms.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libwqe.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/libxml.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/rfsa/adsp/libapps_mem_heap.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/rfsa/adsp/libdspCV_skel.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/rfsa/adsp/libfastcvadsp_skel.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/rfsa/adsp/libfastcvadsp.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/rfsa/adsp/libFastRPC_AUE_Forward_skel.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/rfsa/adsp/libFastRPC_UTF_Forward_skel.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/soundfx/libqcbassboost.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/soundfx/libqcreverb.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/soundfx/libqcvirt.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/vendor.qti.hardware.improvetouch.blobmanager@1.0-service.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/vendor.qti.hardware.improvetouch.blobmanager@1.0_vendor.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/vendor.qti.hardware.improvetouch.gesturemanager@1.0-service.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/vendor.qti.hardware.improvetouch.gesturemanager@1.0_vendor.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/vendor.qti.hardware.improvetouch.touchcompanion@1.0-service.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/vendor.qti.hardware.improvetouch.touchcompanion@1.0_vendor.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/vendor.qti.imsrtpservice@1.0-service-Impl.so
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
LOCAL_SRC_FILES     := ../../.././target/product/msm8909go/vendor/lib/vendor.qti.imsrtpservice@1.0_vendor.so
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
