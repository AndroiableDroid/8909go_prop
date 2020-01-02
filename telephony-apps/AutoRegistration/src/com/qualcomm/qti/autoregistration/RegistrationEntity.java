/*
 *Copyright (c) 2017 Qualcomm Technologies, Inc.
 *All Rights Reserved.
 *Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

package com.qualcomm.qti.autoregistration;

import android.telephony.SubscriptionManager;

import java.io.Serializable;

public class RegistrationEntity implements Serializable {
    boolean isManual = false;
    int ctSlotId = SubscriptionManager.INVALID_PHONE_INDEX;
    int primarySimSlotId = SubscriptionManager.INVALID_PHONE_INDEX;

    boolean isRegistered = false;
    String rawData = null;
    String reltDesc = null;

    public RegistrationEntity (int ctSlotId, int primarySimSlotId) {
        this.ctSlotId = ctSlotId;
        this.primarySimSlotId = primarySimSlotId;
    }

    public RegistrationEntity (int ctSlotId, int primarySimSlotId, boolean isManual) {
        this(ctSlotId, primarySimSlotId);
        this.isManual = isManual;
    }

    public RegistrationEntity (String rawData) {
        this.rawData = rawData;
    }

    public String toString() {
        return "isManual = " + isManual + " ctSlotId = " + ctSlotId
                + " primarySimSlotId = " + primarySimSlotId
                + " isRegistered = " + isRegistered
                + " rawData = " + rawData
                + " reltDesc = " + reltDesc;
    }
}
