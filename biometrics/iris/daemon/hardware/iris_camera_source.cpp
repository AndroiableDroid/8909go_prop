/*===========================================================================
  Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ===========================================================================*/

/*
 * Iris Camera Implementation
 */

#include "common_log.h"
#include "iris_camera_source.h"
#include <cutils/native_handle.h>
#include <cutils/properties.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "IrisCameraSource"
#define MODULE_NAME  "iriscamsource"

using namespace android;


static IrisCameraSource *g_CamSource = NULL;
/*-----------------------------------------------------------------------------
 * IrisCameraSource class
 *-----------------------------------------------------------------------------*/

IrisCameraSource::IrisCameraSource(uint32_t camera) :
    mOpMode(0), mCameraNum(0), mCameraId(camera), mNumFramesDisplayed(0),
    mNumFramesReceived(0), mNumFramesProcessed(0), mNumFreeIonFrame(0), mNumActiveIonFrame(0),
    mNumFreeSurfaceBuf(0), mNumDisplaySurfaceBuf(0),
    mSensorGain(DEFAULT_SENSOR_GAIN),mSensorExpTimeMs(DEFAULT_SENSOR_EXP_TIME_MS),
    mOpened(false), mStarted(false), mSecure(false), mDisplay(false),
    mem_malloc_count(0), mem_free_count(0)
{
    IRIS_CAMERA_SOURCE_LOGD("create");
    g_CamSource = this;
}

IrisCameraSource::IrisCameraSource(uint32_t camera, uint32_t op_mode) :
    mOpMode(op_mode), mCameraNum(0), mCameraId(camera), mNumFramesDisplayed(0),
    mNumFramesReceived(0), mNumFramesProcessed(0), mNumFreeIonFrame(0), mNumActiveIonFrame(0),
    mNumFreeSurfaceBuf(0), mNumDisplaySurfaceBuf(0),
    mSensorGain(DEFAULT_SENSOR_GAIN),mSensorExpTimeMs(DEFAULT_SENSOR_EXP_TIME_MS),
    mOpened(false), mStarted(false), mSecure(false), mDisplay(false),
    mem_malloc_count(0), mem_free_count(0)
{
    IRIS_CAMERA_SOURCE_LOGD("create");
    g_CamSource = this;
}

 IrisCameraSource::~IrisCameraSource()
{

    IRIS_CAMERA_SOURCE_LOGD("destory");
    stop();
    close();
    g_CamSource = NULL;
}

status_t IrisCameraSource::get_source_info(struct iris_frame_info &info)
{
    info.format = IRIS_COLOR_FORMAT_Y_ONLY;
    info.width = mPrevSize.width;
    info.height = mPrevSize.height;
    info.stride = mPrevSize.width;

    return NO_ERROR;
}

status_t IrisCameraSource::get_supported_sizes(int32_t op_mode, Vector<Size>& sizes)
{
    return INVALID_OPERATION;
}

status_t IrisCameraSource::set_op_size(int32_t op_mode, Size size)
{
    if ((op_mode != IRIS_CAMERA_OP_MODE_PREVIEW) &&
        (op_mode != IRIS_CAMERA_OP_MODE_RDI) &&
        (op_mode != IRIS_CAMERA_OP_MODE_SECURE_RDI)) {
        IRIS_CAMERA_SOURCE_LOGE("Only support preview or rdi op mode");
        return INVALID_OPERATION;
    }

    mPrevSize = size;
    mFrameLen = ((size.width + IRIS_CAMERA_BUF_ALIGNMENT -1) & (~(IRIS_CAMERA_BUF_ALIGNMENT -1))) * size.height;
    //to make it page size aligned
    mFrameLen = (mFrameLen + 4095U) & (~4095U);

    IRIS_CAMERA_SOURCE_LOGD("Set preview size %d x %d", size.width, size.height);

    return NO_ERROR;
}

status_t IrisCameraSource::set_display_size(Size size)
{

    mDisplaySize = size;
    mDisplayFrameLen = ((size.width + IRIS_DISPLAY_BUF_ALIGNMENT - 1) & (~(IRIS_DISPLAY_BUF_ALIGNMENT - 1))) * size.height;
    mDisplayFrameLen = (mDisplayFrameLen + 4095U) & (~4095U);

    IRIS_CAMERA_SOURCE_LOGD("Set display size %d x %d", size.width, size.height);

    return NO_ERROR;
}

status_t IrisCameraSource::set_preview_surface(sp<IGraphicBufferProducer> &bufferProducer) {
    status_t result = NO_ERROR;
    char pval[PROPERTY_VALUE_MAX];
    int property_val;

    IRIS_CAMERA_SOURCE_LOGD("Get preview surface from app");

    // 0: no preview 1: preview
    property_get("persist.iris.preview_mode", pval, "1");
    property_val = atoi(pval);
    if (!property_val) {
        IRIS_CAMERA_SOURCE_LOGD("Force iris camera preview off");
        mDisplay = false;
        return result;
    }

    mBufferProducer = bufferProducer;

    if (mBufferProducer != NULL) {
        result = prepare_surface_buffers();
        if (result == OK) {
            mDisplay = true;
            IRIS_CAMERA_SOURCE_LOGD("Display mode is ON");
        } else {
            mBufferProducer = NULL;
            IRIS_CAMERA_SOURCE_LOGE("Prepare surface buffer failed");
        }
    }

    return result;
}

status_t IrisCameraSource::set_op_mode(int32_t op_mode)
{
    status_t result = NO_ERROR;

    if ((op_mode != IRIS_CAMERA_OP_MODE_PREVIEW) &&
        (op_mode != IRIS_CAMERA_OP_MODE_RDI) &&
        (op_mode != IRIS_CAMERA_OP_MODE_SECURE_RDI)) {
        IRIS_CAMERA_SOURCE_LOGE("Only support preview or rdi op mode");
        return INVALID_OPERATION;
    }

    mOpMode = op_mode;
    mSecure = !!(mOpMode&IRIS_CAMERA_OP_MODE_SECURE);

    return NO_ERROR;
}

