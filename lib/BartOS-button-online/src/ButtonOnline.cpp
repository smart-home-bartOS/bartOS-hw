//
// Created by mabartos on 4/19/21.
//

#include "ButtonOnline.h"

#include "json/JsonKeys.h"
#include "utils/JsonUtils.h"

const char *ButtonOnline::STATE = "state";

ButtonOnline::ButtonOnline(ButtonCap *capability) : OnlineCapability<ButtonCap>(capability) {
}

DynamicJsonDocument ButtonOnline::getData() {
    DynamicJsonDocument data(50);
    data[STATE] = getTargetCapability()->isOn();

    data.shrinkToFit();
    data.garbageCollect();
    return data;
}

void ButtonOnline::handleData(DynamicJsonDocument &data) {
    JsonObject object = data.as<JsonObject>();
    const string KEYS[] = {ButtonOnline::STATE, JsonKeys::ENABLED};
    if (containKeys(object, KEYS)) {
        bool isEnabled = object[JsonKeys::ENABLED];
        getTargetCapability()->setEnabled(isEnabled);
    }
}

vector<string> ButtonOnline::getSubscribedPaths() {
    vector<string> vec;
    vec.push_back("/cap/btn" + getID());
    return vec;
}