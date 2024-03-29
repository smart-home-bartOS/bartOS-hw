#include "TemperatureOnline.h"

const char *TemperatureOnline::TEMP = "temp";
const char *TemperatureOnline::UNITS = "units";

TemperatureOnline::TemperatureOnline(TemperatureCap *capability) : OnlineCapability<TemperatureCap>(capability) {
    getTargetCapability()->scheduler()->period("sendEach30s", 30000, [this]() {
        DynamicJsonDocument doc = getData();
        getDataConnector()->sendData("/cap/temp/" + getID(), doc);
    });
}

DynamicJsonDocument TemperatureOnline::getData() {
    DynamicJsonDocument data(50);
    data[TEMP] = getTargetCapability()->getTemperature();
    data[UNITS] = getTargetCapability()->getUnits();

    data.shrinkToFit();
    data.garbageCollect();
    return data;
}
