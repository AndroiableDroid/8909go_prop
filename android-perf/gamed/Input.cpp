/******************************************************************************
  @file  Input.cpp
  @brief   collecting inputs like gpuload, touchcount, etc

  collecting inputs like gpuload, touchcount, etc

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#include <stdlib.h>
#include <cstring>
#include "Config.h"
#include "Stats.h"
#include "Input.h"

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "ANDR-PERF-GAMEDET"
#include <cutils/log.h>

#define INTR_DEV_PATH "/proc/interrupts"
#define GLD_DEV_PATH "/sys/class/kgsl/kgsl-3d0/devfreq/gpu_load"
#define GPUSUSCNT_DEV_PATH "/sys/class/kgsl/kgsl-3d0/devfreq/suspend_time"
#define GPUSP_DEV_PATH "/sys/class/kgsl/kgsl-3d0/devfreq/sampling_period"

#define FRAME_TIME 17

using namespace GamingSustenance;

Input::Input() {
    mGpuLoad = 0;
    mTouchCount = 0;
    mInactivityFrameCount = 0;
    mPrevIntCount = 0;
    mTchIntline = 0;
    mStatsPtr = NULL;
}

void Input::Init(Stats *sptr, int touchInterruptNo) {
    mStatsPtr = sptr;
    mTchIntline = touchInterruptNo;
    return;
}

//Read touch input interrupt count from /proc/interrupts sysfs node
int Input::ReadTevents() {
    FILE *fp = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t nbytes;
    int intline=0;
    int intcount = 0, idiff=0;
    int idx=0, tmpidx=0, nitems=0, itemcnt=0;
    char tmpbuf[MAX_LINE_SIZE] = "";

    /*  TBD - Fix the problem to avoid opening and closing every time */
    if( (fp = fopen(INTR_DEV_PATH, "r")) == NULL) {
        QLOGE("Error while opening %s file", INTR_DEV_PATH);
        return 0;
    }

    while ((nbytes = getline(&line, &len, fp)) != -1) {
        sscanf(line, "%d:", &intline);
        if(intline == mTchIntline) {
            /* process the corresponding interrupt line from /cat/proc/interrupts */
            idx = 0;
            /* read no. of columns in the line..
            varies based on number of cores online at the time of reading */
            while(idx < (int)len) {
                /* remove the spaces */
                while((line[idx] != ' ') && (line[idx] != '\n'))
                    ++idx;
                ++nitems;
                /* reached end of line..done */
                if(line[idx] == '\n')
                    break;
                while(line[idx] == ' ')
                    ++idx;
            }

            intcount = 0;
            idx = 0;
            while(idx < (int)len ) {
                tmpidx = 0;
                while((line[idx] != ' ') && (line[idx] != '\n')) {
                    if(tmpidx >= MAX_LINE_SIZE-1) {
                        tmpidx = MAX_LINE_SIZE-1;
                        break;
                    }
                    tmpbuf[tmpidx++] = line[idx++];
                }
                tmpbuf[tmpidx] = '\0';
                if((itemcnt > 0) && (itemcnt < (nitems - 2))) {
                    /* last 2 columns are subsystem and irq routine */
                    intcount += atoi(tmpbuf);
                }
                if(line[idx] == '\n')
                    break;

                while(line[idx] == ' ')
                    ++idx;
                ++itemcnt;
            }

            idiff = intcount - mPrevIntCount;
            mPrevIntCount = intcount;
            break;
        }
    }

    if (line) {
        free(line);
    }
    if (fp) {
        fclose(fp);
    }
    return idiff;

}

void Input::Read() {
    FILE *gpuldfp = NULL, *gpuscfp=NULL;
    struct timeval tv1;
    int *gld = &mGpuLoad;
    int *iafc = &mInactivityFrameCount;
    int *tcnt = &mTouchCount;

    /* TBD : Need to open and close every to avoid file cache buffering. Fix this  */
    gpuldfp = fopen(GLD_DEV_PATH, "r");
    gpuscfp = fopen(GPUSUSCNT_DEV_PATH, "r");

    if(gpuldfp == NULL) {
        QLOGE("Unable to open %s file to read GPU load\n", GLD_DEV_PATH);
        return;
    }
    if(gpuscfp == NULL) {
        QLOGE("Unable to open %s file ", GPUSUSCNT_DEV_PATH);
        return;
    }
    fscanf(gpuldfp, "%d", gld);
    fclose(gpuldfp);
    fscanf(gpuscfp, "%d", iafc);
    fclose(gpuscfp);

    /* first sample - don't take interrupt count difference and iafc difference */
    if(mStatsPtr && mStatsPtr->IsItNewSampleStart()) {
        *iafc = 0;
    }

    mInactivityFrameCount= mInactivityFrameCount/FRAME_TIME;
    *tcnt = ReadTevents();

    /* first sample - don't take interrupt count difference and iafc difference */
    if(mStatsPtr && mStatsPtr->IsItNewSampleStart()) {
        *tcnt = 0;
    }
    gettimeofday(&tv1, NULL);
    //QLOGI("Sample Data-Time,GPULoad,IAFC,TouchCnt %d.%03d %d %d %d",
    //  (int)tv1.tv_sec, (int)tv1.tv_usec/1000, *gld, *iafc, *tcnt);
}
