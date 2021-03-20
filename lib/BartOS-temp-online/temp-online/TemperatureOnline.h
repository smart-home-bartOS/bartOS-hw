#ifndef TEMPERATURE_ONLINE_H
#define TEMPERATURE_ONLINE_H

#include <string>

#include "online-device/capability/OnlineCapability.h"
#include "temp/TemperatureCap.h"

using namespace std;

class TemperatureOnline : public TemperatureCap, public OnlineCapability {
public:
    TemperatureOnline(const uint8_t &pin,
                      const string &name,
                      unsigned sampleTime,
                      shared_ptr<DataConnector> dataConnector);

    TemperatureOnline(const uint8_t &pin,
                      const string &name,
                      shared_ptr<DataConnector> dataConnector);

    ~TemperatureOnline() = default;

    void handleData(const JsonObject &obj) override {}

    void sendData() override;
};

#endif  //TEMPERATURE_ONLINE_H