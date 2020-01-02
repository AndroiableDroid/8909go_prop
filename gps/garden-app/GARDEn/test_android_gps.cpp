/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2011-2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  =============================================================================*/
#include "platform_lib_log_util.h"
#include <stdarg.h>
#include <pthread.h>
#include <sys/time.h>

#ifdef __ANDROID__
#include <android/log.h>
#include <private/android_filesystem_config.h>
#include "android_runtime/AndroidRuntime.h"
#include "qmi_client_instance_defs.h"
#include <cutils/klog.h>
#endif

#include "loc_cfg.h"
#include "test_android_gps.h"
#include "ulp_service.h"
#include "loc_extended.h"
#include "loc_target.h"
#include <time.h>
#include "qmi_client_instance_defs.h"
#include "EventObserver.h"

#ifdef USE_GLIB
#include "IIzatManager.h"
#include "OSFramework.h"
#include <glib.h>
#define strlcpy g_strlcpy
#endif /* USE_GLIB */

#include "GardenAPIClient.h"

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef enum
{
    ACTION_NONE,
    ACTION_QUIT,
    ACTION_OPEN_ATL,
    ACTION_CLOSE_ATL,
    ACTION_FAIL_ATL,
    ACTION_NI_NOTIFY,
    ACTION_XTRA_DATA,
    ACTION_XTRA_TIME,
    ACTION_NLP_RESPONSE,
    ACTION_PHONE_CONTEXT_UPDATE
} test_thread_action_e_type;

pthread_mutex_t test_thread_mutex;
pthread_cond_t test_thread_cond;

pthread_mutex_t location_conn_mutex;
pthread_cond_t location_conn_cond;


pthread_mutex_t networkpos_req_mutex;
pthread_cond_t networkpos_req_cond;

pthread_mutex_t phone_context_mutex;
pthread_cond_t phone_context_cond;

pthread_mutex_t ulp_location_mutex;
pthread_cond_t ulp_location_cond;

pthread_mutex_t session_status_mutex;
pthread_cond_t session_status_cond;

pthread_mutex_t wait_count_mutex;
pthread_cond_t wait_count_cond;

pthread_mutex_t wait_atlcb_mutex;
pthread_cond_t wait_atlcb_cond;

test_thread_action_e_type test_thread_action;

//Global Phone context stettings
// global phone context setting
bool    is_gps_enabled = TRUE;
/** is network positioning enabled */
bool    is_network_position_available = TRUE;
/** is wifi turned on */
bool    is_wifi_setting_enabled = TRUE;
/** is battery being currently charged */
bool    is_battery_charging = TRUE;
/** is agps enabled */
bool    is_agps_enabled = TRUE;
/** is this a first fix -- TRUE - Yes, FALSE - No */
bool    is_first_fix = TRUE;

#ifdef TEST_ULP
const UlpEngineInterface* pUlpEngineInterface = NULL;
const UlpPhoneContextInterface *pUlpPhoneContextInterface = NULL;
const UlpNetworkInterface* pUlpNetworkInterface = NULL;

typedef void (*ThreadStart) (void *);
struct tcreatorData {
    ThreadStart pfnThreadStart;
    void* arg;
};

void placeMarker(char *name)
{
    int fd=open("/sys/kernel/debug/bootkpi/kpi_values", O_RDWR);
    if (fd > 0)
    {
        write(fd, name, strlen(name));
        close(fd);
    }
}

void *my_thread_fn (void *tcd)
{
    tcreatorData* local_tcd = (tcreatorData*)tcd;
    if (NULL != local_tcd) {
        local_tcd->pfnThreadStart (local_tcd->arg);
        free(local_tcd);
    }

    return NULL;
}

