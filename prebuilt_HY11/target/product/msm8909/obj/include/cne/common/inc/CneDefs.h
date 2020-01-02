#ifndef CNE_DEFS_H
#define CNE_DEFS_H

/**----------------------------------------------------------------------------
  @file CNE_Defs.h

  This file holds various definations that get used across, different CNE
  modules.
-----------------------------------------------------------------------------*/


/*============================================================================
        Copyright (c) 2009-2018 Qualcomm Technologies, Inc.
        All Rights Reserved.
        Confidential and Proprietary - Qualcomm Technologies, Inc.
============================================================================*/


/*============================================================================
  EDIT HISTORY FOR MODULE

  $Header: //depot/asic/sandbox/projects/cne/common/core/inc/CneDefs.h#7 $
  $DateTime: 2009/11/20 17:36:15 $
  $Author: chinht $
  $Change: 1092637 $

  when        who   what, where, why
  ----------  ---   -------------------------------------------------------
  2009-07-15  ysk   First revision.
  2011-07-27  jnb   Added more definitions
  2011-10-28  tej   Updated max application macro and CneAppInfoMsgDataType
  2012-03-09  mtony Added include file, stdint.h, which is directly needed
============================================================================*/
#include <string>
#include <set>
#include <android/multinetwork.h>

enum CommandId {
  COMMAND_UNKNOWN = 0,
  REQUEST_INIT = 1,
  REQUEST_UPDATE_WLAN_INFO = 2,
  REQUEST_UPDATE_WWAN_INFO = 3,
  NOTIFY_RAT_CONNECT_STATUS = 4,
  REQUEST_UPDATE_DEFAULT_NETWORK_INFO = 5,
  NOTIFY_NETWORK_REQUEST_INFO = 6,
  NOTIFY_WLAN_STATUS_PROFILE = 7,
  NOTIFY_NAT_KEEP_ALIVE_RESULT = 8,
  NOTIFY_WWAN_SUBTYPE = 9,
  NOTIFY_MOBILE_DATA_ENABLED = 10,
  //NOTIFY_SOCKET_CLOSED should not be used in HAL solution
  NOTIFY_SOCKET_CLOSED = 11,
  NOTIFY_WLAN_CONNECTIVITY_UP = 12,
  REQUEST_GET_FEATURE_STATUS = 13,
  REQUEST_SET_FEATURE_PREF = 14,
  NOTIFY_ICD_RESULT = 15,
  NOTIFY_JRTT_RESULT = 16,
  NOTIFY_BQE_POST_RESULT = 17,
  NOTIFY_ICD_HTTP_RESULT = 18,
  NOTIFY_ANDSF_DATA_READY = 19,
  NOTIFY_SCREEN_STATE = 20,
  NOTIFY_QUOTA_INFO_QUERY_RESULT = 21,
  NOTIFY_WIFI_AP_INFO = 22,
  NOTIFY_WIFI_P2P_INFO = 23,
  NOTIFY_IMS_PROFILE_OVERRIDE_SETTING = 24,
  NOTIFY_USER_ACTIVE = 25,
  CAS_START_ALL_BROADCAST = 1001,
  CAS_STOP_ALL_BROADCAST = 1002,
  CAS_START_NETCFG_SIGNAL = 1003,
  CAS_STOP_NETCFG_SIGNAL = 1004,
  CAS_START_NONINTERNET_SERVICE = 1005,
  CAS_STOP_NONINTERNET_SERVICE = 1006,
  CAS_START_NETWORK_REQUEST_SIGNAL = 1007,
  CAS_STOP_NETWORK_REQUEST_SIGNAL = 1008,
  CAS_GET_NETWORK_REQUEST_INFO_SIGNAL = 1009,
  CAS_START_FEATURE_STATUS_SIGNAL = 1010,
  CAS_STOP_FEATURE_STATUS_SIGNAL = 1011,
  CAS_NOTIFY_NETCFGCB_DIED = 1012,
  CAS_NOTIFY_NETREQCB_DIED = 1013,
  CAS_NOTIFY_FEATSTATUSCB_DIED = 1014
};

