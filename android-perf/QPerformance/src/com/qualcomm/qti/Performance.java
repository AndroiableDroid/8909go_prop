/*
 * Copyright (c) 2015,2017 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Copyright (c) 2011-2014, The Linux Foundation. All rights reserved.
 */

package com.qualcomm.qti;

import android.util.Log;
import java.util.ArrayList;

public class Performance
{
    private static final String TAG = "Perf";
    static {
        try {
            System.loadLibrary("qti_performance");
        } catch (UnsatisfiedLinkError e) {
        }
    }
    /** @hide */
    public Performance() {
        //Log.d(TAG, "Perf module initialized");
    }

    /* The following are the PerfLock API return values*/
    /** @hide */ public static final int REQUEST_FAILED = -1;
    /** @hide */ public static final int REQUEST_SUCCEEDED = 0;

    /** @hide */ private int handle = 0;

    /* The following functions are the PerfLock APIs*/
    /** @hide */
    public int perfLockAcquire(int duration, int... list) {

        handle = native_perf_lock_acq(handle, duration, list);
        if (handle <= 0)
            return REQUEST_FAILED;
        else
            return handle;
    }

    /** @hide */
    public int perfLockRelease() {
        int retValue = REQUEST_SUCCEEDED;

        retValue = native_perf_lock_rel(handle);
        handle = 0;
        return retValue;
    }

    /** @hide */
    public int perfLockReleaseHandler(int _handle) {
        return native_perf_lock_rel(_handle);
    }

    /** @hide */
    public int perfHint(int hint, String userDataStr, int userData1, int userData2) {

        handle = native_perf_hint(hint, userDataStr, userData1, userData2);
        if (handle <= 0)
            return REQUEST_FAILED;
        else
            return handle;
    }

    public int perfIOPrefetchStart(int PId, String Pkg_name, String Code_path)
    {
        return native_perf_io_prefetch_start(PId,Pkg_name, Code_path);
    }

    public int perfIOPrefetchStop(){
        return native_perf_io_prefetch_stop();
    }

    private native int  native_perf_lock_acq(int handle, int duration, int list[]);
    private native int  native_perf_lock_rel(int handle);
    private native int  native_perf_hint(int hint, String userDataStr, int userData1, int userData2);
    private native int  native_perf_io_prefetch_start(int pid, String pkg_name, String Code_path);
    private native int  native_perf_io_prefetch_stop();
}
