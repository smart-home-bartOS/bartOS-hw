#ifndef ONLINE_DEVICE_H
#define ONLINE_DEVICE_H

#include <ArduinoJson.h>

#include "core/device/Device.h"
#include "online-device/WifiCredentials.h"
#include "online-device/device/connector/DataConnector.h"
#include "online-device/device/connector/ManageConnector.h"

class OnlineDevice : public Device, enable_shared_from_this<OnlineDevice> {
   private:
    bool _storeFileSystem = false;
    shared_ptr<DataConnector> _dataConnector;
    shared_ptr<ManageConnector> _manageConnector;

    WifiCredentials _wifiCredentials;

   public:
    OnlineDevice(shared_ptr<ManageConnector> &manageConn,
                 shared_ptr<DataConnector> &dataConn);
    OnlineDevice(shared_ptr<ManageConnector> &manageConn,
                 shared_ptr<DataConnector> &dataConn,
                 bool storeToFileSystem);
    ~OnlineDevice() = default;

    void init();

    bool createDevice();
    bool connectDevice();
    bool disconnectDevice();

    bool shouldSaveToFileSystem();

    shared_ptr<ManageConnector> getManageConnector();
    shared_ptr<DataConnector> getDataConnector();

    void setManageConnector(shared_ptr<ManageConnector> connector);
    void setManageConnector(shared_ptr<DataConnector> connector);

    void setUpCapabilities(const JsonObject &capsData);

    DynamicJsonDocument getCreateJSON();
    DynamicJsonDocument getConnectJSON();

    WifiCredentials getWifiCredentials();
    void setWifiCredentials(WifiCredentials credentials);
};

#endif  //ONLINE_DEVICE_H