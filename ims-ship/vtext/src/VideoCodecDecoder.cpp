/*****************************************************************************

============================
Copyright (c)  2016-2017  Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================

 File: VideoCodecDecoder.cpp
 Description: Implementation of VideoCodecDecoder

 Revision History
 ===============================================================================
 Date    |   Author's Name    |  BugID  |        Change Description
 ===============================================================================
 1-Dec-16   Sanjeev Mittal      First Version
 *****************************************************************************/
#include<VideoCodecDecoder.h>
#include<string.h>
#include<qplog.h>

#define MEDIA_KEY_LOW_LATENCY (char*)"vendor.qti-ext-dec-picture-order.enable\0"
#define MEDIA_H264_VIDEO_MIME_TYPE  (char*)"video/avc\0"
#define MEDIA_H263_VIDEO_MIME_TYPE  (char*)"video/3gpp\0"
#define MEDIA_HEVC_VIDEO_MIME_TYPE  (char*)"video/hevc\0"
#define MEDIA_MPEG4_VIDEO_MIME_TYPE (char*)"video/mp4v-es\0"


VideoCodecDecoder::VideoCodecDecoder()
{
  iPlayerState = eVideoStateNotReady;
  m_format = NULL;
  AMediaCodecnativeWindow = NULL;
  mCodec = NULL;
  m_bMediaCodecError = false;
  CRITICAL1("VideoCodecDecoder ctor called");
}

VideoCodecDecoder::~VideoCodecDecoder()
{
  CRITICAL1("VideoCodecDecoder dtor called");
}

QPE_VIDEO_ERROR VideoCodecDecoder::DeInit()
{
  if (VIDEO_INIT == m_ePlayerState) {
    ERROR2("DeInit:: Player already released, m_ePlayerState %d",
           m_ePlayerState);
    return VIDEO_ERROR_OK;
  }

  CRITICAL4("PlayerStateTransition:%d DeInit Called: m_ePlayerState %d, m_format %p",
            iPlayerState, m_ePlayerState, m_format);

  if (mCodec) {
    AMediaCodec_delete(mCodec);
  }/*

  if (AMediaCodecnativeWindow) {
    ANativeWindow_release(AMediaCodecnativeWindow);
  }*/
  AMediaCodecnativeWindow = NULL;

  if (m_format) {
    AMediaFormat_delete(m_format);
  }

  SendEventsToThinclient(VIDEO_MSG_DEV_UNINITIALISED);
  AMediaCodecnativeWindow = NULL;
  m_ePlayerState = VIDEO_INIT;
  CRITICAL3("PlayerStateTransition:%d:VIDEO_MSG_DEV_UNINITIALISED:m_ePlayerState %d",
            iPlayerState, m_ePlayerState);
  return VIDEO_ERROR_OK;
}

QPE_VIDEO_ERROR VideoCodecDecoder::Init(QP_VIDEO_CALLBACK tVideoCallBack,
                                        void* pUserData,
                                        QPE_VIDEO_DEV eVDev,
                                        QP_VIDEO_CONFIG *pCodecConfig)
{
  m_bMediaCodecError = false;
  EVENT1("Init:: Register the callback API");
  //please never remove these register api call code as it is first step of
  //registration of callback and variables
  RegisterPlayerCallBack(tVideoCallBack, pUserData,  eVDev, pCodecConfig);
  RegisterCallBacks(tVideoCallBack, pUserData, eVDev);
  CRITICAL3("PlayerStateTransition:%d Init Done: m_ePlayerState %d",
            iPlayerState, m_ePlayerState);
  mTransform = 0;
  return VIDEO_ERROR_OK;
}

