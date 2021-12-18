#include "HttpConnector.h"

#include <ArduinoJson.h>
#include <utils/JsonUtils.h>

#include "HttpClient.h"
#include "HttpPath.h"

HttpClient httpClient;

HttpConnector::HttpConnector(const string &baseURL) : DataConnector(baseURL), ManageConnector(baseURL) {
    httpClient.setServerURL(baseURL);
}

void HttpConnector::connect() {}
void HttpConnector::disconnect() {}
void HttpConnector::create() {}
void HttpConnector::remove() {}
void HttpConnector::update() {}
void HttpConnector::init() {}
void HttpConnector::loop() {}

bool HttpConnector::isValidResponseCode(const int code, const vector<int> &allowedResponseCodes) {
    for (const int item : allowedResponseCodes) {
        if (item == code) {
            return true;
        }
    }
    return false;
}

DynamicJsonDocument HttpConnector::getJsonFromResponse(HttpResponse &response,
                                                       const vector<int> &allowedResponseCodes,
                                                       const string allowedKeys[]) {
    DynamicJsonDocument empty(1024);

    DynamicJsonDocument doc(1024);
    DeserializationError err = deserializeJson(doc, response.getPayload().c_str(), response.getPayload().size());
    if (err) {
        Serial.println(err.c_str());
        return empty;
    }

    JsonObject obj = doc.as<JsonObject>();

    if (!allowedKeys->size() == 0 && !containKeys(obj, allowedKeys)) {
        return empty;
    }

    if (!isValidResponseCode(response.getResponseCode(), allowedResponseCodes)) {
        return empty;
    }

    return doc;
}

DynamicJsonDocument HttpConnector::getJsonFromResponse(HttpResponse &response, const vector<int> &allowedResponseCodes) {
    const string empty[] = {};
    return getJsonFromResponse(response, allowedResponseCodes, empty);
}
/*
DynamicJsonDocument HttpManageDeviceConn::createDevice(long homeID, const DynamicJsonDocument &data) {
    char buffer[2048];
    serializeJson(data, buffer);

    HttpResponse resp = httpClient.doPost(getCreatePath(homeID), string(buffer));
    const vector<int> allowedResponseCodes = {200, 201};

    return getJsonFromResponse(resp, allowedResponseCodes, OnlineDeviceFields::getCreateFields().data());
}

DynamicJsonDocument HttpManageDeviceConn::connectDevice(long homeID, long deviceID) {
    HttpResponse resp = httpClient.doGet(getConnectPath(homeID, deviceID));

    const vector<int> allowedResponseCodes = {200};

    return getJsonFromResponse(resp, allowedResponseCodes, OnlineDeviceFields::getConnectFields().data());
}

DynamicJsonDocument HttpManageDeviceConn::disconnectDevice(long homeID, long deviceID) {
    HttpResponse resp = httpClient.doGet(getDisconnectPath(homeID, deviceID));

    const vector<int> allowedResponseCodes = {200};

    return getJsonFromResponse(resp, allowedResponseCodes);
}
*/