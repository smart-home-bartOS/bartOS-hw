//
// Created by mabartos on 4/21/21.
//

#ifndef BARTOS_HW_DEFAULTWIFIMANAGER_H
#define BARTOS_HW_DEFAULTWIFIMANAGER_H

#include <wifi-manager/BartOsWifiManager.h>

class DefaultWifiManager : public BartOsWifiManager {
private:
    string _accessToken;
    string _deviceName;
    string _serverUrl;
    string _brokerUrl;

    long _homeID = -1;
    long _roomID = -1;
public:
    DefaultWifiManager();

    ~DefaultWifiManager() = default;

    void begin() override;

    string getAccessToken();

    string getDeviceName();

    string getServerUrl();

    string getBrokerUrl();

    long getHomeID();

    long getRoomID();
};


#endif //BARTOS_HW_DEFAULTWIFIMANAGER_H
