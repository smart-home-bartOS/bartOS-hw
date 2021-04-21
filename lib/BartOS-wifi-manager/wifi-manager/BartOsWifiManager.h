#ifndef WIFI_UTILS_H
#define WIFI_UTILS_H

#include <ArduinoJson.h>
#include <WiFiManager.h>

#include <string>
#include <online-device/credentials/AccessWifiCredentials.h>
#include <memory>

using namespace std;

class BartOsWifiManager {
protected:
    shared_ptr<WiFiManager> _wifiManager;
    shared_ptr<AccessWifiCredentials> _wifiCredentials;
public:
    BartOsWifiManager();

    ~BartOsWifiManager() = default;

    virtual void begin() = 0;

    virtual shared_ptr<WiFiManager> getWiFiManager();

    virtual shared_ptr<AccessWifiCredentials> getCredentials();

    virtual void reset();
};

#endif