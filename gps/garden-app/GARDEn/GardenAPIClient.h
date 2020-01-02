/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  =============================================================================*/

#ifndef GARDEN_API_CLINET_H
#define GARDEN_API_CLINET_H

#include <MsgTask.h>
#include <LocTimer.h>
#include <LocationAPIClientBase.h>
#include "test_android_gps.h"

using namespace std;

typedef enum {
    GARDEN_TEST_NONE            = 0,
    GARDEN_TEST_SESSIONLOOP     = (1 << 0),
    GARDEN_TEST_TRACKING        = (1 << 1),
    GARDEN_TEST_NIBACKTOBACK    = (1 << 2),
    GARDEN_TEST_ALL             = (~0L),
} GARDEN_TEST_FLAG;

typedef function<void()> Runnable;

class LocMsgWrapper : public LocMsg {
public:
    LocMsgWrapper(Runnable& runnable) : mRunnable(move(runnable)) {
    }

    virtual void proc() const {
        mRunnable();
    }
private:
    Runnable mRunnable;
};

class GardenTimer : public LocTimer {
public:
    GardenTimer() : LocTimer(), mStarted(false) {}
    inline ~GardenTimer() { stop(); }
    inline void set(const time_t waitTimeSec, const Runnable& runable) {
        mWaitTimeInMs = waitTimeSec * 1000;
        mRunnable = runable;
    }
    inline void start() {
        mStarted = true;
        LocTimer::start(mWaitTimeInMs, false);
    }
    inline void start(const time_t waitTimeSec) {
        mWaitTimeInMs = waitTimeSec * 1000;
        start();
    }
    inline void stop() {
        if (mStarted) {
            LocTimer::stop();
            mStarted = false;
        }
    }
    inline void restart() { stop(); start(); }
    inline void restart(const time_t waitTimeSec) { stop(); start(waitTimeSec); }
    inline bool isStarted() { return mStarted; }

private:
    // Override
    inline virtual void timeOutCallback() override {
        mStarted = false;
        mRunnable();
    }

private:
    time_t mWaitTimeInMs;
    Runnable mRunnable;
    bool mStarted;

};

class GardenAPIClient : public LocationAPIClientBase
{
public:
    GardenAPIClient(CommandLineOptionsType& options);
    virtual ~GardenAPIClient();

    void gnssDeleteAidingData(uint64_t f);
    void gnssSetPositionMode(int mode, int interval, int accuracy);
    int gnssStart();
    int gnssStop();

    // test cases
    void networkInitiated();
    void sessionLoop();
    void startTracking();

    // callbacks we are interested in
    void onCapabilitiesCb(LocationCapabilitiesMask capabilitiesMask) final;
    void onTrackingCb(Location location) final;
    void onGnssNiCb(uint32_t id, GnssNiNotification gnssNiNotification) final;
    void onGnssSvCb(GnssSvNotification gnssSvNotification) final;
    void onGnssNmeaCb(GnssNmeaNotification gnssNmeaNotification) final;
    void onGnssMeasurementsCb(GnssMeasurementsNotification gnssMeasurementsNotification) final;

    void onStartTrackingCb(LocationError error) final;
    void onStopTrackingCb(LocationError error) final;

private:
    void setFlag(GARDEN_TEST_FLAG flag);
    bool hasFlag(GARDEN_TEST_FLAG flag);
    void unsetFlag(GARDEN_TEST_FLAG flag);
    void sessionStep();
    void sessionStop();
    void sync();
    void sendMsg(Runnable& runnable) const;

private:
    int mTestFlag;
    MsgTask* mMsgTask;
    int64_t mTtffSecs;
    int mSessionCount;
    bool mSessionStart;
    int mNiCount;
    int mNiCbCount;
    LocationAPIControlClient* mControlClient;
    LocationCapabilitiesMask mLocationCapabilitiesMask;
    CommandLineOptionsType mOptions;

    LocationOptions mLocationOptions;

    time_t startTime;
    time_t firstFixTime;
    GardenTimer mSessionTimer;

    pthread_mutex_t mLock;
    pthread_cond_t mCond;
};
#endif // GARDEN_API_CLINET_H
