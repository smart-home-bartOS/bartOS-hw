#ifndef MANAGE_CONNECTOR_H
#define MANAGE_CONNECTOR_H

#include <ArduinoJson.h>

#include "device/connector/DeviceConnector.h"

using namespace std;

class ManageConnector : public DeviceConnector {
   public:
    virtual ~ManageConnector(){};

    virtual DynamicJsonDocument createDevice(const DynamicJsonDocument& data) = 0;
    virtual DynamicJsonDocument connectDevice() = 0;
    virtual DynamicJsonDocument disconnectDevice() = 0;
    virtual DynamicJsonDocument getRoom() = 0;
};

#endif  //MANAGE_CONNECTOR_H