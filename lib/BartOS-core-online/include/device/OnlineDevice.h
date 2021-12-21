#ifndef ONLINE_DEVICE_H
#define ONLINE_DEVICE_H

#include <ArduinoJson.h>
#include <device/Device.h>
#include <utils/RandomGenerator.h>

#include <memory>
#include <string>
#include <vector>

#include "capability/OnlineCapability.h"
#include "connector/DataConnector.h"
#include "connector/DataHandler.h"
#include "connector/ManageConnector.h"

using std::shared_ptr;
using std::string;
using std::vector;

#define CONNECTION_STATE_CALLBACK "connection_state_callback_period"
#define DEFAULT_CONNECTION_STATE_PERIOD 500

enum class ConnectionState {
    NOT_CONNECTED,
    CONNECTED,
    NEW_DEVICE
};

class OnlineDevice : public Device,
                     public DataHandler {
   private:
    long _id = -1;
    long _homeID = -1;
    long _roomID = -1;
    string _name = "";

    shared_ptr<DataConnector> _dataConnector = nullptr;
    shared_ptr<ManageConnector> _manageConnector = nullptr;

    vector<shared_ptr<OnlineCapability<Capability>>> _onlineCapabilities;
    ConnectionState _connectionState = ConnectionState::NOT_CONNECTED;

   public:
    OnlineDevice(const string name = "Dev_" + RandomGenerator::randomAlphanum(6));

    ~OnlineDevice() = default;

    void init() override;

    void loop() override;

    void initConnectionState();

    shared_ptr<ManageConnector> getManageConnector();
    void setManageConnector(shared_ptr<ManageConnector> connector);

    shared_ptr<DataConnector> getDataConnector();
    void setDataConnector(shared_ptr<DataConnector> connector);

    long getID();

    void setID(const long &id);

    string getName();
    void setName(const string &name);

    long getHomeID();

    void setHomeID(const long &homeID);

    long getRoomID();

    void setRoomID(const long &roomID);

    vector<shared_ptr<OnlineCapability<Capability>>> getOnlineCaps();

    void setOnlineCaps(vector<shared_ptr<OnlineCapability<Capability>>> &caps);

    void changeConnectionState(ConnectionState state);

    virtual DynamicJsonDocument getInfo() override;
    virtual DynamicJsonDocument getInfoWithCaps();
};

#endif  // ONLINE_DEVICE_H