void mutex_init()
{
    pthread_mutex_init (&test_thread_mutex, NULL);
    pthread_cond_init (&test_thread_cond, NULL);


    pthread_mutex_init (&location_conn_mutex, NULL);
    pthread_cond_init (&location_conn_cond, NULL);

    pthread_mutex_init (&networkpos_req_mutex, NULL);
    pthread_cond_init (&networkpos_req_cond, NULL);

    pthread_mutex_init (&phone_context_mutex, NULL);
    pthread_cond_init (&phone_context_cond, NULL);

    pthread_mutex_init (&session_status_mutex, NULL);
    pthread_cond_init (&session_status_cond, NULL);

    pthread_mutex_init (&wait_count_mutex,NULL);
    pthread_cond_init (&wait_count_cond,NULL);

    pthread_mutex_init (&wait_atlcb_mutex,NULL);
    pthread_cond_init (&wait_atlcb_cond,NULL);

    pthread_mutex_init (&ulp_location_mutex, NULL);
    pthread_cond_init (&ulp_location_cond, NULL);

}

void mutex_destroy()
{
    pthread_mutex_destroy (&test_thread_mutex);
    pthread_cond_destroy (&test_thread_cond);

    pthread_mutex_destroy (&location_conn_mutex);
    pthread_cond_destroy (&location_conn_cond);

    pthread_mutex_destroy (&networkpos_req_mutex);
    pthread_cond_destroy (&networkpos_req_cond);

    pthread_mutex_destroy (&phone_context_mutex );
    pthread_cond_destroy (&phone_context_cond);

    pthread_mutex_destroy (&session_status_mutex);
    pthread_cond_destroy (&session_status_cond);

    pthread_mutex_destroy (&wait_count_mutex);
    pthread_cond_destroy (&wait_count_cond);

    pthread_mutex_destroy (&wait_atlcb_mutex);
    pthread_cond_destroy (&wait_atlcb_cond);

    pthread_mutex_destroy (&ulp_location_mutex );
    pthread_cond_destroy (&ulp_location_cond);

}

void set_phone_context()
{
    garden_print("set_phone_context ");
    is_gps_enabled                = TRUE;
    is_network_position_available = TRUE;
    is_wifi_setting_enabled       = TRUE;
    is_battery_charging           = TRUE;
    //Simulate phone context update from AFW
    pthread_mutex_lock (&test_thread_mutex);
    test_thread_action = ACTION_PHONE_CONTEXT_UPDATE;
    pthread_cond_signal (&test_thread_cond);
    pthread_mutex_unlock (&test_thread_mutex);

}

/*
 * Helper thread for emulating the Android Framework.
 */
void *test_thread (void *args)
{
    garden_print ("Test Thread Enter");
    int rc = 0;
    pthread_mutex_lock (&test_thread_mutex);
    do {
        pthread_cond_wait (&test_thread_cond, &test_thread_mutex);
        /*
         * got a condition
         */
        garden_print ("test thread unblocked, action = %d",
                     test_thread_action);
        if (test_thread_action == ACTION_QUIT) {
            garden_print ("ACTION_QUIT");
            break;
        }
        switch (test_thread_action) {

        case ACTION_NLP_RESPONSE:
            garden_print("ACTION_NLP_RESPONSE \n Simulating AFW injection of network location after 5 secs\n");
            sleep(5);
            pthread_mutex_lock (&networkpos_req_mutex);
            if((pUlpNetworkInterface != NULL) && (pUlpNetworkInterface->ulp_send_network_position != NULL)){
              UlpNetworkPositionReport position_report;
              position_report.valid_flag = ULP_NETWORK_POSITION_REPORT_HAS_POSITION;
              position_report.position.latitude = 32.7;
              position_report.position.longitude = -119;
              position_report.position.HEPE = 1000;
              position_report.position.pos_source = ULP_NETWORK_POSITION_SRC_UNKNOWN;
              pUlpNetworkInterface->ulp_send_network_position(&position_report);
            }

            pthread_cond_signal (&networkpos_req_cond);
            pthread_mutex_unlock (&networkpos_req_mutex);
            break;

        case ACTION_PHONE_CONTEXT_UPDATE:
            pthread_mutex_lock (&phone_context_mutex);
            garden_print("ACTION_PHONE_CONTEXT_UPDATE \n Simulating AFW injection of phone context info\n");
            if(pUlpPhoneContextInterface != NULL) {
              UlpPhoneContextSettings settings;
              settings.context_type = ULP_PHONE_CONTEXT_GPS_SETTING |
                                      ULP_PHONE_CONTEXT_NETWORK_POSITION_SETTING |
                                      ULP_PHONE_CONTEXT_WIFI_SETTING |
                                      ULP_PHONE_CONTEXT_AGPS_SETTING;
              settings.is_gps_enabled = is_gps_enabled;
              settings.is_agps_enabled = is_agps_enabled;
              settings.is_network_position_available = is_network_position_available;
              settings.is_wifi_setting_enabled = is_wifi_setting_enabled;
              pUlpPhoneContextInterface->ulp_phone_context_settings_update(&settings);

            }
            pthread_cond_signal (&phone_context_cond);
            pthread_mutex_unlock (&phone_context_mutex);
            break;
        default:
            break;
        }
        test_thread_action = ACTION_NONE;

    } while (1);
    pthread_mutex_unlock (&test_thread_mutex);

    garden_print ("Test Thread Exit");
    return NULL;
}


