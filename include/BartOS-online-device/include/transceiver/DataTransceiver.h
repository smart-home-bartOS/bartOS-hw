#ifndef ONLINE_CAPABILITY_H
#define ONLINE_CAPABILITY_H

#include <memory>
#include <string>
#include <ArduinoJson.h>
#include <connector/DataConnector.h>
#include <capability/Capability.h>
#include <utils/JsonUtils.h>

using namespace std;

template<class Connector=DataConnector>
class DataTransceiver {
private:
    shared_ptr<Connector> _dataConnector;
    string _defaultPath;
public:
    DataTransceiver(shared_ptr<Connector> dataConnector,
                    const string &defaultPath = "") :
            _dataConnector(dataConnector), _defaultPath(defaultPath) {
    }

    ~DataTransceiver() = default;

    template<class SpecificCapability=Capability>
    void initDataHandler(SpecificCapability *capability, long homeID, long roomID) {};

    template<class SpecificCapability>
    void sendData(SpecificCapability *capability) {};

    void sendDataToDefault(DynamicJsonDocument &data) {
        sendDataToPath(getDefaultPath(), data);
    }

    void sendDataToPath(const string &path, DynamicJsonDocument &data) {
        getDataConnector()->sendData(path, data);
    }

    shared_ptr<Connector> getDataConnector() {
        return _dataConnector;
    }

    void setDataConnector(shared_ptr<Connector> dataConnector) {
        _dataConnector = dataConnector;
    }

    string getDefaultPath() {
        return _defaultPath;
    }

    void setDefaultPath(const string &path) {
        _defaultPath = path;
    }

    static void setRepresentation(JsonObject &obj, const shared_ptr<Capability> &capability) {
        obj.clear();
        obj[CapabilityFields::PIN] = capability->getPin();
        obj[CapabilityFields::TYPE] = capability->getType().c_str();
    }

    static void setUpCapabilityWithActualData(JsonObject &obj, const shared_ptr<Capability> &capability) {
        string keys[] = {CapabilityFields::ID, CapabilityFields::NAME};
        if (containKeys(obj, keys)) {
            capability->setID(obj[CapabilityFields::ID].as<long>());
            capability->setName(obj[CapabilityFields::NAME].as<char *>());
        }
    }
};

#endif  //ONLINE_CAPABILITY_H