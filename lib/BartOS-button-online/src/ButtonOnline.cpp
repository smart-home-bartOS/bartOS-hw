//
// Created by mabartos on 4/19/21.
//

#include "ButtonOnline.h"

#include "json/JsonKeys.h"
#include "json/JsonUtils.h"

const char *ButtonOnline::STATE = "state";

ButtonOnline::ButtonOnline(ButtonCap *capability) : OnlineCapability<ButtonCap>(capability) {
    capability->onChange([this]() {
        DynamicJsonDocument doc = getData();
        getDataConnector()->sendData("/cap/btn/" + getID(), doc);
    });
}

DynamicJsonDocument ButtonOnline::getData() {
    DynamicJsonDocument data(50);
    data[STATE] = getTargetCapability()->isOn();

    data.shrinkToFit();
    data.garbageCollect();
    return data;
}

vector<string> ButtonOnline::getSubscribedPaths() {
    vector<string> vec;
    vec.push_back("/cap/btn" + getID());
    return vec;
}