void test_ulp_location_cb (UlpLocation * location, GpsLocationExtended* locationExtended, enum loc_sess_status status)
{
    if (is_first_fix) {
        placeMarker("K - GPS-First Fix");
        LOC_LOGI("GPS-First Fix");
        is_first_fix = FALSE;
    }
    garden_print("======================================================");
    garden_print ("ulp_location_cb :");
    garden_print("LAT: %f, LON: %f, ACC: %f, TIME: %llu, status: %d",
                 location->gpsLocation.latitude, location->gpsLocation.longitude,
                 location->gpsLocation.accuracy,(long long) location->gpsLocation.timestamp,
                 status);
    garden_print("======================================================");
    pthread_mutex_lock (&ulp_location_mutex);
    pthread_cond_signal (&ulp_location_cond);
    pthread_mutex_unlock (&ulp_location_mutex);
}

void test_ulp_gnss_status_cb (const LocGpsStatusValue status) {
}

void test_ulp_gnss_nmea_cb (const UlpNmea *pNmeaStr) {

    if(pNmeaStr) {
        garden_print ("NMEA : %s", pNmeaStr);
    }
}

void test_ulp_gnss_svinfo_cb (const GnssSvNotification* svNotify,
                              uint16_t source) {

    if(NULL != svNotify) {
        garden_print ("SVInfo : %d\n", svNotify->count);
    }
}

pthread_t test_gps_create_thread_cb (const char *name, void (*start) (void *),
                                void *arg)
{
    garden_print("## loc_gps_create_thread ##:");
    pthread_t thread_id = -1;
    garden_print ("%s", name);

    tcreatorData* tcd = (tcreatorData*)malloc(sizeof(*tcd));

    if (NULL != tcd) {
        tcd->pfnThreadStart = start;
        tcd->arg = arg;

        if (0 > pthread_create (&thread_id, NULL, my_thread_fn, (void*)tcd)) {
            garden_print ("error creating thread");
            free(tcd);
        } else {
            garden_print ("created thread");
        }
    }


    return thread_id;
}

static void test_ulp_request_phone_context_cb(UlpPhoneContextRequest *req)
{
 garden_print ("test_ulp_request_phone_context with context_type: %x,request_type: %d ",
           req->context_type, req->request_type );

 pthread_mutex_lock (&test_thread_mutex);
 test_thread_action = ACTION_PHONE_CONTEXT_UPDATE;
 pthread_cond_signal (&test_thread_cond);
 pthread_mutex_unlock (&test_thread_mutex);
}

static void test_ulp_network_location_request_cb(UlpNetworkRequestPos* req)
{
    garden_print ("test_ulp_network_location_request_cb with request_type: %d,interval %d, desired_position_source: %d",
           req->request_type , req->interval_ms , req->desired_position_source );

    if (req->request_type == ULP_NETWORK_POS_STOP_REQUEST )
    {
       garden_print ("received network provider stop request\n");
    }
    else
    {
       sleep (1);
       pthread_mutex_lock (&test_thread_mutex);
       test_thread_action = ACTION_NLP_RESPONSE;
       pthread_cond_signal (&test_thread_cond);
       pthread_mutex_unlock (&test_thread_mutex);
    }
}
UlpEngineCallbacks sUlpEngineCallbacks = {
    sizeof(UlpEngineCallbacks),
    test_ulp_location_cb,
    test_ulp_gnss_status_cb,
    test_gps_create_thread_cb,
    test_ulp_gnss_nmea_cb,
    test_ulp_gnss_svinfo_cb
};

