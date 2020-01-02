/*****************************************************************************

 ============================
Copyright (c)  2016-2017  Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================

 File: VideoCodecDecoder.h
 Description: Implementation of VideoCodecDecoder

 Revision History
 ===============================================================================
 Date    |   Author's Name    |  BugID  |        Change Description
 ===============================================================================
 1-Dec-16   Sanjeev Mittal			First Version
 *****************************************************************************/

#include<MediaCodecBase.h>
#include <gui/Surface.h>
#include <utils/StrongPointer.h>
#include<VTPlayer.h>
#include <android/native_window.h>
class VideoCodecDecoder : public MediaCodecBase, public VTPlayer
{
  public:
  virtual QPE_VIDEO_ERROR Init(QP_VIDEO_CALLBACK tVideoCallBack,
                           void* pUserData, QPE_VIDEO_DEV eVDev,
                           QP_VIDEO_CONFIG* pCodecConfig);
  virtual QPE_VIDEO_ERROR DeInit();
  virtual QPE_VIDEO_ERROR Start();
  virtual QPE_VIDEO_ERROR Stop();
  virtual QPE_VIDEO_ERROR Pause()   {return VIDEO_ERROR_OK;};
  virtual QPE_VIDEO_ERROR Resume()  {return VIDEO_ERROR_OK;};
  virtual QPE_VIDEO_ERROR Configure(QP_VIDEO_CONFIG CodecConfig);
  QPE_VIDEO_ERROR UpdateNalHeader(
		uint8_t* pVolHeader,
      uint16_t pVolHeaderLen);
  virtual void HandleEvent(void* data) {if(data!=NULL)ERROR1("HandleEvent NOT IMPLEMENTED NA for MediaCodec");};
    //player specific functions
    virtual QPE_VIDEO_ERROR MovetoLoadedState() {
      ERROR1("MoveToLoadedState NOT IMPLEMENTED NA for MediaCodec");
      return VIDEO_ERROR_UNKNOWN;
    };
    virtual void MovetoExecutingState() {
      ERROR1("MovetoExecutingState NOT IMPLEMENTED NA for MediaCodec");
      return;
    };
    virtual QPE_VIDEO_ERROR VideoPlayFrame(QP_MULTIMEDIA_FRAME* pFrame,
                                           int belongs_to_drop_set);
    virtual void SetNativeWindow(sp<ANativeWindow> surfaceFar);
    virtual ~VideoCodecDecoder();
    VideoCodecDecoder();

  private:
    enum eVideoState iPlayerState;
};
