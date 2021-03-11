#include "OnlineCapability.h"

#include "online-device/utils/JsonUtils.h"

OnlineCapability::OnlineCapability(shared_ptr<DataConnector> dataConnector) : _dataConnector(dataConnector) {
}

OnlineCapability::OnlineCapability(shared_ptr<DataConnector> dataConnector, const string &defaultPath) : OnlineCapability(dataConnector) {
    setDefaultPath(defaultPath);
}

void OnlineCapability::handleData(const JsonObject &obj) {
}

void OnlineCapability::sendDataToDefault(DynamicJsonDocument &data) {
    sendData(getDefaultPath(), data);
}

void OnlineCapability::sendData(const string &path, DynamicJsonDocument &data) {
    getDataConnector().get()->sendData(path, data);
}

shared_ptr<DataConnector> OnlineCapability::getDataConnector() {
    return _dataConnector;
}

void OnlineCapability::setDataConnector(shared_ptr<DataConnector> dataConnector) {
    _dataConnector = dataConnector;
}

const string OnlineCapability::getDefaultPath() {
    return _defaultPath;
}
void OnlineCapability::setDefaultPath(const string &path) {
    _defaultPath = path;
}

void OnlineCapability::setRepresentation(JsonObject &obj, shared_ptr<Capability> capability) {
    obj.clear();
    Capability *cap = capability.get();
    obj[CapabilityFields::PIN] = cap->getPin();
    obj[CapabilityFields::TYPE] = cap->getTypeID().c_str();
}

void OnlineCapability::setUpCapabilityWithActualData(JsonObject &obj, shared_ptr<Capability> capability) {
    const vector<string> KEYS{CapabilityFields::ID, CapabilityFields::NAME};
    if (containKeys(obj, KEYS)) {
        capability.get()->setID(obj[CapabilityFields::ID]);
        capability.get()->setName(obj[CapabilityFields::NAME]);
    }
}