status_t IrisCameraSource::open()
{
    status_t result = OK;
    int rc;
    char pval[PROPERTY_VALUE_MAX];
    uint32_t property_val;

    IRIS_CAMERA_SOURCE_LOGD("open camera %d", mCameraId);

    mIonFd = ::open("/dev/ion", O_RDONLY);
    if (mIonFd <= 0) {
        IRIS_CAMERA_SOURCE_LOGE("Ion dev open failed %s\n", strerror(errno));
        return INVALID_OPERATION;
    }

    rc = iris_camera_open(&mCamHandle, mCameraId);
    if (rc != IRIS_CAMERA_OK) {
        IRIS_CAMERA_SOURCE_LOGE("mm_camera_lib_open() err=%d\n", rc);
        return INVALID_OPERATION;
    }

    mCameraNum = iris_camera_get_number_of_cameras(&mCamHandle);
    if ( mCameraId >= mCameraNum ) {
        IRIS_CAMERA_SOURCE_LOGE("Invalid camera index %d (total %d)!", mCameraId, mCameraNum);
        return INVALID_OPERATION;
    }

    if (iris_camera_get_caps(&mCamHandle, &caps) != IRIS_CAMERA_OK) {
        IRIS_CAMERA_SOURCE_LOGE("Can't get camera capbilities");
        return INVALID_OPERATION;
    }

    /* set default parameters based on op_mode */
    mPrevSize.width = 640;
    mPrevSize.height = 480;

    mDisplaySize.width = 0;
    mDisplaySize.height = 0;
    mDisplayFrameLen = 0;

    mBufferProducer = NULL;
    totalFrameCount = 0;
    totalFrameDropCount = 0;

    property_get("persist.iris.camera.exposure", pval, "0");
    property_val = atoi(pval);
    if (property_val != 0 &&
        (property_val >= (caps.min_exp_time_ns / 1000000)) &&
        (property_val <= (caps.max_exp_time_ns / 1000000))) {
        mSensorExpTimeMs = property_val;
        IRIS_CAMERA_SOURCE_LOGD("Retrieve sensor exposure %dms from property", property_val);
    }

    property_get("persist.iris.camera.gain", pval, "0");
    property_val = atoi(pval);
    if (property_val != 0 &&
        (property_val >= (caps.min_gain)) &&
        (property_val <= (caps.max_gain))) {
        mSensorGain = property_val;
        IRIS_CAMERA_SOURCE_LOGD("Retrieve sensor gain %d from property", property_val);
    }

    pthread_mutex_init(&mMutex, NULL);
    pthread_cond_init(&mFrameReadyCond, NULL);

    mOpened = true;

    return result;
}

status_t IrisCameraSource::get_sensor_caps(iris_camera_caps_t &caps)
{
    if (iris_camera_get_caps(&mCamHandle, &caps) != IRIS_CAMERA_OK) {
        IRIS_CAMERA_SOURCE_LOGE("Can't get camera capbilities");
        return INVALID_OPERATION;
    }

    return OK;
}

// Note: this function is called when lock is hold, don't call autoLock again
status_t IrisCameraSource::display_frame(struct iris_cam_surface_buf *surface_buf, uint64_t ts) {
    struct iris_cam_surface_buf *new_surface_buf;

    queue_surface_buffer(surface_buf, ts);
    mDisplaySurfaceBufQueue.push_back(surface_buf);
    surface_buf->state = SURFACE_BUF_STAT_DISP;
    mNumDisplaySurfaceBuf++;
    IRIS_CAMERA_SOURCE_LOGD("display: displayed one new frame %d\n", mNumFramesDisplayed);

    // Only dequeue free buffer from surface when necessary to reduce the latency
    // caused by display sub system
    if (mFreeSurfaceBufQueue.empty()) {
        status_t result = OK;
        int dequeuedSlot = -1;
        sp<Fence> dequeuedFence;

        result = mBufferProducer->dequeueBuffer(&dequeuedSlot, &dequeuedFence,
                                 mDisplaySize.width, mDisplaySize.height, HAL_PIXEL_FORMAT_YCrCb_420_SP,
                                 0);

        if (result == OK) {
            iris_camera_callback_buf_t *org_frame;

            new_surface_buf = *mDisplaySurfaceBufQueue.begin();
            mDisplaySurfaceBufQueue.erase(mDisplaySurfaceBufQueue.begin());
            mNumDisplaySurfaceBuf--;

            if (dequeuedSlot != new_surface_buf->slot) {
                IRIS_CAMERA_SOURCE_LOGE("dequeued surface buf doesn't have the expected slot %d[%d]",
                    dequeuedSlot, new_surface_buf->slot);
            }

            // Wait for release fence
            dequeuedFence->wait(Fence::TIMEOUT_NEVER);
            mFreeSurfaceBufQueue.push_back(new_surface_buf);
            mNumFreeSurfaceBuf++;

            new_surface_buf->state = SURFACE_BUF_STAT_FREE;
            IRIS_CAMERA_SOURCE_LOGD("Dequeued buffer slot %d", dequeuedSlot);
        } else {
            //The first dequeue buffer is expected to be failed
            // since the surface needs to keep one frame
            IRIS_CAMERA_SOURCE_LOGE("dequeue Buffer failed");
        }
    }

    return OK;
}


