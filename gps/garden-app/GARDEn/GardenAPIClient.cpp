/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  =============================================================================*/

#define LOG_NDDEBUG 0
#define LOG_TAG "GardenAPIClient"

#include "GardenAPIClient.h"
#include <LocDualContext.h>

#ifdef __ANDROID__
#include <EventObserver.h>
#include "garden_app_session_tracker.h"

static garden_app_session_tracker* gGardenSessionControl = NULL;
static EventObserver* gEventObserver = NULL;
static void rxSystemEvent(unsigned int systemEvent)
{
    LOC_LOGV("%s: SYSTEM EVENT = %d\n", __func__, systemEvent);
    if (NULL != gGardenSessionControl)
    {
        gGardenSessionControl->process_system_event(systemEvent);
    }
}
#endif

GardenAPIClient::GardenAPIClient(CommandLineOptionsType& options) :
    LocationAPIClientBase(),
    mTestFlag(GARDEN_TEST_NONE),
    mMsgTask(new MsgTask("Garden MsgTask", false)),
    mTtffSecs(-1),
    mSessionCount(0),
    mSessionStart(false),
    mNiCount(0),
    mNiCbCount(0),
    mControlClient(new LocationAPIControlClient()),
    mLocationCapabilitiesMask(0),
    mOptions(options)
{
    pthread_mutex_init(&mLock, NULL);
    pthread_cond_init (&mCond, NULL);

    // set default LocationOptions.
    memset(&mLocationOptions, 0, sizeof(LocationOptions));
    mLocationOptions.size = sizeof(LocationOptions);
    mLocationOptions.minInterval = mOptions.interval;
    mLocationOptions.minDistance = mOptions.accuracy;
    mLocationOptions.mode = (GnssSuplMode)mOptions.positionMode;

    // this Runnable will be called from timer thread
    Runnable timerRunnable = [this] {
        // this Runnable will be called from MsgTask thread
        Runnable runnable = [this] {
            sessionStop();
        };
        sendMsg(runnable);
    };
    mSessionTimer.set(mOptions.t, timerRunnable);

    startTime = firstFixTime = 0;
    startTime = getUpTimeSec();

    LocationCallbacks locationCallbacks;
    memset(&locationCallbacks, 0, sizeof(LocationCallbacks));
    locationCallbacks.size = sizeof(LocationCallbacks);

    locationCallbacks.trackingCb = nullptr;
    locationCallbacks.trackingCb = [this](Location location) {
        onTrackingCb(location);
    };

    locationCallbacks.batchingCb = nullptr;
    locationCallbacks.geofenceBreachCb = nullptr;
    locationCallbacks.geofenceStatusCb = nullptr;
    locationCallbacks.gnssLocationInfoCb = nullptr;

    locationCallbacks.gnssNiCb = nullptr;
    locationCallbacks.gnssNiCb = [this](uint32_t id, GnssNiNotification gnssNiNotification) {
        onGnssNiCb(id, gnssNiNotification);
    };

    locationCallbacks.gnssSvCb = nullptr;
    locationCallbacks.gnssSvCb = [this](GnssSvNotification gnssSvNotification) {
        onGnssSvCb(gnssSvNotification);
    };

    locationCallbacks.gnssNmeaCb = nullptr;
    locationCallbacks.gnssNmeaCb = [this](GnssNmeaNotification gnssNmeaNotification) {
        onGnssNmeaCb(gnssNmeaNotification);
    };

    locationCallbacks.gnssMeasurementsCb = nullptr;
    locationCallbacks.gnssMeasurementsCb = [this](GnssMeasurementsNotification gnssMeasurementsNotification) {
       onGnssMeasurementsCb(gnssMeasurementsNotification);
    };

    locAPISetCallbacks(locationCallbacks);
}

GardenAPIClient::~GardenAPIClient()
{
    if (mSessionTimer.isStarted()) {
        mSessionTimer.stop();
    }
#ifdef __ANDROID__
    if (gEventObserver) {
        delete gEventObserver;
    }
    if (gGardenSessionControl) {
        delete gGardenSessionControl;
    }
#endif
    if (mMsgTask)
        mMsgTask->destroy();

    if (mControlClient) {
        delete mControlClient;
        mControlClient = nullptr;
    }

    pthread_mutex_destroy(&mLock);
    pthread_cond_destroy(&mCond);
}

