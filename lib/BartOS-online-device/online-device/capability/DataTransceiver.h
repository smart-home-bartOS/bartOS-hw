#ifndef ONLINE_CAPABILITY_H
#define ONLINE_CAPABILITY_H

#include <memory>
#include <string>
#include <ArduinoJson.h>
#include <online-device/device/connector/DataConnector.h>
#include <core/capability/Capability.h>

using namespace std;

class DataTransceiver {
private:
    shared_ptr<DataConnector> _dataConnector;
    string _defaultPath;

public:
    explicit DataTransceiver(shared_ptr<DataConnector> dataConnector);

    DataTransceiver(shared_ptr<DataConnector> dataConnector, const string &defaultPath);

    ~DataTransceiver() = default;

    virtual void handleData(const JsonObject &obj);

    virtual void sendData() = 0;

    void sendDataToDefault(DynamicJsonDocument &data);

    void sendData(const string &path, DynamicJsonDocument &data);

    shared_ptr<DataConnector> getDataConnector();

    void setDataConnector(shared_ptr<DataConnector> dataConnector);

    string getDefaultPath();

    void setDefaultPath(const string &path);

    static void setRepresentation(JsonObject &obj, const shared_ptr<Capability>& capability);

    static void setUpCapabilityWithActualData(JsonObject &obj, const shared_ptr<Capability>& capability);
};

#endif  //ONLINE_CAPABILITY_H