status_t IrisCameraSource::add_frame(iris_camera_callback_buf_t *frame) {
    iris_camera_callback_buf_t *org_frame;
    iris_camera_callback_buf_t *new_frame = NULL;

    if (((frame->exp_time_ns/1000000) != mSensorExpTimeMs) || (frame->sensitivity != mSensorGain)) {
        //exp_time and gain do not match, but still pass this frame to TZ for processing
        IRIS_CAMERA_SOURCE_LOGD("add_frame: frame param is not match\n");
    }

    new_frame = (iris_camera_callback_buf_t *) malloc(sizeof(*new_frame));
    *new_frame = *frame;
    mem_malloc_count++;

    totalFrameCount++;

    pthread_mutex_lock(&mMutex);

    if (mNumFramesReceived) {
        //discard the one in waiting list
        //should not happen when mDisplay is true
        org_frame = *mFramesReceived.begin();
        mFramesReceived.erase(mFramesReceived.begin());
        mNumFramesReceived--;
        release_frame(org_frame);
        totalFrameDropCount++;
    }
    // data structure will be reused by the camera lib, so duplicate it here
    mFramesReceived.push_back(new_frame);
    mNumFramesReceived++;
    pthread_cond_signal(&mFrameReadyCond);
    pthread_mutex_unlock(&mMutex);

    IRIS_CAMERA_SOURCE_LOGD("add_frame: receive one new frame %d\n", mNumFramesReceived);

    return OK;
}

void IrisCameraSource::preview_cb (iris_camera_callback_buf_t *frame)
{
    IRIS_CAMERA_SOURCE_LOGD("received one preview frame\n");

    g_CamSource->add_frame(frame);
}

status_t IrisCameraSource::set_flash_mode(bool on)
{
    cam_flash_mode_t mode = CAM_FLASH_MODE_OFF;

    if (on) {
           IRIS_CAMERA_SOURCE_LOGD("FLASH_MODE_TORCH\n");
            mode = CAM_FLASH_MODE_TORCH;
    }

    return iris_camera_send_command(&mCamHandle,
                                      IRIS_CAMERA_CMD_FLASH,
                                      &mode,
                                      NULL);
}

status_t IrisCameraSource::set_nr_mode(bool on)
{
    cam_noise_reduction_mode_t mode = CAM_NOISE_REDUCTION_MODE_OFF;

    if (on) {
           IRIS_CAMERA_SOURCE_LOGD("NR_MODE_HQ\n");
            mode = CAM_NOISE_REDUCTION_MODE_HIGH_QUALITY;
    }

    return iris_camera_send_command(&mCamHandle,
                                      IRIS_CAMERA_CMD_SET_NR_MODE,
                                      &mode,
                                      NULL);
}

status_t IrisCameraSource::set_sensor_gain(uint32_t gain)
{
    iris_camera_callback_buf_t *frame;

    if (gain == mSensorGain) {
        IRIS_CAMERA_SOURCE_LOGD("No gain update");
        return OK;
    }

    mSensorGain = gain;
    IRIS_CAMERA_SOURCE_LOGD("Set new sensor gain %d", gain);

    return iris_camera_send_command(&mCamHandle,
                                      IRIS_CAMERA_CMD_AEC_FORCE_GAIN,
                                      &gain,
                                      NULL);
}

status_t IrisCameraSource::set_sensor_exposure_time(uint32_t exp_ms)
{
    iris_camera_callback_buf_t *frame;

    if (exp_ms == mSensorExpTimeMs) {
        IRIS_CAMERA_SOURCE_LOGD("No exposure time update");
        return OK;
    }

    if ((exp_ms < (caps.min_exp_time_ns / 1000000)) ||
        (exp_ms > (caps.max_exp_time_ns / 1000000))) {
        IRIS_CAMERA_SOURCE_LOGE("Invalid exposure time %d, ignore", exp_ms);
        return OK;
    }

    mSensorExpTimeMs = exp_ms;
    IRIS_CAMERA_SOURCE_LOGD("Set new sensor exposure time %dms", exp_ms);

    return iris_camera_send_command(&mCamHandle,
                                      IRIS_CAMERA_CMD_AEC_FORCE_EXP,
                                      &exp_ms,
                                      NULL);
}

struct iris_cam_surface_buf * IrisCameraSource::get_surface_buffers_by_fd(int fb_fd)
{
    int i;
    struct iris_cam_surface_buf *buf = NULL;

    for (i = 0; i < (int)mNumSurfaceBuf; i++) {
        if (fb_fd == mSurfaceBuf[i].ion_fb_fd) {
            buf = &mSurfaceBuf[i];
            break;
        }
    }

    return buf;
}

status_t IrisCameraSource::register_surface_buffer(int slot, sp<GraphicBuffer> dequeuedBuffer)
{
    status_t ret = NO_ERROR;
    int ion_fd;
    struct ion_fd_data ion_info_fd;
    void *vaddr = NULL;
    struct private_handle_t *priv_handle;
    struct iris_cam_surface_buf *surface_buf = NULL;

    surface_buf = &mSurfaceBuf[slot];
    if (surface_buf->buffer != NULL) {
        IRIS_CAMERA_SOURCE_LOGE("This buffer slot has been registered already");
        return INVALID_OPERATION;
    }

    memset(&ion_info_fd, 0, sizeof(ion_info_fd));
    priv_handle = (struct private_handle_t *)(dequeuedBuffer->handle);

    ion_fd = ::open("/dev/ion", O_RDONLY);
    if (ion_fd < 0) {
        IRIS_CAMERA_SOURCE_LOGE("failed: could not open ion device");
        ret = NO_MEMORY;
        goto end;
    } else {
        ion_info_fd.fd = priv_handle->fd;
        if (::ioctl(ion_fd,
                  ION_IOC_IMPORT, &ion_info_fd) < 0) {
            LOGE("ION import failed\n");
            ::close(ion_fd);
            ret = NO_MEMORY;
            goto end;
        }
    }
    IRIS_CAMERA_SOURCE_LOGD("fd = %d, size = %d, offset = %d slot %d",
            priv_handle->fd,
            priv_handle->size,
            priv_handle->offset,
            slot);

    surface_buf->ion_dev_fd = ion_fd;
    surface_buf->ion_fb_fd = ion_info_fd.fd;
    surface_buf->size = priv_handle->size;
    surface_buf->ion_fb_handle = ion_info_fd.handle;
    //Only allocate secure buffer from surface, so no virtual address will be mapped
    surface_buf->vaddr = NULL;
    surface_buf->state = SURFACE_BUF_STAT_FREE;
    surface_buf->slot = slot;
    surface_buf->native_buffer = dequeuedBuffer->getNativeBuffer();
    surface_buf->buffer = dequeuedBuffer;
    surface_buf->initialized = false;

    mFreeSurfaceBufQueue.push_back(surface_buf);
    mNumFreeSurfaceBuf++;

end:
    LOGD("X ");
    return ret;
}

