#include "TemperatureOnline.h"

TemperatureOnline::TemperatureOnline(const string &name,
                                     const uint8_t &pin,
                                     const unsigned sampleTime,
                                     shared_ptr<DataConnector> dataConnector) : TemperatureCap(name, pin, sampleTime),
                                                                                OnlineCapability(dataConnector, getTypeID()) {}

TemperatureOnline::TemperatureOnline(const string &name,
                                     const uint8_t &pin,
                                     shared_ptr<DataConnector> dataConnector) : TemperatureOnline(name, pin, 0, dataConnector) {
}

void TemperatureOnline::sendData() {
    DynamicJsonDocument data(100);
    data[CapabilityWithValue::VALUE_FIELD] = getValue();

    data.shrinkToFit();
    sendDataToDefault(data);
    data.garbageCollect();
}
