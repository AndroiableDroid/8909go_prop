/******************************************************************************
  @file  Whitelists.cpp
  @brief  whitelists framework

  whitelists framework

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#include "WhiteLists.h"

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "ANDR-PERF-GM-WHITELISTS"
#include <cutils/log.h>

#define WHITELIST_PATH "/system/etc/gamedwhitelist.xml"
#define WHITELIST_PATH_NEW "/system/vendor/etc/gamedwhitelist.xml"
#define XMLROOT_ATTR "AppCatalog"
#define XMLCHILD_ATTR "GamedAppList"
#define XMLCHILD_ATTR_GAMED_RW_WHITE_LIST "GamedRWAppList"
#define XMLCHILD_ATTR_GAMED_RO_GAME_LIST "GamedROGameList"
#define XMLCHILD_ATTR_GAMED_RO_BLACK_LIST "GamedROBlackList"
#define XMLELEM_ATTR "AppAttributes"
#define EMPTY_STRING ""
#define NO_EXPECTED_TYPE -1

using namespace GamingSustenance;

void AppInfo::print() {
    if((mPackageName) && (mActivityType)) {
        QLOGI("packageName %s, activityType %s", mPackageName, mActivityType);
    }
}

bool AppList::AddElementInList(char *pName, int aType) {
    if (NULL == pName) {
        QLOGE("While adding to list package name not defined");
        return false;
    }


    if ((mCurAddPos) < mMaxSize) {
        if(mCurAddPos < mAppList.size()) {
            AppInfo *tmp = mAppList[mCurAddPos];
            mAppList[mCurAddPos] = new AppInfo(pName, aType);
            if(tmp) {
                delete tmp;
                tmp = NULL;
            }
        } else {
            mAppList.push_back(new AppInfo(pName, aType));
        }
        mCurAddPos = (mCurAddPos+1)%mMaxSize;
    } else {
        QLOGE("AppList size not enough for adding new element");
        return false;
    }
    return true;
}

void AppList::mPrintList(void) {
    for (vector<AppInfo*>::iterator iter = mAppList.begin();
            iter != mAppList.end(); ++iter) {
        QLOGI("Name %s type %d",
                (*iter)->getPackageName(), (*iter)->getActivityType());
    }
}

int AppList::CheckNameInListAndGetType(char *pNameToCheck) {
    if(pNameToCheck == NULL) {
        QLOGI("App-name to search is NULL");
        return GAMEDET_IS_UNKNOWN;
    }

    for (vector<AppInfo*>::iterator iter = mAppList.begin();
            iter != mAppList.end(); ++iter) {
        if(!strcmp((*iter)->getPackageName(), pNameToCheck)) {
            QLOGI("Packagename found, return the type");
            return (*iter)->getActivityType();
        }
    }

    QLOGI("App name not found returning Unknown type for the app");
    return GAMEDET_IS_UNKNOWN;
}

bool AppList::ExistsInList(char *pNameToCheck) {
    if(pNameToCheck == NULL) {
        QLOGI("App-name to search is NULL");
        return false;
    }

    //Check in the list now
    for (vector<AppInfo*>::iterator iter = mAppList.begin();
            iter != mAppList.end(); ++iter) {
        if(!strcmp((*iter)->getPackageName(), pNameToCheck)) {
            QLOGI("Packagename found in list return true");
            return true;
        }
    }

    return false;
}

AppList::~AppList() {
    for (vector<AppInfo*>::iterator iter = mAppList.begin();
            iter != mAppList.end(); ++iter) {
        if (*iter) {
            QLOGE("deleteing list item");
            delete (*iter);
            (*iter) = NULL;
        }
    }
}

XmlData *XmlData::mXmlData=NULL;

XmlData::~XmlData() {
    if(mXmlParser) {
        delete mXmlParser;
        mXmlParser = NULL;
    }
}

void XmlData::Init() {
    const string fName(WHITELIST_PATH);
    const string fNameNew(WHITELIST_PATH_NEW);
    const string xmlRoot(XMLROOT_ATTR);
    const string xmlChild(XMLCHILD_ATTR_GAMED_RW_WHITE_LIST);
    const string xmlChild1(XMLCHILD_ATTR_GAMED_RO_GAME_LIST);
    const string xmlChild2(XMLCHILD_ATTR_GAMED_RO_BLACK_LIST);
    int glistId, blistId, wlistId;
    glistId = blistId = wlistId = -1;

    mXmlParser = new AppsListXmlParser();
    if (mXmlParser) {
        wlistId = mXmlParser->Register(xmlRoot, xmlChild,
               PopulateWhiteListFrmXml, NULL);
        glistId = mXmlParser->Register(xmlRoot, xmlChild1,
                PopulateReadOnlyGameListFrmXml, NULL);
        blistId = mXmlParser->Register(xmlRoot, xmlChild2,
                PopulateReadOnlyBlackListFrmXml, NULL);
        QLOGI("Registerd callback ids whitelist %d, read-only gamelist %d, black-list %d", wlistId, glistId,
                blistId);
        //call the parser
        if (mXmlParser->Parse(fNameNew) < 0) {
            //try old path
            mXmlParser->Parse(fName);
        }
        //De-register
        if (mXmlParser->DeRegister(blistId)) {
            blistId = -1;
        } else {
            QLOGE("Could not de-register black-list parser");
        }
        if (mXmlParser->DeRegister(glistId)) {
            glistId = -1;
        } else {
            QLOGE("Could not de-register readonly game list parser");
        }
    }
}

bool XmlData::ValidatePackageName(char *pName) {
    if (pName == NULL) {
        QLOGE("Package name null");
        return false;
    }
    //TODO truncate trailing whitespaces
    if (strlen(pName) < 1) {
        QLOGE("length of pname is less than 1. Empty string?");
        return false;
    } else {
        return true;
    }
    return false;
}

bool XmlData::ValidateActivityType(char *aType, int expectedType, int &type) {
    type = GAMEDET_IS_UNKNOWN;
    if (aType == NULL) {
        QLOGE("Activity type null");
        return false;
    }
    type = mXmlData->MapActivityType(aType);
    //expectedType set, then type should match the expected type
    // else if type is not GAMEDET_IS_UNKNOWN return true
    if (expectedType != NO_EXPECTED_TYPE) {
        if (type == expectedType) {
            QLOGI("Type %d and expected type %d match", type, expectedType);
            return true;
        }
        return false;
    } else {
        //expected type is not specified
        // return true if type is not Unknown
        if (type != GAMEDET_IS_UNKNOWN) {
            QLOGI("Type is %d", type);
            return true;
        }
        QLOGI("Unknown type found return false");
        return false;
    }
    return false;
}

void XmlData::PopulateWhiteListFrmXml(xmlNodePtr node, void *) {
    char *packageName = NULL;
    char *activityType = NULL;
    int aType = GAMEDET_IS_UNKNOWN;
    if (NULL == node) {
        QLOGE("Node null from xmlParser");
        return;
    }

    if(!xmlStrcmp(node->name, BAD_CAST "AppAttributes")) {
        if(xmlHasProp(node, BAD_CAST "PackageName"))
            packageName  = (char *) xmlGetProp(node, BAD_CAST "PackageName");
        if(xmlHasProp(node, BAD_CAST "ActivityType"))
            activityType = (char *) xmlGetProp(node, BAD_CAST "ActivityType");
        QLOGI("Identified pname %s atype %s in list",
                packageName ? packageName : "NULL",
                activityType ? activityType : "NULL");

        if (mXmlData->ValidatePackageName(packageName) &&
            mXmlData->ValidateActivityType(activityType,
                NO_EXPECTED_TYPE, aType)) {
            if (mXmlData->AddElementInList(packageName,aType,
                        mXmlData->mWhiteList)) {
                QLOGI("Added in white list");
            }
        } else {
            QLOGE("Entry ignored");
        }
    }
    if (packageName) {
        xmlFree(packageName);
        packageName = NULL;
    }
    if (activityType) {
        xmlFree(activityType);
        activityType = NULL;
    }
    return;
}

void XmlData::PopulateReadOnlyGameListFrmXml(xmlNodePtr node, void *) {
    char *packageName = NULL;
    char *activityType = NULL;
    int aType = GAMEDET_IS_UNKNOWN;

    if(node == NULL) {
        QLOGE("XmlParser node is NULL");
        return;
    }

    if(!xmlStrcmp(node->name, BAD_CAST "AppAttributes")) {
        if(xmlHasProp(node, BAD_CAST "PackageName"))
            packageName  = (char *) xmlGetProp(node, BAD_CAST "PackageName");
        if(xmlHasProp(node, BAD_CAST "ActivityType"))
            activityType = (char *) xmlGetProp(node, BAD_CAST "ActivityType");
        QLOGI("Identified pname %s atype %s in list",
                packageName ? packageName : "NULL",
                activityType ? activityType : "NULL");

        if (mXmlData->ValidatePackageName(packageName) &&
                mXmlData->ValidateActivityType(activityType,
                    GAMEDET_IS_GAME, aType)) {
            if (mXmlData->AddElementInList(packageName,aType,
                        mXmlData->mWhiteList)) {
                QLOGI("Added in white list");
            }
        } else {
            QLOGE("Entry ignored");
        }
    }
    if (packageName) {
        xmlFree(packageName);
        packageName = NULL;
    }
    if (activityType) {
        xmlFree(activityType);
        activityType = NULL;
    }
    return;
}

void XmlData::PopulateReadOnlyBlackListFrmXml(xmlNodePtr node, void *) {
    char *packageName = NULL;
    char *activityType = NULL;
    int aType = GAMEDET_IS_UNKNOWN;

    if(node == NULL) {
        QLOGE("XmlParser node is NULL");
        return;
    }

    if(!xmlStrcmp(node->name, BAD_CAST "AppAttributes")) {
        if(xmlHasProp(node, BAD_CAST "PackageName"))
            packageName  = (char *) xmlGetProp(node, BAD_CAST "PackageName");
      if(xmlHasProp(node, BAD_CAST "ActivityType"))
          activityType = (char *) xmlGetProp(node, BAD_CAST "ActivityType");

      QLOGI("Identified pname %s atype %s in list",
          packageName ? packageName : "NULL",
          activityType ? activityType : "NULL");

      if (mXmlData->ValidatePackageName(packageName) &&
              mXmlData->ValidateActivityType(activityType,
                  NO_EXPECTED_TYPE, aType)) {
          if (mXmlData->AddElementInList(packageName, aType, mXmlData->mWhiteList)) {
              QLOGI("Added in white list");
          }
      } else {
          QLOGE("Entry ignored");
      }
    }
    if (packageName) {
        xmlFree(packageName);
        packageName = NULL;
    }
    if (activityType) {
        xmlFree(activityType);
        activityType = NULL;
    }
    return;
}

bool XmlData::AddElementInList(char *pName, int aType, AppList &list) {
    return list.AddElementInList(pName, aType);
}

int XmlData::CheckInListAndGetType(char *pName, AppList &list) {
    return list.CheckNameInListAndGetType(pName);
}

bool XmlData::ExistsInList(char *pName, AppList &list) {
    return list.ExistsInList(pName);
}

int XmlData::MapActivityType(char *aTypeStr) {
    int aType = GAMEDET_IS_UNKNOWN;
    if(aTypeStr) {
        if(!strcmp((aTypeStr), GAMEDET_IS_APP_STR))
            aType = GAMEDET_IS_APP;
        else if(!strcmp((aTypeStr), GAMEDET_IS_BM_STR))
            aType = GAMEDET_IS_BM;
        else if(!strcmp((aTypeStr), GAMEDET_IS_GAME_STR))
            aType = GAMEDET_IS_GAME;
        else {
            aType = GAMEDET_IS_UNKNOWN;
            QLOGE("Activity-type not found. Returning unknown");
        }
    }
    return aType;
}