void IrisCameraSource::unregister_surface_buffer(int slot)
{
    struct iris_cam_surface_buf *surface_buf;

    surface_buf = &mSurfaceBuf[slot];

    if (surface_buf->vaddr) {
        munmap(surface_buf->vaddr, surface_buf->size);
    }

    if (surface_buf->ion_dev_fd > 0) {
        ioctl(surface_buf->ion_dev_fd, ION_IOC_FREE, &surface_buf->ion_fb_handle);
        ::close(surface_buf->ion_dev_fd);
    }
    surface_buf->buffer = NULL;
}

status_t IrisCameraSource::queue_surface_buffer(struct iris_cam_surface_buf *surface_buf, int64_t timestamp)
{
    IGraphicBufferProducer::QueueBufferOutput output;

    IGraphicBufferProducer::QueueBufferInput input = IGraphicBufferProducer::QueueBufferInput(
                timestamp,
                false,
                HAL_DATASPACE_UNKNOWN,
                Rect(0, 0, mDisplaySize.width, mDisplaySize.height),
                0,
                0,
                Fence::NO_FENCE);

    return mBufferProducer->queueBuffer(surface_buf->slot, input, &output);
}

status_t IrisCameraSource::prepare_surface_buffers()
{
    status_t result = OK;
    int minBuffers;
    int dequeuedSlot = -1, i = 0;
    sp<Fence> dequeuedFence;
    sp<GraphicBuffer> dequeuedBuffer;
    int dequeueFlag = 0;
    IGraphicBufferProducer::QueueBufferOutput output;

    if (mBufferProducer == NULL) {
        IRIS_CAMERA_SOURCE_LOGD("Buffer procuder is not available");
        return OK;
    }

    memset(mSurfaceBuf, 0, sizeof (struct iris_cam_surface_buf) * IRIS_CAMERA_SD_FRAME_NUM);
    //Only allocate secure buffer from surface
    dequeueFlag = GRALLOC_USAGE_HW_CAMERA_WRITE|GRALLOC_USAGE_HW_COMPOSER|GRALLOC_USAGE_HW_FB |
                    GRALLOC_USAGE_PRIVATE_MM_HEAP | GRALLOC_USAGE_PROTECTED |
                    GRALLOC_USAGE_PRIVATE_UNCACHED;


    mBufferProducer->connect((IProducerListener*)(NULL),
                                     NATIVE_WINDOW_API_CPU,
                                     false,
                                     &output);
    mBufferProducer->query(NATIVE_WINDOW_MIN_UNDEQUEUED_BUFFERS, &minBuffers);

    if (minBuffers > IRIS_CAMERA_SD_FRAME_NUM) {
        IRIS_CAMERA_SOURCE_LOGE("Minimum buffer num exceeds camera requirement %d:%d", minBuffers, IRIS_CAMERA_SD_FRAME_NUM);
        return INVALID_OPERATION;
    }
    minBuffers = IRIS_CAMERA_SD_FRAME_NUM;
    IRIS_CAMERA_SOURCE_LOGD("Set surface buffer num %d", minBuffers);
    mNumSurfaceBuf = minBuffers;

    result = mBufferProducer->setMaxDequeuedBufferCount(minBuffers);
    if (OK != result) {
        IRIS_CAMERA_SOURCE_LOGE("Set surface buffer count failed");
        return result;
    }

    for (i = 0; i < (int)mNumSurfaceBuf; i++) {
        result = mBufferProducer->dequeueBuffer(&dequeuedSlot, &dequeuedFence,
                                 mDisplaySize.width, mDisplaySize.height, HAL_PIXEL_FORMAT_YCrCb_420_SP,
                                 dequeueFlag);

        if (result == IGraphicBufferProducer::BUFFER_NEEDS_REALLOCATION) {
            IRIS_CAMERA_SOURCE_LOGD("Dequeue buf slot %d from surface", dequeuedSlot);
            result = mBufferProducer->requestBuffer(dequeuedSlot, &dequeuedBuffer);
            if (OK != result) {
                IRIS_CAMERA_SOURCE_LOGE("Request buffer from surface failed");
                goto deq_buf_fail;
            }

            dequeuedFence->wait(Fence::TIMEOUT_NEVER);

            register_surface_buffer(dequeuedSlot, dequeuedBuffer);
        } else if (result == OK) {
            // Should not happen
            IRIS_CAMERA_SOURCE_LOGE("Buf dequeued slot %d", dequeuedSlot);
        } else {
            IRIS_CAMERA_SOURCE_LOGE("dequeue Buffer failed");
            result = INVALID_OPERATION;
            goto deq_buf_fail;
        }
    }

    return OK;

deq_buf_fail:
    for (i = 0; i < (int)mNumSurfaceBuf; i++) {
        if (mSurfaceBuf[i].buffer != NULL) {
            unregister_surface_buffer(mSurfaceBuf[i].slot);
            mBufferProducer->cancelBuffer(mSurfaceBuf[i].slot, Fence::NO_FENCE);
        }
    }
    return result;
}

