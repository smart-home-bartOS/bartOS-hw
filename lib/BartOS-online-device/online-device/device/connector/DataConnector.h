#ifndef DATA_CONNECTOR_H
#define DATA_CONNECTOR_H

#include <string>

#include "DeviceConnector.h"

using namespace std;

class DataConnector : public DeviceConnector {
   public:
    virtual ~DataConnector(){};

    virtual void sendData(const string& path, DynamicJsonDocument data) = 0;
};

#endif  //DATA_CONNECTOR_H