#ifndef HTTP_PATH_H
#define HTTP_PATH_H

#include <device/DevicePath.h>

#include <string>

using std::string;

static const string& CONNECT_PATH = "connect";
static const string& DISCONNECT_PATH = "disconnect";

static string getConnectPath(const long homeID, const long deviceID) {
    return getHomeDevicePath(homeID, deviceID) + "/" + CONNECT_PATH;
}

static string getDisconnectPath(const long homeID, const long deviceID) {
    return getHomeDevicePath(homeID, deviceID) + "/" + DISCONNECT_PATH;
}

#endif  // HTTP_PATH_H