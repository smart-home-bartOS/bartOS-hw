#ifndef WIFI_CREDENTIALS_H
#define WIFI_CREDENTIALS_H

#include <string>

using namespace std;

class WifiCredentials {
private:
    string _ssid;
    string _pass;
protected:
    string getPassword();

public:
    WifiCredentials();

    WifiCredentials(const string &ssid, const string &pass);

    ~WifiCredentials() = default;

    string getSSID();

    void setSSID(const string &ssid);

    void setPassword(const string &pass);
};

#endif  //WIFI_CREDENTIALS_H