//
// Created by mabartos on 4/19/21.
//

#include "HumidityOnline.h"

const char *HumidityOnline::HUMIDITY = "humidity";

HumidityOnline::HumidityOnline(HumidityCap *capability) : OnlineCapability<HumidityCap>(capability) {
    getTargetCapability()->scheduler()->period("sendEach25s", 25000, [this]() {
        DynamicJsonDocument doc = getData();
        getDataConnector()->sendData("/cap/hum/" + getID(), doc);
    });
}

DynamicJsonDocument HumidityOnline::getData() {
    DynamicJsonDocument data(50);
    data[HUMIDITY] = getTargetCapability()->getHumidity();

    data.shrinkToFit();
    data.garbageCollect();
    return data;
}

vector<string> HumidityOnline::getSubscribedPaths() {
    vector<string> vec;
    return vec;
}