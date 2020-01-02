/******************************************************************************
    Copyright (c) 2016 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.
 *******************************************************************************/

#include "XtraSubscriber.h"
#include "IzatDefines.h"
#include "IDataItemCore.h"
#include "DataItemId.h"
#include "DataItemConcreteTypes.h"
#include "DataItemsFactory.h"
#include <platform_lib_log_util.h>

#define LOG_NDEBUG 0

#ifdef LOG_TAG
#undef LOG_TAG
#define LOG_TAG "[XTRA2]XtraSubscriber"
#endif

namespace izat_manager
{

XtraSubscriber::XtraSubscriber(const struct s_IzatContext * izatContext) :
        mIzatContext(izatContext)
{
    ENTRY_LOG();

    subscribe(true);

    EXIT_LOG_WITH_ERROR("%d", 0);
}

XtraSubscriber::~XtraSubscriber()
{
    ENTRY_LOG();

    subscribe(false);

    EXIT_LOG_WITH_ERROR("%d", 0);
}

void XtraSubscriber::subscribe(bool yes)
{
    ENTRY_LOG();

    // Subscription data list
    std::list<DataItemId> subItemIdList;
    subItemIdList.push_back(NETWORKINFO_DATA_ITEM_ID);
    subItemIdList.push_back(MCCMNC_DATA_ITEM_ID);

    if (yes) {
        LOC_LOGD(LOG_TAG" subscribe to NETWORKINFO, MCCMNC data items");

        mIzatContext->mSystemStatusOsObsrvr->subscribe(subItemIdList, this);

        // request data list
        LOC_LOGD(LOG_TAG" request to TAC data items");

        std::list<DataItemId> reqItemIdList;
        reqItemIdList.push_back(TAC_DATA_ITEM_ID);

        mIzatContext->mSystemStatusOsObsrvr->requestData(reqItemIdList, this);

    } else {
        LOC_LOGD(LOG_TAG" unsubscribe to NETWORKINFO, MCCMNC data items");

        mIzatContext->mSystemStatusOsObsrvr->unsubscribe(subItemIdList, this);
    }

    EXIT_LOG_WITH_ERROR("%d", 0);
}

// IDataItemObserver overrides
void XtraSubscriber::getName (string & name)
{
    name = "XtraSubscriber";
}

void XtraSubscriber::notify(const std::list<IDataItemCore *> & dlist)
{
    ENTRY_LOG();

    mIzatContext->mMsgTask->sendMsg(new (nothrow) handleOsObserverUpdateMsg(this, dlist));

    EXIT_LOG_WITH_ERROR("%d", 0);
}

XtraSubscriber::handleOsObserverUpdateMsg::handleOsObserverUpdateMsg(XtraSubscriber* xtraSubscriber,
           const std::list<IDataItemCore *> & dataItemList) : mXtraSubscriberObj(xtraSubscriber)
{
    ENTRY_LOG();

    int result = -1;
    do {
        std::list<IDataItemCore *>::const_iterator it = dataItemList.begin();
        for (; it != dataItemList.end(); it++) {
            IDataItemCore *updatedDataItem = *it;

            IDataItemCore * dataitem = DataItemsFactory::createNewDataItem(updatedDataItem->getId());
            BREAK_IF_ZERO(2, dataitem);
            // Copy the contents of the data item
            dataitem->copy(updatedDataItem);

            mDataItemList.push_back(dataitem);
        }
        result = 0;
    } while(0);

    EXIT_LOG_WITH_ERROR("%d", result);
}

void XtraSubscriber::handleOsObserverUpdateMsg::proc() const
{

    ENTRY_LOG();

    int result = -1;

    do {
        std::list<IDataItemCore *>::const_iterator it = mDataItemList.begin();
        for (; it != mDataItemList.end(); it++) {
            IDataItemCore* dataItem = *it;
            switch (dataItem->getId())
            {
                case NETWORKINFO_DATA_ITEM_ID:
                {
                    NetworkInfoDataItem *networkInfo= static_cast<NetworkInfoDataItem*>(dataItem);

                    LOC_LOGD(LOG_TAG" NETWORKINFO connected=%d type=%d", networkInfo->mConnected, networkInfo->mType);

                    // TODO: ipc to XTRA daemon
                }
                break;

                case TAC_DATA_ITEM_ID:
                {
                    TacDataItem *tac= static_cast<TacDataItem*>(dataItem);

                    LOC_LOGD(LOG_TAG" TAC=%s", tac->mValue.c_str());

                    // TODO: ipc to XTRA daemon
                }
                break;

                case MCCMNC_DATA_ITEM_ID:
                {
                    MccmncDataItem *mccmnc= static_cast<MccmncDataItem*>(dataItem);

                    LOC_LOGD(LOG_TAG" MCCMNC=%s", mccmnc->mValue.c_str());

                    // TODO: ipc to XTRA daemon
                }
                break;

                default:
                break;
            }
        }
        result = 0;
    } while(0);

    EXIT_LOG_WITH_ERROR("%d", result);
}

XtraSubscriber::handleOsObserverUpdateMsg::~handleOsObserverUpdateMsg()
{
    ENTRY_LOG();

    std::list<IDataItemCore *>::const_iterator it = mDataItemList.begin();
    for (; it != mDataItemList.end(); it++)
    {
        delete *it;
    }

    EXIT_LOG_WITH_ERROR("%d", 0);
}

}
