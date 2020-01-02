
#ifndef CNE_QMI_H
#define CNE_QMI_H
/**
 * @file CneQmi.h
 *
 *
 * ============================================================================
 *             Copyright (c) 2011-2017 Qualcomm Technologies,
 *             Inc. All Rights Reserved.
 *             Qualcomm Technologies Confidential and Proprietary
 * ============================================================================
 */

/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include <stdlib.h>
#include <CneSrmDefs.h>
#include <CneSrm.h>
#include "CneQmiSvc.h"
#include "CneQmiDsd.h"
#include "CneQmiDpm.h"
#include "CneQmiDms.h"
#include "CneQmiWds.h"
#include <string>
#include <pthread.h>
#include <queue.h>
#include <unordered_map>
#include <set>
#include <memory>
#include <functional>
#include "CneCom.h"
#include "CneDefs.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "qmi_cci_target_ext.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "qmi_client.h"
#include "data_system_determination_v01.h"
#include "data_port_mapper_v01.h"
#include "device_management_service_v01.h"
#include "wireless_data_service_v01.h"
#ifdef __cplusplus
}
#endif
#pragma GCC diagnostic pop

//WARNING This should never be defined as 1 when committing
#define CNE_QMI_SANITY 0

class WmsInterface;

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/
#ifndef NELEM
#define NELEM(x) (sizeof(x)/sizeof*(x))
#endif

#ifndef IFNAMSIZ
#define IFNAMSIZ 16
#endif

#ifndef CNE_QMI_CLIENT_INIT_TIMEOUT
#define CNE_QMI_CLIENT_INIT_TIMEOUT 1000
#endif


static const int64_t WAKELOCK_TIMER = 1000; //millisec
static const int MAX_WAKELOCK_NAME_LEN = 32;
static const char* DSD_IND_WAKELOCK = "cne_dsd_ind_handler_wl";
using namespace std;

/*----------------------------------------------------------------------------
 * Type Declarations
 * -------------------------------------------------------------------------*/
/**
 * @brief
 * CneQmi events type.
 * TODO: handle event registrations for each QMI port separately and
 * dispatch events as appropriate
 */
typedef enum {
  QMI_EVENT_MIN = 0,
  QMI_EVENT_DSD_UP,
  QMI_EVENT_MAX
} CneQmiEventType;

/*----------------------------------------------------------------------------
 * Class Definitions
 * -------------------------------------------------------------------------*/

class CneQmi: public EventDispatcher<CneQmiEventType> {
  public:
      typedef enum
      {
        DPM = 0,
        DMS = 1,
        DSD_PRIMARY = 2,
        DSD_SECONDARY = 3,
        WDS = 4,
        VOICE = 5
      } cne_qmi_enum_type;

      /**
       * @brief Constructor
       */
      CneQmi (CneSrm &setSrm, CneCom &setCneCom, CneTimer &setTimer);
      /**
       * @brief Destructor
       */
      ~CneQmi (void);
      /**
       *  @brief Init QMI service for CNE.
       *  @return None
       */
      void init (void);

      void sendWifiAvailableStatus(dsd_wlan_available_req_msg_v01 &status);

      void sendWqeProfileStatus(dsd_set_wqe_profile_quality_status_req_msg_v01 &status);

      void sendWifiMeasurementReport(dsd_wifi_meas_report_req_msg_v01 &report);

      void stopWifiMeasurement(uint32_t meas_id);

      void sendNotifyDataSettings(dsd_notify_data_settings_req_msg_v01 &dataSettingsReq);

      CneSrm& getSrm();

      CneTimer& getTimer();

      bool setLoActivity(dsd_wwan_activity_enum_type_v01 loActivity);

      void setDataLowLatencyLevel(const int uplink, const int downlink);

      void setDataLowLatencyPriorityData(bool isPriority);

      void resetDataLowLatencyLevelAndPriorityData
      (
        const int slotId,
        const int uplink,
        const int downlink,
        bool isPriority
      );

      void registerServiceUpCb(cne_qmi_enum_type qmi_service, shared_ptr<function<void()>> cb_function);

      void releaseServiceUpCb(cne_qmi_enum_type qmi_service, shared_ptr<function<void()>> cb_function);

/**
 * @brief Private class to track each QMI port wds connection
 */

  private:
      /**private copy constructor* - no copies allowed */
      CneQmi (const CneQmi &);

      /** reference to SRM */
      CneSrm &srm;

      CneCom &com;

      CneTimer &timer;

      qmi_idl_service_object_type dsd_svc_obj;

      qmi_client_type qmi_client_hndl;

      qmi_client_os_params mQmiDsdOsParams, mQmiDpmOsParams, mQmiDmsOsParams, mQmiWdsOsParams;

      qmi_client_type mQmiDsdNotifier, mQmiDpmNotifier, mQmiDmsNotifier, mQmiWdsNotifier;

      unordered_map <int, CneQmiSvc*> qmiObjMap;

      map <int, set<shared_ptr<function<void()>>>> qmiServiceCbMap;

      static WmsInterface *wmsInst;

      bool isDsdSvcUp;

      int dsdSvcUpFd;
      int dpmSvcUpFd;
      int dmsSvcUpFd;
      int wdsSvcUpFd;
      int errorFd;

      /**
       * @brief SRM event handler wrapper
       *
       * @return None
       */
      static void srmEventHandler
      (
        SrmEvent    event,
        const void  *event_data,
        void    *user_data
      );

      /**
       * @brief processes SRM events
       *
       * @return None
       */
      void processSrmEvent (SrmEvent event, const void *event_data);

      void initQmiDsd(qmi_service_info &info);
      void regQmiDsdSvcUp();
      /**
       * @brief Initializes QMI Data Port Mapper Client
       *
       * @return None
       */
      void initQmiDpm();
      void regQmiDpmSvcUp();

      void initQmiDms();
      void regQmiDmsSvcUp();

      static CneQmi *qmiSelf;

      void initQmiWds();
      void regQmiWdsSvcUp();

      static void cneQmiErrorCb
      (
        qmi_client_type userHandle,
        qmi_client_error_type error,
        void *err_cb_data
      );

      static void cneQmiDsdNotifyCb
      (
        qmi_client_type user_handle,
        qmi_idl_service_object_type service_obj,
        qmi_client_notify_event_type service_event,
        void *notify_cb_data
      );

      static void cneQmiDpmNotifyCb
      (
        qmi_client_type user_handle,
        qmi_idl_service_object_type service_obj,
        qmi_client_notify_event_type service_event,
        void *notify_cb_data
      );

      static void cneQmiDmsNotifyCb
      (
        qmi_client_type user_handle,
        qmi_idl_service_object_type service_obj,
        qmi_client_notify_event_type service_event,
        void *notify_cb_data
      );

      static void cneQmiWdsNotifyCb
      (
        qmi_client_type user_handle,
        qmi_idl_service_object_type service_obj,
        qmi_client_notify_event_type service_event,
        void *notify_cb_data
      );

      static void handleQmiSSR(int fd,void *arg);

      static void handleDsdSvcUpInd(int fd, void *arg);
      static void handleDpmSvcUpInd(int fd, void *arg);
      static void handleDmsSvcUpInd(int fd, void *arg);
      static void handleWdsSvcUpInd(int fd, void *arg);
      void handleModemDownInd();

      void dumpReport(dsd_wifi_meas_report_req_msg_v01 &report);

      WmsInterface* loadWms(void);

      void processQmiCb (int qmi_service);
};

#endif /* CNE_QMI_H */