enum MessageId {
  REQUEST_BRING_RAT_DOWN = 1,
  REQUEST_BRING_RAT_UP = 2,
  REQUEST_START_RSSI_OFFLOAD = 3,
  REQUEST_STOP_RSSI_OFFLOAD = 4,
  REQUEST_START_NAT_KEEP_ALIVE = 5,
  REQUEST_STOP_NAT_KEEP_ALIVE = 6,
  NOTIFY_ACCESS_DENIED = 7,
  NOTIFY_ACCESS_ALLOWED = 8,
  NOTIFY_DISALLOWED_AP = 9,
  REQUEST_START_ACTIVE_PROBE = 10,
  REQUEST_SET_DEFAULT_ROUTE = 11,
  REQUEST_START_ICD = 12,
  REQUEST_STOP_ACTIVE_PROBE = 13,
  REQUEST_POST_BQE_RESULTS = 14,
  NOTIFY_FEATURE_STATUS = 15,
  RESP_SET_FEATURE_PREF = 16,
  NOTIFY_POLICY_UPDATE_DONE = 17,
  REQUEST_UPDATE_POLICY = 18,
  REQUEST_QUOTA_INFO_QUERY = 19,
  CAS_RESERVED_INFO = 1001,
  CAS_WWAN_NETCFG_INFO = 1002,
  CAS_WLAN_NETCFG_INFO = 1003,
  CAS_NETWORK_REQUEST_INFO = 1004,
  CAS_FEATURE_STATUS_INFO = 1005
};


/*
 * WARNING WARNING WARNING WARNING WARNING
 * set to CFLAG PROTOMSG_TEST in Android.mk for libcne and cneapiclient
 * for testing protocol buf msg
 * Make sure TEST is also set to true in CneMsg.java
 * Both places need to be set to true to test
 * Otherwise, behavior is undefined.
 * WARNING WARNING WARNING WARNING WARNING
 */

/**
 * Possible return codes
 *
 * New values should be added to CneUtils::init()
 */
typedef enum
{
  /* ADD other new error codes here */
  CNE_RET_SERVICE_NOT_AVAIL = -13,
  CNE_RET_ASYNC_RESPONSE = -12,
  CNE_RET_ERR_READING_FILE_STAT = -11,
  CNE_RET_PARSER_NO_MATCH = -10,
  CNE_RET_PARSER_VALIDATION_FAIL = -9,
  CNE_RET_PARSER_TRAVERSE_FAIL = -8,
  CNE_RET_PARSER_PARSE_FAIL = -7,
  CNE_RET_ERR_OPENING_FILE = -6,
  CNE_RET_INVALID_DATA = -5,
  CNE_RET_OUT_OF_MEM = -4,
  CNE_RET_ALREADY_EXISTS = -3,
  CNE_RET_NOT_ALLOWED_NOW = -2,
  CNE_RET_ERROR = -1,

  CNE_RET_OK = 1,
  CNE_RET_PARSER_MATCH = 2
} CneRetType;

typedef enum
{
  CNE_WIFI_MODE_STA,
  CNE_WIFI_MODE_SAP,
  CNE_WIFI_MODE_P2PGO,
  CNE_WIFI_MODE_P2PCLI
} CneWiFiModeType;

#ifndef MAX
   #define  MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )
#endif /* MAX */

#ifndef MIN
   #define  MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )
#endif /* MIN */