UlpPhoneContextCallbacks pUlpPhoneContextCallbacks = {
    test_ulp_request_phone_context_cb,
};

UlpNetworkLocationCallbacks pUlpNetworkLocationCallbacks = {
    test_ulp_network_location_request_cb,
};
#endif
// Default Agps command line values
static AgpsCommandLineOptionsType sAgpsCommandLineOptions = {
    LOC_AGPS_TYPE_SUPL,
    "myapn.myapn.com",
    AGPS_APN_BEARER_IPV4,
    0x10000, // SUPL version
    "supl.host.com",
    1234,
    "c2k.pde.com",
    1234
};

/** Default values for position/location */
static LocGpsLocation sPositionDefaultValues = {
    sizeof(LocGpsLocation),
    0,
    32.90285,
    -117.202185,
    0,
    0,
    0,
    10000,
    (LocGpsUtcTime)0,
};


// Default values
static CommandLineOptionsType sOptions = {
    LOC_GPS_POSITION_RECURRENCE_SINGLE,
    1,
    60, // Time to stop fix.
    1, // Android frame work (AFW)AGpsBearerType
    true, // Yes to Legacy
    1, // ULP test case number
    0, // By default don't delete aiding data.
    LOC_GPS_POSITION_MODE_STANDALONE, // Standalone mode.
    1000, // 1000 millis between fixes
    0, // Accuracy
    0, // 1 millisecond?
    sPositionDefaultValues,
    {0}, // Invalid for NI response
    0, // Defaults to 0 back to back NI test
    0, // Number of elements in NI response pattern
    sAgpsCommandLineOptions, // default Agps values
    1, // Agps Success
    0, // Test Ril Interface
    {0}, // Default path to config file, will be set in main
    0, // By default do not disable automatic time injection
    0, // NI SUPL flag defaults to zero
    0, // Print NMEA info. By default does not get printed
    0, // SV info. Does not print the detaul by default
    20, // Default value of 20 seconds for time to first fix
    0, // ZPP test case number
    0, // Xtra Enabled By default
    0, // Minimum number of SVs option off by default
    0, // Minimum number of SNR option off by default
    0  //Tracking Session status off by default
};


static loc_param_s_type cfg_parameter_table[] =
{
    {"SUPL_VER",     &sOptions.agpsData.suplVer,                         NULL, 'n'},
    {"SUPL_HOST",    &sOptions.agpsData.suplHost,                        NULL, 's'},
    {"SUPL_PORT",    &sOptions.agpsData.suplPort,                        NULL, 'n'},
    {"C2K_HOST",     &sOptions.agpsData.c2kHost,                         NULL, 's'},
    {"C2K_PORT",     &sOptions.agpsData.c2kPort,                         NULL, 'n'},
};

uint64_t getUpTimeSec()
{
    struct timespec ts;

    ts.tv_sec = ts.tv_nsec = 0;
    clock_gettime(CLOCK_BOOTTIME, &ts);
    return ts.tv_sec + (ts.tv_nsec / 1000000000LL);
}

void garden_print(const char *fmt, ...)
{
    va_list ap;
    char buf[1024];
    va_start(ap, fmt);
    vsnprintf(buf, 1024, fmt, ap);
    va_end(ap);
    fprintf(stderr,"GARDEN: %s\n",buf);
    LOC_LOGV("%s", buf);
}

int timeval_difference (struct timeval *result, struct timeval *x, struct timeval *y)
{
    /* Perform the carry for the later subtraction by updating y. */
    if (x->tv_usec < y->tv_usec) {
        int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
        y->tv_usec -= 1000000 * nsec;
        y->tv_sec += nsec;
    }
    if (x->tv_usec - y->tv_usec > 1000000) {
        int nsec = (x->tv_usec - y->tv_usec) / 1000000;
        y->tv_usec += 1000000 * nsec;
        y->tv_sec -= nsec;
    }

    /* Compute the time remaining to wait.
       tv_usec is certainly positive. */
    result->tv_sec = x->tv_sec - y->tv_sec;
    result->tv_usec = x->tv_usec - y->tv_usec;

    /* Return 1 if result is negative. */
    return x->tv_sec < y->tv_sec;
}

