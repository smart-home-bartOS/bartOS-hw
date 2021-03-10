#include "WifiCredentials.h"

WifiCredentials::WifiCredentials() {}

WifiCredentials::WifiCredentials(const string& ssid, const string& pass) : _ssid(ssid), _pass(pass) {}

string WifiCredentials::getSSID() {
    return _ssid;
}

void WifiCredentials::setSSID(const string& ssid) {
    _ssid = ssid;
}

string WifiCredentials::getPassword() {
    return _pass;
}

void WifiCredentials::setPassword(const string& pass) {
    _pass = pass;
}