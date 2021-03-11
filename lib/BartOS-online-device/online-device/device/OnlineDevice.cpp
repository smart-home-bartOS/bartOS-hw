#include "OnlineDevice.h"

#include "OnlineDeviceFields.h"
#include "core/capability/CapabilityFields.h"
#include "core/storage/FsManager.h"
#include "online-device/capability/OnlineCapability.h"
#include "online-device/utils/JsonUtils.h"

extern FsManager fsManager;

OnlineDevice::OnlineDevice(shared_ptr<ManageConnector> &manageConn,
                           shared_ptr<DataConnector> &dataConn,
                           bool storeToFileSystem) : _manageConnector(manageConn),
                                                     _dataConnector(dataConn),
                                                     _storeFileSystem(storeToFileSystem) {
    setConnectionType(ConnectionType::ONLINE);
    shared_ptr<Device> instance = make_shared<OnlineDevice>(shared_from_this());
    _manageConnector.get()->setDevice(instance);
    _dataConnector.get()->setDevice(instance);
}

OnlineDevice::OnlineDevice(shared_ptr<ManageConnector> &manageConn,
                           shared_ptr<DataConnector> &dataConn) : OnlineDevice(manageConn, dataConn, false) {
}

void OnlineDevice::init() {
    getManageConnector().get()->connect();
    getDataConnector().get()->connect();
}

bool OnlineDevice::shouldSaveToFileSystem() {
    return _storeFileSystem;
}

shared_ptr<ManageConnector> OnlineDevice::getManageConnector() {
    return _manageConnector;
}

shared_ptr<DataConnector> OnlineDevice::getDataConnector() {
    return _dataConnector;
}

size_t getCreateJSONSize(size_t capabilitiesSize) {
    return JSON_ARRAY_SIZE(capabilitiesSize) + capabilitiesSize * (JSON_OBJECT_SIZE(3) + 100) + JSON_OBJECT_SIZE(4) + 500;
}

DynamicJsonDocument OnlineDevice::getCreateJSON() {
    const size_t capacity = getCreateJSONSize(getCapabilities().size());
    DynamicJsonDocument create(capacity);

    create[DeviceFields::NAME] = getName().c_str();
    JsonArray caps = create.createNestedArray(DeviceFields::CAPABILITIES);

    for (auto &item : getCapabilities()) {
        if (item.get()->getConnectionType() == ConnectionType::ONLINE) {
            JsonObject obj = caps.createNestedObject();
            OnlineCapability::setRepresentation(obj, item);
        }
    }

    return create;
}

bool OnlineDevice::createDevice() {
    DynamicJsonDocument doc = getManageConnector().get()->createDevice(getCreateJSON());

    setID(doc[DeviceFields::ID]);
    setUpCapabilities(doc.as<JsonObject>());

    setInitialized(true);

    doc.garbageCollect();
    return true;
}

bool OnlineDevice::connectDevice() {
    DynamicJsonDocument doc = getManageConnector().get()->connectDevice();

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
    getManageConnector().get()->disconnectDevice();
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

void OnlineDevice::setWifiCredentials(WifiCredentials credentials) {
    _wifiCredentials = credentials;
}