// Called after stop stream to release all surface buffers
status_t IrisCameraSource::reset_surface_buffers()
{
    struct iris_cam_surface_buf *surface_buf = NULL;
    int i;

    for (i = 0; i < (int)mNumSurfaceBuf; i++) {
        surface_buf = &mSurfaceBuf[i];
        if (surface_buf->buffer != NULL) {
            IRIS_CAMERA_SOURCE_LOGD("Unregister surface buffer %d", mSurfaceBuf[i].slot);
            unregister_surface_buffer(mSurfaceBuf[i].slot);

            if (surface_buf->state != SURFACE_BUF_STAT_DISP)
                mBufferProducer->cancelBuffer(surface_buf->slot, Fence::NO_FENCE);
        }
        surface_buf->buffer = NULL;
    }

    return OK;
}

status_t IrisCameraSource::start()
{
    status_t result = OK;
    int i;
    struct iris_cam_ion_buf *buf;

    IRIS_CAMERA_SOURCE_LOGD("start");

    if (!mSecure) {
        //allocate ION buffer from QSEECOM heap for none-secure camera usecase
        for (i = 0; i < IRIS_CAMERA_MAX_FRAME_NUM; i++) {
            buf = allocIonBuf();
            if (!buf) {
                IRIS_CAMERA_SOURCE_LOGE("Fail to allocate ion buf");
                goto START_FAILED;
            }

            mFreeIonFrameQueue.push_back(buf);
            mNumFreeIonFrame++;
        }
    }

    nextDumpFrameIndex = 1;

    iris_camera_set_preview_resolution(&mCamHandle, mPrevSize.width, mPrevSize.height);
    iris_camera_set_preview_cb(&mCamHandle, preview_cb);
    iris_camera_send_command(&mCamHandle,
                                      IRIS_CAMERA_CMD_AEC_FORCE_EXP,
                                      &mSensorExpTimeMs,
                                      NULL);
    iris_camera_send_command(&mCamHandle,
                                      IRIS_CAMERA_CMD_AEC_FORCE_GAIN,
                                      &mSensorGain,
                                      NULL);

    if (IRIS_CAMERA_OK != iris_camera_open_preview(&mCamHandle,
        !!(mOpMode&IRIS_CAMERA_OP_MODE_RDI),
        mSecure)) {
        IRIS_CAMERA_SOURCE_LOGE("iris_camera_open_preview failed\n");
        goto START_FAILED;
    }

    IRIS_CAMERA_SOURCE_LOGD("ACTION_START_PREVIEW \n");
    if (IRIS_CAMERA_OK != iris_camera_start_preview(&mCamHandle)) {
        IRIS_CAMERA_SOURCE_LOGE("iris_camera_start_preview failed\n");
        return INVALID_OPERATION;
    }
    IRIS_CAMERA_SOURCE_LOGD("Enable flash\n");
    set_flash_mode(true);

    mStarted = true;
    gettimeofday (&mStartTime, NULL);

    return result;

START_FAILED:
    stop();
    return INVALID_OPERATION;
}

status_t IrisCameraSource::stop()
{
    int rc = 0, i;
    iris_camera_callback_buf_t *frame;
    struct iris_cam_ion_buf *buf;
    struct iris_cam_surface_buf *surface_buf;
    struct timeval cur_time;

    IRIS_CAMERA_SOURCE_LOGD("stop");

    if (!mOpened) {
        IRIS_CAMERA_SOURCE_LOGE("Iris camera is closed");
        return OK;
    }

    gettimeofday (&cur_time, NULL);
    IRIS_CAMERA_SOURCE_LOGD("Total frame received %d dropped %d", totalFrameCount, totalFrameDropCount);
    IRIS_CAMERA_SOURCE_LOGD("Framerate is %d", (int)(totalFrameCount * 1000/((cur_time.tv_usec - mStartTime.tv_usec)/1000 + (cur_time.tv_sec - mStartTime.tv_sec)*1000)));

    rc = iris_camera_stop_preview(&mCamHandle);
    if (rc != IRIS_CAMERA_OK) {
        IRIS_CAMERA_SOURCE_LOGE("iris_camera_stop_stream() err=%d", rc);
    }

    mStarted = false;

    pthread_mutex_lock(&mMutex);
    while (mNumFramesProcessed > 0) {
        frame = *mFramesProcessed.begin();
        mFramesProcessed.erase(mFramesProcessed.begin());
        mNumFramesProcessed--;
        release_frame(frame);
    }

    while (mNumFramesReceived > 0) {
        frame = *mFramesReceived.begin();
        mFramesReceived.erase(mFramesReceived.begin());
        mNumFramesReceived--;
        release_frame(frame);
    }

    while (mNumFramesDisplayed > 0) {
        frame = *mFramesDisplayed.begin();
        mFramesDisplayed.erase(mFramesDisplayed.begin());
        mNumFramesDisplayed--;
        release_frame(frame);
    }

    while (mNumFreeIonFrame > 0) {
        buf = *mFreeIonFrameQueue.begin();
        mFreeIonFrameQueue.erase(mFreeIonFrameQueue.begin());
        mNumFreeIonFrame--;
        releaseIonBuf(buf);
    }

    while (mNumActiveIonFrame > 0) {
        buf = *mActiveIonFrameQueue.begin();
        mActiveIonFrameQueue.erase(mActiveIonFrameQueue.begin());
        mNumActiveIonFrame--;
        releaseIonBuf(buf);
    }

    if (mDisplay) {
        while (mNumFreeSurfaceBuf > 0) {
            surface_buf = *mFreeSurfaceBufQueue.begin();
            mFreeSurfaceBufQueue.erase(mFreeSurfaceBufQueue.begin());
            mNumFreeSurfaceBuf--;
        }

        while (mNumTzSurfaceBuf > 0) {
            surface_buf = *mTzSurfaceBufQueue.begin();
            mTzSurfaceBufQueue.erase(mTzSurfaceBufQueue.begin());
            mNumTzSurfaceBuf--;
        }

        while (mNumDisplaySurfaceBuf > 0) {
            surface_buf = *mDisplaySurfaceBufQueue.begin();
            mDisplaySurfaceBufQueue.erase(mDisplaySurfaceBufQueue.begin());
            mNumDisplaySurfaceBuf--;
        }
        reset_surface_buffers();
        IRIS_CAMERA_SOURCE_LOGD("Reset all surface buffers");
    }
    pthread_mutex_unlock(&mMutex);

    return OK;
}

