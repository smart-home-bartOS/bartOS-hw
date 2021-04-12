#ifndef ONLINE_DEVICE_H
#define ONLINE_DEVICE_H

#include <ArduinoJson.h>
#include <core/device/Device.h>
#include <online-device/device/connector/DataConnector.h>
#include <online-device/device/connector/ManageConnector.h>
#include <online-device/WifiCredentials.h>

class OnlineDevice : public Device, enable_shared_from_this<OnlineDevice> {
private:
    DataConnector &_dataConnector;
    ManageConnector &_manageConnector;

    WifiCredentials _wifiCredentials;

public:
    OnlineDevice(const vector<shared_ptr<Capability>> &capabilities,
                 ManageConnector &manageConn,
                 DataConnector &dataConn
    );

    OnlineDevice(const vector<shared_ptr<Capability>> &capabilities,
                 ManageConnector &manageConn,
                 DataConnector &dataConn,
                 bool storeToFileSystem);

    ~OnlineDevice() = default;

    void init() override;

    bool createDevice();

    bool connectDevice();

    bool disconnectDevice();

    ManageConnector &getManageConnector();

    DataConnector &getDataConnector();

    void setUpCapabilities(const JsonObject &capsData);

    DynamicJsonDocument getCreateJSON();

    WifiCredentials getWifiCredentials();

    void setWifiCredentials(const WifiCredentials &credentials);
};

#endif  //ONLINE_DEVICE_H