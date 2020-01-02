/*
 * Copyright (c) 2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

package com.qualcomm.qti.ipass;

import android.app.Activity;
import android.view.Menu;
import android.view.MenuItem;
import android.content.Intent;
import android.graphics.RectF;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.content.Context;
import android.widget.Toast;
import android.os.HandlerThread;
import android.view.Gravity;

import android.view.SurfaceHolder;
import android.view.SurfaceHolder.Callback;
import android.view.SurfaceView;
import android.widget.FrameLayout;
import android.widget.FrameLayout.LayoutParams;
import android.view.Surface;

import java.util.Arrays;
import java.nio.ByteBuffer;

import com.qualcomm.qti.ipass.R;
import android.hardware.iris.IrisManager;
import android.hardware.iris.Iris;
import android.hardware.iris.IrisOperationStatus;

import android.os.CancellationSignal;

import android.graphics.Rect;
import android.util.Size;

public class SimpleActivity extends Activity  implements SurfaceHolder.Callback{

    private static final String TAG = "IrisActivity";
    boolean mStarted = false;
    private Button mBtnStart;
    private Toast mToast;

    private enum Status {
        STOPPED, VERIFYING
    };

    private Status mCurrentStatus;

    private final Handler mHandler = new Handler();
    private TextView mTextViewInfo;

    private IrisManager mIrisManager;
    CancellationSignal mCancelSignal;

    private SurfaceView mSurfaceView;
    private SurfaceHolder mSurfaceHolder;
    private Surface mSurface;
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
        mSurface = holder.getSurface();
        mHandler.post(new Runnable() {
            @Override
            public void run() {
                handle_authenticate();
                updateStartButton();
            }
        });

    }
    
    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        Log.v(TAG, "surfaceDestroyed");
        mSurface = null;
    }


    public class TestAuthenticationCallback extends IrisManager.AuthenticationCallback {
        @Override
        public void onAuthenticationError(int errorCode, CharSequence errString) {
            postInfo("Authenticate error, err code=" + errorCode +" "+errString);
            mCurrentStatus = Status.STOPPED;
            updateStartButton();
            mToast.cancel();
            mSurfaceView.setVisibility(View.INVISIBLE);
        }

        @Override
        public void onAuthenticationStatus(IrisOperationStatus status) {
            if (status.mQuality != 0) {
                mToast.setText(status.mHelpString);
                Log.v(TAG, "quality=" +status.mQuality);
                if (status.mHelpString != null)
                    Log.v(TAG, status.mHelpString.toString());

                mToast.show();
            } else {
                mToast.cancel();
            }
        }

        @Override
        public void onAuthenticationSucceeded(IrisManager.AuthenticationResult result) {
            mCurrentStatus = Status.STOPPED;
            updateStartButton();
            postInfo("Authenticate successful");
            mToast.cancel();
            mSurfaceView.setVisibility(View.INVISIBLE);
        }

        @Override
        public void onAuthenticationFailed() {
            postInfo("Fail to Authenticate");
            mCurrentStatus = Status.STOPPED;
            updateStartButton();
            mToast.cancel();
            mSurfaceView.setVisibility(View.INVISIBLE);
        }
    };

    private void updateStartButton() {
        if (mCurrentStatus == Status.STOPPED) {
            mBtnStart.setEnabled(true);
        } else {
            mBtnStart.setEnabled(false);
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    @Override
    protected void onPause() {
        if (mCancelSignal != null)
            mCancelSignal.cancel();
        super.onPause();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.simple);

        mIrisManager = (IrisManager)getSystemService(Context.IRIS_SERVICE);
        Size previewSize = mIrisManager.getPreviewSize(IrisManager.IRIS_PREVIEW_SIZE_AUTH);

        if (previewSize != null)
            Log.v(TAG, previewSize.toString());
        else
            Log.v(TAG, "fail to get preview size");

        mParent = findViewById(R.id.surface_parent);
        mTextViewInfo = (TextView) findViewById(R.id.textViewInfo);

        mSurfaceView = (SurfaceView)findViewById(R.id.texture);
        mSurfaceView.setVisibility(View.VISIBLE);
        mSurfaceHolder = mSurfaceView.getHolder();
        mSurfaceHolder.addCallback(this);
        mSurfaceHolder.setType(SurfaceHolder.SURFACE_TYPE_PUSH_BUFFERS);
        if (previewSize != null) {
            mWidth = previewSize.getWidth();
            mHeight = previewSize.getHeight();
        }
        mSurfaceHolder.setFixedSize(mWidth, mHeight);


        mSurfaceView.setVisibility(View.INVISIBLE);

        mCurrentStatus = Status.STOPPED;

        mBtnStart = (Button) findViewById(R.id.btnStart);
        mBtnStart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (mCurrentStatus == Status.STOPPED) {
                    handle_authenticate();
                    updateStartButton();
                }
            }
        });

        mToast = Toast.makeText(this, "", Toast.LENGTH_SHORT);
        mToast.setGravity(Gravity.TOP|Gravity.LEFT, 0, 0);
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        return super.onOptionsItemSelected(item);
    }

    public void handle_authenticate() {
        if (!mIrisManager.hasEnrolledIris()) {
            postInfo("No enrolled iris");
            return;
        }

        if (mSurface == null) {
            postInfo("No surface available");
            mSurfaceView.setVisibility(View.VISIBLE);
            return;
        }

        TestAuthenticationCallback authenticationResult = new TestAuthenticationCallback();
        mCancelSignal = new CancellationSignal();

        mIrisManager.setPreviewSurface(mSurface);
        mIrisManager.authenticate(null, mCancelSignal, 0, authenticationResult, null);
        mCurrentStatus = Status.VERIFYING;
        postInfo("Authenticating...");
    }

    void postInfo(final String info) {
        mTextViewInfo.setText(info);
    }
}