void GardenAPIClient::gnssDeleteAidingData(uint64_t f)
{
    if (mControlClient == nullptr) return;

    GnssAidingData data;
    memset(&data, 0, sizeof (GnssAidingData));
    data.sv.svTypeMask = GNSS_AIDING_DATA_SV_TYPE_GPS_BIT |
        GNSS_AIDING_DATA_SV_TYPE_GLONASS_BIT |
        GNSS_AIDING_DATA_SV_TYPE_QZSS_BIT |
        GNSS_AIDING_DATA_SV_TYPE_BEIDOU_BIT |
        GNSS_AIDING_DATA_SV_TYPE_GALILEO_BIT;

    if (f == LOC_GPS_DELETE_ALL)
        data.deleteAll = true;
    else {
        if (f & LOC_GPS_DELETE_EPHEMERIS) data.sv.svMask |= GNSS_AIDING_DATA_SV_EPHEMERIS_BIT;
        if (f & LOC_GPS_DELETE_ALMANAC) data.sv.svMask |= GNSS_AIDING_DATA_SV_ALMANAC_BIT;
        if (f & LOC_GPS_DELETE_POSITION) data.common.mask |= GNSS_AIDING_DATA_COMMON_POSITION_BIT;
        if (f & LOC_GPS_DELETE_TIME) data.common.mask |= GNSS_AIDING_DATA_COMMON_TIME_BIT;
        if (f & LOC_GPS_DELETE_IONO) data.sv.svMask |= GNSS_AIDING_DATA_SV_IONOSPHERE_BIT;
        if (f & LOC_GPS_DELETE_UTC) data.common.mask |= GNSS_AIDING_DATA_COMMON_UTC_BIT;
        if (f & LOC_GPS_DELETE_HEALTH) data.sv.svMask |= GNSS_AIDING_DATA_SV_HEALTH_BIT;
        if (f & LOC_GPS_DELETE_SVDIR) data.sv.svMask |= GNSS_AIDING_DATA_SV_DIRECTION_BIT;
        if (f & LOC_GPS_DELETE_SVSTEER) data.sv.svMask |= GNSS_AIDING_DATA_SV_STEER_BIT;
        if (f & LOC_GPS_DELETE_SADATA) data.sv.svMask |= GNSS_AIDING_DATA_SV_SA_DATA_BIT;
        if (f & LOC_GPS_DELETE_RTI) data.common.mask |= GNSS_AIDING_DATA_COMMON_RTI_BIT;
        if (f & LOC_GPS_DELETE_CELLDB_INFO) data.common.mask |= GNSS_AIDING_DATA_COMMON_CELLDB_BIT;
    }
    mControlClient->locAPIGnssDeleteAidingData(data);
}

void GardenAPIClient::gnssSetPositionMode(int mode, int interval, int accuracy)
{
    memset(&mLocationOptions, 0, sizeof(LocationOptions));
    mLocationOptions.size = sizeof(LocationOptions);
    mLocationOptions.minInterval = interval;
    mLocationOptions.minDistance = accuracy;
    mLocationOptions.mode = GNSS_SUPL_MODE_STANDALONE;
    if (((GnssSuplMode)mode == GNSS_SUPL_MODE_MSA) &&
            (mLocationCapabilitiesMask & LOCATION_CAPABILITIES_GNSS_MSA_BIT))
        mLocationOptions.mode = GNSS_SUPL_MODE_MSA;
    if (((GnssSuplMode)mode == GNSS_SUPL_MODE_MSA) &&
            (mLocationCapabilitiesMask & LOCATION_CAPABILITIES_GNSS_MSB_BIT))
        mLocationOptions.mode = GNSS_SUPL_MODE_MSB;
    //locAPIUpdateTrackingOptions(mLocationOptions);
}

int GardenAPIClient::gnssStart()
{
    locAPIStartTracking(mLocationOptions);
    return 0;
}

int GardenAPIClient::gnssStop()
{
    locAPIStopTracking();
    return 0;
}

