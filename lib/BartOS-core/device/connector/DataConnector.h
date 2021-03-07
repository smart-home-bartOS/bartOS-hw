#ifndef DATA_CONNECTOR_H
#define DATA_CONNECTOR_H

#include <string>

#include "device/connector/DeviceConnector.h"

using namespace std;

template <typename DataResponse, typename DataType>
class DataConnector : public DeviceConnector {
   public:
    virtual ~DataConnector(){};

    virtual DataResponse sendData(const string& path, DataType data) = 0;
};

#endif  //DATA_CONNECTOR_H