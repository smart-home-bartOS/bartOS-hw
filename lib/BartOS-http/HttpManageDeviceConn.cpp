#include "HttpManageDeviceConn.h"

#include <ArduinoJson.h>

#include "HttpClient.h"
#include "device/Device.h"
#include "device/DeviceFields.h"
#include "device/DevicePath.h"
#include "utils/JsonUtils.h"

HttpClient httpClient;
extern Device device;

HttpManageDeviceConn::HttpManageDeviceConn(const string& serverURL) : _serverURL(serverURL) {
    httpClient.setServerURL(serverURL);
}

void HttpManageDeviceConn::connect() {}
void HttpManageDeviceConn::disconnect() {}

void HttpManageDeviceConn::setServerURL(const string& serverURL) {
    _serverURL = serverURL;
}

string HttpManageDeviceConn::getServerURL() {
    return _serverURL;
}

size_t getCreateJSONSize(size_t capabilitiesSize) {
    return JSON_ARRAY_SIZE(capabilitiesSize) + capabilitiesSize * (JSON_OBJECT_SIZE(3) + 100) + JSON_OBJECT_SIZE(4) + 500;
}

DynamicJsonDocument getCreateJSON() {
    const size_t capacity = getCreateJSONSize(device.getCapabilities().size());
    DynamicJsonDocument create(capacity);

    create[NAME] = device.getName().c_str();
    JsonArray caps = create.createNestedArray(CAPABILITIES);

    for (auto& item : device.getCapabilities()) {
        JsonObject obj = caps.createNestedObject();
        item->editCreateCapNested(obj);
    }

    return create;
}

HttpResponse HttpManageDeviceConn::createDevice() {
    char buffer[2048];
    DynamicJsonDocument json = getCreateJSON();
    serializeJson(json, buffer);

    HttpResponse resp = httpClient.doPost(getHomePath(device.getHomeID()), string(buffer));

    DynamicJsonDocument doc(1024);
    DeserializationError err = deserializeJson(doc, resp.getPayload().c_str(), resp.getPayload().size());
    if (err) {
        Serial.println(err.c_str());
        return;
    }

    JsonObject obj = doc.as<JsonObject>();

    vector<string> keys{ID, NAME, CAPABILITIES};
    if (!containKeys(obj, keys) || resp.getResponseCode() != 200 || resp.getResponseCode() != 201) {
        return;
    }
    //TODO
    device.setID(obj[ID]);
    MessageForwarder::manageCreateSPIFS(obj, ID);

    setInitialized(true);
    doc.garbageCollect();
}

HttpResponse HttpManageDeviceConn::connectDevice() {}
HttpResponse HttpManageDeviceConn::disconnectDevice() {}
HttpResponse HttpManageDeviceConn::getRoom() {}