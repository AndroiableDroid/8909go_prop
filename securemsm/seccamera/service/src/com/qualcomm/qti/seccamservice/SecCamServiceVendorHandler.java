// Copyright (c) 2017 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
package com.qualcomm.qti.seccamservice;

import android.os.Bundle;
import android.os.Message;
import android.os.Messenger;
import android.os.RemoteException;
import android.util.Log;

public class SecCamServiceVendorHandler {

    private final static String LOG_TAG = "SECCAM-SERVICE-VENDOR-HANDLER";

    public static final int JNI_OK = 0;
    public static final int JNI_EPERM = -1;
    public static final int JNI_EINVAL = -22;
    public static final int JNI_ETIMEDOUT = -110;

    private static final int MSG_VENDOR_EXCHANGE_TIMESTAMP = 2000;

    //=========================================================================
    // JNI API
    //=========================================================================
    private static native long exchangeTimestampWithTA(long timestamp);

    //=========================================================================
    static void handleVendorMessage_MSG_VENDOR_EXCHANGE_TIMESTAMP(Message msg) {
        int ret = JNI_OK;

        Log.d(LOG_TAG, "::handleVendorMessage_MSG_VENDOR_EXCHANGE_TIMESTAMP");
        Messenger activityMessenger = msg.replyTo;
        Message replyMsg = Message.obtain();
        replyMsg.what = MSG_VENDOR_EXCHANGE_TIMESTAMP;
        Bundle in_bundle = msg.getData();
        long hlosTimestamp = in_bundle.getLong("hlosTimestamp");

        // Call the JNI function to handle the timestamp exchange command
        long tzTimestamp = exchangeTimestampWithTA(hlosTimestamp);

        Bundle out_bundle = new Bundle();
        out_bundle.putLong("tzTimestamp", tzTimestamp);
        replyMsg.setData(out_bundle);
        try {
            activityMessenger.send(replyMsg);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    //=========================================================================
    static boolean handleVendorMessage(Message msg) {
        Log.d(LOG_TAG, "::handleVendorMessage");
        boolean ret = false;

        switch(msg.what) {
            case MSG_VENDOR_EXCHANGE_TIMESTAMP: {
                handleVendorMessage_MSG_VENDOR_EXCHANGE_TIMESTAMP(msg);
                ret = true;
                break;
            }
            default:
                ret = false;
        }

        return ret;
    }
}
