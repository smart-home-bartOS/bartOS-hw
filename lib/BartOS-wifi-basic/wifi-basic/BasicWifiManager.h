//
// Created by mabartos on 4/29/21.
//

#ifndef BARTOS_HW_BASICWIFIMANAGER_H
#define BARTOS_HW_BASICWIFIMANAGER_H

using namespace std;

#include <string>

#include <wifi-basic/credentials/WifiCredentials.h>
#include <ESP8266WiFi.h>

class BasicWifiManager : public WifiCredentials {
public:
    BasicWifiManager(const string &ssid = "", const string &pass = "");

    ~BasicWifiManager() = default;

    void disableWifi();

    void connect(WiFiMode wiFiMode = WIFI_STA);

    void disconnect(bool wifiOff = false);
};


#endif //BARTOS_HW_BASICWIFIMANAGER_H
