#include "HttpConnector.h"

#include <ArduinoJson.h>
#include <device/DevicePath.h>
#include <json/JsonUtils.h>

#include "HttpClient.h"
#include "HttpPath.h"
#include "device/OnlineDevice.h"

HttpConnector::HttpConnector(HttpClient &httpClient, const string &baseURL) : DataConnector(baseURL), ManageConnector(baseURL), _httpClient(httpClient) {
    _httpClient.setServerURL(baseURL);
}

void HttpConnector::sendData(const string &path, DynamicJsonDocument &data) {
    const string &devicePath = getHomeDevicePath(getOnlineDevice()->getHomeID(), getOnlineDevice()->getID());
    HttpResponse resp = _httpClient.doPost(devicePath, jsonToString(data));

    DynamicJsonDocument output = getJsonFromResponse(resp, {200});
    notify(devicePath, output);
}

void HttpConnector::connect() {
    DynamicJsonDocument data = getOnlineDevice()->getInfo();

    const string &connectPath = getConnectPath(getOnlineDevice()->getHomeID(), getOnlineDevice()->getID());

    HttpResponse resp = _httpClient.doPost(connectPath, jsonToString(data));

    DynamicJsonDocument output = getJsonFromResponse(resp, {200, 400});
    notify(connectPath, output);
}

void HttpConnector::disconnect() {
    const string &disconnectPath = getDisconnectPath(getOnlineDevice()->getHomeID(), getOnlineDevice()->getID());

    HttpResponse resp = _httpClient.doGet(disconnectPath);

    DynamicJsonDocument output = getJsonFromResponse(resp, {200, 400});
    notify(disconnectPath, output);
}

void HttpConnector::create() {
    DynamicJsonDocument data = getOnlineDevice()->getInfoWithCaps();

    const string &homePath = getHomePath(getOnlineDevice()->getHomeID());

    HttpResponse resp = _httpClient.doPost(homePath, jsonToString(data));

    DynamicJsonDocument output = getJsonFromResponse(resp, {201});
    notify(homePath, output);
}

void HttpConnector::remove() {
    const string &devicePath = getHomeDevicePath(getOnlineDevice()->getHomeID(), getOnlineDevice()->getID());

    HttpResponse resp = _httpClient.doDelete(devicePath);

    DynamicJsonDocument output = getJsonFromResponse(resp, {200, 204});
    notify(devicePath, output);
}

void HttpConnector::update() {
    DynamicJsonDocument data = getOnlineDevice()->getInfoWithCaps();

    const string &devicePath = getHomeDevicePath(getOnlineDevice()->getHomeID(), getOnlineDevice()->getID());

    HttpResponse resp = _httpClient.doPatch(devicePath, jsonToString(data));

    DynamicJsonDocument output = getJsonFromResponse(resp, {200});
    notify(devicePath, output);
}

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

DynamicJsonDocument HttpConnector::getJsonFromResponse(HttpResponse &response, const vector<int> &allowedResponseCodes) {
    DynamicJsonDocument empty(10);

    DynamicJsonDocument doc(1024);
    DeserializationError err = deserializeJson(doc, response.getPayload().c_str(), response.getPayload().size());
    if (err) {
        Serial.println(err.c_str());
        return empty;
    }

    JsonObject obj = doc.as<JsonObject>();

    if (!isValidResponseCode(response.getResponseCode(), allowedResponseCodes)) {
        return empty;
    }

    return doc;
}