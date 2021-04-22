//
// Created by mabartos on 4/20/21.
//

#ifndef BARTOS_HW_ACCESSWIFICREDENTIALS_H
#define BARTOS_HW_ACCESSWIFICREDENTIALS_H

#include "WifiCredentials.h"

class AccessWifiCredentials : public WifiCredentials {
private:
    string _accessToken;
public:
    AccessWifiCredentials();

    AccessWifiCredentials(const string &accessToken, const string &ssid, const string &pass);

    ~AccessWifiCredentials() = default;

    string getAccessToken();

    void setAccessToken(const string &token);
};


#endif //BARTOS_HW_ACCESSWIFICREDENTIALS_H