#ifdef __cplusplus
  extern "C" {
#endif /* __cplusplus */

/*----------------------------------------------------------------------------
 * Include C Files
 * -------------------------------------------------------------------------*/
#include <sys/types.h>
#include <stdint.h>

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/
#ifndef TRUE
  /** Boolean true value. */
  #define TRUE   1
#endif /* TRUE */

#ifndef FALSE
  /** Boolean false value. */
  #define FALSE  0
#endif /* FALSE */

#ifndef NULL
/** NULL */
  #define NULL  0
#endif /* NULL */

#define CNE_IPA_IFACE_NAME_MAX 20 // Mirror with IPA_RESOURCE_NAME_MAX in msm_ipa.h

#define CNE_MAX_SSID_LEN 33
// Max BSSID size is 64 bits (EUI-64). We receive this value as a string in human readable format:
// (00:00:00:00:00:00:00:00). There are 23 chars + null termination char + 1 reserved = 25.
#define CNE_MAX_BSSID_LEN 25
#define CNE_MAX_SCANLIST_SIZE 40
#define CNE_MAX_APPLIST_SIZE 500
#define CNE_MAX_IPADDR_LEN 46
#define CNE_MAX_IFACE_NAME_LEN 16
#define CNE_MAX_TIMESTAMP_LEN 32
#define CNE_MAX_CAPABILITIES_LEN 256
#define CNE_MAX_URI_LEN 128
#define CNE_MAX_BQE_FILESIZE_LEN 10
// FIXME temp make this bigger
#define CNE_MAX_VENDOR_DATA_LEN 640
#define CNE_MAX_PROTOCOL_BUFFER_LEN 1024
#define CNE_SERVICE_DISABLED 0
#define CNE_SERVICE_ENABLED 1
#define CNE_MAX_BROWSER_APP_LIST 40
#define CNE_MAX_DNS_ADDRS 4
#define CNE_MAX_MCC_MNC_LEN 7 //6 for mccmnc number + 1 for null termination

#define CNE_APP_NAME_MAX_LEN 256
#define CNE_HASHES_MAX_LEN 256 //TODO

#define CNE_MAX_PROFILE_NAME_LEN 11
#define CNE_MAX_OPERATOR_NAME_LEN 50

#define CNE_FEATURE_IWLAN_PROP "persist.vendor.cnd.iwlan"
#define CNE_FEATURE_WQE_PROP "persist.vendor.cnd.wqe"
#define CNE_FEATURE_WQE_CQE_TIMER_PROP "persist.cne.cqetimer"
#define BSSID_PLACEHOLDER "00:00:00:00:00:00"

#define CND_RET_CODE_OK 0
#define CND_RET_CODE_UNKNOWN_ERROR -1
#define CND_RET_CODE_INVALID_DATA -2

#define STRUCT_PACKED __attribute__ ((packed))

typedef uint32_t u32;

typedef CommandId cne_cmd_enum_type;
typedef CommandId CneEvent;
typedef MessageId cne_msg_enum_type;


typedef enum
{
    NETWORK_STATE_CONNECTING = 0,
    NETWORK_STATE_CONNECTED = 1,
    NETWORK_STATE_SUSPENDED = 2,
    NETWORK_STATE_DISCONNECTING = 3,
    NETWORK_STATE_DISCONNECTED = 4,
    NETWORK_STATE_UNKNOWN = 5
}cne_network_state_enum_type;

typedef enum
{
    SCREEN_STATE_EVT = 1,
    USER_ACTIVE_EVT = 2
}cne_background_event_enum_type;

typedef enum
{
    FEATURE_OFF = 1,
    FEATURE_ON = 2,
    FEATURE_STATUS_UNKNOWN = 65535
}cne_feature_status;

typedef enum
{
    POLICY_ANDSF = 1,
    POLICY_UNKOWN = 10,
    POLICY_MAX = 10
}cne_policy_type;

typedef enum
{
    RAT_MIN = 0, //For tagging only
    RAT_WWAN = 0,
    RAT_WLAN = 1,
    RAT_WWAN_MMS = 2,
    RAT_WWAN_SUPL = 3,
    RAT_WWAN_IMS = 4,
    RAT_WWAN_RCS = 5,
    RAT_WWAN_EIMS = 6,
    RAT_WWAN_EMERGENCY = 7,
    /*RAT_WWAN_DUN;*/
    /*RAT_WWAN_FOTA;*/
    /*RAT_WWAN_CBS;*/
    /*RAT_WWAN_IA;*/
    /*RAT_WWAN_XCAP;*/
    RAT_WLAN_SOFTAP = 100,
    RAT_WLAN_P2P = 101,
    /* any new rats should be added here */
    RAT_ANY = 253,
    /**< Any of the above RATs */
    RAT_NONE = 254,
    /**< None of the abvoe RATs */
    RAT_MAX = 255, //For tagging only
    /** @internal */
    RAT_INVALID = 255
    /**< INVALID RAT */
}cne_rat_type;
typedef cne_rat_type CneRatType;

typedef enum
{
    SUBTYPE_UNKNOWN = 0,
    SUBTYPE_GPRS = 1,
    SUBTYPE_EDGE = 2,
    SUBTYPE_UMTS = 3,
    SUBTYPE_CDMA = 4,
    SUBTYPE_EVDO_0 = 5,
    SUBTYPE_EVDO_A = 6,
    SUBTYPE_1xRTT = 7,
    SUBTYPE_HSDPA = 8,
    SUBTYPE_HSUPA = 9,
    SUBTYPE_HSPA = 10,
    SUBTYPE_IDEN = 11,
    SUBTYPE_EVDO_B = 12,
    SUBTYPE_LTE = 13,
    SUBTYPE_EHRPD = 14,
    SUBTYPE_HSPAP = 15,
    SUBTYPE_GSM = 16,
    SUBTYPE_TD_SCDMA = 17,
    SUBTYPE_IWLAN = 18,
    SUBTYPE_LTE_CA = 19,

    //CNE Defines for WLAN subtypes not in TelephonyManager.java
    SUBTYPE_WLAN_B = 100,
    SUBTYPE_WLAN_G = 101
}cne_rat_subtype;
typedef cne_rat_subtype CneRatSubType;

typedef enum
{
    SLOT_UNSPECIFIED = 0,
    SLOT_FIRST_IDX = 1,
    SLOT_SECOND_IDX = 2,
    SLOT_THIRD_IDX = 3,
    SLOT_MAX_IDX = 3
}cne_slot_type;
typedef cne_slot_type CneSlotType;

typedef enum
{
    INVALID = 0,
    SUBINFO_NOT_READY = 1
}cne_bringuperror_type;

typedef enum
{
    SOFTAP_STATE_DISABLING = 10,
    SOFTAP_STATE_DISABLED = 11,
    SOFTAP_STATE_ENABLING = 12,
    SOFTAP_STATE_ENABLED = 13,
    SOFTAP_STATE_FAILED = 14,
    SOFTAP_STATE_UNKNOWN = 65535
}cne_softApStatus_type;

typedef enum
{
    FEATURE_WQE = 1,
    FEATURE_IWLAN = 2,
    FEATURE_UNKNOWN = 65535
}cne_feature_type;

typedef enum
{
    WIFI_STATE_DISABLING = 0,
    WIFI_STATE_DISABLED = 1,
    WIFI_STATE_ENABLING = 2,
    WIFI_STATE_ENABLED = 3,
    WIFI_STATE_UNKNOWN = 4
}cne_wifi_state_enum_type;

typedef enum
{
    FAM_MIN = 0,
    FAM_NONE = 0,
    FAM_V4 = 1,
    FAM_V6 = 2,
    FAM_V4_V6 = 3,
    FAM_MAX = 3
}cne_fam_type;

typedef enum
{
    _2GHz = 0,
    _5GHz = 1,
    FREQ_BAND_SIZE = 2
}CneFreqBand;

typedef enum
{
    WLAN_QUALITY_UNKNOWN = 0,
    WLAN_QUALITY_BAD = 1,
    WLAN_QUALITY_GOOD = 2
}CneWQEQuality;

typedef enum  {
    WLAN_UNKNOWN = 0,
    WLAN_CONNECTED = 1,
    WLAN_DISCONNECTED = 2,
    WQE_RESULT_ONGOING_CQE_PASS_RSSI = 3,
    WQE_RESULT_ONGOING_CQE_PASS_MAC = 4,
    WQE_RESULT_ONGOING_CQE_PASS_INCONCL = 5,
    WQE_RESULT_ONGOING_CQE_FAILED_RSSI = 6,
    WQE_RESULT_ONGOING_CQE_FAILED_MAC = 7,
    WQE_RESULT_ONGOING_CQE_FAILED_INCONCL = 8,
    WQE_RESULT_CONCLUDED = 9,
    WQE_RESULT_CONCLUDED_CQE_FAILED_RSSI = 10,
    WQE_RESULT_CONCLUDED_CQE_FAILED_MAC = 11,
    WQE_RESULT_CONCLUDED_CQE_FAILED_INCONCL = 12,
    WQE_RESULT_CONCLUDED_ICD_FAILED = 13,
    WQE_RESULT_CONCLUDED_BQE_FAILED = 14,
    WQE_RESULT_CONCLUDED_TQE_FAILED = 15
}CneWQEResultReason;

/* cmd handlers will pass the cmd data as raw bytes.
 * the bytes specified below are for a 32 bit machine
 */
/** @note
   BooleanNote: the daemon will receive the boolean as a 4 byte integer
   cne may treat it as a 1 byte internally
 */

/**
 Request info structure sent by CNE for the request
 CNE_REQUEST_SET_DEFAULT_ROUTE_MSG
 */
typedef struct
{
  cne_rat_type rat;
} cne_set_default_route_req_data_type;

typedef struct _ratInfo {
    cne_rat_type rat;
    net_handle_t netHdl;
    int status;
    cne_slot_type slot;
    cne_bringuperror_type errorCause;
    char iface[CNE_MAX_IFACE_NAME_LEN];
    char ipV4Addr[CNE_MAX_IPADDR_LEN];
    char ipV6Addr[CNE_MAX_IPADDR_LEN];
    char timestamp[CNE_MAX_TIMESTAMP_LEN];

    _ratInfo(): rat(RAT_NONE), netHdl(0), status(-1), slot(SLOT_UNSPECIFIED),
                errorCause(INVALID) {
        bzero(iface, CNE_MAX_IFACE_NAME_LEN);
        bzero(ipV4Addr, CNE_MAX_IPADDR_LEN);
        bzero(ipV6Addr, CNE_MAX_IPADDR_LEN);
        bzero(timestamp, CNE_MAX_TIMESTAMP_LEN);
    }

} CneRatInfoType;

// Make sure the array is in sync with the enum.
static const char* FreqBandToString[] = {"2.4GHz", "5GHz"};

typedef struct  _WlanInfo{
    int32_t type;
    int32_t status;
    int32_t rssi;
    char ssid[CNE_MAX_SSID_LEN];
    char bssid[CNE_MAX_BSSID_LEN];
    char ipAddr[CNE_MAX_IPADDR_LEN];
    char iface[CNE_MAX_IFACE_NAME_LEN];
    char ipAddrV6[CNE_MAX_IPADDR_LEN];
    char ifaceV6[CNE_MAX_IFACE_NAME_LEN];
    char timeStamp[CNE_MAX_TIMESTAMP_LEN];
    net_handle_t netHdl;
    bool isAndroidValidated;
    CneFreqBand freqBand;
    cne_wifi_state_enum_type wifiState;
    char dnsInfo[CNE_MAX_DNS_ADDRS][CNE_MAX_IPADDR_LEN];
    CneWiFiModeType mode;

    _WlanInfo(): type(-1), status(-1), rssi(-127), netHdl(0),
        isAndroidValidated(false), freqBand(_2GHz), wifiState(WIFI_STATE_UNKNOWN), mode(CNE_WIFI_MODE_STA){
        bzero(ssid, CNE_MAX_SSID_LEN);
        bzero(bssid, CNE_MAX_BSSID_LEN);
        bzero(ipAddr, CNE_MAX_IPADDR_LEN);
        bzero(iface, CNE_MAX_IFACE_NAME_LEN);
        bzero(ipAddrV6, CNE_MAX_IPADDR_LEN);
        bzero(ifaceV6, CNE_MAX_IFACE_NAME_LEN);
        bzero(timeStamp, CNE_MAX_TIMESTAMP_LEN);
        for (int i = 0; i < CNE_MAX_DNS_ADDRS; i++)
        {
          memset(dnsInfo[i], 0, CNE_MAX_IPADDR_LEN);
        }
    }

    //Copy constructor
    _WlanInfo(const struct _WlanInfo &src):
        type(src.type), status(src.status), rssi(src.rssi),
        netHdl(src.netHdl), isAndroidValidated(src.isAndroidValidated),
        freqBand(src.freqBand), wifiState(src.wifiState)
    {
      strlcpy(ssid, src.ssid, CNE_MAX_SSID_LEN);
      strlcpy(bssid, src.bssid, CNE_MAX_BSSID_LEN);
      strlcpy(ipAddr, src.ipAddr, CNE_MAX_IPADDR_LEN);
      strlcpy(iface, src.iface, CNE_MAX_IFACE_NAME_LEN);
      strlcpy(ipAddrV6, src.ipAddrV6, CNE_MAX_IPADDR_LEN);
      strlcpy(ifaceV6, src.ifaceV6, CNE_MAX_IFACE_NAME_LEN);
      strlcpy(timeStamp, src.timeStamp, CNE_MAX_TIMESTAMP_LEN);
      for (int i = 0; i < CNE_MAX_DNS_ADDRS; i++)
      {
          strlcpy(dnsInfo[i], src.dnsInfo[i], CNE_MAX_IPADDR_LEN);
      }
    }
} CneWlanInfoType;

typedef struct _WwanInfo  {
    int32_t type;
    int32_t status;
    int32_t rssi;
    int32_t roaming;
    CneRatSubType subrat;
    char ipAddr[CNE_MAX_IPADDR_LEN];
    char iface[CNE_MAX_IFACE_NAME_LEN];
    char ipAddrV6[CNE_MAX_IPADDR_LEN];
    char ifaceV6[CNE_MAX_IFACE_NAME_LEN];
    char timeStamp[CNE_MAX_TIMESTAMP_LEN];
    char mccMnc[CNE_MAX_MCC_MNC_LEN];
    net_handle_t netHdl;
    cne_slot_type slot;

    _WwanInfo(): type(-1), status(-1), rssi(-127),
        roaming(-1), subrat(SUBTYPE_UNKNOWN), netHdl(0),
        slot(SLOT_UNSPECIFIED) {
            bzero(ipAddr, CNE_MAX_IPADDR_LEN);
            bzero(iface, CNE_MAX_IFACE_NAME_LEN);
            bzero(ipAddrV6, CNE_MAX_IPADDR_LEN);
            bzero(ifaceV6, CNE_MAX_IFACE_NAME_LEN);
            bzero(timeStamp, CNE_MAX_TIMESTAMP_LEN);
            bzero(mccMnc, CNE_MAX_MCC_MNC_LEN);
        }
} CneWwanInfoType;

typedef struct {
    int32_t level;
    int32_t frequency;
    char ssid[CNE_MAX_SSID_LEN];
    char bssid[CNE_MAX_BSSID_LEN];
    char capabilities[CNE_MAX_CAPABILITIES_LEN];
}CneWlanScanListInfoType;

typedef struct  {
    int numItems;
    CneWlanScanListInfoType scanList[CNE_MAX_SCANLIST_SIZE];
} CneWlanScanResultsType;

typedef struct {
    cne_rat_type rat;
    cne_network_state_enum_type ratStatus;
    char ipAddr[CNE_MAX_IPADDR_LEN];
    char ipAddrV6[CNE_MAX_IPADDR_LEN];
} CneRatStatusType;

typedef struct {
    cne_rat_type rat;
    cne_slot_type slot;
} CneRatSlotType;

typedef struct {
    uint8_t disallowed; /// bool
    uint8_t reason; /// Congested/Firewalled
    char bssid[CNE_MAX_BSSID_LEN];
} CneDisallowedAPType;

typedef struct {
    int32_t uid;
    uint8_t isBlocked;
} CneNsrmBlockedUidType;

/* data structure used to for the parent app request and result for ATP */
typedef struct {
  int cookie;
  char childAppName[CNE_APP_NAME_MAX_LEN+1];
  uid_t parentUid;
} CneAtpParentAppInfoMsg_t;

typedef struct {
  char bssid[CNE_MAX_BSSID_LEN];
  char uri[CNE_MAX_URI_LEN];
  char httpuri[CNE_MAX_URI_LEN];
  char fileSize[CNE_MAX_BQE_FILESIZE_LEN];
} CneBQEActiveProbeMsgType;

typedef struct {
    char uri[CNE_MAX_URI_LEN];
    char httpuri[CNE_MAX_URI_LEN];
    char bssid[CNE_MAX_BSSID_LEN];
    uint32_t timeout;
    uint32_t tid;
} CneIcdStartMsgType;

typedef struct {
    char bssid[CNE_MAX_BSSID_LEN];
    uint8_t result;
    uint8_t flags;
    uint32_t tid;
    uint32_t icdQuota;
    uint8_t icdProb;
    uint32_t bqeQuota;
    uint8_t bqeProb;
    uint32_t mbw;
    uint32_t tputDl;
    uint32_t tputSdev;
} CneIcdResultCmdType;

typedef struct {
    char bssid[CNE_MAX_BSSID_LEN];
    uint8_t result;
    uint32_t tid;
    int family;
} CneIcdHttpResultCmdType;

typedef struct {
  int32_t type;
  int32_t state;
} CneStateType;

typedef struct {
    uint32_t result;
    uint32_t jrttMillis;
    uint32_t getTsSeconds;
    uint32_t getTsMillis;
} CneJrttResultCmdType;

typedef struct {
  char bssid[CNE_MAX_BSSID_LEN];
  char uri[CNE_MAX_URI_LEN];
  uint32_t tputKiloBitsPerSec;
  uint32_t timeStampSec;
} CneBQEPostParamsMsgType;

typedef struct {
  cne_feature_type featureId;
  cne_feature_status featureStatus;
} CneFeatureInfoType;

typedef struct {
  cne_feature_type featureId;
  cne_feature_status featureStatus;
  int32_t result;
} CneFeatureRespType;

/**
  Response info structure returned for the event
   CNE_NOTIFY_POLICY_UPDATE_DONE.
 */
typedef struct
{
  cne_policy_type policy;
  /**< policy type andsf or nsrm */
  int32_t result;
  /**< 0 for sucess -1 for failure */
} CnePolicyUpdateRespType;

typedef struct _CneWlanFamType
{
  cne_fam_type family;
  bool isAndroidValidated;
  _CneWlanFamType(): family(FAM_NONE), isAndroidValidated(false) {}
}CneWlanFamType;

typedef struct
{
  char profile[CNE_MAX_PROFILE_NAME_LEN];
  int connectionStatus;
  int reasonCode;
} CneProfileWlanStatus;

typedef struct {
    char profileName[CNE_MAX_PROFILE_NAME_LEN];
    char operatorName[CNE_MAX_OPERATOR_NAME_LEN];
    int rssiHigh;
    int rssiLow;
}CneRssiOffloadInfo;

typedef struct {
    uint32_t timer;
    uint16_t srcPort;
    uint16_t destPort;
    char destIp[CNE_MAX_IPADDR_LEN];
    int32_t subsInfo;
}CneNatKeepAliveRequestInfo;

typedef struct {
    int32_t subsInfo;
}CneStopNatKeepAliveRequestInfo;

typedef struct {
    int32_t errorcode;
    int32_t subsInfo;
}CneNatKeepAliveResultInfo;

typedef struct {
    int32_t isQuotaReached;
}CneQuotaInfo;

typedef struct _CneMobileDataState{
    int32_t isEnabled;
    _CneMobileDataState():isEnabled(0){};
}CneMobileDataState;

typedef struct {
    int currState;
    int prevState;
} CneWifiApInfoType;

typedef struct {
    int32_t currState;
} CneWifiP2pInfoType;

typedef struct _IMSProfileOverrideSetting{
    int32_t isOverrideSet;
    _IMSProfileOverrideSetting():isOverrideSet(0){};
}IMSProfileOverrideSetting;

typedef struct _DefaultNetwork {
  int32_t network;
} CneDefaultNetworkType;
/*----------------------------------------------------------------------------
 * Function Declarations and Documentation
 * -------------------------------------------------------------------------*/

typedef struct {
    int fd;
    std::string profile;
}CliProfileInfo;

typedef struct {
    int fd;
    CneRatType rat;
    CneSlotType slot;
}CliNetRequestInfo;

#ifdef __cplusplus
  }
#endif /* __cplusplus */

#endif /* CNE_DEFS_H */
