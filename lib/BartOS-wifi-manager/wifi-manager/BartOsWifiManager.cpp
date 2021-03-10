#include "BartOsWifiManager.h"

#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <LittleFS.h>

#include "ESP8266TrueRandom.h"
#include "FS.h"

#define SSID_SIZE 100
#define PASSWORD_SIZE 100

char ssid[SSID_SIZE];
char password[PASSWORD_SIZE];

WiFiManager wifiManager;

BartOsWifiManager::BartOsWifiManager() {
}

void BartOsWifiManager::begin() {
    setWifiManager();
}

void BartOsWifiManager::setWifiManager() {
    string label("<h3> WiFi Manager</h3>");
    WiFiManagerParameter ssid_parameter("ssid", "SSID", ssid, SSID_SIZE);
    WiFiManagerParameter password_parameter("password", "Password", password, PASSWORD_SIZE);

    wifiManager.addParameter(&ssid_parameter);
    wifiManager.addParameter(&password_parameter);

    string WIFI_NAME("SmartHome BartOS");

    if (!wifiManager.autoConnect(WIFI_NAME.c_str())) {
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
    LittleFS.format();
    wifiManager.resetSettings();
}