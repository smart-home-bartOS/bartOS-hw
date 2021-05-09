//
// Created by mabartos on 4/21/21.
//

#include "default/DefaultWifiManager.h"

#define ACCESS_TOKEN_SIZE 50
#define SSID_SIZE 70
#define PASSWORD_SIZE 70

#define DEVICE_NAME_SIZE 50
#define HOME_ID_SIZE 40
#define ROOM_ID_SIZE 40
#define SERVER_URL_SIZE 60
#define BROKER_URL_SIZE 60

DefaultWifiManager::DefaultWifiManager() : BartOsWifiManager() {
}

void DefaultWifiManager::begin() {
    /* Alloc buffers */
    char accessToken[ACCESS_TOKEN_SIZE];

    char deviceName[DEVICE_NAME_SIZE];
    char home[HOME_ID_SIZE];
    char room[ROOM_ID_SIZE];

    char serverUrl[SERVER_URL_SIZE];
    char brokerUrl[BROKER_URL_SIZE];

    string label("<h3> WiFi Manager</h3>");

    /* Create parameters */
    WiFiManagerParameter access_token_parameter("accessToken", "Access token", "", ACCESS_TOKEN_SIZE);

    WiFiManagerParameter device_name_parameter("deviceName", "Device Name", "", DEVICE_NAME_SIZE);
    WiFiManagerParameter home_parameter("homeID", "Home ID", "", HOME_ID_SIZE);
    WiFiManagerParameter room_parameter("roomID", "Room ID", "", ROOM_ID_SIZE);

    WiFiManagerParameter server_parameter("serverUrl", "Server URL", "localhost:8080", SERVER_URL_SIZE);
    WiFiManagerParameter broker_parameter("brokerUrl", "Broker URL", "localhost:1883", BROKER_URL_SIZE);

    /* Add parameters to app*/
    getWiFiManager()->addParameter(&access_token_parameter);

    getWiFiManager()->addParameter(&device_name_parameter);
    getWiFiManager()->addParameter(&home_parameter);
    getWiFiManager()->addParameter(&room_parameter);

    getWiFiManager()->addParameter(&server_parameter);
    getWiFiManager()->addParameter(&broker_parameter);
    /* Start */
    string WIFI_NAME("SmartHome BartOS");

    if (!getWiFiManager()->autoConnect(WIFI_NAME.c_str())) {
        reset();
    }

    //TODO wrong memory access
    /* Copy values to buffers */
    strcpy(accessToken, access_token_parameter.getValue());

    strcpy(deviceName, device_name_parameter.getValue());
    strcpy(home, home_parameter.getValue());
    strcpy(room, room_parameter.getValue());

    strcpy(serverUrl, server_parameter.getValue());
    strcpy(brokerUrl, broker_parameter.getValue());

    /*Set values*/
    _accessToken = accessToken;
    _deviceName = deviceName;
    _homeID = strtol(home, nullptr, 10);
    _roomID = strtol(room, nullptr, 10);

    _serverUrl = serverUrl;
    _brokerUrl = brokerUrl;

    Serial.println("Connected");
    Serial.println(WiFi.localIP());
    Serial.println(WiFi.gatewayIP());
    Serial.println(WiFi.subnetMask());
}

string DefaultWifiManager::getDeviceName() {
    return _deviceName;
}

string DefaultWifiManager::getServerUrl() {
    return _serverUrl;
}

string DefaultWifiManager::getBrokerUrl() {
    return _brokerUrl;
}

long DefaultWifiManager::getHomeID() {
    return _homeID;
}

long DefaultWifiManager::getRoomID() {
    return _roomID;
}