// callbacks
void GardenAPIClient::onCapabilitiesCb(LocationCapabilitiesMask capabilitiesMask)
{
    garden_print("## %s ##:  Capabilities: 0x%x", "onCapabilitiesCb", capabilitiesMask);
    if (capabilitiesMask & LOCATION_CAPABILITIES_TIME_BASED_TRACKING_BIT)
        garden_print("    LOCATION_CAPABILITIES_TIME_BASED_TRACKING_BIT");
    if (capabilitiesMask & LOCATION_CAPABILITIES_TIME_BASED_BATCHING_BIT)
        garden_print("    LOCATION_CAPABILITIES_TIME_BASED_BATCHING_BIT");
    if (capabilitiesMask & LOCATION_CAPABILITIES_DISTANCE_BASED_TRACKING_BIT)
        garden_print("    LOCATION_CAPABILITIES_DISTANCE_BASED_TRACKING_BIT");
    if (capabilitiesMask & LOCATION_CAPABILITIES_DISTANCE_BASED_BATCHING_BIT)
        garden_print("    LOCATION_CAPABILITIES_DISTANCE_BASED_BATCHING_BIT");
    if (capabilitiesMask & LOCATION_CAPABILITIES_GEOFENCE_BIT)
        garden_print("    LOCATION_CAPABILITIES_GEOFENCE_BIT");
    if (capabilitiesMask & LOCATION_CAPABILITIES_GNSS_MEASUREMENTS_BIT)
        garden_print("    LOCATION_CAPABILITIES_GNSS_MEASUREMENTS_BIT");
    if (capabilitiesMask & LOCATION_CAPABILITIES_GNSS_MSB_BIT)
        garden_print("    LOCATION_CAPABILITIES_GNSS_MSB_BIT");
    if (capabilitiesMask & LOCATION_CAPABILITIES_GNSS_MSA_BIT)
        garden_print("    LOCATION_CAPABILITIES_GNSS_MSA_BIT");
    mLocationCapabilitiesMask = capabilitiesMask;
}

void GardenAPIClient::onTrackingCb(Location location)
{
    struct timeval result = {0,0};
    garden_print("## %s ##:", "onTrackingCb");
    garden_print("    LAT: %f, LON: %f, ALT: %f, SPE: %f",
            location.latitude, location.longitude, location.altitude, location.speed);
    garden_print("    BEA:, %f ACC: %f, TIME: %llu",
            location.bearing, location.accuracy, (long long) location.timestamp);

    if(mTtffSecs == -1) {
        firstFixTime = getUpTimeSec();
        mTtffSecs = firstFixTime - startTime;
        garden_print("  TTFF in Secs:: %ld, fixThresholdInSecs %ld, StartTime: %ld, FirstFixTime: %ld",
                (firstFixTime - startTime), mOptions.fixThresholdInSecs, startTime, firstFixTime );

    }
}

void GardenAPIClient::onGnssNiCb(uint32_t id, GnssNiNotification gnssNiNotification)
{
    garden_print("## %s ##:  Count: %d", "onGnssNiCb", mNiCbCount++);
    bool esEnabled = loc_core::ContextBase::mGps_conf.SUPL_ES;
    garden_print("  ACTION_NI_NOTIFY: id %d", id);
    garden_print("    ni_type %d, notify_flags %d, timeout %d, default_response %d",
            (int) gnssNiNotification.type, (int) gnssNiNotification.options,
            gnssNiNotification.timeout, gnssNiNotification.timeoutResponse);
    garden_print("    requestor_id %s, text %s",
            gnssNiNotification.requestor, gnssNiNotification.message);
    garden_print("    requestor_id_encoding %d, text_encoding %d, extras %s, esEnabled %d",
            gnssNiNotification.requestorEncoding, gnssNiNotification.messageEncoding, gnssNiNotification.extras, esEnabled);

    if (mNiCount > 0) {
        int pc = mOptions.niCount - mNiCount;
        pc = pc % mOptions.niResPatCount;

        Runnable runnable = [this, id, pc] {
            mNiCount--;
            if(mOptions.networkInitiatedResponse[pc] != 3){
                locAPIGnssNiResponse(id, (GnssNiResponse)mOptions.networkInitiatedResponse[pc]);
            };
            if (mNiCount == 0) {
                locAPIStopTracking();
                unsetFlag(GARDEN_TEST_NIBACKTOBACK);
            }
        };
        sendMsg(runnable);
    }
}

