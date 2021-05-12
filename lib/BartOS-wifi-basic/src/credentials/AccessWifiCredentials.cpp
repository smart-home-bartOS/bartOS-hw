//
// Created by mabartos on 4/20/21.
//

#include "credentials/AccessWifiCredentials.h"

AccessWifiCredentials::AccessWifiCredentials() : WifiCredentials() {
}

AccessWifiCredentials::AccessWifiCredentials(const string &accessToken,
                                             const string &ssid,
                                             const string &pass) :
        WifiCredentials(ssid, pass), _accessToken(accessToken) {
}

string AccessWifiCredentials::getAccessToken() {
    return _accessToken;
}

void AccessWifiCredentials::setAccessToken(const string &token) {
    _accessToken = token;
}