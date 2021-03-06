#include "OnlineDevice.h"

#include "device/DeviceFields.h"
#include "storage/FsManager.h"
#include "utils/JsonUtils.h"

extern FsManager fsManager;

OnlineDevice::OnlineDevice(shared_ptr<ManageConnector> &manageConn,
                           shared_ptr<DataConnector> &dataConn) : _manageConnector(manageConn),
                                                                  _dataConnector(dataConn) {
}

OnlineDevice::OnlineDevice(shared_ptr<ManageConnector> &manageConn,
                           shared_ptr<DataConnector> &dataConn,
                           bool storeToFileSystem) : _manageConnector(manageConn),
                                                     _dataConnector(dataConn),
                                                     _storeFileSystem(storeToFileSystem) {
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

bool OnlineDevice::createDevice() {
    DynamicJsonDocument doc = getManageConnector().get()->connectDevice();
    if (shouldSaveToFileSystem()) {
        const vector<string> keys{ID};
        JsonObject obj = doc.as<JsonObject>();
        if (!containKeys(obj, keys)) {
            Serial.println("Create device response doesn't contain required data.");
            return false;
        }
        fsManager.saveToConfigFile(doc);
    }

    setID(doc[ID]);
    return true;
}

bool OnlineDevice::connectDevice() {
}

bool OnlineDevice::disconnectDevice() {
}
