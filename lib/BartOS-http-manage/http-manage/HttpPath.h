#ifndef HTTP_PATH_H
#define HTTP_PATH_H

using namespace std;
#include <string>
#include <online-device/device/DevicePath.h>

static const string& CONNECT_PATH = "connect";
static const string& DISCONNECT_PATH = "disconnect";
static const string& CREATE_PATH = "create";

static string getConnectPath(const long homeID, const long deviceID) {
    getHomeDevicePath(homeID, deviceID) + "/" + CONNECT_PATH;
}

static string getDisconnectPath(const long homeID, const long deviceID) {
    getHomeDevicePath(homeID, deviceID) + "/" + DISCONNECT_PATH;
}

static string getCreatePath(const long homeID) {
    getHomePath(homeID) + "/" + CREATE_PATH;
}

#endif  //HTTP_PATH_H