void GardenAPIClient::onGnssSvCb(GnssSvNotification gnssSvNotification)
{
    garden_print("## %s ##: Number of SVs: %d\n", "onGnssSvCb", gnssSvNotification.count);
    if(mOptions.satelliteDetails) {
        for (size_t i = 0; i < gnssSvNotification.count; i++) {
            GnssSv& sv =  gnssSvNotification.gnssSvs[i];
            const char* type = NULL;
            switch(sv.type) {
                case GNSS_SV_TYPE_GPS:
                    type = "GPS";
                    break;
                case GNSS_SV_TYPE_SBAS:
                    type = "SBAS";
                    break;
                case GNSS_SV_TYPE_GLONASS:
                    type = "GLONASS";
                    break;
                case GNSS_SV_TYPE_QZSS:
                    type = "QZSS";
                    break;
                case GNSS_SV_TYPE_BEIDOU:
                    type = "BEIDOU";
                    break;
                case GNSS_SV_TYPE_GALILEO:
                    type = "GALILEO";
                default:
                    type = "UNKNOWN";
                    break;
            }
            garden_print("    [%d]%s cN0Dbhz: %f, elevation: %f, azimuth: %f",
                    sv.svId, type, sv.cN0Dbhz, sv.elevation, sv.azimuth);
            garden_print("    has_ephemer: %d, has_almanac: %d, used_in_fix: %d",
                    (sv.gnssSvOptionsMask & GNSS_SV_OPTIONS_HAS_EPHEMER_BIT),
                    (sv.gnssSvOptionsMask & GNSS_SV_OPTIONS_HAS_ALMANAC_BIT),
                    (sv.gnssSvOptionsMask & GNSS_SV_OPTIONS_USED_IN_FIX_BIT));
        }
    }
    if (mSessionCount > 0 && mOptions.stopOnMinSvs && mOptions.stopOnMinSnr) {
        if (mOptions.stopOnMinSvs <= (int)gnssSvNotification.count) {
            int minCnSvCount = 0;
            for (size_t i = 0; i < gnssSvNotification.count; i++) {
                if (gnssSvNotification.gnssSvs[i].cN0Dbhz >= mOptions.stopOnMinSnr) {
                    minCnSvCount++;
                }
            }
            if (minCnSvCount >= mOptions.stopOnMinSvs){
                garden_print("  Stop test, as %d SVs are seen with at least a SNR of %f",
                        mOptions.stopOnMinSvs, mOptions.stopOnMinSnr);
                mSessionTimer.stop();
                Runnable runnable = [this] {
                    sessionStop();
                };
                sendMsg(runnable);
            }
        }
    }
}

void GardenAPIClient::onGnssNmeaCb(GnssNmeaNotification gnssNmeaNotification)
{
    if(mOptions.printNmea && gnssNmeaNotification.nmea) {
        garden_print("## %s ##:", "onGnssNmeaCb");
        garden_print("    Timestamp: %llu Length:%d, String:%s",
                gnssNmeaNotification.timestamp, gnssNmeaNotification.length, gnssNmeaNotification.nmea);
    }
}

void GardenAPIClient::onGnssMeasurementsCb(GnssMeasurementsNotification gnssMeasurementsNotification)
{
    garden_print("## onGnssMeasurementsCb ##::");

    garden_print(" Measurements for %d satellites", gnssMeasurementsNotification.count);

    for (int i = 0; i< gnssMeasurementsNotification.count && i < GNSS_MEASUREMENTS_MAX; i++) {
        garden_print("%02d : Const: %d,  svid: %d,"
            " time_offset_ns: %f, state %d,"
            " c_n0_dbhz: %f, pseudorange_rate_mps: %f,"
            " pseudorange_rate_uncertainty_mps: %f,"
            " agcLevelDb: %lf, flags: %d",
            i + 1,
            gnssMeasurementsNotification.measurements[i].svType,
            gnssMeasurementsNotification.measurements[i].svId,
            gnssMeasurementsNotification.measurements[i].timeOffsetNs,
            gnssMeasurementsNotification.measurements[i].stateMask,
            gnssMeasurementsNotification.measurements[i].carrierToNoiseDbHz,
            gnssMeasurementsNotification.measurements[i].pseudorangeRateMps,
            gnssMeasurementsNotification.measurements[i].pseudorangeRateUncertaintyMps,
            gnssMeasurementsNotification.measurements[i].agcLevelDb,
            gnssMeasurementsNotification.measurements[i].flags);
    }
    garden_print(" Clocks Info");
    garden_print(" time_ns: %lld, full_bias_ns: %lld,"
        " bias_ns: %g, bias_uncertainty_ns: %g,"
        " drift_nsps: %g, drift_uncertainty_nsps: %g,"
        " hw_clock_discontinuity_count: %d, flags: 0x%04x",
        gnssMeasurementsNotification.clock.timeNs,
        gnssMeasurementsNotification.clock.fullBiasNs,
        gnssMeasurementsNotification.clock.biasNs,
        gnssMeasurementsNotification.clock.biasUncertaintyNs,
        gnssMeasurementsNotification.clock.driftNsps,
        gnssMeasurementsNotification.clock.driftUncertaintyNsps,
        gnssMeasurementsNotification.clock.hwClockDiscontinuityCount,
        gnssMeasurementsNotification.clock.flags);
}

