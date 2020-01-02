/*
 *Copyright (c) 2017 Qualcomm Technologies, Inc.
 *All Rights Reserved.
 *Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

package com.qualcomm.qti.autoregistration;

import android.app.AlarmManager;
import android.app.PendingIntent;
import android.app.job.JobInfo;
import android.app.job.JobScheduler;
import android.content.ComponentName;
import android.content.Context;
import android.content.BroadcastReceiver;
import android.content.IntentFilter;
import android.content.Intent;
import android.content.SharedPreferences;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.os.ServiceManager;
import android.os.SystemProperties;
import android.os.RemoteException;
import android.preference.PreferenceManager;
import android.telephony.ServiceState;
import android.telephony.SubscriptionInfo;
import android.telephony.SubscriptionManager;
import android.telephony.TelephonyManager;
import android.text.TextUtils;
import android.util.Log;
import android.widget.Toast;

import com.android.internal.telephony.PhoneConstants;
import com.android.internal.telephony.TelephonyIntents;

import org.codeaurora.internal.IExtTelephony;

import java.util.List;

public class RegistrationTracker {
    private static final String TAG = "RegistrationTracker";
    private static final boolean DBG = true;
    private static final long DELAY_REQUEST_AFTER_POWER_ON = 60 * 1000;
    private static final long DELAY_REQUEST_AFTER_DDS_CHANGE = 60 * 1000;
    private static final long INTERVAL_RESCHEDUAL = 60 * 60 * 1000;
    private static final int MAX_REQUEST_TIMES = 10;

    private static final String PREF_ICCID_ON_SUCCESS = "sim_iccid";
    private static final String PREF_REQUEST_COUNT = "register_request_count";
    private static final String PREF_WIFI_MAC = "wifi_macid";

    public static final String ACTION_AUTO_REGISTERATION =
            "com.qualcomm.qti.action.AUTO_REGISTRATION";
    public static final String ACTION_AUTO_REGISTERATION_RETRY =
            "com.qualcomm.qti.action.AUTO_REGISTRATION_RETRY";
    //China Telecomm Issuer Identification Number
    public static final String CT_IIN = "898603,898611,898612";
    // SharedPreferences key for last known build fingerprint.
    private static final String KEY_FINGERPRINT = "build_fingerprint";

    private static RegistrationTracker sInstance;
    private Context mContext;
    private SharedPreferences mSharedPreferences;
    private AlarmManager mAlarmManager;
    private IExtTelephony mExtTelephony = IExtTelephony.Stub.
            asInterface(ServiceManager.getService("extphone"));
    private SubscriptionManager mSubscriptionManager;
    private ConnectivityManager mConnectivityManager;
    private BroadcastReceiver mWifiStateChangeListener = null;
    private BroadcastReceiver mNeworkStateChangeListener = null;
    private boolean mRegistering = false;
    public static boolean mPowerOn = true;
    private boolean mDelayBarrier = true;
    private int mJobId = 0;
    private boolean mDdsChanged = false;
    private boolean mVoLTESwitchChanged = false;
    private RegistrationEntity mEntity = null;

    private RegistrationTracker(Context context) {
        Log.d(TAG, "RegistrationTracker constructor");
        mContext = context;
        mSharedPreferences = PreferenceManager.getDefaultSharedPreferences(mContext);
        mAlarmManager = (AlarmManager) context.getSystemService(Context.ALARM_SERVICE);
        mSubscriptionManager = SubscriptionManager.from(context);
        mConnectivityManager = (ConnectivityManager)
                context.getSystemService(Context.CONNECTIVITY_SERVICE);
        String mac =  mSharedPreferences.getString(PREF_WIFI_MAC, null);
        if(mac == null) {
           sanityCheckMacForWifi();
        }
        checkSystemUpdatedStatus();
        mSharedPreferences.edit().putInt(PREF_REQUEST_COUNT, 0).commit();
        monitorNetworkConnectionStatus();
    }

    public static void setup(Context context) {
        if (sInstance == null) {
            sInstance = new RegistrationTracker(context);
        }
    }

    public void teardown() {
        cancelNextSchedule();
        if (mNeworkStateChangeListener != null) {
            mContext.unregisterReceiver(mNeworkStateChangeListener);
            mNeworkStateChangeListener = null;
        }
    }

    public static RegistrationTracker getInstance() {
        if (sInstance == null) {
            throw new RuntimeException("Need sutup firstly");
        }
        return sInstance;
    }

    public void enforce() {
        final JobScheduler scheduler = (JobScheduler) mContext
                .getSystemService(Context.JOB_SCHEDULER_SERVICE);
        if (scheduler.getPendingJob(mJobId) != null) {
            scheduler.cancel(mJobId);
        }
        onRegistrationRequestManually();
    }

    public void persistResult(Intent intent) {
        if (intent != null) {
            RegistrationEntity entity = (RegistrationEntity)
                    intent.getSerializableExtra("REG_ENTITY");
            Log.d(TAG, "persist result, entity is " + entity);
            if (entity != null) {
                mEntity = entity;
                if (entity.isRegistered) {
                    mSharedPreferences.edit().putString(PREF_ICCID_ON_SUCCESS, getIccIdText())
                            .commit();
                    mDdsChanged = false;
                    mVoLTESwitchChanged = false;
                    if (mNeworkStateChangeListener != null) {
                        mContext.unregisterReceiver(mNeworkStateChangeListener);
                        mNeworkStateChangeListener = null;
                        mContext.stopService(new Intent(mContext, RegistrationService.class));
                    }
                    Log.d(TAG, "auto registration success");
                } else if (!entity.isRegistered && !entity.isManual) {
                    scheduleNextIfNeed(entity);
                }
                toast(entity.reltDesc);
            }
            mRegistering = false;
        }
    }

    public void reschedule(Intent intent) {
        if (intent != null) {
            Log.d(TAG, "start to reschedule with entity is " + mEntity);
            if (mEntity != null) {
                scheduleRegistrationJob(mEntity);
            } else {
                tryToRegister(false);
            }
        }
    }

    private void sanityCheckMacForWifi() {
        mWifiStateChangeListener = new BroadcastReceiver() {
            public void onReceive(Context context, Intent intent) {
                String action = intent.getAction();
                if (action.equals(WifiManager.WIFI_STATE_CHANGED_ACTION)) {
                    if (intent.getIntExtra(WifiManager.EXTRA_WIFI_STATE, 0) ==
                            WifiManager.WIFI_STATE_ENABLED) {
                        WifiManager wifiManager = (WifiManager)
                                mContext.getSystemService(Context.WIFI_SERVICE);
                        WifiInfo wifiInfo = wifiManager.getConnectionInfo();
                        Log.d(TAG, "wifi info is " + wifiInfo);
                        String macAddress = wifiInfo == null ? null : wifiInfo.getMacAddress();
                        mSharedPreferences.edit().putString(PREF_WIFI_MAC, macAddress).commit();
                        if (mWifiStateChangeListener != null) {
                            mContext.unregisterReceiver(mWifiStateChangeListener);
                        }
                    }
                }
            }
        };
        IntentFilter wifiStateChangeFilter = new IntentFilter(
               WifiManager.WIFI_STATE_CHANGED_ACTION);
        mContext.registerReceiver(mWifiStateChangeListener, wifiStateChangeFilter);
    }

    private void checkSystemUpdatedStatus() {
        final String lastFingerprint = mSharedPreferences.getString(KEY_FINGERPRINT, null);
        Log.d( TAG, "Build fingerprint. old: " + lastFingerprint + " new: " + Build.FINGERPRINT);
        if (!Build.FINGERPRINT.equals(lastFingerprint)) {
            mSharedPreferences.edit().putString(KEY_FINGERPRINT, Build.FINGERPRINT)
                    .commit();
            mSharedPreferences.edit().putString(PREF_ICCID_ON_SUCCESS, "")
                    .commit();
        }
    }

    private void monitorNetworkConnectionStatus() {
        if (mNeworkStateChangeListener != null) {
            return;
        }
        mNeworkStateChangeListener = new BroadcastReceiver() {
            public void onReceive(Context context, Intent intent) {
                String action = intent.getAction();
                if (intent.getAction().equals(ConnectivityManager.CONNECTIVITY_ACTION)) {
                    Log.d(TAG, "Try to register since CONNECTIVITY_ACTION");
                    tryToRegister(false);
                } else if (intent.getAction().equals(
                        TelephonyIntents.ACTION_SERVICE_STATE_CHANGED)) {
                    ServiceState state = ServiceState.newFromBundle(intent.getExtras());
                    if (state.getState() == ServiceState.STATE_IN_SERVICE) {
                        Log.d(TAG, "Try to register since ACTION_SERVICE_STATE_CHANGED");
                        tryToRegister(true);
                    }
                }
            }
        };
        IntentFilter intentFilter = new IntentFilter(ConnectivityManager.CONNECTIVITY_ACTION);
        intentFilter.addAction(TelephonyIntents.ACTION_SERVICE_STATE_CHANGED);
        mContext.registerReceiver(mNeworkStateChangeListener, intentFilter);
    }

    public void tryToRegisterAfterDdsChanged() {
        Log.d(TAG, "Try to register since dds changed");
        mDdsChanged = true;
        mVoLTESwitchChanged = false;
        mRegistering = false;
        mSharedPreferences.edit().putInt(PREF_REQUEST_COUNT, 0).commit();
        cancelNextSchedule();
        // delay to register to avoid device not camp network after hotswap
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                tryToRegister(false);
            }
        }, DELAY_REQUEST_AFTER_DDS_CHANGE);
    }

    public void tryToRegisterAfterVoLTESwitchChanged() {
        Log.d(TAG, "Try to register since VOLTE switch changed");
        mVoLTESwitchChanged= true;
        mDdsChanged = false;
        mRegistering = false;
        mSharedPreferences.edit().putInt(PREF_REQUEST_COUNT, 0).commit();
        cancelNextSchedule();
        // delay to register to avoid device not camp network after hotswap
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                tryToRegister(false);
            }
        }, DELAY_REQUEST_AFTER_DDS_CHANGE);
    }

    private void tryToRegister(boolean serviceChanged) {
        if (mConnectivityManager != null) {
            NetworkInfo info = mConnectivityManager.getActiveNetworkInfo();
            if (info != null && info.isConnected()) {
                // Once the SIM changed, try to register
                String iccIdText = getIccIdText();
                if (!iccIdText.equals(
                    mSharedPreferences.getString(PREF_ICCID_ON_SUCCESS, null))
                            || mDdsChanged || mVoLTESwitchChanged) {
                    cancelNextSchedule();
                    // if under wifi, need wait for in-service so that SID and baseId can be fetched
                    boolean underWifi = info.getType() == ConnectivityManager.TYPE_WIFI;
                    Log.d(TAG, "Try to register underWifi = " + underWifi +
                            " serviceChanged = " + serviceChanged + " mDdsChanged = " + mDdsChanged +
                            " mVoLTESwitchChanged = " + mVoLTESwitchChanged);
                    if (serviceChanged || !underWifi || (underWifi && hasService())) {
                        onRegistrationRequest();
                    }
                }
            } else if (mDdsChanged || mVoLTESwitchChanged){
                Log.d(TAG, "No network now after dds changed or volte switch changed");
                monitorNetworkConnectionStatus();
            } else {
                Log.d(TAG, "Try to register without network");
            }
        }
    }

    private boolean hasService() {
        List<SubscriptionInfo> subList = mSubscriptionManager.getActiveSubscriptionInfoList();
        if (subList != null) {
            for (SubscriptionInfo subInfo : subList) {
                ServiceState state = TelephonyManager.getDefault()
                        .getServiceStateForSubscriber(subInfo.getSubscriptionId());
                if (state.getState() == ServiceState.STATE_IN_SERVICE) {
                    return true;
                }
            }
        }
        return false;
    }

    private void onRegistrationRequestManually() {
        int slotId = getCTSlotId();
        if (slotId < 0) {
            // Giving phone id on primary stack
            // so that MEID can be fetched
            slotId = getPrimaryStackPhoneId();
            Log.d(TAG, "Getting phone ID: " + slotId + "primary stack");
        }

        if (!isDDSOnCTSlotWithoutWifi()) {
            Toast.makeText(mContext, R.string.register_failed, Toast.LENGTH_LONG).show();
            return;
        }
        scheduleRegistrationJob(new RegistrationEntity(slotId, getPrimarySimPhoneId(), true));
    }

    private int getPrimarySimPhoneId() {
        String carrierMode = SystemProperties.get("persist.radio.carrier_mode", "default");
        boolean cTClassA = carrierMode.equals("ct_class_a");
        if (!cTClassA) {
            int ddsSubId =  mSubscriptionManager.getDefaultDataSubscriptionId();
            int ddsSlotId = SubscriptionManager.getSlotIndex(ddsSubId);
            // sim on dds slot is treated as primary SIM
            return ddsSlotId;
        }
        // sim on  phone 0 is treated as primay SIM for class a
        return PhoneConstants.SUB1;
    }

    private void onRegistrationRequest() {
        Log.d(TAG, "onRegistrationRequest");
        // MT in APM or SIM state not ready will not register.
        Log.d(TAG, "mRegistering = " + mRegistering + " isAnySimCardReady = "
            + isAnySimCardReady() + " hasRoamingSub = " + hasRoamingSub());
        if (mRegistering || !isAnySimCardReady() || hasRoamingSub()) {
            if (DBG) {
                Log.d(TAG, "Any SIM is not ready or in Roaming state, not to register");
            }
            return;
        }
        // remaing the delay for fetching correct parameters when power up
        // otherwise, aligning with SMS auto reg
        if (mPowerOn) {
            if (mDelayBarrier) {
                mDelayBarrier = false;
                new Handler().postDelayed(new Runnable() {
                    @Override
                    public void run() {
                        mPowerOn = false;
                        onRegistrationRequest();
                    }
                }, DELAY_REQUEST_AFTER_POWER_ON);
            }
            return;
        }

        String iccIdText = getIccIdText();
        if (DBG) {
            Log.d(TAG, "Iccid: " + iccIdText);
        }

        if (!mDdsChanged && !mVoLTESwitchChanged && (isIccIdChanged(iccIdText)
                || iccIdText.equals(mSharedPreferences.getString(PREF_ICCID_ON_SUCCESS, null)))) {
            Toast.makeText(mContext, R.string.already_registered, Toast.LENGTH_LONG).show();
            if (DBG) {
                Log.d(TAG, "Registered subs, Ignore");
            }
            return;
        }
        int slotId = getCTSlotId();

        if (!isDDSOnCTSlotWithoutWifi()) {
            return;
        }

        mRegistering = true;
        scheduleRegistrationJob(new RegistrationEntity(slotId, getPrimarySimPhoneId()));
    }

    private boolean hasRoamingSub() {
        for (int i = 0; i < TelephonyManager.getDefault().getPhoneCount(); i++ ) {
            int[] subId = SubscriptionManager.getSubId(i);
            if (subId != null && TelephonyManager.getDefault().isNetworkRoaming(subId[0])) {
                return true;
            }
        }
        return false;
    }

    private int getPrimaryStackPhoneId() {
        int phoneId = 0;
        try {
            if (mExtTelephony != null) {
                phoneId = mExtTelephony.getPrimaryStackPhoneId();
            }
        } catch (RemoteException ex) {
            Log.w(TAG, "Failed to get primary stack id");
        }
        return phoneId;
    }

    private int getCTSlotId() {
        Log.d(TAG, "getCTSlotId");
        List<SubscriptionInfo> subList = mSubscriptionManager.getActiveSubscriptionInfoList();
        if (subList != null) {
            for (SubscriptionInfo subInfo : subList) {
                String iccId = subInfo.getIccId();
                if(iccId != null) {
                    for (String iin : CT_IIN.split(","))    {
                        if (iccId.startsWith(iin)) {
                             Log.d(TAG, "Got CT slot index: " + subInfo.getSimSlotIndex());
                            return subInfo.getSimSlotIndex();
                        }
                    }
                }
            }
        }
        Log.d(TAG, "No slot with CT card");
        return SubscriptionManager.INVALID_PHONE_INDEX ;
    }

    private boolean isDDSOnCTSlotWithoutWifi() {
        // Without wifi but dds in SIM2 will not register.
        ConnectivityManager connMgr =
                (ConnectivityManager) mContext.getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo networkInfo = connMgr.getActiveNetworkInfo();
        if (networkInfo != null && networkInfo.isConnected()) {
            if (TelephonyManager.from(mContext).isMultiSimEnabled()) {
                if (networkInfo.getType() != ConnectivityManager.TYPE_WIFI) {
                    SubscriptionInfo subInfo = mSubscriptionManager.getActiveSubscriptionInfo(
                        SubscriptionManager.getDefaultDataSubscriptionId());
                    boolean ctWithDds = false;
                    if (subInfo != null) {
                        String iccId = subInfo.getIccId();
                        if (iccId != null) {
                            for (String iin : CT_IIN.split(",")) {
                                if (iccId.startsWith(iin)) {
                                    ctWithDds = true;
                                    break;
                                }
                            }
                        }
                    }
                    if (DBG && !ctWithDds) {
                        Log.d(TAG, "DDS now on non CT slot without wifi, not to register");
                    }
                    return ctWithDds;
                }
            }
        }
        return true;
    }

    private boolean isAnySimCardReady() {
        int numPhones = TelephonyManager.getDefault().getPhoneCount();
        for (int index = 0; index < numPhones; index++) {
            if (TelephonyManager.getDefault().getSimState(index)
                    == TelephonyManager.SIM_STATE_READY) {
                return true;
            }
        }
        return false;
    }

    private boolean isIccIdChanged(String iccId) {
        boolean flag = true;
        if (iccId.contains(",")) {
            String[] strArray = TextUtils.split(iccId, ",");
            for (String str : strArray) {
                flag &= TextUtils.isEmpty(str.trim());
            }
        } else {
            flag = TextUtils.isEmpty(iccId.trim());
        }
        return flag;
    }

    private String getIccIdText() {
        String iccId = null;
        if (TelephonyManager.getDefault().isMultiSimEnabled()) {
            int phoneCount = TelephonyManager.getDefault().getPhoneCount();
            for (int index = 0; index < phoneCount; index++) {
                String id = TelephonyManager.from(mContext).getSimSerialNumber(
                        SubscriptionManager.getSubId(index)[0]);
                if (id == null) {
                    id = " ";
                }
                if (iccId == null) {
                    iccId = id;
                } else {
                    iccId += ("," + id);
                }
            }
        } else {
            String id = TelephonyManager.from(mContext).getSimSerialNumber();
            iccId = (null == id) ? " " : id;
        }
        return iccId;
    }

    protected void scheduleNextIfNeed(RegistrationEntity entity) {
        int requestCount = mSharedPreferences.getInt(PREF_REQUEST_COUNT, 0) + 1;
        mSharedPreferences.edit().putInt(PREF_REQUEST_COUNT, requestCount).commit();
        if (requestCount < MAX_REQUEST_TIMES) {
            cancelNextSchedule();
            Log.d(TAG, "last auto registration fail, schedule the " + requestCount + " retry.");
            Intent intent = new Intent(ACTION_AUTO_REGISTERATION_RETRY);
            intent.addFlags(Intent.FLAG_RECEIVER_INCLUDE_BACKGROUND);
            PendingIntent pendingIntent = PendingIntent.getBroadcast(mContext, 0, intent, 0);
            mAlarmManager.set(AlarmManager.RTC_WAKEUP,
                    System.currentTimeMillis() + INTERVAL_RESCHEDUAL, pendingIntent);
        }
    }

    private void cancelNextSchedule() {
        PendingIntent pi = PendingIntent.getBroadcast(mContext, 0, new Intent(
                 ACTION_AUTO_REGISTERATION_RETRY), PendingIntent.FLAG_NO_CREATE);
        if (pi != null) {
            mAlarmManager.cancel(pi);
            Log.d(TAG, "cancel the pending intent: ACTION_AUTO_REGISTERATION_RETRY");
        }
    }

    private void toast(final String resultDesc) {
        String resultInfo = resultDesc;
        if (TextUtils.isEmpty(resultDesc)) {
            resultInfo = mContext.getResources().getString(
                    R.string.register_failed);
        } else {
            resultInfo = getLocalString(resultDesc);
        }
        Toast.makeText(mContext, resultInfo, Toast.LENGTH_LONG).show();
    }

    private String getLocalString(String originalResult) {
        String[] origNames = mContext.getResources()
                .getStringArray(R.array.original_registry_results);
        String[] localNames = mContext.getResources()
                .getStringArray(R.array.local_registry_results);
        for (int i = 0; i < origNames.length; i++) {
            if (origNames[i].equalsIgnoreCase(originalResult)) {
                return mContext.getString(mContext.getResources().getIdentifier(localNames[i],
                        "string", mContext.getPackageName()));
            }
        }
        return originalResult;
    }

    private void scheduleRegistrationJob(RegistrationEntity entity) {
        Log.d(TAG, "scheduleRegistrationJob");
        JobInfo.Builder builder = new JobInfo.Builder(mJobId++,
                new ComponentName(mContext, RegistrationJobService.class));
        builder.setOverrideDeadline(1000);
        builder.setRequiredNetworkType(JobInfo.NETWORK_TYPE_ANY);
        builder.setPersisted(false);
        Bundle extras = new Bundle();
        extras.putSerializable("REG_ENTITY", entity);
        builder.setTransientExtras(extras);
        JobScheduler tm =
                (JobScheduler) mContext.getSystemService(Context.JOB_SCHEDULER_SERVICE);
        tm.schedule(builder.build());
    }
}
