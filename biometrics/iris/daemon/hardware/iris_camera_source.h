/*===========================================================================
  Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ===========================================================================*/

/*
 * Part of Secure Camera HLOS listener
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <linux/msm_ion.h>
#include <utils/Log.h>
#include <utils/RefBase.h>
#include <utils/Mutex.h>
#include <utils/Condition.h>
#include <cutils/properties.h>
#include <cutils/memory.h>
#include "iris_tz_api.h"
#include "iris_frame_source.h"
#include "iris_camera.h"
#include <gui/IGraphicBufferProducer.h>
#include <gui/IProducerListener.h>
#include <gralloc_priv.h>

using namespace android;

#define IRIS_CAMERA_SOURCE_DEBUG
#ifdef IRIS_CAMERA_SOURCE_DEBUG
#define IRIS_CAMERA_SOURCE_LOGD(fmt, args...) ALOGE(fmt, ##args)
#else
#define IRIS_CAMERA_SOURCE_LOGD(fmt, args...) do{}while(0)
#endif
#define IRIS_CAMERA_SOURCE_LOGE(fmt, args...) ALOGE(fmt, ##args)


/**
 * Iris Camera OP mode
 */
#define IRIS_CAMERA_OP_MODE_PREVIEW     (1 << 0)
#define IRIS_CAMERA_OP_MODE_VIDEO       (1 << 1)
#define IRIS_CAMERA_OP_MODE_RDI         (1 << 2)
#define IRIS_CAMERA_OP_MODE_SECURE      (1 << 3)
#define IRIS_CAMERA_OP_MODE_SNAPSHOT      (1 << 4)
#define IRIS_CAMERA_OP_MODE_SECURE_RDI         (IRIS_CAMERA_OP_MODE_SECURE|IRIS_CAMERA_OP_MODE_RDI)

#define IRIS_CAMERA_MAX_FRAME_NUM   2
#define IRIS_CAMERA_SD_FRAME_NUM 4

#define IRIS_DISPLAY_BUF_ALIGNMENT    64
#define IRIS_CAMERA_BUF_ALIGNMENT    16

struct iris_cam_ion_buf {
    int ion_dev_fd;
    int ion_buf_fd;
    ion_user_handle_t ion_buf_handle;
    size_t size;
    void *data;
};

typedef enum {
    SURFACE_BUF_STAT_FREE = 0,
    SURFACE_BUF_STAT_TZ,//used by tz
    SURFACE_BUF_STAT_DISP,//used by display
} iris_cam_surface_buf_stat_t;

struct iris_cam_surface_buf {
    iris_cam_surface_buf_stat_t state;
    int slot;
    //need to keep to <sp> pointer here as a ref
    sp<GraphicBuffer> buffer;
    ANativeWindowBuffer *native_buffer;

    int ion_dev_fd;
    int ion_fb_fd;
    ion_user_handle_t ion_fb_handle;
    void *vaddr;
    size_t size;

    bool initialized; //need TZ to initialize
};
/**
 * IrisCamera
 * A common class for IR and RGB cameras
 */
class IrisCameraSource : public iris_frame_source {
public:
    IrisCameraSource(uint32_t camera);
    IrisCameraSource(uint32_t camera, uint32_t op_mode);
    virtual ~IrisCameraSource();

    status_t open();
    status_t close();
    status_t start();
    status_t stop();

    /* retrive all supported resolutions for different mode */
    status_t get_supported_sizes(int32_t op_mode, Vector<Size>& sizes);

    /* set resolution for preview or video op mode */
    status_t set_op_size(int32_t op_mode, Size size);

    /* set op mode */
    status_t set_op_mode(int32_t op_mode);

    status_t get_source_info(struct iris_frame_info &info);

    /* add frame from callback */
    status_t add_frame (iris_camera_callback_buf_t *frame);

    /* get iris frame */
    status_t get_frame(iris_frame &frame, iris_frame &display_frame);

    /* release iris frame */
    void put_frame(iris_frame &frame, iris_frame &display_frame);

