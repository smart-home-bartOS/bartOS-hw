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

    ~HttpManageDeviceConn() override = default;

    void connect() override;

    void disconnect() override;

    void setServerURL(const string &serverURL);

    string getServerURL();

    DynamicJsonDocument createDevice(long homeID, const DynamicJsonDocument &data) override;

    DynamicJsonDocument connectDevice(long homeID, long deviceID) override;

    DynamicJsonDocument disconnectDevice(long homeID, long deviceID) override;
};

#endif  //HTTP_MANAGE_DEVICE_CONNECTOR_H