/*
 *Copyright (c) 2017 Qualcomm Technologies, Inc.
 *All Rights Reserved.
 *Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

package com.qualcomm.qti.autoregistration;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;

public class RegistrationService extends Service {
    private final String TAG = "RegistrationService";

    @Override
    public void onCreate() {
        super.onCreate();
        Log.d(TAG, "onCreate");
        RegistrationTracker.setup(getApplicationContext());
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        Log.d(TAG, "onDestroy");
        RegistrationTracker.getInstance().teardown();
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }
}
