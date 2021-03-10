#include "HttpManageDeviceConn.h"

#include <ArduinoJson.h>

#include "HttpClient.h"
#include "HttpPath.h"
#include "core/device/Device.h"
#include "online-device/device/DevicePath.h"
#include "online-device/device/OnlineDeviceFields.h"
#include "online-device/utils/JsonUtils.h"

HttpClient httpClient;

HttpManageDeviceConn::HttpManageDeviceConn(const string& serverURL) : _serverURL(serverURL) {
    httpClient.setServerURL(serverURL);
}

void HttpManageDeviceConn::connect() {
}
void HttpManageDeviceConn::disconnect() {
}

void HttpManageDeviceConn::setServerURL(const string& serverURL) {
    _serverURL = serverURL;
}

string HttpManageDeviceConn::getServerURL() {
    return _serverURL;
}

bool isValidResponseCode(const int code, const vector<int> allowedResponseCodes) {
    for (const int item : allowedResponseCodes) {
        if (item == code) {
            return true;
        }
    }
    return false;
}

DynamicJsonDocument getJsonFromResponse(HttpResponse& response, const vector<int> allowedResponseCodes, const vector<string> allowedKeys) {
    DynamicJsonDocument doc(1024);
    DeserializationError err = deserializeJson(doc, response.getPayload().c_str(), response.getPayload().size());
    if (err) {
        Serial.println(err.c_str());
        return;
    }

    JsonObject obj = doc.as<JsonObject>();

    if (!allowedKeys.empty() && !containKeys(obj, allowedKeys)) {
        return;
    }

    if (!isValidResponseCode(response.getResponseCode(), allowedResponseCodes)) {
        return;
    }

    return doc;
}

DynamicJsonDocument getJsonFromResponse(HttpResponse& response, const vector<int> allowedResponseCodes) {
    const vector<string> emptyVector = {};
    return getJsonFromResponse(response, allowedResponseCodes, emptyVector);
}

DynamicJsonDocument HttpManageDeviceConn::createDevice(const DynamicJsonDocument& data) {
    char buffer[2048];
    serializeJson(data, buffer);
    Device* device = getDevice().get();

    HttpResponse resp = httpClient.doPost(getCreatePath(device->getHomeID()), string(buffer));
    const vector<int> allowedResponseCodes = {200, 201};

    return getJsonFromResponse(resp, allowedResponseCodes, OnlineDeviceFields::getCreateFields());
}

DynamicJsonDocument HttpManageDeviceConn::connectDevice() {
    Device* device = getDevice().get();

    HttpResponse resp = httpClient.doGet(getConnectPath(device->getHomeID(), device->getID()));

    const vector<int> allowedResponseCodes = {200};

    return getJsonFromResponse(resp, allowedResponseCodes, OnlineDeviceFields::getConnectFields());
}

DynamicJsonDocument HttpManageDeviceConn::disconnectDevice() {
    Device* device = getDevice().get();

    HttpResponse resp = httpClient.doGet(getDisconnectPath(device->getHomeID(), device->getID()));

    const vector<int> allowedResponseCodes = {200};

    return getJsonFromResponse(resp, allowedResponseCodes);
}

//TODO
DynamicJsonDocument HttpManageDeviceConn::getRoom() {}