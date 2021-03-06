#ifndef MANAGE_CONNECTOR_H
#define MANAGE_CONNECTOR_H

#include <ArduinoJson.h>

#include "device/connector/Connector.h"

using namespace std;

class ManageConnector : public DeviceConnector {
   public:
    virtual ~ManageConnector(){};

    virtual void connect() = 0;
    virtual void disconnect() = 0;

    virtual DynamicJsonDocument createDevice() = 0;
    virtual DynamicJsonDocument connectDevice() = 0;
    virtual DynamicJsonDocument disconnectDevice() = 0;
    virtual DynamicJsonDocument getRoom() = 0;
};

#endif  //MANAGE_CONNECTOR_H