#ifndef WIFI_UTILS_H
#define WIFI_UTILS_H

#include <ArduinoJson.h>
#include <WiFiManager.h>

#include <string>
#include <online-device/credentials/AccessWifiCredentials.h>
#include <memory>

using namespace std;

class BartOsWifiManager {
private:
    shared_ptr<WiFiManager> _wifiManager;
    shared_ptr<AccessWifiCredentials> _wifiCredentials;
    bool _shouldSaveConfig = false;
    long _homeID = -1;

    void initWifiManager();

public:
    BartOsWifiManager();

    ~BartOsWifiManager() = default;

    void begin();

    shared_ptr<WiFiManager> getWiFiManager();

    shared_ptr<AccessWifiCredentials> getCredentials();

    bool shouldSaveConfig();

    long getHomeID();

    void reset();
};

#endif