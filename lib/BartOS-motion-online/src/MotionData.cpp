//
// Created by mabartos on 4/29/21.
//

#include "MotionData.h"

const char *MotionData::DETECTED = "detected";

MotionData::MotionData(shared_ptr<PubSubDataConnector> dataConnector) :
        PubSubDataTransceiver(dataConnector) {}

void MotionData::sendData(MotionCap *cap) {
    if (cap == nullptr)return;

    DynamicJsonDocument data(20);
    data[DETECTED] = cap->isMotionDetected();

    data.shrinkToFit();
    sendDataToDefault(data);
    data.garbageCollect();
}