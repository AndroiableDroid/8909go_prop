/******************************************************************************
  @file    BoostConfigReader.cpp
  @brief   Implementation of reading boost config xml files

  DESCRIPTION

  ---------------------------------------------------------------------------
  Copyright (c) 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/

#include "BoostConfigReader.h"
#include "mp-ctl.h"
#include <cutils/log.h>

#if QC_DEBUG
#  define QLOGE(...)    ALOGE(__VA_ARGS__)
#  define QLOGD(...)    ALOGD(__VA_ARGS__)
#  define QLOGW(...)    ALOGW(__VA_ARGS__)
#  define QLOGI(...)    ALOGI(__VA_ARGS__)
#  define QLOGV(...)    ALOGV(__VA_ARGS__)
#else
#  define QLOGE(...)
#  define QLOGD(...)
#  define QLOGW(...)
#  define QLOGI(...)
#  define QLOGV(...)
#endif

//perf mapping tags in xml file
#define PERF_BOOSTS_XML_ROOT "PerfBoosts"
#define PERF_BOOSTS_XML_CHILD_MAPPINGS "BoostParamsMappings"
#define PERF_BOOSTS_XML_ATTRIBUTES_TAG "BoostAttributes"
#define PERF_BOOSTS_XML_MAPTYPE_TAG "MapType"
#define PERF_BOOSTS_XML_RESOLUTION_TAG "Resolution"
#define PERF_BOOSTS_XML_MAPPINGS_TAG "Mappings"
#define PERF_BOOSTS_XML_TARGET_TAG "Target"

//perf boost config tags
#define BOOSTS_CONFIGS_XML_ROOT "BoostConfigs"
#define BOOSTS_CONFIGS_XML_CHILD_CONFIG "PerfBoost"
#define BOOSTS_CONFIGS_XML_ELEM_CONFIG_TAG "Config"
#define BOOSTS_CONFIGS_XML_ELEM_RESOURCES_TAG "Resources"
#define BOOSTS_CONFIGS_XML_ELEM_ENABLE_TAG "Enable"
#define BOOSTS_CONFIGS_XML_ELEM_ID_TAG "Id"
#define BOOSTS_CONFIGS_XML_ELEM_TYPE_TAG "Type"
#define BOOSTS_CONFIGS_XML_ELEM_TIMEOUT_TAG "Timeout"

//power hint tags
#define POWER_HINT_XML_ROOT "HintConfigs"
#define POWER_HINT_XML_CHILD_CONFIG "Powerhint"

#define MAP_TYPE_VAL_FREQ "freq"
#define MAP_TYPE_VAL_CLUSTER "cluster"
#define MAP_RES_TYPE_VAL_1080p "1080p"
#define MAP_RES_TYPE_VAL_2560 "2560"
#define MAP_RES_TYPE_VAL_720p "720p"

using namespace std;

#define PERF_MAPPING_XML "/vendor/etc/perf/perfmapping.xml"
#define PERF_BOOSTS_CONFIGS_XML "/vendor/etc/perf/perfboostsconfig.xml"
#define POWER_CONFIGS_XML "/vendor/etc/powerhint.xml"

PerfBoostsStore PerfBoostsStore::mStore;

PerfBoostsStore::ParamsMappingInfo::ParamsMappingInfo(int mtype, char *tname, int res, int maptable[], int mapsize) {
    mMapType = mtype;
    memset(mTName, 0, sizeof(mTName));
    if (tname) {
        strlcpy(mTName, tname, TARG_NAME_LEN);
    }
    mResolution = res;
    mMapSize = (mapsize<=MAX_MAP_TABLE_SIZE)?mapsize:MAX_MAP_TABLE_SIZE;
    memset(mMapTable, -1, sizeof(mMapTable));
    for (int i=0; i < mMapSize; i++) {
        mMapTable[i] = maptable[i];
    }
}

PerfBoostsStore::BoostConfigInfo::BoostConfigInfo(int idnum, int type, bool enable, int timeout, char *tname, int res, char *resourcesPtr) {
    mId = idnum;
    mType = type;
    mEnable = enable;
    mTimeout = timeout;

    memset(mTName, 0, sizeof(mTName));
    if (tname) {
        strlcpy(mTName, tname, TARG_NAME_LEN);
    }

    mResolution = res;

    memset(mConfigTable, -1, sizeof(mConfigTable));
    mConfigsSize = ConvertToIntArray(resourcesPtr, mConfigTable, MAX_OPCODE_VALUE_TABLE_SIZE);
}

PerfBoostsStore::PerfBoostsStore() {
}

PerfBoostsStore::~PerfBoostsStore() {
    //delete mappings
    while (!mBoostParamsMappings.empty()) {
        ParamsMappingInfo *tmp = mBoostParamsMappings.back();
        if (tmp) {
            delete tmp;
        }
        mBoostParamsMappings.pop_back();
    }
    //delete perf boost configs
    while (!mBoostConfigs.empty()) {
        BoostConfigInfo *tmp = mBoostConfigs.back();
        if (tmp) {
            delete tmp;
        }
        mBoostConfigs.pop_back();
    }
    //delete power hint
    while (!mPowerHint.empty()) {
        BoostConfigInfo *tmp = mPowerHint.back();
        if (tmp) {
            delete tmp;
        }
        mPowerHint.pop_back();
    }
}

void PerfBoostsStore::Init() {
    XmlParserInit();
}

void PerfBoostsStore::XmlParserInit() {
    const string fMappingsName(PERF_MAPPING_XML);
    const string fPerfConfigsName(PERF_BOOSTS_CONFIGS_XML);
    const string fPowerHintName(POWER_CONFIGS_XML);
    const string xmlMappingsRoot(PERF_BOOSTS_XML_ROOT);
    const string xmlChildMappings(PERF_BOOSTS_XML_CHILD_MAPPINGS);
    const string xmlConfigsRoot(BOOSTS_CONFIGS_XML_ROOT);
    const string xmlChildConfigs(BOOSTS_CONFIGS_XML_CHILD_CONFIG);
    const string xmlPHintRoot(POWER_HINT_XML_ROOT);
    const string xmlPowerChildConfigs(POWER_HINT_XML_CHILD_CONFIG);

    int idnum;

    AppsListXmlParser *xmlParser = new AppsListXmlParser();
    if (NULL == xmlParser) {
        return;
    }

    //appboosts mappings
    idnum = xmlParser->Register(xmlMappingsRoot, xmlChildMappings, BoostParamsMappingsCB, NULL);
    xmlParser->Parse(fMappingsName);
    xmlParser->DeRegister(idnum);

    //perf boost configs
    idnum = xmlParser->Register(xmlConfigsRoot, xmlChildConfigs, BoostConfigsCB, NULL);
    xmlParser->Parse(fPerfConfigsName);
    xmlParser->DeRegister(idnum);

    //power hint configs
    idnum = xmlParser->Register(xmlPHintRoot, xmlPowerChildConfigs, BoostConfigsCB, NULL);
    xmlParser->Parse(fPowerHintName);
    xmlParser->DeRegister(idnum);

    delete xmlParser;

    return;
}

void PerfBoostsStore::BoostParamsMappingsCB(xmlNodePtr node, void *) {
    char *maptype = NULL, *resolution = NULL, *mappings = NULL, *tname = NULL;
    int mtype = MAP_TYPE_UNKNOWN, res = MAP_RES_TYPE_ANY;
    int marray[MAX_MAP_TABLE_SIZE];
    int msize = 0;

    PerfBoostsStore *store = PerfBoostsStore::getBoostsStore();
    if (NULL == store) {
        return;
    }

    if(!xmlStrcmp(node->name, BAD_CAST PERF_BOOSTS_XML_ATTRIBUTES_TAG)) {
        maptype = (char *) xmlGetProp(node, BAD_CAST PERF_BOOSTS_XML_MAPTYPE_TAG);
        mtype = store->ConvertToEnumMappingType(maptype);

        tname = (char *) xmlGetProp(node, BAD_CAST PERF_BOOSTS_XML_TARGET_TAG);

        resolution = (char *) xmlGetProp(node, BAD_CAST PERF_BOOSTS_XML_RESOLUTION_TAG);
        res = store->ConvertToEnumResolutionType(resolution);

        mappings = (char *) xmlGetProp(node, BAD_CAST PERF_BOOSTS_XML_MAPPINGS_TAG);
        msize = store->ConvertToIntArray(mappings, marray, MAX_MAP_TABLE_SIZE);

        QLOGI("Identified maptype %s target %s resolution %s mappings %s in mappings table",
              maptype ? maptype : "NULL",
              tname ? tname : "NULL",
              resolution ? resolution : "NULL",
              mappings ? mappings : "NULL");

        if (mappings != NULL) {
            store->mBoostParamsMappings.push_back(new ParamsMappingInfo(mtype, tname, res, marray, msize));
            xmlFree(mappings);
        }
        if (maptype) {
            xmlFree(maptype);
        }
        if (resolution) {
            xmlFree(resolution);
        }
        if (tname) {
            xmlFree(tname);
        }
    }
    return;
}

void PerfBoostsStore::BoostConfigsCB(xmlNodePtr node, void *) {
    char *idPtr = NULL, *resourcesPtr = NULL, *enPtr = NULL, *tname = NULL;
    char *timeoutPtr = NULL, *targetPtr = NULL, *resPtr = NULL;
    int idnum = -1, type = -1, timeout = -1, res = 0;
    bool en = false;

   PerfBoostsStore *store = PerfBoostsStore::getBoostsStore();
    if (NULL == store) {
        return;
    }

    if(!xmlStrcmp(node->name, BAD_CAST BOOSTS_CONFIGS_XML_ELEM_CONFIG_TAG)) {
        if(xmlHasProp(node, BAD_CAST BOOSTS_CONFIGS_XML_ELEM_ID_TAG)) {
            idPtr = (char *)xmlGetProp(node, BAD_CAST BOOSTS_CONFIGS_XML_ELEM_ID_TAG);
            if (NULL != idPtr) {
                idnum = strtol(idPtr, NULL, 0);
                xmlFree(idPtr);
            }
        }

        if(xmlHasProp(node, BAD_CAST BOOSTS_CONFIGS_XML_ELEM_TYPE_TAG)) {
            idPtr = (char *)xmlGetProp(node, BAD_CAST BOOSTS_CONFIGS_XML_ELEM_TYPE_TAG);
            if (NULL != idPtr) {
                type = strtol(idPtr, NULL, 0);
                xmlFree(idPtr);
            }
        }

        if(xmlHasProp(node, BAD_CAST BOOSTS_CONFIGS_XML_ELEM_ENABLE_TAG)) {
            enPtr = (char *) xmlGetProp(node, BAD_CAST BOOSTS_CONFIGS_XML_ELEM_ENABLE_TAG);
            if (NULL != enPtr) {
                en = (0 == strncmp(enPtr, "true", strlen(enPtr)));
                xmlFree(enPtr);
            }
        }

        if(xmlHasProp(node, BAD_CAST BOOSTS_CONFIGS_XML_ELEM_TIMEOUT_TAG)) {
            timeoutPtr = (char *) xmlGetProp(node, BAD_CAST BOOSTS_CONFIGS_XML_ELEM_TIMEOUT_TAG);
            if (NULL != timeoutPtr) {
                timeout = strtol(timeoutPtr, NULL, 0);
                xmlFree(timeoutPtr);
            }
        }

        if(xmlHasProp(node, BAD_CAST PERF_BOOSTS_XML_TARGET_TAG)) {
            tname = (char *) xmlGetProp(node, BAD_CAST PERF_BOOSTS_XML_TARGET_TAG);
        }

        if(xmlHasProp(node, BAD_CAST PERF_BOOSTS_XML_RESOLUTION_TAG)) {
          resPtr = (char *) xmlGetProp(node, BAD_CAST PERF_BOOSTS_XML_RESOLUTION_TAG);
          res = store->ConvertToEnumResolutionType(resPtr);
          xmlFree(resPtr);
        }

        if(xmlHasProp(node, BAD_CAST BOOSTS_CONFIGS_XML_ELEM_RESOURCES_TAG)) {
            resourcesPtr = (char *) xmlGetProp(node, BAD_CAST BOOSTS_CONFIGS_XML_ELEM_RESOURCES_TAG);
        }

        QLOGI("Identified id=%d type=%d enable=%d timeout=%d target=%s resolution=%s config=%s in table",
              idnum, type, en, timeout,
              tname ? tname : "NULL",
              resPtr ? resPtr : "NULL",
              resourcesPtr ? resourcesPtr : "NULL");

        if (resourcesPtr != NULL) {
            //vendor perf hint
            if (idnum > VENDOR_HINT_START && idnum < VENDOR_PERF_HINT_END) {
                store->mBoostConfigs.push_back(new BoostConfigInfo(idnum, type, en, timeout, tname, res, resourcesPtr));
            } else {
                //power hint
                store->mPowerHint.push_back(new BoostConfigInfo(idnum, type, en, timeout, tname, res, resourcesPtr));
            }

            xmlFree(resourcesPtr);
        }

        //did not release these only, now copied in boostconfig, you can release now
        if (tname) {
            xmlFree(tname);
        }
    }
    return;
}

PerfBoostsStore::ValueMapType
PerfBoostsStore::ConvertToEnumMappingType(char *maptype) {
    ValueMapType ret = MAP_TYPE_UNKNOWN;

    if (NULL == maptype) {
        return ret;
    }

    switch(maptype[0]) {
    case 'f':
        if (!strncmp(maptype, MAP_TYPE_VAL_FREQ, strlen(MAP_TYPE_VAL_FREQ))) {
            ret = MAP_TYPE_FREQ;
        }
        break;
    case 'c':
        if (!strncmp(maptype, MAP_TYPE_VAL_CLUSTER, strlen(MAP_TYPE_VAL_CLUSTER))) {
            ret = MAP_TYPE_CLUSTER;
        }
        break;
    }
    return ret;
}

PerfBoostsStore::ValueMapResType
PerfBoostsStore::ConvertToEnumResolutionType(char *res) {
    ValueMapResType ret = MAP_RES_TYPE_ANY;

    if (NULL == res) {
        return ret;
    }

    switch(res[0]) {
    case '1':
        if (!strncmp(res, MAP_RES_TYPE_VAL_1080p, strlen(MAP_RES_TYPE_VAL_1080p))) {
            ret = MAP_RES_TYPE_1080P;
        }
        break;
    case '7':
        if (!strncmp(res, MAP_RES_TYPE_VAL_720p, strlen(MAP_RES_TYPE_VAL_720p))) {
            ret = MAP_RES_TYPE_720P;
        }
        break;
    case '2':
        if (!strncmp(res, MAP_RES_TYPE_VAL_2560, strlen(MAP_RES_TYPE_VAL_2560))) {
            ret = MAP_RES_TYPE_2560;
        }
    }
    return ret;
}

int PerfBoostsStore::ConvertToIntArray(char *str, int intArray[], int size) {
    int i = 0;
    char *pch = NULL;
    char *end = NULL;
    char *endPtr = NULL;

    if ((NULL == str) || (NULL == intArray)) {
        return i;
    }

    end = str + strlen(str);

    do {
        pch = strchr(str, ',');
        intArray[i] = strtol(str, &endPtr, 0);
        i++;
        str = pch;
        if (NULL != pch) {
            str++;
        }
    } while ((NULL != str) && (str < end) && (i < size));

    return i;
}

int PerfBoostsStore::GetFreqMap(int res, int **maparray, char *tname) {
    int mapsize = 0;

    if (!maparray || !tname) {
        return mapsize;
    }

    vector<ParamsMappingInfo*>::iterator itbegin = mBoostParamsMappings.begin();
    vector<ParamsMappingInfo*>::iterator itend = mBoostParamsMappings.end();

    for (vector<ParamsMappingInfo*>::iterator it = itbegin; it != itend; ++it) {
        if ((NULL != *it) && ((*it)->mMapType == MAP_TYPE_FREQ) && ((*it)->mResolution == res) && !strncmp((*it)->mTName, tname, strlen(tname))) {
                mapsize = (*it)->mMapSize;
                *maparray = (*it)->mMapTable;
        }
    }
    return mapsize;
}

int PerfBoostsStore::GetClusterMap(int **maparray, char *tname) {
    int mapsize = 0;

    if (!maparray || !tname) {
        return mapsize;
    }

    vector<ParamsMappingInfo*>::iterator itbegin = mBoostParamsMappings.begin();
    vector<ParamsMappingInfo*>::iterator itend = mBoostParamsMappings.end();

    for (vector<ParamsMappingInfo*>::iterator it = itbegin; it != itend; ++it) {
        if ((NULL != *it) && (*it)->mMapType == MAP_TYPE_CLUSTER && !strncmp((*it)->mTName, tname, strlen(tname))) {
                *maparray = (*it)->mMapTable;
                mapsize = MAX_MAP_TABLE_SIZE;
        }
    }
    return mapsize;
}

int PerfBoostsStore::GetBoostConfig(int hintId, int type, int *mapArray, int *timeout,
                                    char *tName, int res) {
    int mapsize = 0;

    if (!mapArray) {
        return mapsize;
    }

    vector<BoostConfigInfo*>::iterator itbegin;
    vector<BoostConfigInfo*>::iterator itend;

    //vendor perf hint
    if (hintId > VENDOR_HINT_START && hintId < VENDOR_PERF_HINT_END) {
        itbegin = mBoostConfigs.begin();
        itend = mBoostConfigs.end();
    } else {
        //power hint
        itbegin = mPowerHint.begin();
        itend = mPowerHint.end();
    }


    for (vector<BoostConfigInfo*>::iterator it = itbegin; it != itend; ++it) {
        if ((NULL != *it) && ((*it)->mId == hintId) && ((*it)->mType == type) &&
            (((*it)->mResolution == MAP_RES_TYPE_ANY) || (*it)->mResolution == res) &&
            (!tName || (0 == (*it)->mTName[0]) || !strncmp((*it)->mTName, tName, strlen(tName)))) {
            if ((*it)->mEnable) {
                mapsize = (*it)->mConfigsSize;
                if (NULL != mapArray) {
                    for (int i=0; i<mapsize; i++) {
                        mapArray[i] = (*it)->mConfigTable[i];
                    }
                }
                if (timeout) {
                    *timeout = (*it)->mTimeout;
                }
            }
            break;
        }
    }
    return mapsize;
}

