/*
 *  Copyright (c) 2017 Qualcomm Technologies, Inc.
 *  All Rights Reserved.
 *  Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

package com.qualcomm.qti.backup_wrapper;

import android.os.SystemService;
import android.util.Log;
import com.qualcomm.qti.backup_wrapper.WrapperNotSupportException;

public class SystemServiceWrapper {

    private static final String TAG = "SystemServiceWrapper";

    public static void start(String name) throws WrapperNotSupportException{
        try {
            SystemService.start(name);
        } catch (Exception e) {
            Log.e(TAG,"start: catch an exception ", e);
            throw new WrapperNotSupportException(TAG + " Not support!", e);
        }
    }

    public static void stop(String name) throws WrapperNotSupportException{
        try {
            SystemService.stop(name);
        } catch (Exception e) {
            Log.e(TAG,"stop: catch an exception ", e);
            throw new WrapperNotSupportException(TAG + " Not support!", e);
        }
    }
}