void VideoCodecDecoder::SetNativeWindow(sp<ANativeWindow> surfaceFar)
{
  AMediaCodecnativeWindow = surfaceFar.get();
  CRITICAL3("mNativeWindowSurfaceFar = %p %d",
            AMediaCodecnativeWindow.get(), __LINE__);

  /*If we are in INIT and SURFACE pending states, surface should not be NULL */
  if (VIDEO_INIT == m_ePlayerState && AMediaCodecnativeWindow.get() ) {
    m_ePlayerState = VIDEO_CODEC_PENDING;
    CRITICAL2("Surface State is Ready, m_ePlayerState %d", m_ePlayerState);
  } else if (VIDEO_SURFACE_PENDING == m_ePlayerState &&
             AMediaCodecnativeWindow.get() ) {
    CRITICAL1("Surface State is Ready, Codec already received");
    //! Move to Surface rcvd state so that Configure API will proceed further
    m_ePlayerState = VIDEO_SURFACE_RECEIVED;
    QPE_VIDEO_ERROR eStatus = StartPlayer(m_codecConfig);

    if (eStatus == VIDEO_ERROR_OK) {
      MINIMAL1("Calling sempost vtplayframe");
      sem_post_videoplay();
    }
  } else if (VIDEO_CODEC_CONFIGURED == m_ePlayerState) {
    /* If we are in play state already, then stop the player first. */
    IsEventInternalTriggered(TRUE);
    Stop();
    IsEventInternalTriggered(FALSE);
    //! Move back to Surface pending state
    m_ePlayerState = VIDEO_SURFACE_PENDING;
    //! Set player start flag so that, after surface is received
    //! Start() API will be called after configure() API
    m_bPlayerStartReq = true;

    if (NULL != AMediaCodecnativeWindow.get() ) {
      //! Move to Surface rcvd state so that Configure API will proceed further
      m_ePlayerState = VIDEO_SURFACE_RECEIVED;
      QPE_VIDEO_ERROR eStatus = StartPlayer(m_codecConfig);
    }
  } //! if(VIDEO_CODEC_CONFIGURED == m_ePlayerState)

  return;
}