/*=============================================================================
  FUNCTION test_main

  Android Framework simulation entry point.

  Includes individual tests for specific features.

  Search the makefile for "TEST_ANDROID_GPS_FLAGS" and uncomment the
  flags that correspond to desired tests.

  =============================================================================*/
int test_main()
{
    int rc = 0;
    pthread_t tid;
    test_thread_action = ACTION_NONE;

    GardenAPIClient* sClient = new GardenAPIClient(sOptions);

    if (!sClient) {
        garden_print(" Could not create locationAPI client, Cannot proceed ");
        return -1;
    }
    mutex_init();
    pthread_create (&tid, NULL, test_thread, NULL);
#ifdef USE_GLIB
    IIzatManager * pIzatManager = getIzatManager (OSFramework::getOSFramework());
    if(NULL == pIzatManager){
            garden_print ("getIzatManager returned NULL!!");
    } else {
        pIzatManager->enableProvider(IZAT_STREAM_NETWORK);
    }
    pUlpEngineInterface =
        (const UlpEngineInterface*)ulp_get_extension(ULP_ENGINE_INTERFACE);
   pUlpNetworkInterface =
        (UlpNetworkInterface*)ulp_get_extension(ULP_NETWORK_INTERFACE);
   pUlpPhoneContextInterface =
        (const UlpPhoneContextInterface*)ulp_get_extension(ULP_PHONE_CONTEXT_INTERFACE);
   if((NULL == pUlpEngineInterface)||
        (NULL == pUlpNetworkInterface)||
        (NULL == pUlpPhoneContextInterface)) {
              ALOGE("Error in classInit.ulp_get_extension is null ");
    }
#endif
#ifdef __ANDROID__
    ulp_init(&sUlpEngineCallbacks, &pUlpNetworkLocationCallbacks, &pUlpPhoneContextCallbacks);
    pUlpEngineInterface =
        (const UlpEngineInterface*)ulp_get_extension(ULP_ENGINE_INTERFACE);
    pUlpNetworkInterface =
        (UlpNetworkInterface*)ulp_get_extension(ULP_NETWORK_INTERFACE);
    pUlpPhoneContextInterface =
           (const UlpPhoneContextInterface*)ulp_get_extension(ULP_PHONE_CONTEXT_INTERFACE);
    if((NULL == pUlpEngineInterface)||
       (NULL == pUlpNetworkInterface)||
       (NULL == pUlpPhoneContextInterface)) {
        LOC_LOGE("Error in classInit.ulp_get_extension is null ");
    }
    garden_print("sleep for 100 msec \n");
    usleep(100000);

    if(NULL != pUlpEngineInterface)
    {
       pthread_mutex_lock (&ulp_location_mutex);
       pUlpEngineInterface->system_update(ULP_LOC_EVENT_OBSERVER_STOP_EVENT_TX);
       pthread_mutex_unlock (&ulp_location_mutex);
    }

#endif
    if (sOptions.deleteAidingDataMask)
        garden_print("gnssDeleteAidingData \n");
        sClient->gnssDeleteAidingData(sOptions.deleteAidingDataMask);

    if (sOptions.niSuplFlag) {
        garden_print("Going to run Network Initiated Test, niCount: %d...", sOptions.niCount);
        sClient->networkInitiated();
        garden_print("Network Initiated Test finished");
    }
#ifdef USE_GLIB
    garden_print("ulp_phone_context_settings_update \n");
    set_phone_context();
#endif
    if (sOptions.l > 0) {
        garden_print("Going to run SessionLoop Test, loop: %d...", sOptions.l);
        sClient->sessionLoop();
        garden_print("SessionLoop Test finished");
    }

#ifdef __ANDROID__
    /*********
     *
     *   ## IMPORTANT ##
     *   This tracking option will start a tracking session in continous loop
     *   Alwasys keep this as a last test case and add new test cases
     *   before this option
     *
     ******* */
    if(sOptions.tracking == 1) {
        garden_print("Going to run Tracking Test, this will never return, press Ctl-c to exit...");
        sClient->startTracking();
    }
#endif

    delete sClient;
#ifdef USE_GLIB
    delete pIzatManager;
#endif
    garden_print ("GARDEn Tests Finished!");
    mutex_destroy();
    sleep(1);

    return rc;
}

