#ifndef WIFI_UTILS_H
#define WIFI_UTILS_H

#include <ArduinoJson.h>
#include <WiFiManager.h>

#include <string>
#include <online-device/WifiCredentials.h>

using namespace std;

class BartOsWifiManager : public WifiCredentials {
private:
    WiFiManager &_wifiManager;
    bool _shouldSaveConfig = false;

    WiFiManager &getWiFiManager();

    void setWifiManager();

public:
    explicit BartOsWifiManager(WiFiManager &wifiManager);

    ~BartOsWifiManager() = default;

    void begin();

    bool shouldSaveConfig();

    void reset();
};

#endif