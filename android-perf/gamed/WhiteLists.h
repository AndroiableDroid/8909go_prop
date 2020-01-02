/******************************************************************************
  @file  Whitelists.h
  @brief  whitelists framework

  whitelists framework

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#ifndef __WHITE_LIST_H__
#define __WHITE_LIST_H__
#include <string.h>
#include <vector>
#include "Config.h"
#include "XmlParser.h"

namespace GamingSustenance {

#define MAX_APPLIST_SIZE 100
#define MAX_ROLIST_SIZE 20

class AppInfo {
    private:
        char* mPackageName;
        int mActivityType;
    public:
        void print();
        explicit AppInfo(char* pName, int aType)
        {
            int strSize = strlen(pName) + 1;
            if (strSize > MAX_MSG_APP_NAME_LEN) {
                strSize = MAX_MSG_APP_NAME_LEN;
            }
            mPackageName = (char *) malloc(sizeof(char)*(strSize));
            if(NULL != mPackageName) {
                strlcpy(mPackageName, pName, strSize);
            }
            mActivityType = aType;
        }
        ~AppInfo() {
            if(mPackageName) {
                free(mPackageName);
            }
        }
        char* getPackageName(void) {
            return mPackageName;
        }
        int getActivityType(void) {
            return mActivityType;
        }
        bool isActivityGame() {
            if (mActivityType == GAMEDET_IS_GAME){
                return true;
            }
            return false;
        }
        bool isActivityBM() {
            if(mActivityType == GAMEDET_IS_BM) {
                return true;
            }
            return false;
        }
        bool isActivityApp() {
            if(mActivityType == GAMEDET_IS_APP) {
                return true;
            }
            return false;
        }
};


class AppList {
    private:
        unsigned int mMaxSize;
        unsigned int mCurAddPos;
        std::vector<AppInfo*> mAppList;
    private:
        void mPrintList();
    public:
        explicit AppList(int size) {
            mMaxSize = size;
            mCurAddPos = 0;
        }
        ~AppList();
        bool AddElementInList(char*, int);
        int CheckNameInListAndGetType(char*);
        bool ExistsInList(char*);
};

class XmlData {
    private:
        static XmlData *mXmlData;
        AppsListXmlParser *mXmlParser;
        AppList mWhiteList;
        AppList mBlackList;
        AppList mROGameList;
    private:
        void Init();
    public:
        ~XmlData();
        XmlData() :mWhiteList(MAX_APPLIST_SIZE), mBlackList(MAX_ROLIST_SIZE), mROGameList(MAX_ROLIST_SIZE){}

        static XmlData* getInstance() {
            if (NULL == mXmlData) {
                mXmlData = new XmlData();
                mXmlData->Init();
            }
            return mXmlData;
        }

        static void PopulateWhiteListFrmXml(xmlNodePtr, void *);
        static void PopulateReadOnlyGameListFrmXml(xmlNodePtr, void *);
        static void PopulateReadOnlyBlackListFrmXml(xmlNodePtr, void *);
        bool AddElementInList(char*, int, AppList&);
        int CheckInListAndGetType(char*, AppList&);
        bool ExistsInList(char*, AppList&);
        int MapActivityType(char*);
        bool ValidatePackageName(char* pName);
        bool ValidateActivityType(char *activityType, int expectedType, int &aType);

        AppList& GetWhiteList() {
            return mWhiteList;
        }
        AppList& GetBlackList() {
            return mBlackList;
        }
        AppList& GetROGameList() {
            return mROGameList;
        }
};

}; //for namespace
#endif
