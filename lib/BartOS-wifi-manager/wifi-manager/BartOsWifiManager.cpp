#include "BartOsWifiManager.h"

#include "ESP8266TrueRandom.h"

#define HOME_ID_SIZE 50
#define ACCESS_TOKEN_SIZE 100
#define SSID_SIZE 100
#define PASSWORD_SIZE 100

BartOsWifiManager::BartOsWifiManager() {
    _wifiManager = make_shared<WiFiManager>();
    _wifiCredentials = make_shared<AccessWifiCredentials>();
}

void BartOsWifiManager::begin() {
    initWifiManager();
}

shared_ptr<WiFiManager> BartOsWifiManager::getWiFiManager() {
    return _wifiManager;
}

shared_ptr<AccessWifiCredentials> BartOsWifiManager::getCredentials() {
    return _wifiCredentials;
}

void BartOsWifiManager::initWifiManager() {
    char home[HOME_ID_SIZE];
    char accessToken[ACCESS_TOKEN_SIZE];
    char ssid[SSID_SIZE];
    char password[PASSWORD_SIZE];

    string label("<h3> WiFi Manager</h3>");
    WiFiManagerParameter ssid_parameter("ssid", "SSID", ssid, SSID_SIZE);
    WiFiManagerParameter password_parameter("password", "Password", password, PASSWORD_SIZE);
    WiFiManagerParameter home_parameter("homeID", "Home ID", home, HOME_ID_SIZE);
    WiFiManagerParameter access_token_parameter("accessToken", "Access token", accessToken, ACCESS_TOKEN_SIZE);

    getWiFiManager()->addParameter(&ssid_parameter);
    getWiFiManager()->addParameter(&password_parameter);
    getWiFiManager()->addParameter(&home_parameter);
    getWiFiManager()->addParameter(&access_token_parameter);

    string WIFI_NAME("SmartHome BartOS");

    if (!getWiFiManager()->autoConnect(WIFI_NAME.c_str())) {
        reset();
    }

    strcpy(ssid, ssid_parameter.getValue());
    strcpy(password, password_parameter.getValue());
    strcpy(home, home_parameter.getValue());
    strcpy(accessToken, access_token_parameter.getValue());

    getCredentials()->setSSID(ssid);
    getCredentials()->setPassword(password);
    getCredentials()->setAccessToken(accessToken);
    _homeID = strtol(home, nullptr, 10);
}

bool BartOsWifiManager::shouldSaveConfig() {
    return _shouldSaveConfig;
}

void BartOsWifiManager::reset() {
    getWiFiManager()->resetSettings();
}

long BartOsWifiManager::getHomeID() {
    return _homeID;
}