#include "device/OnlineDevice.h"

#include <cstring>
#include <memory>

#include "json/JsonKeys.h"
#include "state/NewDeviceState.h"

using std::make_shared;

OnlineDevice::OnlineDevice(const string name) : Device(), _name(name) {
    changeConnectionState(make_shared<NewDeviceState>(this));
}

void OnlineDevice::init() {
    if (getManageConnector() != nullptr) {
        getManageConnector()->init();
    }
    if (getDataConnector() != nullptr) {
        getDataConnector()->init();
    }
    _connectionState->init();

    Device::init();
}

void OnlineDevice::loop() {
    Device::loop();

    _connectionState->loop();

    if (getManageConnector() != nullptr) {
        getManageConnector()->loop();
    };
    if (getDataConnector() != nullptr) {
        getDataConnector()->loop();
    };
}

string OnlineDevice::getName() {
    return _name;
}

void OnlineDevice::setName(const string &name) {
    _name = name;
}

shared_ptr<ManageConnector> OnlineDevice::getManageConnector() {
    return _manageConnector;
}

shared_ptr<DataConnector> OnlineDevice::getDataConnector() {
    return _dataConnector;
}

void OnlineDevice::setManageConnector(shared_ptr<ManageConnector> connector) {
    _manageConnector = connector;
}

void OnlineDevice::setDataConnector(shared_ptr<DataConnector> connector) {
    _dataConnector = connector;
}

long OnlineDevice::getID() {
    return _id;
}

void OnlineDevice::setID(const long &id) {
    _id = id;
}

long OnlineDevice::getHomeID() {
    return _homeID;
}

void OnlineDevice::setHomeID(const long &homeID) {
    _homeID = homeID;
}

long OnlineDevice::getRoomID() {
    return _roomID;
}

void OnlineDevice::setRoomID(const long &roomID) {
    _roomID = roomID;
}

vector<shared_ptr<OnlineCapability<Capability>>> OnlineDevice::getOnlineCaps() {
    return _onlineCapabilities;
}

void OnlineDevice::setOnlineCaps(vector<shared_ptr<OnlineCapability<Capability>>> &caps) {
    _onlineCapabilities = caps;
}

void OnlineDevice::changeConnectionState(shared_ptr<ConnectionState> state) {
    _connectionState = state;
}

DynamicJsonDocument OnlineDevice::getInfo() {
    DynamicJsonDocument doc(512);

    doc[JsonKeys::ID] = getID();
    doc[JsonKeys::NAME] = getName();
    doc[JsonKeys::HOME_ID] = getHomeID();
    doc[JsonKeys::ROOM_ID] = getRoomID();
    doc[JsonKeys::COUNT_OF_CAPS] = getOnlineCaps().size();

    doc.shrinkToFit();
    doc.garbageCollect();

    return doc;
}

DynamicJsonDocument OnlineDevice::getInfoWithCaps() {
    DynamicJsonDocument doc = getData();

    JsonArray caps = doc.createNestedArray(JsonKeys::CAPABILITIES);

    for (auto item : getOnlineCaps()) {
        JsonObject obj = item->getData().as<JsonObject>();
        caps.add(obj);
    }

    doc.shrinkToFit();
    doc.garbageCollect();

    return doc;
}