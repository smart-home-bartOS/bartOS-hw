#include "TemperatureData.h"

#include <online-device/device/connector/PubSubDataConnector.h>

TemperatureData::TemperatureData(shared_ptr<PubSubDataConnector> dataConnector) :
        PubSubDataTransceiver(dataConnector) {
}

void TemperatureData::sendData(TemperatureCap *capability) {
    if (capability == nullptr) return;

    DynamicJsonDocument data(100);
    data[TEMPERATURE_FIELD] = capability->getTemperature();
    data[UNITS_FIELD] = capability->getUnits().c_str();

    data.shrinkToFit();
    sendDataToDefault(data);
    data.garbageCollect();
}

const char *TemperatureData::TEMPERATURE_FIELD = "temperature";
const char *TemperatureData::UNITS_FIELD = "units";
