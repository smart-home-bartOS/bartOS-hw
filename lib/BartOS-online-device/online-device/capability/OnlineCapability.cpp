#include "OnlineCapability.h"

#include <utility>
#include <online-device/utils/JsonUtils.h>

OnlineCapability::OnlineCapability(shared_ptr<DataConnector> dataConnector) : _dataConnector(std::move(dataConnector)) {
}

OnlineCapability::OnlineCapability(shared_ptr<DataConnector> dataConnector, const string &defaultPath)
        : OnlineCapability(std::move(dataConnector)) {
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
    _dataConnector = std::move(dataConnector);
}

string OnlineCapability::getDefaultPath() {
    return _defaultPath;
}

void OnlineCapability::setDefaultPath(const string &path) {
    _defaultPath = path;
}

void OnlineCapability::setRepresentation(JsonObject &obj, const shared_ptr<Capability> &capability) {
    obj.clear();
    Capability *cap = capability.get();
    obj[CapabilityFields::PIN] = cap->getPin();
    obj[CapabilityFields::TYPE] = cap->getType().c_str();
}

void OnlineCapability::setUpCapabilityWithActualData(JsonObject &obj, const shared_ptr<Capability> &capability) {
    const vector<string> KEYS{CapabilityFields::ID, CapabilityFields::NAME};
    if (containKeys(obj, KEYS)) {
        capability->setID(obj[CapabilityFields::ID].as<long>());
        capability->setName(obj[CapabilityFields::NAME].as<char*>());
    }
}
