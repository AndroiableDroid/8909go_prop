/*
 *Copyright (c) 2017 Qualcomm Technologies, Inc.
 *All Rights Reserved.
 *Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

package com.qualcomm.qti.autoregistration;

import android.app.job.JobParameters;
import android.app.job.JobService;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.text.TextUtils;
import android.util.SparseArray;
import android.util.Log;

public class RegistrationJobService extends JobService {
    private final String TAG = "RegistrationJobService";
    private final SparseArray<JobParameters> mJobParamsMap = new SparseArray<JobParameters>();
    private Handler mHandler = new Handler();

    @Override
    public boolean onStartJob(JobParameters params) {
        mJobParamsMap.put(params.getJobId(), params);
        Log.d(TAG, "onStartJob job size = " + mJobParamsMap.size());
        if (mJobParamsMap.size() == 1) {
            performJob(params);
        }
        return true;
    }

    @Override
    public boolean onStopJob(JobParameters params) {
        Log.d(TAG, "onStopJob job size = " + mJobParamsMap.size());
        int ind = mJobParamsMap.indexOfValue(params);
        if (ind > -1) {
            mJobParamsMap.remove(ind);
        }
        return false;
    }

    private void performJob(JobParameters params) {
        Log.d(TAG, "performJob job size = " + mJobParamsMap.size());
        RegistrationEntity entity = (RegistrationEntity)
                params.getTransientExtras().getSerializable("REG_ENTITY");
        if (entity == null) return;
        Log.d(TAG, "performJob RegistrationEntity = " + entity);
        if (TextUtils.isEmpty(entity.rawData)) {
            new RegistrationTask(this, entity.ctSlotId, entity.primarySimSlotId) {
                @Override
                public void onResult(boolean registered, String rawData, String resultDesc) {
                    parseResult(registered, rawData, resultDesc);
                }
            };
        } else {
            new RegistrationTask(entity.rawData) {
                @Override
                public void onResult(boolean registered, String rawData, String resultDesc) {
                    parseResult(registered, rawData, resultDesc);
                }
            };
        }
    }

    private void parseResult(boolean registered, String rawData, String resultDesc) {
        mHandler.post(new Runnable() {
            @Override
            public void run() {
                if (mJobParamsMap.size() == 0) {
                    return;
                }
                JobParameters params = mJobParamsMap.valueAt(0);
                if (params == null) {
                    return;
                } else {
                    jobFinished(params, false);
                    mJobParamsMap.removeAt(0);
                    if (mJobParamsMap.size() > 0) {
                        performJob(mJobParamsMap.valueAt(0));
                    }
                }
                RegistrationEntity entity = (RegistrationEntity)
                        params.getTransientExtras().getSerializable("REG_ENTITY");
                entity.isRegistered = registered;
                entity.rawData = rawData;
                entity.reltDesc = resultDesc;
                notifyResult(entity);
            }
        });
    }

    private void notifyResult(RegistrationEntity entity) {
        Intent intent = new Intent(RegistrationTracker.ACTION_AUTO_REGISTERATION);
        Log.d(TAG, "performJob RegistrationEntity = " + entity);
        intent.putExtra("REG_ENTITY", entity);
        intent.setFlags(Intent.FLAG_RECEIVER_FOREGROUND);
        intent.setClass(this, AutoRegReceiver.class);
        sendOrderedBroadcast(intent, null);
    }
}