status_t IrisCameraSource::close()
{
    char pval[PROPERTY_VALUE_MAX];
    int property_val;

    IRIS_CAMERA_SOURCE_LOGD("close");

    if (!mOpened) {
        IRIS_CAMERA_SOURCE_LOGE("Iris camera is closed");
        return OK;
    }

    if (mIonFd > 0)
        ::close(mIonFd);

    iris_camera_close(&mCamHandle);

    mBufferProducer = NULL;

    pthread_mutex_destroy(&mMutex);
    pthread_cond_destroy(&mFrameReadyCond);

    // If property doesn't exit or 0, don't save sensor params
    property_get("persist.iris.camera.exposure", pval, "0");
    property_val = atoi(pval);
    if (property_val) {
        snprintf(pval, PROPERTY_VALUE_MAX, "%d", mSensorExpTimeMs);
        property_set("persist.iris.camera.exposure", pval);
        IRIS_CAMERA_SOURCE_LOGD("Record Sensor Exp_Time %dms", mSensorExpTimeMs);
    }

    property_get("persist.iris.camera.gain", pval, "0");
    property_val = atoi(pval);
    if (property_val) {
        snprintf(pval, PROPERTY_VALUE_MAX, "%d", mSensorGain);
        property_set("persist.iris.camera.gain", pval);
        IRIS_CAMERA_SOURCE_LOGD("Record Sensor gain %d", mSensorGain);
    }

    if (mem_malloc_count != mem_free_count)
        IRIS_CAMERA_SOURCE_LOGE("WARNING: memory leak! malloc count %d free count %d",
            mem_malloc_count, mem_free_count);

    mOpened = false;

    return OK;
}

struct iris_cam_ion_buf *IrisCameraSource::allocIonBuf( )
{
    int rc = 0;
    struct ion_handle_data handle_data;
    struct ion_allocation_data alloc;
    struct ion_fd_data ion_info_fd;
    void *data = NULL;
    struct iris_cam_ion_buf *buf = NULL;

    buf = (struct iris_cam_ion_buf *)malloc(sizeof(*buf));
    if (!buf) {
        IRIS_CAMERA_SOURCE_LOGE("Failed to alloc cam_ion_buf");
        return NULL;
    }
    mem_malloc_count++;
    memset(&alloc, 0, sizeof(alloc));
    alloc.len = mFrameLen;
    alloc.align = 4096;
    alloc.heap_id_mask = ION_HEAP(ION_QSECOM_HEAP_ID);
    rc = ioctl(mIonFd, ION_IOC_ALLOC, &alloc);
    if (rc < 0) {
        IRIS_CAMERA_SOURCE_LOGE("ION allocation failed %s with rc = %d \n",strerror(errno), rc);
        goto ION_ALLOC_FAILED;
    }

    memset(&ion_info_fd, 0, sizeof(ion_info_fd));
    ion_info_fd.handle = alloc.handle;
    rc = ioctl(mIonFd, ION_IOC_SHARE, &ion_info_fd);
    if (rc < 0) {
        IRIS_CAMERA_SOURCE_LOGE("ION map failed %s\n", strerror(errno));
        goto ION_MAP_FAILED;
    }

    data = mmap(NULL,
                alloc.len,
                PROT_READ  | PROT_WRITE,
                MAP_SHARED,
                ion_info_fd.fd,
                0);

    if (data == MAP_FAILED) {
        IRIS_CAMERA_SOURCE_LOGE("ION_MMAP_FAILED: fd %d %s (%d)\n", ion_info_fd.fd, strerror(errno), errno);
        goto ION_MAP_FAILED;
    }

    buf->ion_dev_fd = mIonFd;
    buf->ion_buf_fd = ion_info_fd.fd;
    buf->ion_buf_handle = ion_info_fd.handle;
    buf->size = alloc.len;
    buf->data = data;

    return buf;

ION_MAP_FAILED:
    memset(&handle_data, 0, sizeof(handle_data));
    handle_data.handle = ion_info_fd.handle;
    ioctl(mIonFd, ION_IOC_FREE, &handle_data);
ION_ALLOC_FAILED:
    free(buf);
    mem_free_count++;
    IRIS_CAMERA_SOURCE_LOGE("Failed with error code %d", rc);

    return NULL;
}

int IrisCameraSource::cloneIonBuf(iris_camera_callback_buf_t *frame, struct iris_cam_ion_buf * buf)
{
    void *org_data = NULL;

    if (!buf || !frame) {
        IRIS_CAMERA_SOURCE_LOGE("No ION buffer is allocated\n");
        return -1;
    }

    org_data = mmap(NULL,
                buf->size,
                PROT_READ  | PROT_WRITE,
                MAP_SHARED,
                frame->frame->fd,
                0);
    if (org_data == MAP_FAILED) {
        IRIS_CAMERA_SOURCE_LOGE("ION_MMAP_FAILED: fd %d org buf %s (%d)\n", frame->frame->fd, strerror(errno), errno);
        return -1;
    }

    memcpy(buf->data, org_data, buf->size);
    munmap(org_data, buf->size);

    return 0;
}

