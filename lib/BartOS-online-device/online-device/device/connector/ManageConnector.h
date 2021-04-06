#ifndef MANAGE_CONNECTOR_H
#define MANAGE_CONNECTOR_H

#include <ArduinoJson.h>
#include "DeviceConnector.h"

using namespace std;

class ManageConnector : public DeviceConnector {
public:
    ~ManageConnector() override = default;

    virtual DynamicJsonDocument createDevice(const DynamicJsonDocument &data) = 0;

    virtual DynamicJsonDocument connectDevice() = 0;

    virtual DynamicJsonDocument disconnectDevice() = 0;

    virtual DynamicJsonDocument getRoom() = 0;
};

#endif  //MANAGE_CONNECTOR_H