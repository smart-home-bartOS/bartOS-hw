#ifndef ONLINE_DEVICE_H
#define ONLINE_DEVICE_H

#include <ArduinoJson.h>
#include <device/Device.h>
#include <utils/RandomGenerator.h>

#include <unordered_map>

#include "connector/DataConnector.h"
#include "connector/ManageConnector.h"

class OnlineDevice : public Device {
   private:
    long _id = -1;
    long _homeID = -1;
    long _roomID = -1;

    shared_ptr<DataConnector> _dataConnector = nullptr;
    shared_ptr<ManageConnector> _manageConnector = nullptr;

    vector<shared_ptr<OnlineCapability>> _onlineCapabilities;
    ConnectionState &_connectionState;

   public:
    OnlineDevice(const string name = "Dev_" + RandomGenerator::randomAlphanum(6));

    ~OnlineDevice() = default;

    void init() override;

    void loop() override;

    shared_ptr<ManageConnector> getManageConnector();

    shared_ptr<DataConnector> getDataConnector();

    long getID();

    void setID(const long &id);

    long getHomeID();

    void setHomeID(const long &homeID);

    long getRoomID();

    void setRoomID(const long &roomID);

    vector<shared_ptr<OnlineCapability>> getOnlineCaps();

    void setOnlineCaps(vector<shared_ptr<OnlineCapability>> &caps);

    void changeConnectionState(ConnectionState &state);
};

#endif  // ONLINE_DEVICE_H