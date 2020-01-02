/*
 *Copyright (c) 2014, 2017 Qualcomm Technologies, Inc.
 *All Rights Reserved.
 *Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

package com.qualcomm.qti.autoregistration;

import java.io.IOException;
import java.io.InputStream;
import java.net.URI;
import java.util.ArrayList;
import java.util.List;

import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.ByteArrayEntity;
import org.apache.http.impl.client.DefaultHttpClient;

import org.json.JSONException;
import org.json.JSONObject;

import android.content.Context;
import android.os.Bundle;
import android.os.Message;
import android.text.TextUtils;
import android.util.Base64;
import android.util.Log;

public abstract class RegistrationTask {

    private static final String TAG = "RegistrationTask";
    private static final boolean DBG = false;

    private static final String CHARSET = "UTF-8";
    private static final String SERVER_URI = "http://zzhc.vnet.cn";
    private static final String RESULT_SUCCESS = "0";
    private static final String RESULT_DESCRIPTION = "resultDesc";
    private static final String RESULT_CODE = "resultCode";
    private static final int MAX_LENGTH = 1024;

    private final RegistrationPairs mRegistrationPairs;

    public RegistrationTask(Context context, int ctSlotId, int primarySimPhoneId) {
        mRegistrationPairs = new RegistrationPairs(context, ctSlotId, primarySimPhoneId) {

            @Override
            public void onDeviceInfosGot(JSONObject data) {
                final String rawData = data.toString();
                requestWithRawData(rawData);
            }
        };
        mRegistrationPairs.load();
    }

    public RegistrationTask(String rawData) {
        mRegistrationPairs = null;
        requestWithRawData(rawData);
    }

    public void requestWithRawData(final String rawdata) {
        new Thread() {
            public void run() {
                byte[] byteToPost = Base64.encode(rawdata.getBytes(), Base64.DEFAULT);
                String response = post(byteToPost);
                onResult(isRegisterSucceed(response), rawdata, getResultDesc(response));
            }
        }.start();
    }

    public abstract void onResult(boolean registered, String rawData, String resultDesc);

    private String post(byte[] data) {
        InputStream is = null;
        String response = null;
        try {
            HttpClient client = new DefaultHttpClient();
            HttpPost request = new HttpPost(new URI(SERVER_URI));
            request.setHeader("Content-Type", "application/encrypted-json");
            request.setEntity(new ByteArrayEntity(data));
            is = client.execute(request).getEntity().getContent();
            byte[] resp = read(is);

            if (data != null) {
                response = new String(resp, CHARSET);
            }
            Log.d(TAG, "Response: " + response);
        } catch (Exception e) {
            Log.w(TAG, "failed to post", e);
        } catch (OutOfMemoryError e) {
            Log.w(TAG, "failed to post", e);
        } finally {
            try {
                if (is != null) {
                    is.close();
                }
            } catch (Exception e) {
            }
        }
        return response;
    }

    private boolean isRegisterSucceed(String response) {
        boolean flag = false;
        try {
            if (!TextUtils.isEmpty(response)) {
                JSONObject resultInfo = new JSONObject(response);
                if (resultInfo != null) {
                    String resultCode = resultInfo.getString(RESULT_CODE);
                    if (!TextUtils.isEmpty(resultCode)
                            && TextUtils.equals(resultCode, RESULT_SUCCESS)) {
                        flag = true;
                    }
                }
            }
        } catch (JSONException e) {
            Log.w(TAG, "failed to parse String object", e);
        }
        return flag;
    }

    private String getResultDesc(String response) {
        String resultDesc = null;
        try {
            if (!TextUtils.isEmpty(response)) {
                JSONObject resultInfo = new JSONObject(response);
                if (resultInfo != null) {
                    resultDesc = resultInfo.getString(RESULT_DESCRIPTION);
                }
            }
        } catch (JSONException e) {
            Log.w(TAG, "failed to parse String object", e);
        }
        return resultDesc;
    }

    private static byte[] read(InputStream is) throws IOException {
        byte[] data = null;
        byte[] buffer = new byte[MAX_LENGTH];
        int length = -1;
        while ((length = is.read(buffer)) != -1) {
            if (data == null) {
                data = new byte[length];
                System.arraycopy(buffer, 0, data, 0, length);
            } else {
                byte[] temp = new byte[data.length + length];
                System.arraycopy(data, 0, temp, 0, data.length);
                System.arraycopy(buffer, 0, temp, data.length, length);
                data = temp;
            }
        }
        return data;
    }
}