QPE_VIDEO_ERROR VideoCodecDecoder::Configure(QP_VIDEO_CONFIG tCodecConfig)
{
  QPE_VIDEO_ERROR status;
  media_status_t mstatus;
  AMediaFormat *format = NULL;
  enum eVideoState prevState = iPlayerState;
  CRITICAL4("Configure: m_ePlayerState %d, m_format %p, iPlayerState %d",
            m_ePlayerState, m_format, iPlayerState);
  /* Copy Codec Config info into class param */
  UpdateCodecConfigInfo(&tCodecConfig);
  /* For every config request, Transform needs to be calculated */
  mTransform = 0;

  /* Check player state before configuring codec. */
  if (VIDEO_INIT == m_ePlayerState ||
      VIDEO_SURFACE_PENDING == m_ePlayerState) {
    m_ePlayerState = VIDEO_SURFACE_PENDING;
    CRITICAL2("Configure: Waiting for Surface, m_ePlayerState %d",
              m_ePlayerState);
    //! Send Dummy response to Modem
    SendEventsToThinclient(VIDEO_MSG_CODEC_CHANGED);
    return VIDEO_ERROR_OK;
  }

  if (eVideoStateActive == iPlayerState) {
    MINIMAL1("Configure:  Codec is already Active, stop before configuring it");
    bool OutsideInternalEvent = m_bInternalEvent;
    m_bInternalEvent = true;
    status = Stop();
    m_bInternalEvent = OutsideInternalEvent;

    if (VIDEO_ERROR_OK != status) {
      ERROR2("Configure:  Codec stop failed status %d", status);
      return VIDEO_ERROR_OK;
    }
  }

  //! this needs further debugging, crashing
  if (m_format != NULL) {
    CRITICAL1("Configure: format is clearedup");
    AMediaFormat_delete(m_format);
  }

  AMediaCodec_delete(mCodec); //rk: Needs further testing
  m_format = AMediaFormat_new();

  if (NULL == m_format) {
    ERROR1("Configure: m_format is null")
    return VIDEO_ERROR_UNKNOWN;
  }

  AMediaFormat_setInt32(m_format, AMEDIAFORMAT_KEY_WIDTH, m_codecConfig.iWidth);
  AMediaFormat_setInt32(m_format, AMEDIAFORMAT_KEY_HEIGHT, m_codecConfig.iHeight);
  AMediaFormat_setInt32(m_format, MEDIA_KEY_LOW_LATENCY, 1);
  CRITICAL1("Configure: Creating Decoder Mime");

  if (VIDEO_CODEC_H264 == m_codecConfig.eCodec) {
    mCodec = AMediaCodec_createDecoderByType(MEDIA_H264_VIDEO_MIME_TYPE);
    AMediaFormat_setString(m_format, AMEDIAFORMAT_KEY_MIME,
                           MEDIA_H264_VIDEO_MIME_TYPE);
  } else if (VIDEO_CODEC_H265 == m_codecConfig.eCodec) {
    mCodec = AMediaCodec_createDecoderByType(MEDIA_HEVC_VIDEO_MIME_TYPE);
    AMediaFormat_setString(m_format, AMEDIAFORMAT_KEY_MIME,
                           MEDIA_HEVC_VIDEO_MIME_TYPE);
  } else if (VIDEO_CODEC_H263 == m_codecConfig.eCodec) {
    mCodec = AMediaCodec_createDecoderByType(MEDIA_H263_VIDEO_MIME_TYPE);
    AMediaFormat_setString(m_format, AMEDIAFORMAT_KEY_MIME,
                           MEDIA_H263_VIDEO_MIME_TYPE);
  } else if ((VIDEO_CODEC_MPEG4_ISO == m_codecConfig.eCodec) ||
             (VIDEO_CODEC_MPEG4_XVID == m_codecConfig.eCodec) ) {
    mCodec = AMediaCodec_createDecoderByType(MEDIA_MPEG4_VIDEO_MIME_TYPE);
    AMediaFormat_setString(m_format, AMEDIAFORMAT_KEY_MIME,
                           MEDIA_MPEG4_VIDEO_MIME_TYPE);
  }

  if (NULL == mCodec) {
    ERROR1("Configure:: mCodec is null while creating encoder mime");
    return VIDEO_ERROR_UNKNOWN;
  }

  CRITICAL2("Configuring decoder, mCodec %p", mCodec);
  mstatus = AMediaCodec_configure(mCodec, m_format,
                                  AMediaCodecnativeWindow.get(), NULL, 0);

  if (AMEDIA_OK != mstatus) {
    ERROR2("Configure returned status %d", (int)mstatus);
    return VIDEO_ERROR_UNKNOWN;
  }

  SendEventsToThinclient(VIDEO_MSG_CODEC_CHANGED);
  CRITICAL3("PlayerStateTransition:%d:VIDEO_MSG_CODEC_CHANGED: m_ePlayerState %d",
            iPlayerState, m_ePlayerState);
  /* Move player state to Configured */
  m_ePlayerState = VIDEO_CODEC_CONFIGURED;
  iPlayerState = eVideoStateIdle;

  //this is for callwaiting scenarios or
  if (eVideoStateActive == prevState) {
    mstatus = AMediaCodec_start(mCodec);

    if (AMEDIA_OK != mstatus) {
      ERROR2("configured Start returned status %d", (int)mstatus);
      return VIDEO_ERROR_UNKNOWN;
    }

    iPlayerState = eVideoStateActive;
    CRITICAL1("Configure: Started mCodec from configured API");
  }

  return VIDEO_ERROR_OK;
}

