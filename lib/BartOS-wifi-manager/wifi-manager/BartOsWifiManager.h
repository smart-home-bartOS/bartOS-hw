#ifndef WIFI_UTILS_H
#define WIFI_UTILS_H

#include <ArduinoJson.h>
#include <WiFiManager.h>

#include <string>
#include <online-device/WifiCredentials.h>

using namespace std;

class BartOsWifiManager : public WifiCredentials {
private:
    bool _shouldSaveConfig = false;

    void setWifiManager();

public:
    BartOsWifiManager();

    ~BartOsWifiManager() = default;

    void begin();

    bool shouldSaveConfig();

    void reset();
};

#endif