int IrisCameraSource::releaseIonBuf(struct iris_cam_ion_buf *buf)
{
    struct ion_handle_data handle_data;
    int rc = 0;

    if (!buf) {
        IRIS_CAMERA_SOURCE_LOGE("ION buffer is not valid\n");
        return -1;
    }

    rc = munmap(buf->data, buf->size);

    if (buf->ion_buf_fd >= 0) {
        ::close(buf->ion_buf_fd);
    }

    memset(&handle_data, 0, sizeof(handle_data));
    handle_data.handle = buf->ion_buf_handle;
    ioctl(buf->ion_dev_fd, ION_IOC_FREE, &handle_data);
    free(buf);
    mem_free_count++;
    IRIS_CAMERA_SOURCE_LOGD("Released one ION buf");

    return rc;
}

void IrisCameraSource::dump_frame(iris_frame &frame) {
    FILE *f;
    void *ret;
    int bufferFD = frame.frame_handle;
    char filename[256];
    char pval[PROPERTY_VALUE_MAX];
    int property_val;

    property_get("persist.iris.camera.dumpframe", pval, "0");
    property_val = atoi(pval);

    if (!property_val) {
        IRIS_CAMERA_SOURCE_LOGD("No frame dump");
        return;
    }

    sprintf(filename, "/data/misc/camera/iris_camera_dump_%d_exp_%d_gain_%d.raw", nextDumpFrameIndex,
        frame.info.frame_config.exposure_ms, frame.info.frame_config.gain);

    ret = ::mmap(NULL,
        frame.frame_len,
        PROT_READ  | PROT_WRITE,
        MAP_SHARED,
        bufferFD,
        0);

    if (ret == MAP_FAILED) {
        IRIS_CAMERA_SOURCE_LOGE("mmap failed");
        return;
    }

    f = fopen(filename, "wb+");

    if (f == NULL) {
        IRIS_CAMERA_SOURCE_LOGE("%s: fopen %s failed: %d", __func__, filename, errno);
        ::munmap(ret, frame.frame_len);
        return;
    }

    IRIS_CAMERA_SOURCE_LOGE("dump file %p size %d to file %s\n", ret, frame.frame_len, filename);
    size_t n = fwrite(ret, frame.frame_len, 1, f);
    if (n != 1) {
        ::munmap(ret, frame.frame_len);
        fclose(f);
        IRIS_CAMERA_SOURCE_LOGE("%s: fwrite failed size %d (%u): %d", __func__, frame.frame_len, (unsigned)n, errno);
        return;
    }

    ::munmap(ret, frame.frame_len);
    fclose(f);
    nextDumpFrameIndex++;
}

status_t IrisCameraSource::get_frame(iris_frame &frame, iris_frame &display_frame) {
    iris_camera_callback_buf_t *org_frame;
    struct timeval tv_start, tv_end;
    struct iris_cam_ion_buf *buf;
    struct iris_cam_surface_buf *surface_buf;
    uint32_t orientationFlag = 0;

    IRIS_CAMERA_SOURCE_LOGD("Enter get_frame");
    if (mFramesReceived.empty()) {
        IRIS_CAMERA_SOURCE_LOGE("No frame available");
        return NOT_ENOUGH_DATA;
    }

    if (mFreeIonFrameQueue.empty() && !mSecure) {
        IRIS_CAMERA_SOURCE_LOGE("No free ION buf available");
        return NOT_ENOUGH_DATA;
    }

    if (mFreeSurfaceBufQueue.empty() && mDisplay) {
        IRIS_CAMERA_SOURCE_LOGE("No free Surface buf available");
        return NOT_ENOUGH_DATA;
    }

    pthread_mutex_lock(&mMutex);
    org_frame = *mFramesReceived.begin();
    mFramesReceived.erase(mFramesReceived.begin());
    mNumFramesReceived--;

    if (!mSecure) {
        buf = *mFreeIonFrameQueue.begin();
        mFreeIonFrameQueue.erase(mFreeIonFrameQueue.begin());
        mNumFreeIonFrame--;
    }

    if (mDisplay) {
        surface_buf = *mFreeSurfaceBufQueue.begin();
        mFreeSurfaceBufQueue.erase(mFreeSurfaceBufQueue.begin());
        mNumFreeSurfaceBuf--;
    }
    pthread_mutex_unlock(&mMutex);

    IRIS_CAMERA_SOURCE_LOGD("get frame buffer fd %d\n", org_frame->frame->fd);

    if (!mSecure) {
        //copy to QSEECOM ion fd
        gettimeofday (&tv_start, NULL);

        if (cloneIonBuf(org_frame, buf) < 0) {
            IRIS_CAMERA_SOURCE_LOGE("Failed to alloc ION buf");
            return -1;
        }
        gettimeofday (&tv_end, NULL);
        IRIS_CAMERA_SOURCE_LOGD("Clone time is %d ms", (int)((tv_end.tv_usec - tv_start.tv_usec)/1000 + (tv_end.tv_sec - tv_start.tv_sec)*1000));

        frame.frame_handle = buf->ion_buf_fd;
    } else {
        frame.frame_handle = org_frame->frame->fd;
    }

    frame.frame_len = mFrameLen;
    frame.info.format = IRIS_COLOR_FORMAT_Y_ONLY;
    frame.info.width = mPrevSize.width;
    frame.info.height = mPrevSize.height;
    frame.info.stride = mPrevSize.width; //TODO: may need to align
    frame.info.frame_config.gain = org_frame->sensitivity;
    frame.info.frame_config.exposure_ms = org_frame->exp_time_ns/1000000;

    if (mOrientation == -1)
        orientationFlag = IRIS_FRAME_FLAG_ORIENTATION_MASK;
    else
        orientationFlag = (mOrientation << IRIS_FRAME_FLAG_ORIENTATION_BIT ) & IRIS_FRAME_FLAG_ORIENTATION_MASK;

    frame.frame_flag = orientationFlag;

    IRIS_CAMERA_SOURCE_LOGD("frame orientation = %d", mOrientation);

    if (mDisplay) {
        display_frame.info.format = IRIS_COLOR_FORMAT_Y_ONLY;
        display_frame.info.width = mDisplaySize.width;
        display_frame.info.height = mDisplaySize.height;
        display_frame.info.stride = (mDisplaySize.width + IRIS_DISPLAY_BUF_ALIGNMENT - 1) & (~(IRIS_DISPLAY_BUF_ALIGNMENT - 1));
        display_frame.info.frame_config.gain = 0;
        display_frame.info.frame_config.exposure_ms = 0;
        display_frame.frame_handle = surface_buf->ion_fb_fd;
        display_frame.frame_flag = orientationFlag;
        if (!surface_buf->initialized) {
            display_frame.frame_len = surface_buf->size;
            display_frame.frame_flag |= 1 << IRIS_FRAME_FLAG_REQUIRE_INIT_BIT;
            surface_buf->initialized = true;
        } else {
            //pass Y plane size only to reduce the memory size
            display_frame.frame_len = mDisplayFrameLen;
        }
    } else {
        memset(&display_frame, 0, sizeof (iris_frame));
    }

    if (!mSecure) {
        dump_frame(frame);
    }

    pthread_mutex_lock(&mMutex);
    if (!mSecure) {
        mActiveIonFrameQueue.push_back(buf);
        mNumActiveIonFrame++;
    }

    if (mDisplay) {
        mTzSurfaceBufQueue.push_back(surface_buf);
        mNumTzSurfaceBuf++;
    }

    mFramesProcessed.push_back(org_frame);
    mNumFramesProcessed++;
    pthread_mutex_unlock(&mMutex);

    IRIS_CAMERA_SOURCE_LOGD("get_frame: deliver one frame fd %d %d gain %d exp_time %dms\n",
            frame.frame_handle, mNumFramesReceived, frame.info.frame_config.gain, frame.info.frame_config.exposure_ms);

    return OK;
}