void printHelp(char **arg)
{
    garden_print("usage: %s -l <xxx> -t <xxx>", arg[0]);
    garden_print("    -l:  Number of sessions to loop through. Takes an argument. An argument of 0 means no sessions. Defaults:%d", sOptions.l);
    garden_print("    -t:  User defined length of time to issue stop navigation. Takes an argument. Time in seconds Defaults: %d", sOptions.t);
    garden_print("    -d:  Delete aiding data: Takes a hexadecimal mask as an argument as given in gps.h Defaults: 0x%X ",sOptions.deleteAidingDataMask);
    garden_print("    -m:  Position Mode. Takes an argument 0:LOC_GPS_POSITION_MODE_STANDALONE, 1:LOC_GPS_POSITION_MODE_MS_BASED, 2:LOC_GPS_POSITION_MODE_MS_ASSISTED Defaults: %d ", sOptions.positionMode);
    garden_print("    -i:  Interval. Takes an argument. Time in milliseconds between fixes Defaults: %d", sOptions.interval);
    garden_print("    -a:  Accuracy. Takes an argument. Accuracy in meters Defaults: %d ", sOptions.accuracy);
    garden_print("    -P:  (UNUSED)Inject Position. Takes 3 arguments seperated by a COMMA. Latitude, Longitude, and accuracy Defaults: %f,%f,%d ",sOptions.location.latitude,sOptions.location.longitude,(int)sOptions.location.accuracy);
    garden_print("    -N:  Network Initiated. Takes 2 arguments separated by COMMA. First being the number of back to back NI tests and second being a COMMA separated pattern of  1:Accept, 2:Deny,or 3:No Response Defaults: %d:%d",sOptions.niCount,0);
    for(int i = 0; i<sOptions.niResPatCount; ++i) { garden_print("%12d",sOptions.networkInitiatedResponse[i]); }
    garden_print("    -c:  gps.conf file. Takes an argument. The argument is the path to gps.conf file. Defaults: %s",sOptions.gpsConfPath);
    garden_print("    -k:  used in conjunction with -N option to indicate that the test being conducted is an NI SUPL test. Takes no arguments.");
    garden_print("    -n:  Use this option to print nmea string, timestamp and length. Takes no arguments. Defaults:%d",sOptions.printNmea);
    garden_print("    -y:  Use this option to print detailed info on satellites in view. Defaults:%d",sOptions.satelliteDetails);
    garden_print("    -o:  This option, when used, will enforce a check to determine if time to first fix is within a given threshold value. Takes one argument, the threshold value in seconds. Defaults: %d",sOptions.fixThresholdInSecs);
    garden_print("    -A:  Minimum number of SVs seen in combination with -B option to determine when to stop the test without actually getting a position report to save test time");
    garden_print("    -B:  Minimum SNR for each SV seen in -A option to determine when to stop the test  without actually getting a position report to save test time");
    garden_print("    -T:  Start a tracking session *WARNING* this tracking session will run until process is alive Ctrl-C to exit");
    garden_print("    -h:  print this help");
}


