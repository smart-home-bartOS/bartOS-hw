#include "HttpManageDeviceConn.h"
#include "HttpClient.h"
#include "HttpPath.h"

#include <ArduinoJson.h>
#include <online-device/utils/JsonUtils.h>
#include <online-device/device/OnlineDeviceFields.h>

HttpClient httpClient;

HttpManageDeviceConn::HttpManageDeviceConn(const string &serverURL) : _serverURL(serverURL) {
    httpClient.setServerURL(serverURL);
}

void HttpManageDeviceConn::connect() {
}

void HttpManageDeviceConn::disconnect() {
}

void HttpManageDeviceConn::setServerURL(const string &serverURL) {
    _serverURL = serverURL;
}

string HttpManageDeviceConn::getServerURL() {
    return _serverURL;
}

bool isValidResponseCode(const int code, const vector<int> &allowedResponseCodes) {
    for (const int item : allowedResponseCodes) {
        if (item == code) {
            return true;
        }
    }
    return false;
}

DynamicJsonDocument getJsonFromResponse(HttpResponse &response,
                                        const vector<int> &allowedResponseCodes,
                                        const vector<string> &allowedKeys) {
    DynamicJsonDocument empty(1024);

    DynamicJsonDocument doc(1024);
    DeserializationError err = deserializeJson(doc, response.getPayload().c_str(), response.getPayload().size());
    if (err) {
        Serial.println(err.c_str());
        return empty;
    }

    JsonObject obj = doc.as<JsonObject>();

    if (!allowedKeys.empty() && !containKeys(obj, allowedKeys)) {
        return empty;
    }

    if (!isValidResponseCode(response.getResponseCode(), allowedResponseCodes)) {
        return empty;
    }

    return doc;
}

DynamicJsonDocument getJsonFromResponse(HttpResponse &response, const vector<int> &allowedResponseCodes) {
    const vector<string> emptyVector = {};
    return getJsonFromResponse(response, allowedResponseCodes, emptyVector);
}

DynamicJsonDocument HttpManageDeviceConn::createDevice(long homeID, const DynamicJsonDocument &data) {
    char buffer[2048];
    serializeJson(data, buffer);

    HttpResponse resp = httpClient.doPost(getCreatePath(homeID), string(buffer));
    const vector<int> allowedResponseCodes = {200, 201};

    return getJsonFromResponse(resp, allowedResponseCodes, OnlineDeviceFields::getCreateFields());
}

DynamicJsonDocument HttpManageDeviceConn::connectDevice(long homeID, long deviceID) {
    HttpResponse resp = httpClient.doGet(getConnectPath(homeID, deviceID));

    const vector<int> allowedResponseCodes = {200};

    return getJsonFromResponse(resp, allowedResponseCodes, OnlineDeviceFields::getConnectFields());
}

DynamicJsonDocument HttpManageDeviceConn::disconnectDevice(long homeID, long deviceID) {
    HttpResponse resp = httpClient.doGet(getDisconnectPath(homeID, deviceID));

    const vector<int> allowedResponseCodes = {200};

    return getJsonFromResponse(resp, allowedResponseCodes);
}

//TODO
DynamicJsonDocument HttpManageDeviceConn::getRoom(long homeID, long deviceID) {}