void IrisCameraSource::put_frame(iris_frame &frame, iris_frame &preview_frame) {
    iris_camera_callback_buf_t *org_frame;
    struct iris_cam_ion_buf *buf;
    struct iris_cam_surface_buf *surface_buf;
    uint64_t ts;

    pthread_mutex_lock(&mMutex);
    org_frame = *mFramesProcessed.begin();
    mFramesProcessed.erase(mFramesProcessed.begin());
    mNumFramesProcessed--;

    if (!mSecure) {
        buf = *mActiveIonFrameQueue.begin();
        mActiveIonFrameQueue.erase(mActiveIonFrameQueue.begin());
        mNumActiveIonFrame--;
        mFreeIonFrameQueue.push_back(buf);
        mNumFreeIonFrame++;

        if (frame.frame_handle != (uint32_t)buf->ion_buf_fd) {
            IRIS_CAMERA_SOURCE_LOGE("Released frame doesn't match with record\n");
        }
    }
    pthread_mutex_unlock(&mMutex);

    ts = org_frame->frame->ts.tv_sec * 1000000000 + org_frame->frame->ts.tv_nsec;

    IRIS_CAMERA_SOURCE_LOGD("put_frame: release one frame fd %d %d\n", frame.frame_handle, mNumFramesProcessed);
    release_frame(org_frame);

    if (mDisplay && preview_frame.frame_len) {
        pthread_mutex_lock(&mMutex);
        surface_buf = *mTzSurfaceBufQueue.begin();
        mTzSurfaceBufQueue.erase(mTzSurfaceBufQueue.begin());
        mNumTzSurfaceBuf--;

        if (surface_buf->ion_fb_fd != (int)preview_frame.frame_handle) {
            IRIS_CAMERA_SOURCE_LOGE("display frame buf fd doesn't match");
        }

        display_frame(surface_buf, ts);
        pthread_mutex_unlock(&mMutex);
    }
}

status_t IrisCameraSource::wait_for_frame_available(uint32_t timeout_ms)
{
    status_t ret = OK;
    struct timespec ts;
    int rc;

    pthread_mutex_lock(&mMutex);
    while (mNumFramesReceived == 0) {
        rc = clock_gettime(CLOCK_REALTIME, &ts);
        if (rc < 0) {
            IRIS_CAMERA_SOURCE_LOGE("Error reading the real time clock!!");
            ret = INVALID_OPERATION;
            break;
        } else {
            ts.tv_sec += timeout_ms/1000;
            ts.tv_nsec  += (timeout_ms%1000) * 1000000;
            rc = pthread_cond_timedwait(&mFrameReadyCond, &mMutex, &ts);
            if (rc == ETIMEDOUT) {
                IRIS_CAMERA_SOURCE_LOGE("Unblocked on timeout!!!!");
                ret = TIMED_OUT;
                break;
            } else if (mNumFramesReceived > 0) {
                ret = OK;
                break;
            }
        }
    }
    pthread_mutex_unlock(&mMutex);

    return ret;
}

void IrisCameraSource::release_frame(iris_camera_callback_buf_t *frame)
{
    struct iris_cam_surface_buf *surface_buf = NULL;

    IRIS_CAMERA_SOURCE_LOGD("Release one frame");
    iris_camera_release_preview_buf(frame);

    free(frame);
    mem_free_count++;
}

void IrisCameraSource::set_frame_orientation(int orientation)
{
    mOrientation = orientation;
}

