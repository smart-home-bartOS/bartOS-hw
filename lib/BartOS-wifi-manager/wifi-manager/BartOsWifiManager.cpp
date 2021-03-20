#include "BartOsWifiManager.h"

#include "ESP8266TrueRandom.h"

#define SSID_SIZE 100
#define PASSWORD_SIZE 100

BartOsWifiManager::BartOsWifiManager(WiFiManager &wifiManager) : _wifiManager(wifiManager) {
}

void BartOsWifiManager::begin() {
    setWifiManager();
}

WiFiManager &BartOsWifiManager::getWiFiManager() {
    return _wifiManager;
}

void BartOsWifiManager::setWifiManager() {
    char ssid[SSID_SIZE];
    char password[PASSWORD_SIZE];

    string label("<h3> WiFi Manager</h3>");
    WiFiManagerParameter ssid_parameter("ssid", "SSID", ssid, SSID_SIZE);
    WiFiManagerParameter password_parameter("password", "Password", password, PASSWORD_SIZE);

    getWiFiManager().addParameter(&ssid_parameter);
    getWiFiManager().addParameter(&password_parameter);

    string WIFI_NAME("SmartHome BartOS");

    if (!getWiFiManager().autoConnect(WIFI_NAME.c_str())) {
        reset();
    }

    strcpy(ssid, ssid_parameter.getValue());
    strcpy(password, password_parameter.getValue());

    setSSID(ssid);
    setPassword(password);
}

bool BartOsWifiManager::shouldSaveConfig() {
    return _shouldSaveConfig;
}

void BartOsWifiManager::reset() {
    getWiFiManager().resetSettings();
}