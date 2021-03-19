#include "OnlineDevice.h"

#include <cstring>
#include <memory>
#include <core/storage/FsManager.h>
#include <online-device/capability/OnlineCapability.h>

#include "OnlineDeviceFields.h"

extern FsManager fsManager;

OnlineDevice::OnlineDevice(ManageConnector &manageConn,
                           DataConnector &dataConn,
                           bool storeToFileSystem) : _manageConnector(manageConn),
                                                     _dataConnector(dataConn) {
    setConnectionType(ConnectionType::ONLINE);
    _manageConnector.setDevice(shared_from_this());
    _dataConnector.setDevice(shared_from_this());
}

OnlineDevice::OnlineDevice(ManageConnector &manageConn,
                           DataConnector &dataConn) : OnlineDevice(manageConn, dataConn, false) {
}

void OnlineDevice::init() {
    getManageConnector().connect();
    getDataConnector().connect();
}

ManageConnector &OnlineDevice::getManageConnector() {
    return _manageConnector;
}

DataConnector &OnlineDevice::getDataConnector() {
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
            OnlineCapability::setRepresentation(obj, item);
        }
    }

    return create;
}

bool OnlineDevice::createDevice() {
    DynamicJsonDocument doc = getManageConnector().createDevice(getCreateJSON());

    setID(doc[DeviceFields::ID]);
    setUpCapabilities(doc.as<JsonObject>());

    setInitialized(true);

    doc.garbageCollect();
    return true;
}

bool OnlineDevice::connectDevice() {
    DynamicJsonDocument doc = getManageConnector().connectDevice();

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
    getManageConnector().disconnectDevice();
}

void OnlineDevice::setUpCapabilities(const JsonObject &capsData) {
    if (capsData.containsKey(CapabilityFields::CAPABILITIES)) {
        JsonArray caps = capsData[CapabilityFields::CAPABILITIES];

        for (JsonObject capData : caps) {
            if (capData.containsKey(CapabilityFields::PIN)) {
                auto p_cap = getCapByPin(capData[CapabilityFields::PIN]);
                if (p_cap != nullptr) {
                    OnlineCapability::setUpCapabilityWithActualData(capData, p_cap);
                }
            }
        }
    }
}

WifiCredentials OnlineDevice::getWifiCredentials() {
    return _wifiCredentials;
}

void OnlineDevice::setWifiCredentials(const WifiCredentials &credentials) {
    _wifiCredentials = credentials;
}