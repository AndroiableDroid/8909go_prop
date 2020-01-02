/*
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Not a Contribution.
 * Apache license notifications and license are retained
 * for attribution purposes only.
 */

/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License
 */

package com.android.settings.iris;

import android.content.Intent;
import android.content.res.ColorStateList;
import android.os.Bundle;
import android.view.View;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.util.Log;
import android.util.Size;
import android.graphics.Rect;
import android.view.Gravity;
import android.view.SurfaceHolder;
import android.view.SurfaceHolder.Callback;
import android.view.SurfaceView;
import android.widget.FrameLayout;
import android.widget.FrameLayout.LayoutParams;

import android.app.Activity;
import android.os.Handler;
import android.widget.Toast;

import com.android.settings.ChooseLockSettingsHelper;
import com.android.settings.R;

import android.util.Size;
import android.graphics.Rect;

import android.hardware.iris.IrisManager;
import android.hardware.iris.IrisOperationStatus;
import java.util.Arrays;

/**
 * Activity which handles the actual enrolling for fingerprint.
 */
public class IrisEnrollEnrolling extends IrisEnrollBase 
    implements SurfaceHolder.Callback, IrisEnrollSidecar.Listener {

    private static final String TAG_SIDECAR = "sidecar";
    private static final String TAG = "IrisEnrollEnrolling";

    private static final int PROGRESS_BAR_MAX = 100;
    private static final int FINISH_DELAY = 250;

    private ProgressBar mProgressBar;
    private ProgressBar mProgressBar1;
    private TextView mStartMessage;
    private TextView mErrorText;
    private IrisEnrollSidecar mSidecar;
    private boolean mRestoring;

    private SurfaceView mSurfaceView;
    private SurfaceHolder mSurfaceHolder;

    private final Handler mHandler = new Handler();
    private Toast mToast;
    private View mParent;
    private int mWidth = 1920, mHeight = 960;

    // SurfaceHolder callbacks
    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        Log.v(TAG, "surfaceChanged: width = " + width + ", height = " + height);
        Log.v(TAG, "parent width=" + mParent.getWidth());
        if (mParent != null && mParent.getWidth() > 0) {
            FrameLayout.LayoutParams params = (FrameLayout.LayoutParams) mSurfaceView.getLayoutParams();
            params.width = mParent.getWidth();
            params.height = params.width * mHeight / mWidth;
            Log.v(TAG, "layout width=" + params.width + " layout height="+params.height);
            mSurfaceView.setLayoutParams(params);
        }

    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        Log.v(TAG, "surfaceCreated");
        mSurfaceHolder = holder;
        mHandler.post(mEnrollRunnable);
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        Log.v(TAG, "surfaceDestroyed");
        mSurfaceHolder = null;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.iris_enroll_enrolling);
        mParent = findViewById(R.id.surface_parent);
        mStartMessage = (TextView) findViewById(R.id.start_message);
        mProgressBar = (ProgressBar) findViewById(R.id.iris_progress_bar);
        mProgressBar1 = (ProgressBar) findViewById(R.id.iris_progress_bar1);

        mSurfaceView = (SurfaceView)findViewById(R.id.iris_preview_texture);

        mSurfaceHolder = mSurfaceView.getHolder();
        mSurfaceHolder.addCallback(this);
        mSurfaceHolder.setType(SurfaceHolder.SURFACE_TYPE_PUSH_BUFFERS);

        IrisManager irisManager = getSystemService(IrisManager.class);
        Size previewSize = irisManager.getPreviewSize(IrisManager.IRIS_PREVIEW_SIZE_ENROLL);

        if (previewSize != null) {
            mWidth = previewSize.getWidth();
            mHeight = previewSize.getHeight();
        }
        mSurfaceHolder.setFixedSize(mWidth, mHeight);


        mSurfaceView.setVisibility(View.VISIBLE);

        mRestoring = savedInstanceState != null;
        mToast = Toast.makeText(this, "", Toast.LENGTH_SHORT);
        mToast.setGravity(Gravity.TOP | Gravity.CENTER_HORIZONTAL, 0, 0);

    }

    @Override
    protected void onStart() {
        super.onStart();
    }

    @Override
    protected void onStop() {
        Log.w(TAG, "onStop");
        super.onStop();
        if (mSidecar != null) {
            mSidecar.setListener(null);
            mSidecar.setPreviewSurface(null);
            mSidecar = null;
        }

        if (!isChangingConfigurations()) {
            finish();
        }
    }

    private void startEnroll() {

        mSidecar = (IrisEnrollSidecar) getFragmentManager().findFragmentByTag(TAG_SIDECAR);
        if (mSidecar == null) {
            mSidecar = new IrisEnrollSidecar();
            getFragmentManager().beginTransaction().add(mSidecar, TAG_SIDECAR).commit();
        }
        mSidecar.setListener(this);
        mSidecar.setPreviewSurface(mSurfaceHolder.getSurface());
        updateProgress();
    }

    private void launchFinish(byte[] token) {
        Log.w(TAG, "launchFinish");
        clearHelp();
        Intent intent = getFinishIntent();
        intent.addFlags(Intent.FLAG_ACTIVITY_FORWARD_RESULT);
        intent.putExtra(ChooseLockSettingsHelper.EXTRA_KEY_CHALLENGE_TOKEN, token);
        startActivity(intent);
        finish();
    }

    protected Intent getFinishIntent() {
        return new Intent(this, IrisEnrollFinish.class);
    }

    @Override
    public void onEnrollmentError(CharSequence errString) {
        showError(errString);
    }

    @Override
    public void onEnrollmentStatus(IrisOperationStatus status) {
        updateProgress();
        if (status.mHelpString != null)
            showHelp(status.mHelpString);
        else
            clearHelp();

        if (status.mDesc.mVendorInfo != null && status.mDesc.mVendorInfo.length > 0)
            Log.v(TAG,  Arrays.toString(status.mDesc.mVendorInfo));

        Log.v(TAG, "left eye pupil x=" + status.mDesc.mLeftEye.mPupilX);
        Log.v(TAG, "left eye pupil y=" + status.mDesc.mLeftEye.mPupilY);
    }

    @Override
    public void onEnrollmentDone() {
        updateProgress();
        mProgressBar.postDelayed(mDelayedFinishRunnable, FINISH_DELAY);
    }
    private void updateProgress() {
        int progress = getProgress(100, mSidecar.getEnrollmentProgress());
        int previousProgress = mProgressBar.getProgress();
        mProgressBar.setProgress(progress);
        mProgressBar1.setProgress(progress);
        Log.w(TAG, "updateProgress " + progress);
        if (progress > previousProgress)
           clearHelp();
    }
    

    private int getProgress(int steps, int progress) {
        int p = Math.max(0, progress);
        return PROGRESS_BAR_MAX * p / steps;
    }

    private void showError(CharSequence error) {
        Log.w(TAG, "showError " + error);
        mStartMessage.setText(error);
    }

    private void showHelp(CharSequence helpString) {
        mToast.setText(helpString);
        mToast.show();
    }

    private void clearHelp() {
        mToast.cancel();
    }

    // Give the user a chance to see progress completed before jumping to the next stage.
    private final Runnable mDelayedFinishRunnable = new Runnable() {
        @Override
        public void run() {
            launchFinish(mToken);
        }
    };

    private final Runnable mEnrollRunnable = new Runnable() {
        @Override
        public void run() {
            startEnroll();
        }
    };

}