void GardenAPIClient::onStartTrackingCb(LocationError error)
{
    garden_print("## %s ##: %s", "onStartTrackingCb",
            error == LOCATION_ERROR_SUCCESS ? "SUCCESS" : "FAIL");
}

void GardenAPIClient::onStopTrackingCb(LocationError error)
{
    garden_print("## %s ##: %s", "onStopTrackingCb",
            error == LOCATION_ERROR_SUCCESS ? "SUCCESS" : "FAIL");
    if (hasFlag(GARDEN_TEST_SESSIONLOOP)) {
        Runnable runnable = [this] {
            sessionStep();
        };
        sendMsg(runnable);
    }
}

// private functions
void GardenAPIClient::setFlag(GARDEN_TEST_FLAG flag)
{
    pthread_mutex_lock(&mLock);
    mTestFlag |= flag;
    pthread_mutex_unlock(&mLock);
}

bool GardenAPIClient::hasFlag(GARDEN_TEST_FLAG flag)
{
    pthread_mutex_lock(&mLock);
    bool ret = mTestFlag & flag;
    pthread_mutex_unlock(&mLock);
    return ret;
}

void GardenAPIClient::unsetFlag(GARDEN_TEST_FLAG flag)
{
    pthread_mutex_lock(&mLock);
    mTestFlag &= (~flag);
    if (!mTestFlag) {
        garden_print("Test flags cleared!");
        pthread_cond_signal(&mCond);
    }
    pthread_mutex_unlock(&mLock);
}

void GardenAPIClient::sessionStep()
{
    if (mSessionStart == true) {
        return;
    }
    if (mSessionCount == 0) {
        garden_print("All %d session(s) finished.", mOptions.l);
        unsetFlag(GARDEN_TEST_SESSIONLOOP);
        return;
    }
    mSessionStart = true;
    mSessionCount--;
    garden_print("Session %d/%d", mOptions.l - mSessionCount, mOptions.l);

    locAPIStartTracking(mLocationOptions);

    mSessionTimer.start(mOptions.t);
}

void GardenAPIClient::sessionStop()
{
    if (mSessionStart == false)
        return;
    mSessionStart = false;
    locAPIStopTracking();
}

// call this function if we want to wait previous test finished.
void GardenAPIClient::sync()
{
    pthread_mutex_lock(&mLock);
    // wait all test flags cleared
    if (mTestFlag) {
        pthread_cond_wait(&mCond, &mLock);
    }
    pthread_mutex_unlock(&mLock);
}

void GardenAPIClient::sendMsg(Runnable& runnable) const {
    mMsgTask->sendMsg(new LocMsgWrapper(runnable));
}

// test cases
void GardenAPIClient::networkInitiated()
{
    setFlag(GARDEN_TEST_NIBACKTOBACK);

    mNiCount = mOptions.niCount;
    locAPIStartTracking(mLocationOptions);

    sync();
}

void GardenAPIClient::sessionLoop()
{
    setFlag(GARDEN_TEST_SESSIONLOOP);

    mSessionCount = mOptions.l;
    sessionStep();

    sync();
}

void GardenAPIClient::startTracking()
{
#ifdef __ANDROID__
    // this flag will never be unset
    setFlag(GARDEN_TEST_TRACKING);

    if (!gGardenSessionControl) {
        gGardenSessionControl = new garden_app_session_tracker(this);
    }

    if (!gEventObserver) {
        gEventObserver = new EventObserver(rxSystemEvent);
    }

    sync();
#else
    LOC_LOGE("%s] Tracking test is not supported in current platform.\n", __func__);
#endif
}
