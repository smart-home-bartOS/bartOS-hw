//
// Created by mabartos on 4/19/21.
//

#include "LightsData.h"

const char *LightsData::INTENSITY = "intensity";

LightsData::LightsData(shared_ptr<PubSubDataConnector> dataConnector) :
        PubSubDataTransceiver(dataConnector) {
}

void LightsData::sendData(LightsCap *cap) {
    if (cap == nullptr) return;

    DynamicJsonDocument data(100);
    data[INTENSITY] = cap->getActualIntensity();

    data.shrinkToFit();
    sendDataToDefault(data);
    data.garbageCollect();
}