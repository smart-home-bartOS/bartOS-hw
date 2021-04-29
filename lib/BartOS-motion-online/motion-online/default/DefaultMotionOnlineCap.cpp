//
// Created by mabartos on 4/29/21.
//

#include "DefaultMotionOnlineCap.h"

DefaultMotionOnlineCap::DefaultMotionOnlineCap(shared_ptr <PubSubDataConnector> dataConnector,
                                               const uint8_t &pin,
                                               const string &name) :
        DefaultMotionCap(pin, name), MotionData(dataConnector) {
}

void DefaultMotionOnlineCap::execute() {
    DefaultMotionCap::execute();
    if (DefaultMotionCap::isMotionDetected()) sendData();
}

void DefaultMotionOnlineCap::sendData() {
    MotionData::sendData(this);
}