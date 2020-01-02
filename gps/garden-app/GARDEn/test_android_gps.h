/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2011, 2016-2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
#ifndef TEST_ANDROID_GPS_H
#define TEST_ANDROID_GPS_H

#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <gps_extended.h>

/** Agps Command Line options **/
typedef struct agps_command_line_options {
    LocAGpsType agpsType; // Agps type
    const char * apn; // apn
    AGpsBearerType agpsBearerType; // Agps bearer type.
    /* values for struct members from here down are initialized by reading gps.conf
       file using -c options to garden */
    unsigned long suplVer;
    char suplHost[256];
    int suplPort;
    char c2kHost[256];
    int c2kPort;
} AgpsCommandLineOptionsType;

/** Structure that holds the command line options given to main **/
typedef struct command_line_options {
    LocGpsPositionRecurrence r; // recurrence type
    int l; // Number of sessions to loop through.
    int t; // time to stop fix in seconds
    int s; // Stacks to test.
    int b; // Legacy TRUE OR FALSE.
    int ulpTestCaseNumber; // Run specified ULP test case number
    int deleteAidingDataMask; // Specifies Hexadecimal mask for deleting aiding data.
    int positionMode; // Specifies Position mode.
    int interval; // Time in milliseconds between fixes.
    int accuracy; // Accuracy in meters
    int responseTime; // Requested time to first fix in milliseconds
    LocGpsLocation location; // Only latitude, longiture and accuracy are used in this structure.
    int networkInitiatedResponse[256]; // To store the response pattern
    int niCount; // Number of back to back Ni tests
    int niResPatCount; // Number of elements in the response pattern
    AgpsCommandLineOptionsType agpsData; // Agps Data
    int isSuccess; // Success, Failure, ...
    int rilInterface; // Ril Interface
    char gpsConfPath[256]; // Path to config file
    int disableAutomaticTimeInjection; // Flag to indicate whether to disable or enable automatic time injection
    int niSuplFlag; // Flag to indicate that tests being conducted is ni supl
    int printNmea; // Print nmea string
    int satelliteDetails; // Print detailed info on satellites in view.
    int fixThresholdInSecs; // User specified time to first fix threshold in seconds
    int zppTestCaseNumber; // Run specified ULP test case number
    int enableXtra; // Flag to enable/disable Xtra
    int stopOnMinSvs; // part of conditions that cause test to stop. Minimum number of SVs
    float stopOnMinSnr; // part of conditions that casue test to stop. Minimum number of SNR
    int tracking;    // start tracking session
} CommandLineOptionsType;

void garden_print(const char *fmt, ...);
uint64_t getUpTimeSec();
int timeval_difference (struct timeval *result, struct timeval *x, struct timeval *y);

#endif // TEST_ANDROID_GPS_H
