//
// Created by mabartos on 4/29/21.
//

#ifndef BARTOS_HW_BASICWIFIMANAGER_H
#define BARTOS_HW_BASICWIFIMANAGER_H

using namespace std;

#include <string>

#include "credentials/WifiCredentials.h"
#include <ESP8266WiFi.h>

class BasicWifiManager : public WifiCredentials {
private:
    string _ipAddr = "";
    string _gateway = "";
    string _subnetMask = "";

    bool _connected = false;

public:
    BasicWifiManager(const string &ssid = "", const string &pass = "");

    ~BasicWifiManager() = default;

    void disableWifi();

    void connect(WiFiMode wiFiMode = WIFI_STA);

    void disconnect(bool wifiOff = false);

    bool isConnected();

    string getIPAddress();

    string getGateway();

    string getSubnetMask();

    void printInfo();
};


#endif //BARTOS_HW_BASICWIFIMANAGER_H
