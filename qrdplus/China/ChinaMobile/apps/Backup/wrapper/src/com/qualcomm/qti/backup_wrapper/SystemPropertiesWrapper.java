/*
 *  Copyright (c) 2017 Qualcomm Technologies, Inc.
 *  All Rights Reserved.
 *  Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

package com.qualcomm.qti.backup_wrapper;

import android.os.SystemProperties;
import android.util.Log;
import com.qualcomm.qti.backup_wrapper.WrapperNotSupportException;

public class SystemPropertiesWrapper {

    private static final String TAG = "SystemPropertiesWrapper";

    /**
     * Get the value for the given key.
     * @return if the key isn't found, return def if it isn't null, or an empty string otherwise
     * @throws IllegalArgumentException if the key exceeds 32 characters
     */
    public static String get(String key, String def) throws WrapperNotSupportException {
        try{
            return SystemProperties.get(key, def);
        } catch (Exception e) {
            Log.e(TAG,"get: catch an exception ", e);
            throw new WrapperNotSupportException(TAG + " Not support!", e);
        }
    }

    /**
     * Set the value for the given key.
     * @throws IllegalArgumentException if the key exceeds 32 characters
     * @throws IllegalArgumentException if the value exceeds 92 characters
     */
    public static void set(String key, String val) throws WrapperNotSupportException {
        try{
            SystemProperties.set(key, val);
        } catch (Exception e) {
            Log.e(TAG,"get: catch an exception ", e);
            throw new WrapperNotSupportException(TAG + " Not support!", e);
        }
    }
}
