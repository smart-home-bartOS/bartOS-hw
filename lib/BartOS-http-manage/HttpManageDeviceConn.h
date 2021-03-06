#ifndef HTTP_MANAGE_DEVICE_CONNECTOR_H
#define HTTP_MANAGE_DEVICE_CONNECTOR_H

#include <string>

#include "HttpResponse.h"
#include "device/connector/ManageConnector.h"

using namespace std;

class HttpManageDeviceConn : public ManageConnector {
   private:
    string _serverURL;

   public:
    HttpManageDeviceConn(const string& serverURL);
    ~HttpManageDeviceConn() = default;

    void connect();
    void disconnect();

    void setServerURL(const string& serverURL);
    string getServerURL();

    DynamicJsonDocument createDevice();
    DynamicJsonDocument connectDevice();
    DynamicJsonDocument disconnectDevice();
    DynamicJsonDocument getRoom();
};

#endif  //HTTP_MANAGE_DEVICE_CONNECTOR_H