#ifndef HTTP_MANAGE_DEVICE_CONNECTOR_H
#define HTTP_MANAGE_DEVICE_CONNECTOR_H

#include <string>
#include <online-device/device/connector/ManageConnector.h>

using namespace std;

class HttpManageDeviceConn : public ManageConnector {
private:
    string _serverURL;

public:
    explicit HttpManageDeviceConn(const string &serverURL);

    ~HttpManageDeviceConn() = default;

    void connect();

    void disconnect();

    void setServerURL(const string &serverURL);

    string getServerURL();

    DynamicJsonDocument createDevice(const DynamicJsonDocument &data) override;

    DynamicJsonDocument connectDevice() override;

    DynamicJsonDocument disconnectDevice() override;

    DynamicJsonDocument getRoom() override;
};

#endif  //HTTP_MANAGE_DEVICE_CONNECTOR_H