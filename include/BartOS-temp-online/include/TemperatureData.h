#ifndef TEMPERATURE_ONLINE_H
#define TEMPERATURE_ONLINE_H

#include <string>

#include <TemperatureCap.h>
#include <transceiver/PubSubDataTransceiver.h>

using namespace std;

class TemperatureData : public PubSubDataTransceiver {
public:
    static const char *TEMPERATURE_FIELD;
    static const char *UNITS_FIELD;

    TemperatureData(shared_ptr<PubSubDataConnector> dataConnector);

    ~TemperatureData() = default;

    void sendData(TemperatureCap *capability);
};

#endif  //TEMPERATURE_ONLINE_H