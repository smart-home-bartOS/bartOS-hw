#ifndef MANAGE_CONNECTOR_H
#define MANAGE_CONNECTOR_H

#include <ArduinoJson.h>
#include "DeviceConnector.h"

using namespace std;

class ManageConnector : public DeviceConnector {
public:
    ~ManageConnector() = default;

    virtual DynamicJsonDocument createDevice(long homeID, const DynamicJsonDocument &data) = 0;

    virtual DynamicJsonDocument connectDevice(long homeID, long deviceID) = 0;

    virtual DynamicJsonDocument disconnectDevice(long homeID, long deviceID) = 0;
};

#endif  //MANAGE_CONNECTOR_H