QPE_VIDEO_ERROR VideoCodecDecoder::Start()
{
  CHECK_MEDIA_ERROR;
  media_status_t mstatus;
  QPE_VIDEO_ERROR eStatus = VIDEO_ERROR_OK;

  do {
    if (eVideoStateActive == iPlayerState) {
      CRITICAL3("Component already started, m_ePlayerState %d, iPlayerState %d",
                m_ePlayerState, iPlayerState);
      break;
    }
    /* If Codec is not yet configured, then send dummy indication to Upper Layer*/
    else if (VIDEO_INIT == m_ePlayerState ||
        VIDEO_SURFACE_PENDING == m_ePlayerState) {
      m_ePlayerState = VIDEO_SURFACE_PENDING;
      m_bPlayerStartReq = true;
      eStatus = VIDEO_ERROR_PLAYER_DOWN;
      CRITICAL2("Component not configured, send Dummy VIDEO_MSG_PLAYER_STARTED, m_ePlayerState %d",
                m_ePlayerState);
      break;
    }

    /* If codec is not yet configured, then configure it first.*/
    if (VIDEO_CODEC_PENDING == m_ePlayerState) {
      if ((mCodec == NULL) || (m_format == NULL)) {
        ERROR5("PlayerStateTransition:%d: m_ePlayerState %d, mCodec %p, m_format %p failed",
               iPlayerState, m_ePlayerState, mCodec, m_format);
        eStatus = VIDEO_ERROR_UNKNOWN;
        break;
      }

      /* For every config request, Transform needs to be calculated */
      mTransform = 0;
      CRITICAL2("PlayerStateTransition:%d: Configure decoder from Start API",
                iPlayerState);
      mstatus = AMediaCodec_configure(mCodec, m_format,
                                      AMediaCodecnativeWindow.get(), NULL, 0);

      if (AMEDIA_OK != mstatus) {
        ERROR2("Configure from Start failed, status %d", (int)mstatus);
        eStatus = VIDEO_ERROR_UNKNOWN;
        break;
      }

      CRITICAL3("PlayerStateTransition:%d:VIDEO_MSG_CODEC_CHANGED: m_ePlayerState %d",
                iPlayerState, m_ePlayerState);
      /* Move player state to Configured */
      m_ePlayerState = VIDEO_CODEC_CONFIGURED;
    } //! if (VIDEO_CODEC_PENDING == m_ePlayerState)

    /* We reached this stage means, Codec is configured properly */
    m_bPlayerStartReq = false;
    mstatus = AMediaCodec_start(mCodec);

    if (AMEDIA_OK != mstatus) {
      ERROR2("PlayerStateTransition:%d:Codec start failed", iPlayerState);
      eStatus = VIDEO_ERROR_UNKNOWN;
      break;
    }

    iPlayerState = eVideoStateActive;
  } while (0);

  if ((VIDEO_ERROR_OK == eStatus) || (VIDEO_ERROR_PLAYER_DOWN == eStatus)) {
    CRITICAL3("PlayerStateTransition:%d:VIDEO_MSG_PLAYER_STARTED m_ePlayerState %d",
              iPlayerState, m_ePlayerState);
    SendEventsToThinclient(VIDEO_MSG_PLAYER_STARTED);
  } else {
    ERROR3("PlayerStateTransition:%d:VIDEO_MSG_PLAYER_STARTED failed, m_ePlayerState %d",
           iPlayerState, m_ePlayerState);
    SendEventsToThinclient(VIDEO_MSG_ERROR);
  }

  return eStatus;
}

QPE_VIDEO_ERROR VideoCodecDecoder::Stop()
{
  QPE_VIDEO_ERROR eStatus = VIDEO_ERROR_OK;
  CRITICAL3("PlayerStateTransition:%d:Stop: m_ePlayerState %d requested",
            iPlayerState, m_ePlayerState);

  /* Check Codec state before initiating stop command */
  if (eVideoStateActive == iPlayerState) {
    m_ePlayerState = VIDEO_CODEC_PENDING;
    /*If surface is set to NULL, intermittently then this flag will help to call
      start() API*/
    m_bPlayerStartReq = true;
    iPlayerState = eVideoStateNotReady;
    media_status_t mStatus = AMediaCodec_stop(mCodec);

    if (AMEDIA_OK != mStatus) {
      ERROR3("PlayerStateTransition:%d: stop failed, status %d",
             iPlayerState, (int)mStatus);
      SendEventsToThinclient(VIDEO_MSG_ERROR);
      eStatus = VIDEO_ERROR_UNKNOWN;
    } else {
      CRITICAL3("PlayerStateTransition:%d:VIDEO_MSG_PLAYER_STOPPED m_ePlayerState %d",
                iPlayerState, m_ePlayerState);
    }
  } else {
    CRITICAL2("PlayerStateTransition:%d: not in active state, send dummy indication",
              iPlayerState);
  }

  if (VIDEO_ERROR_OK == eStatus) {
    SendEventsToThinclient(VIDEO_MSG_PLAYER_STOPPED);
  }

  return eStatus;
}

