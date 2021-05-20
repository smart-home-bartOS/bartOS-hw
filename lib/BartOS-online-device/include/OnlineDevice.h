#ifndef ONLINE_DEVICE_H
#define ONLINE_DEVICE_H

#include <ArduinoJson.h>
#include <device/Device.h>
#include <connector/DataConnector.h>
#include <connector/ManageConnector.h>
#include <utils/RandomGenerator.h>
#include <unordered_map>

class OnlineDevice : public Device {
private:
    long _id = -1;
    long _homeID = -1;
    long _roomID = -1;
    shared_ptr<DataConnector> _dataConnector;
    shared_ptr<ManageConnector> _manageConnector;

    bool _storeToFileSystem;
protected:
    DynamicJsonDocument getCreateJSON();
public:
    OnlineDevice(shared_ptr<DataConnector> dataConn,
                 shared_ptr<ManageConnector> manageConn= nullptr,
                 const string name = "Dev_" + RandomGenerator::randomAlphanum(6),
                 bool storeToFileSystem = false
    );

    ~OnlineDevice() = default;

    void init() override;

    void loop() override;

    bool createDevice();

    bool connectDevice();

    bool disconnectDevice();

    shared_ptr<ManageConnector> getManageConnector();

    shared_ptr<DataConnector> getDataConnector();

    void setUpCapabilities(const JsonObject &capsData);

    long getID();

    void setID(const long &id);

    long getHomeID();

    void setHomeID(const long &homeID);

    long getRoomID();

    void setRoomID(const long &roomID);
};

#endif  //ONLINE_DEVICE_H