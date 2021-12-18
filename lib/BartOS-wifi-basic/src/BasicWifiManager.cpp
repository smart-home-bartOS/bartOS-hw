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
    _connected = true;
    _ipAddr = WiFi.localIP().toString().c_str();
    _gateway = WiFi.gatewayIP().toString().c_str();
    _subnetMask = WiFi.subnetMask().toString().c_str();

    printInfo();
}

void BasicWifiManager::disconnect(bool wifiOff) {
    WiFi.disconnect(wifiOff);
    _connected = false;
    Serial.printf("'%s' was disconnected\n", getSSID().c_str());
}

void BasicWifiManager::disableWifi() {
    WiFi.disconnect(true);
    _connected = false;
    Serial.println("Wifi was disabled");
}

bool BasicWifiManager::isConnected() {
    return _connected;
}

string BasicWifiManager::getIPAddress() {
    return _ipAddr;
}

string BasicWifiManager::getGateway() {
    return _gateway;
}

string BasicWifiManager::getSubnetMask() {
    return _subnetMask;
}

void BasicWifiManager::printInfo() {
    Serial.println("----- WiFi status -----");
    Serial.printf("State: %s \n", isConnected() ? "Connected" : "Disconnected");
    Serial.printf("SSID: %s \n", getSSID().c_str());
    Serial.printf("IP address: %s\n", getIPAddress().c_str());
    Serial.printf("Gateway: %s\n", getGateway().c_str());
    Serial.printf("Subnet mask: %s\n", getSubnetMask().c_str());
}