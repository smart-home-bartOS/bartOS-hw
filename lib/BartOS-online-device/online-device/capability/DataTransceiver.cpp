#include "DataTransceiver.h"

#include <utility>
#include <online-device/utils/JsonUtils.h>

DataTransceiver::DataTransceiver(shared_ptr<DataConnector> dataConnector) : _dataConnector(std::move(dataConnector)) {
}

DataTransceiver::DataTransceiver(shared_ptr<DataConnector> dataConnector, const string &defaultPath)
        : DataTransceiver(std::move(dataConnector)) {
    setDefaultPath(defaultPath);
}

void DataTransceiver::handleData(const JsonObject &obj) {
}

void DataTransceiver::sendDataToDefault(DynamicJsonDocument &data) {
    sendData(getDefaultPath(), data);
}

void DataTransceiver::sendData(const string &path, DynamicJsonDocument &data) {
    getDataConnector()->sendData(path, data);
}

shared_ptr<DataConnector> DataTransceiver::getDataConnector() {
    return _dataConnector;
}

void DataTransceiver::setDataConnector(shared_ptr<DataConnector> dataConnector) {
    _dataConnector = std::move(dataConnector);
}

string DataTransceiver::getDefaultPath() {
    return _defaultPath;
}

void DataTransceiver::setDefaultPath(const string &path) {
    _defaultPath = path;
}

void DataTransceiver::setRepresentation(JsonObject &obj, const shared_ptr<Capability> &capability) {
    obj.clear();
    Capability *cap = capability.get();
    obj[CapabilityFields::PIN] = cap->getPin();
    obj[CapabilityFields::TYPE] = cap->getType().c_str();
}

void DataTransceiver::setUpCapabilityWithActualData(JsonObject &obj, const shared_ptr<Capability> &capability) {
    const vector<string> KEYS{CapabilityFields::ID, CapabilityFields::NAME};
    if (containKeys(obj, KEYS)) {
        capability->setID(obj[CapabilityFields::ID].as<long>());
        capability->setName(obj[CapabilityFields::NAME].as<char*>());
    }
}
