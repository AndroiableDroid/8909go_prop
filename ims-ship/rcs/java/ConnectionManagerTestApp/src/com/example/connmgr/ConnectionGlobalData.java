/*=============================================================================
  Copyright (c) 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/

package com.example.connmgr;

import android.content.Context;

import com.qualcomm.qti.imscmservice.V1_1.IImsCmServiceListener;
import com.qualcomm.qti.imscmservice.V1_1.IImsCmService;
import com.qualcomm.qti.imscmservice.V1_0.IImsCMConnection;
import com.qualcomm.qti.imscmservice.V1_0.IImsCMConnectionListener;
import com.qualcomm.qti.imscmservice.V1_1.IMSCM_CONFIG_DATA;
import com.qualcomm.qti.imscmservice.V1_0.QIMSCM_USER_CONFIG;
import com.qualcomm.qti.imscmservice.V1_1.QIMS_CM_DEVICE_CONFIG;
import com.qualcomm.qti.imscmservice.V1_0.IMSCM_AUTOCONFIG_DATA;
import com.qualcomm.qti.imscmservice.V1_0.IMSCM_ConfigType;
import com.qualcomm.qti.imscmservice.V1_1.IMSCM_AUTOCONFIG_TRIGGER_REASON;


public class ConnectionGlobalData  {
    final static String TAG = "UI_ConnMgr_ConnectionGlobalData";
    public static final String SM_FEATURE_TAG =
        "+g.3gpp.icsi-ref=\"urn%3Aurn-7%3A3gpp-service.ims.icsi.oma.cpm.largemsg\"";
    public static final String IM_FEATURE_TAG =
        "+g.3gpp.icsi-ref=\"urn%3Aurn-7%3A3gpp-service.ims.icsi.oma.cpm.session\"";
    public static final String FT_FEATURE_TAG =
        "+g.3gpp.icsi-ref=\"urn%3Aurn-7%3A3gpp-service.ims.icsi.oma.cpm.filetransfer\"";
    public static final String PRESENCE_FEATURE_TAG =
        "+g.3gpp.iari-ref=\"urn%3Aurn-7%3A3gpp-application.ims.iari.rcse.dp\"";
    public static final String  INVALID_FEATURE_TAG3 =
        "+g.3gpp.icsi-ref=\"urn%3Aurn-7%3A3gpp-service.ims.icsi.oma.cpm.anyinvalidtag\"";
    public static IImsCmService connMgr = null;
    public static long cmServiceHandle = 0; //assigned onServiceReady Callback
    public static IImsCmServiceListener connMgrListener = null ;
    public static IImsCMConnection connSm = null;
    public static IImsCMConnectionListener connSmListener = null;
    public static IImsCMConnection connIm = null;
    public static IImsCMConnectionListener connImListener = null;
    public static IImsCMConnection connInvalid = null;
    public static IImsCMConnectionListener connInvalidListener = null;
    public static boolean IMSPDNConnected = false;
    public static int connMgrInitialised = 0 ;
    public static int connSmInitialised = 0 ;
    public static int connImInitialised = 0 ;
    public static int connInvalidInitialised = 0 ;
    public static Context mContext = null;
    public static int userData = 6789; //random value assigned
    public static int subId = 0 ;
    public static IMSCM_CONFIG_DATA configData = null;
    public static QIMSCM_USER_CONFIG userConfigData = null;
    public static QIMS_CM_DEVICE_CONFIG deviceConfigData = null;
    public static IMSCM_AUTOCONFIG_DATA autoConfigData = null;
    public static int configType = IMSCM_ConfigType.IMSCM_USER_CONFIG;
    public static int autoConfigType = IMSCM_ConfigType.IMSCM_AUTO_CONFIG;
    public static int deviceConfigType = IMSCM_ConfigType.IMSCM_DEVICE_CONFIG;
    public static int triggerAcsReasonType = IMSCM_AUTOCONFIG_TRIGGER_REASON.IMSCM_AUTOCONFIG_INVALID_TOKEN;

}
