#include "OnlineDevice.h"

#include <cstring>
#include <memory>
#include <core/storage/FsManager.h>
#include <online-device/transceiver/DataTransceiver.h>

#include "OnlineDeviceFields.h"

OnlineDevice::OnlineDevice(const vector<shared_ptr<Capability>> &capabilities,
                           shared_ptr<ManageConnector> manageConn,
                           shared_ptr<DataConnector> dataConn,
                           const string name,
                           bool storeToFileSystem) :
        Device(capabilities, name, ConnectionType::ONLINE),
        _dataConnector(dataConn),
        _manageConnector(manageConn),
        _storeToFileSystem(storeToFileSystem) {
}

void OnlineDevice::init() {
    getManageConnector()->connect();
    getDataConnector()->connect();
    Device::init();

    getID() != -1 ? connectDevice() : createDevice();
}

shared_ptr<ManageConnector> OnlineDevice::getManageConnector() {
    return _manageConnector;
}

shared_ptr<DataConnector> OnlineDevice::getDataConnector() {
    return _dataConnector;
}

size_t getCreateJSONSize(size_t capabilitiesSize) {
    return JSON_ARRAY_SIZE(capabilitiesSize) + capabilitiesSize * (JSON_OBJECT_SIZE(3) + 100) + JSON_OBJECT_SIZE(4) +
           500;
}

DynamicJsonDocument OnlineDevice::getCreateJSON() {
    const size_t capacity = getCreateJSONSize(getCapabilities().size());
    DynamicJsonDocument create(capacity);

    create[DeviceFields::NAME] = getName().c_str();
    JsonArray caps = create.createNestedArray(DeviceFields::CAPABILITIES);

    for (auto &item : getCapabilities()) {
        if (item->getConnectionType() == ConnectionType::ONLINE) {
            JsonObject obj = caps.createNestedObject();
            DataTransceiver<DataConnector>::setRepresentation(obj, item);
        }
    }

    return create;
}

bool OnlineDevice::createDevice() {
    DynamicJsonDocument doc = getManageConnector()->createDevice(getHomeID(), getCreateJSON());

    setID(doc[DeviceFields::ID]);
    setUpCapabilities(doc.as<JsonObject>());

    setInitialized(true);

    doc.garbageCollect();
    return true;
}

bool OnlineDevice::connectDevice() {
    DynamicJsonDocument doc = getManageConnector()->connectDevice(getHomeID(), getID());

    const char *name = doc[DeviceFields::NAME];
    if (strcmp(name, getName().c_str()) != 0) {
        setName(string(name));
    }

    if (doc.containsKey(DeviceFields::ROOM_ID)) {
        long roomID = doc[DeviceFields::ROOM_ID];
        if (roomID != getRoomID()) {
            setRoomID(roomID);
        }
    }

    setUpCapabilities(doc.as<JsonObject>());
    setInitialized(true);

    doc.garbageCollect();
    return true;
}

bool OnlineDevice::disconnectDevice() {
    getManageConnector()->disconnectDevice(getHomeID(), getID());
    return true;
}

void OnlineDevice::setUpCapabilities(const JsonObject &capsData) {
    if (capsData.containsKey(CapabilityFields::CAPABILITIES)) {
        JsonArray caps = capsData[CapabilityFields::CAPABILITIES];

        for (JsonObject capData : caps) {
            if (containKeys(capData, {CapabilityFields::PIN, CapabilityFields::TYPE})) {
                uint8_t pin = capData[CapabilityFields::PIN];
                const char *type = capData[CapabilityFields::TYPE];

                auto p_cap = getCapByPinAndType(pin, type);
                if (p_cap != nullptr) {
                    DataTransceiver<DataConnector>::setUpCapabilityWithActualData(capData, p_cap);
                }
            }
        }
    }
}

shared_ptr<WifiCredentials> OnlineDevice::getCredentials() {
    return _wifiCredentials;
}

void OnlineDevice::setCredentials(shared_ptr<WifiCredentials> credentials) {
    _wifiCredentials = credentials;
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

void OnlineDevice::changeCapAvailability(bool state) {
    for (auto &item : getCapabilities()) {
        item->setEnabled(state);
    }
}

void OnlineDevice::disableAllCapabilities() {
    changeCapAvailability(false);
}

void OnlineDevice::enableAllCapabilities() {
    changeCapAvailability(true);
}