QPE_VIDEO_ERROR VideoCodecDecoder::VideoPlayFrame(QP_MULTIMEDIA_FRAME* pFrame,
    int belongs_to_drop_set)
{
  QPE_VIDEO_ERROR eStatus = VIDEO_ERROR_OK;
  MEDIA_PACKET_INFO_RX* pRxPkt = NULL;
  ssize_t bufidx = -1;
  timeval tv;

  if (pFrame == NULL) {
    ERROR1("Pframe is null in VideoplayFrame");
    return VIDEO_ERROR_UNKNOWN;
  }

  uint32_t length = pFrame->iDataLen;

  if (length <= 0 || pFrame->pData == NULL) {
    CRITICAL1("length is null or data is null");
    return VIDEO_ERROR_UNKNOWN;
  }

  CHECK_MEDIA_ERROR;
  pRxPkt = &(pFrame->sMediaPacketInfo.sMediaPktInfoRx);

  /* Validate player state before proceeding further */
  if (eVideoStateActive != iPlayerState) {
    MINIMAL2("VideoPlayFrame: Player is not active %d",
             iPlayerState);
    return VIDEO_ERROR_PLAYER_BUSY; // we have to return player is busy and
    //return this so that we don't loose rendering frames.
  }

  uint32_t system_time_decode_video_frame = (uint32_t)(getCurrentAVTime() / 1000);
  gettimeofday(&tv, NULL);
  uint32_t currenttime = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
  bufidx = AMediaCodec_dequeueInputBuffer(mCodec,
                                          1000000); //time out in microsecond 1000ms
  MINIMAL3("input buffer %zd timestamp: %llu", bufidx, pRxPkt->iTimeStamp);

  if (bufidx >= 0) {
    size_t bufsize;
    auto buf = AMediaCodec_getInputBuffer(mCodec, bufidx, &bufsize);

    if (buf) {
      memcpy(buf, pFrame->pData, length);
    }

    AMediaCodec_queueInputBuffer(mCodec, bufidx, 0, length,
                                 pRxPkt->iTimeStamp, 0);
  }

  AMediaCodecBufferInfo info;
  auto status = AMediaCodec_dequeueOutputBuffer(mCodec, &info,
                100000); //time out in microsecond 100ms

  if (status >= 0) {
    if (info.flags & AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM) {
      CRITICAL1("VideoPlayFrame output EOS");
    }

    QP_VIDEO_PLAYOUT_INFO playoutInfo;
    memset(&playoutInfo, 0, sizeof(playoutInfo));
    playoutInfo.version = 4;
    playoutInfo.ucFrameNalType = pFrame->pData[4];
    playoutInfo.ulFrameSize = length;
    playoutInfo.source_time_video_frame =
      pFrame->sMediaPacketInfo.sMediaPktInfoRx.source_time_video_frame;
    playoutInfo.source_rtp_timestamp =
      pFrame->sMediaPacketInfo.sMediaPktInfoRx.source_rtp_timestamp;
    playoutInfo.system_time_decode_video_frame =
      system_time_decode_video_frame;
    //it should be avtimer + current time and later current time will be substracted from
    gettimeofday(&tv, NULL);
    playoutInfo.system_time_render_video_frame = (uint32_t)(
          system_time_decode_video_frame +
          ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - currenttime));

    if (belongs_to_drop_set) {
      //if it belongs to dropset then set the rendertime to 0
      playoutInfo.system_time_render_video_frame = 0;
    }

    LOGPACKET(LOG_VIDEO_PLAYOUT_C, &playoutInfo, sizeof(playoutInfo));
    int32_t transform;

    switch (pFrame->cvoInfo & 0x03) {
      case CVO_ZERO_ROTATION:
        transform = 0;
        DEBUG1("Rotation 0");
        break;

      case CVO_90_ROTATION:
        transform = NATIVE_WINDOW_TRANSFORM_ROT_90;
        DEBUG1("Rotation 90");
        break;

      case CVO_180_ROTATION:
        transform = NATIVE_WINDOW_TRANSFORM_ROT_180;
        DEBUG1("Rotation 180");
        break;

      case CVO_270_ROTATION:
        transform = NATIVE_WINDOW_TRANSFORM_ROT_270;
        DEBUG1("Rotation 270");
        break;

      default:
        transform = 0;
        break;
    }

    switch (pFrame->cvoInfo & 0x04) {
      case CVO_FLIP_ENABLED:
        transform |= NATIVE_WINDOW_TRANSFORM_FLIP_H;
        DEBUG1("Rotation fliph");
        break; //Flip horizontal

      default:
        break;
    }

    if (transform != mTransform) {
      CRITICAL3("VideoPlayFrame: Transform=%d prevTransform=%d", transform,
                mTransform);
      ANativeWindow_setBuffersTransform(AMediaCodecnativeWindow.get(), transform);
      mTransform = transform;
    }

    CRITICAL2("VideoPlayFrame: output buffers rendered=%d", !belongs_to_drop_set);
    AMediaCodec_releaseOutputBuffer(mCodec, status, !belongs_to_drop_set);
  } else if (status == AMEDIACODEC_INFO_OUTPUT_BUFFERS_CHANGED) {
    CRITICAL1("VideoPlayFrame output buffers changed");
  } else if (status == AMEDIACODEC_INFO_OUTPUT_FORMAT_CHANGED) {
    auto format = AMediaCodec_getOutputFormat(mCodec);
    CRITICAL2_STR("VideoPlayFrame format changed to: %s",
                  AMediaFormat_toString(format));
    int iWidth = 0, iHeight = 0;
    auto bStatus = AMediaFormat_getInt32(format, AMEDIAFORMAT_KEY_WIDTH, &iWidth);
    bStatus = AMediaFormat_getInt32(format, AMEDIAFORMAT_KEY_HEIGHT, &iHeight);
    PlayerMsg info;
    //FillBufferInfo info;
    memset(&info, 0, sizeof(PlayerMsg));
    info.type = RESOLUTION_UPDATE;
    info.data.resolution.height = iHeight;
    info.data.resolution.width  = iWidth;
    EVENT2("Resolution information in VideoCodecDecoder is %p", &info);
    CRITICAL3("VideoPlayFrame: Posting event RESOLUTION_UPDATE height = %d width =  %d",
              iHeight, iWidth);
    postEvent(&info);
    AMediaFormat_delete(format);
  } else if (status == AMEDIACODEC_INFO_TRY_AGAIN_LATER) {
    CRITICAL1("VideoPlayFrame: No Output Buffers Available");
  } else {
    CRITICAL2("VideoPlayFrame: unexpected info code: %zd", status);
    SendEventsToThinclient(VIDEO_MSG_ERROR);
    m_bMediaCodecError = true;
  }

  return VIDEO_ERROR_OK;
}


QPE_VIDEO_ERROR VideoCodecDecoder::UpdateNalHeader(
  uint8_t* pVolHeader,
  uint16_t pVolHeaderLen)
{
  CRITICAL3("VideoCodecDecoder::UpdateNalHeader pVolHeader : %p pVolHeaderLen : %d",
            pVolHeader, pVolHeaderLen);

  if (pVolHeader != NULL && pVolHeaderLen > 0) {
    memset(m_pRxNalInfo->rawnal, 0, VIDEOOMX_MAX_NAL_LENGTH - 1);
    memcpy(m_pRxNalInfo->rawnal, pVolHeader,
           pVolHeaderLen);
    m_pRxNalInfo->nalLength = (uint32_t) pVolHeaderLen;
  }

  return VIDEO_ERROR_OK;
}
