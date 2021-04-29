//
// Created by mabartos on 4/29/21.
//

#include "BasicWifiManager.h"

BasicWifiManager::BasicWifiManager(const string &ssid, const string &pass) :
        WifiCredentials(ssid, pass) {
}

void BasicWifiManager::connect(WiFiMode wiFiMode) {
    WiFi.mode(wiFiMode);
    WiFi.begin(getSSID().c_str(), getPassword().c_str());
    Serial.printf("Connecting to '%s'\n", getSSID().c_str());
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");

    Serial.println("WiFi connected");
    Serial.println("IP address: " + WiFi.localIP().toString());
}

void BasicWifiManager::disconnect(bool wifiOff) {
    WiFi.disconnect(wifiOff);
    Serial.printf("'%s' was disconnected\n", getSSID().c_str());
}

void BasicWifiManager::disableWifi() {
    WiFi.disconnect(true);
    Serial.println("Wifi was disabled");
}