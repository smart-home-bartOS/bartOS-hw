#include "TemperatureOnline.h"

TemperatureOnline::TemperatureOnline(TemperatureCap *capability) : OnlineCapability<TemperatureCap>(capability) {
}

DynamicJsonDocument TemperatureOnline::getData() {
    DynamicJsonDocument data(50);
    data[STATE] = getTargetCapability()->isOn();

    data.shrinkToFit();
    data.garbageCollect();
    return data;
}

void TemperatureOnline::handleData(DynamicJsonDocument &data) {
    JsonObject object = data.as<JsonObject>();
    const string KEYS[] = {ButtonOnline::STATE, JsonKeys::ENABLED};
    if (containKeys(object, KEYS)) {
        bool isEnabled = object[JsonKeys::ENABLED];
        getTargetCapability()->setEnabled(isEnabled);
    }
}

vector<string> TemperatureOnline::getSubscribedPaths() {
    vector<string> vec;
    vec.push_back("/cap/btn" + getID());
    return vec;
}

const char *TemperatureOnline::TEMP = "temp";
const char *TemperatureOnline::UNIT = "units";
