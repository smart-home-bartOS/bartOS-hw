#include "TemperatureOnline.h"

#include <utility>

TemperatureOnline::TemperatureOnline(const uint8_t &pin,
                                     const string &name,
                                     unsigned sampleTime,
                                     shared_ptr<DataConnector> dataConnector)
        : TemperatureCap(pin, name, sampleTime),
          OnlineCapability(move(dataConnector), CapabilityType::TEMPERATURE) {
}

TemperatureOnline::TemperatureOnline(const uint8_t &pin,
                                     const string &name,
                                     shared_ptr<DataConnector> dataConnector)
        : TemperatureOnline(pin, name, 0, move(dataConnector)) {
}

void TemperatureOnline::sendData() {
    DynamicJsonDocument data(100);
    data[CapabilityType::TEMPERATURE] = getTemperature();

    data.shrinkToFit();
    sendDataToDefault(data);
    data.garbageCollect();
}
