#include "OnlineDevice.h"

#include "device/DeviceFields.h"
#include "storage/FsManager.h"
#include "utils/JsonUtils.h"

extern FsManager fsManager;

OnlineDevice::OnlineDevice(shared_ptr<ManageConnector> &manageConn,
                           shared_ptr<DataConnector> &dataConn,
                           bool storeToFileSystem) : _manageConnector(manageConn),
                                                     _dataConnector(dataConn),
                                                     _storeFileSystem(storeToFileSystem) {
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

    create[NAME] = getName().c_str();
    JsonArray caps = create.createNestedArray(CAPABILITIES);

    for (auto &item : getCapabilities()) {
        JsonObject obj = caps.createNestedObject();
        item->editCreateCapNested(obj);
    }

    return create;
}

bool OnlineDevice::createDevice() {
    DynamicJsonDocument doc = getManageConnector().get()->createDevice(getCreateJSON());

    setID(doc[ID]);
    setCapsIDFromJSON(doc.as<JsonObject>());

    setInitialized(true);

    doc.garbageCollect();
    return true;
}

bool OnlineDevice::connectDevice() {
    DynamicJsonDocument doc = getManageConnector().get()->connectDevice();

    const char *name = doc[NAME];
    if (strcmp(name, getName().c_str()) != 0) {
        setName(string(name));
    }

    if (doc.containsKey(ROOM_ID)) {
        long roomID = doc[ROOM_ID];
        if (roomID != getRoomID()) {
            setRoomID(roomID);
        }
    }

    setCapsIDFromJSON(doc.as<JsonObject>());
    setInitialized(true);

    doc.garbageCollect();
    return true;
}

bool OnlineDevice::disconnectDevice() {
    getManageConnector().get()->disconnectDevice();
}
