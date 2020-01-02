/*
 *Copyright (c) 2014, 2017 Qualcomm Technologies, Inc.
 *All Rights Reserved.
 *Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

package com.qualcomm.qti.autoregistration;

import com.android.internal.telephony.TelephonyIntents;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.SystemProperties;
import android.os.UserHandle;
import android.os.Process;
import android.util.Log;

public class AutoRegReceiver extends BroadcastReceiver {
    private static final String TAG = "AutoRegReceiver";
    private static final boolean DBG = true;
    private boolean ENABLED = SystemProperties.getBoolean(
            "persist.vendor.radio.ps.registration.enabled", false);

    @Override
    public void onReceive(Context context, Intent intent) {
        if (DBG) {
            Log.d(TAG, "onReceived action:" + intent.getAction());
        }
        String receivedAction = intent.getAction();
        if (receivedAction == null || !ENABLED || UserHandle.myUserId() != 0) {
            Log.d(TAG, "bait out");
            if (receivedAction != null && context != null) {
                Process.killProcess(Process.myPid());
            }
            return;
        }
        if (receivedAction.equals(Intent.ACTION_BOOT_COMPLETED)) {
            if (DBG) {
                Log.d(TAG, "Action boot completed..");
            }
            context.startService(new Intent(context, RegistrationService.class));
        } else if ((!RegistrationTracker.mPowerOn
            && receivedAction.equals("org.codeaurora.intent.action.ACTION_DDS_SWITCH_DONE"))) {
            if (DBG) {
                Log.d(TAG, "Action dds switch done..");
            }
            RegistrationTracker.getInstance().tryToRegisterAfterDdsChanged();
        } else if (receivedAction.equals(TelephonyIntents.SECRET_CODE_ACTION)) {
            if (DBG) {
                Log.d(TAG, "Action secret code received..");
            }
            RegistrationTracker.getInstance().enforce();
        } else if (receivedAction.equals(RegistrationTracker.ACTION_AUTO_REGISTERATION)) {
            if (DBG) {
                Log.d(TAG, "Action result received..");
            }
            RegistrationTracker.getInstance().persistResult(intent);
        } else if (receivedAction.equals(RegistrationTracker.ACTION_AUTO_REGISTERATION_RETRY)) {
            if (DBG) {
                Log.d(TAG, "Action reschedual received..");
            }
            RegistrationTracker.getInstance().reschedule(intent);
        } else if (receivedAction.equals("org.codeaurora.intent.action.ACTION_ENHANCE_4G_SWITCH")) {
            if (DBG) {
                Log.d(TAG, "Action VOLTE switch done..");
            }
            RegistrationTracker.getInstance().tryToRegisterAfterVoLTESwitchChanged();
        }
    }

}
