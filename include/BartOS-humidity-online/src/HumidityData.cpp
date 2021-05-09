//
// Created by mabartos on 4/19/21.
//

#include "HumidityData.h"

HumidityData::HumidityData(shared_ptr<PubSubDataConnector> dataConnector) :
        PubSubDataTransceiver(dataConnector) {}

void HumidityData::sendData(HumidityCap *cap) {
    if (cap == nullptr) return;

    DynamicJsonDocument data(50);
    data[HUMIDITY_FIELD] = cap->getHumidity();

    data.shrinkToFit();
    sendDataToDefault(data);
    data.garbageCollect();
}

const char *HumidityData::HUMIDITY_FIELD = "humidity";
