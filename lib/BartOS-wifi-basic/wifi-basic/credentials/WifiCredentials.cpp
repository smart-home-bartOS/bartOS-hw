#include "WifiCredentials.h"

#include <utility>

WifiCredentials::WifiCredentials() = default;

WifiCredentials::WifiCredentials(const string &ssid, const string &pass) :
        _ssid(std::move(ssid)), _pass(std::move(pass)) {}

string WifiCredentials::getSSID() {
    return _ssid;
}

void WifiCredentials::setSSID(const string &ssid) {
    _ssid = ssid;
}

string WifiCredentials::getPassword() {
    return _pass;
}

void WifiCredentials::setPassword(const string &pass) {
    _pass = pass;
}