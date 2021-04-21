#include "BartOsWifiManager.h"

BartOsWifiManager::BartOsWifiManager() {
    _wifiManager = make_shared<WiFiManager>();
    _wifiCredentials = make_shared<AccessWifiCredentials>();
}

shared_ptr<WiFiManager> BartOsWifiManager::getWiFiManager() {
    return _wifiManager;
}

shared_ptr<AccessWifiCredentials> BartOsWifiManager::getCredentials() {
    return _wifiCredentials;
}

void BartOsWifiManager::reset() {
    getWiFiManager()->resetSettings();
    _wifiCredentials.reset();
}