int main(int argc, char *argv[])
{
    int result = 0;
    int opt;
    extern char *optarg;
    char *argPtr;
    char *tokenPtr;

    // Initialize gps conf path
    strlcpy(sOptions.gpsConfPath, LOC_PATH_GPS_CONF, sizeof(sOptions.gpsConfPath));

    while ((opt = getopt (argc, argv, "l:t:h:d:m:i:a:P:N:D:w:c:kny:o:z:A:B:T::")) != -1) {
        switch (opt) {
            case 'l':
                sOptions.l = atoi(optarg);
                garden_print("Number of Sessions to loop through:%d",sOptions.l);
                break;
            case 't':
                sOptions.t = atoi(optarg);
                garden_print("User defined length of time to issue stop navigation:%d",sOptions.t);
                break;
            case 'd':
                sOptions.deleteAidingDataMask = strtoll(optarg,NULL,16);
                garden_print("Delete Aiding Mask:%x",sOptions.deleteAidingDataMask);
                break;
            case 'm':
                sOptions.positionMode = atoi(optarg);
                garden_print("Position Mode:%d",sOptions.positionMode);
                break;
            case 'i':
                sOptions.interval = atoi(optarg);
                garden_print("Interval:%d",sOptions.interval);
                break;
            case 'a':
                sOptions.accuracy = atoi(optarg);
                garden_print("Accuracy:%d",sOptions.accuracy);
                break;
            case 'P':
                sOptions.location.flags = 0x0011;
                tokenPtr = strtok_r(optarg, ",", &argPtr);
                if(tokenPtr != NULL) {
                    sOptions.location.latitude = atof(tokenPtr);
                    tokenPtr = strtok_r(NULL, ",", &argPtr);
                    if(tokenPtr != NULL) {
                        sOptions.location.longitude = atof(tokenPtr);
                        tokenPtr = strtok_r(NULL, ",", &argPtr);
                        if(tokenPtr != NULL) {
                            sOptions.location.accuracy = atoi(tokenPtr);
                        }
                    }
                }
                garden_print("Inject Position:: flags:%x, lat:%f, lon:%f, acc:%d",sOptions.location.flags,
                        sOptions.location.latitude, sOptions.location.longitude,sOptions.location.accuracy);
                break;
            case 'N':
                // Number of back to back tests
                tokenPtr = strtok_r(optarg, ",", &argPtr);
                if(tokenPtr != NULL) {
                    sOptions.niCount = atoi(tokenPtr);
                    if(sOptions.niCount > 0)
                    {
                        char *ret;
                        while((ret = strtok_r(NULL, ",", &argPtr)) != NULL)
                        {
                            sOptions.networkInitiatedResponse[sOptions.niResPatCount++] = atoi(ret);
                        }
                    }
                }
                garden_print("Number of back to back NI tests : %d",sOptions.niCount);
                break;
            case 'c':
                strlcpy(sOptions.gpsConfPath,optarg,256);
                // Initialize by reading the gps.conf file
                UTIL_READ_CONF(sOptions.gpsConfPath, cfg_parameter_table);
                garden_print("Parameters read from the config file :");
                garden_print("**************************************");
                garden_print("SUPL_VER      : 0x%X",sOptions.agpsData.suplVer);
                garden_print("SUPL_HOST     : %s",sOptions.agpsData.suplHost);
                garden_print("SUPL_PORT     : %ld",sOptions.agpsData.suplPort);
                garden_print("C2K_HOST      : %s",sOptions.agpsData.c2kHost);
                garden_print("C2K_PORT      : %ld",sOptions.agpsData.c2kPort);
                garden_print("**************************************");
                break;
            case 'k':
                sOptions.niSuplFlag = 1;
                garden_print("NI SUPL flag:%d",sOptions.niSuplFlag);
                break;
            case 'n':
                sOptions.printNmea = 1;
                garden_print("Print NMEA info:%d",sOptions.printNmea);
                break;
            case 'y':
                sOptions.satelliteDetails = 1;
                garden_print("Print Details Satellites in View info:%d",sOptions.satelliteDetails);
                break;
            case 'o':
                sOptions.fixThresholdInSecs = atoi(optarg);
                garden_print("Time to first fix threshold value in seconds : %d", sOptions.fixThresholdInSecs);
                break;
            case 'A':
                sOptions.stopOnMinSvs = atoi(optarg);
                garden_print("Stop on Minimum Svs: %d",sOptions.stopOnMinSvs);
                break;
            case 'B':
                sOptions.stopOnMinSnr = atof(optarg);
                garden_print("Stop on Minimum SNR: %f",sOptions.stopOnMinSnr);
                break;
            case 'T':
                sOptions.tracking = 1;
                garden_print("Start Tracking Session -- continuous untill processs is alive press Ctrl-C to exit");
                break;
            case 'h':
            default:
                printHelp(argv);
                return 0;
        }
    }

    garden_print("Starting GARDEn");
    placeMarker("M - Garden-Start");
    result = test_main();

    garden_print("Exiting GARDEn");
    return result;
}
