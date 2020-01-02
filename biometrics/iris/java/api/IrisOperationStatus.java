/*
 * Copyright (c) 2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
package android.hardware.iris;

import android.os.Parcel;
import android.os.Parcelable;
import android.util.Log;
/**
 * Container for iris metadata.
 * @hide
 */
public final class IrisOperationStatus implements Parcelable {
    private static final String TAG = "IrisOperationStatus";

    public static class IrisEyeDesc {
        public int mPupilX;
        public int mPupilY;
        public int mPupilRadius;
        public int mIrisX;
        public int mIrisY;
        public int mIrisRadius;

        public IrisEyeDesc(Parcel in) {
            mPupilX = in.readInt();
            mPupilY = in.readInt();
            mPupilRadius = in.readInt();
            mIrisX = in.readInt();
            mIrisY = in.readInt();
            mIrisRadius = in.readInt();
            Log.v(TAG, "IrisOperationStatus mPupilX" + mPupilX + "mPupilY" + mPupilY);
        }
    };

    public static class IrisFrameDesc {
        public IrisEyeDesc mLeftEye;
        public IrisEyeDesc mRightEye;
        public byte[] mVendorInfo;
        public IrisFrameDesc(Parcel in) {
            mLeftEye = new IrisEyeDesc(in);
            mRightEye = new IrisEyeDesc(in);
            mVendorInfo = in.createByteArray();
        }
    };

    public int mProgress;
    public int mQuality;
    public IrisFrameDesc mDesc;
    public CharSequence mHelpString;

    private IrisOperationStatus(Parcel in) {
        mProgress = in.readInt();
        mQuality = in.readInt();
        Log.v(TAG, "IrisOperationStatus mprogress" + mProgress + "quality" + mQuality);
        mDesc = new IrisFrameDesc(in);
    }

    private void writeEyeDesc(Parcel out, IrisEyeDesc desc) {
        out.writeInt(desc.mPupilX);
        out.writeInt(desc.mPupilY);
        out.writeInt(desc.mPupilRadius);
        out.writeInt(desc.mIrisX);
        out.writeInt(desc.mIrisY);
        out.writeInt(desc.mIrisRadius);
    }
    private void writeFrameDesc(Parcel out, IrisFrameDesc desc) {
        writeEyeDesc(out, desc.mLeftEye);
        writeEyeDesc(out, desc.mRightEye);
        out.writeByteArray(desc.mVendorInfo);
    }
    public int describeContents() {
        return 0;
    }

    public void writeToParcel(Parcel out, int flags) {
        out.writeInt(mProgress);
        out.writeInt(mQuality);
        writeFrameDesc(out, mDesc);
    }

    public static final Parcelable.Creator<IrisOperationStatus> CREATOR
            = new Parcelable.Creator<IrisOperationStatus>() {
        public IrisOperationStatus createFromParcel(Parcel in) {
            return new IrisOperationStatus(in);
        }

        public IrisOperationStatus[] newArray(int size) {
            return new IrisOperationStatus[size];
        }
    };
};
