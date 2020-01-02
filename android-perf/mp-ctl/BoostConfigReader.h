/******************************************************************************
  @file    Boostconfigreader.h
  @brief   Implementation of boostconfigreader

  DESCRIPTION

  ---------------------------------------------------------------------------
  Copyright (c) 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/

#ifndef __BOOSTCONFIG_READER__H_
#define __BOOSTCONFIG_READER__H_


#include <vector>
#include "XmlParser.h"

/* size of logical cluster map is 8, size of logical
 * freq map is 5, so taking max(8) */
#define MAX_MAP_TABLE_SIZE 8

#define TARG_NAME_LEN 32
#define MAX_OPCODE_VALUE_TABLE_SIZE 32

using namespace std;

class PerfBoostsStore {
public:
    typedef enum {
        MAP_TYPE_UNKNOWN,
        MAP_TYPE_FREQ,
        MAP_TYPE_CLUSTER
    }ValueMapType;

    typedef enum {
        MAP_RES_TYPE_ANY   = 0,
        MAP_RES_TYPE_720P  = 720,
        MAP_RES_TYPE_1080P = 1080,
        MAP_RES_TYPE_2560  = 2560
    }ValueMapResType;

private:
    class ParamsMappingInfo {
    public:
        explicit ParamsMappingInfo(int mtype, char *tname, int res, int maptable[], int mapsize);

        int mMapType;
        char mTName[TARG_NAME_LEN];
        int mResolution;
        int mMapTable[MAX_MAP_TABLE_SIZE];
        int mMapSize;
    };

    class BoostConfigInfo {
    public:
        explicit BoostConfigInfo(int idnum, int type, bool enable, int timeout, char *tname, int res, char *resourcesPtr);
        int mId;
        int mType;
        bool mEnable;
        int mTimeout;
        char mTName[TARG_NAME_LEN];
        int mResolution;
        int mConfigTable[MAX_OPCODE_VALUE_TABLE_SIZE];
        int mConfigsSize;
    };
private:
    //perf boost configs
    vector<BoostConfigInfo*> mBoostConfigs;

    //power hint
    vector<BoostConfigInfo*> mPowerHint;

    //perf params mappings
    vector<ParamsMappingInfo*> mBoostParamsMappings;

    // Singelton object of this class
    static PerfBoostsStore mStore;

private:
    //xml open/read/close
    void XmlParserInit();

    //target specific boost params xml CBs
    static void BoostParamsMappingsCB(xmlNodePtr node, void *);

    //target specific boost configurations xml CB
    static void BoostConfigsCB(xmlNodePtr node, void *);

    //support routines
    ValueMapType ConvertToEnumMappingType(char *maptype);
    ValueMapResType ConvertToEnumResolutionType(char *res);
    static int ConvertToIntArray(char *mappings, int mapArray[], int msize);

    //ctor, copy ctor, assignment overloading
    PerfBoostsStore();
    PerfBoostsStore(PerfBoostsStore const& oh);
    PerfBoostsStore& operator=(PerfBoostsStore const& oh);

public:
    //interface to boost params mappings
    int GetFreqMap(int res, int **maparray, char *tname);
    int GetClusterMap(int **maparray, char *tname);

    //interface to boost configs
    int GetBoostConfig(int hintId, int type, int *mapArray, int *timeout,
                       char *tName = NULL, int res = MAP_RES_TYPE_ANY);

    //Initialize cur_target
    void Init();

    static PerfBoostsStore *getBoostsStore() {
        return &mStore;
    }

    //dtor
    ~PerfBoostsStore();
};

#endif /*__BOOSTCONFIG_READER__H_*/