    /* wait until next frame available or timeout */
    virtual status_t wait_for_frame_available(uint32_t timeout_ms);

    /* set resolution for display */
    status_t set_display_size(Size size);
    status_t set_preview_surface(sp<IGraphicBufferProducer> &bufferProducer);

    status_t set_sensor_gain(uint32_t gain);
    status_t set_sensor_exposure_time(uint32_t exp_ms);
    uint32_t get_sensor_gain() { return mSensorGain; }
    uint32_t get_sensor_exposure_time() { return mSensorExpTimeMs; }
    status_t get_sensor_caps(iris_camera_caps_t &caps);
    status_t set_nr_mode(bool on);
    status_t set_flash_mode(bool on);
    static void preview_cb (iris_camera_callback_buf_t *frame);

    void set_frame_orientation(int orientation);

private:
    status_t prepare_surface_buffers();
    status_t register_surface_buffer(int slot, sp<GraphicBuffer> dequeuedBuffer);
    void unregister_surface_buffer(int slot);
    status_t reset_surface_buffers();
    status_t queue_surface_buffer(struct iris_cam_surface_buf *surface_buf, int64_t timestamp);
    status_t display_frame(iris_camera_callback_buf_t *frame);
    status_t display_frame(struct iris_cam_surface_buf *surface_buf, uint64_t ts);
    struct iris_cam_surface_buf *get_surface_buffers_by_fd(int fb_fd);

    void release_frame(iris_camera_callback_buf_t *frame);
    void dump_frame(iris_frame &frame);
    status_t cloneIonBuf(iris_camera_callback_buf_t *frame, struct iris_cam_ion_buf * buf);
    status_t releaseIonBuf(struct iris_cam_ion_buf *buf);
    struct iris_cam_ion_buf * allocIonBuf();

private:
    pthread_mutex_t mMutex;
    uint32_t mOpMode;
    uint32_t mCameraNum;      /** Number of cameras available */
    uint32_t mCameraId;      /** camera id */
    Size mPrevSize;
    size_t mFrameLen;         /** Number of bytes in frame */
    Size mDisplaySize;
    size_t mDisplayFrameLen;         /** Number of bytes in frame */
    List<iris_camera_callback_buf_t *> mFramesDisplayed;
    uint32_t mNumFramesDisplayed;
    List<iris_camera_callback_buf_t *> mFramesReceived;
    uint32_t mNumFramesReceived;
    List<iris_camera_callback_buf_t *> mFramesProcessed;
    uint32_t mNumFramesProcessed;
    List<struct iris_cam_ion_buf *> mFreeIonFrameQueue;
    uint32_t mNumFreeIonFrame;
    List<struct iris_cam_ion_buf *> mActiveIonFrameQueue;
    uint32_t mNumActiveIonFrame;

    List<struct iris_cam_surface_buf *> mFreeSurfaceBufQueue;
    uint32_t mNumFreeSurfaceBuf;
    List<struct iris_cam_surface_buf *> mTzSurfaceBufQueue;
    uint32_t mNumTzSurfaceBuf;
    List<struct iris_cam_surface_buf *> mDisplaySurfaceBufQueue;
    uint32_t mNumDisplaySurfaceBuf;

    struct iris_cam_surface_buf mSurfaceBuf[IRIS_CAMERA_SD_FRAME_NUM];
    uint32_t mNumSurfaceBuf;

    iris_camera_handle mCamHandle;
    iris_camera_caps_t caps;

    pthread_cond_t mFrameReadyCond;

    int mIonFd;

    /* sensor settings */
    uint32_t mSensorGain;
    uint32_t mSensorExpTimeMs;

    sp<IGraphicBufferProducer> mBufferProducer;

    bool mOpened;
    bool mStarted;
    bool mSecure;
    bool mDisplay;

    /* statistic data */
    int mem_malloc_count;
    int mem_free_count;
    int totalFrameCount;
    int totalFrameDropCount;
    struct timeval mStartTime;

    /* frame dump */
    int nextDumpFrameIndex;

    int mOrientation;
};

