/*=============================================================================
  Copyright (c) 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/

package com.example.connmgr;

import android.util.Log;

import com.qualcomm.qti.imscmservice.V1_0.IImsCMConnectionListener;
import com.qualcomm.qti.imscmservice.V1_0.IImsCMConnection;
import com.qualcomm.qti.imscmservice.V1_0.IMSCM_CONNECTION_EVENT_DATA;
import com.qualcomm.qti.imscmservice.V1_0.IMSCM_CONN_INCOMING_MESSAGE;


public class ConnectionListenerImpl extends IImsCMConnectionListener.Stub {
  final static String TAG = "UI_ConnMgr_ConnectionListenerImpl";

  /*handleEventReceived: Callback function to inform clients about a
    registration status change, changes in service allowed by policy
    manager because of a RAT change,and any forceful terminations
    of the connection object by the QTI framework because of PDP
    status changes.
  */
  @Override
  public void onEventReceived(IMSCM_CONNECTION_EVENT_DATA event) {
    Log.d(TAG, "onEventReceived event is "+event.toString());
    if(event.eEvent == 1) {
       Log.d(TAG, "onEventReceived ConnectionSm is initialized");
       ConnectionGlobalData.connSmInitialised = 1;
    }
  }

  /*handleIncomingMessage: This callback indicates the incoming message to the client.*/
  @Override
  public void handleIncomingMessage(IMSCM_CONN_INCOMING_MESSAGE nIncomingMessageObj)
  {
    Log.d(TAG, "handleIncomingMessage nIncomingMessageObj" + nIncomingMessageObj.toString());
  }

  /*onCommandStatus: Status of the sendMessage
    (whether or not the message was transmitted to network)
    is returned asynchronously via
    the onCommandStatus callback with messageID as a parameter.
  */
  @Override
  public void onCommandStatus(int status, int userdata) {
    Log.d(TAG, "handleCommandStatus status is "+status + "userdata " + userdata);
  }
}
