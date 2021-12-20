#ifndef BARTOS_HW_MQTT_PATH_H
#define BARTOS_HW_MQTT_PATH_H

#include <device/DevicePath.h>

#include <string>

using std::string;

static const string& CONNECT = "connect";
static const string& CREATE = "create";
static const string& DISCONNECT = "disconnect";
static const string& REMOVE = "remove";
static const string& UPDATE = "update";

static string getConnectPath(const long homeID, const long deviceID) {
    return getHomeDevicePath(homeID, deviceID) + "/" + CONNECT;
}

static string getDisconnectPath(const long homeID, const long deviceID) {
    return getHomeDevicePath(homeID, deviceID) + "/" + DISCONNECT;
}

static string getCreatePath(const long homeID) {
    return getHomePath(homeID) + "/" + CREATE;
}

static string getRemovePath(const long homeID, const long deviceID) {
    return getHomeDevicePath(homeID, deviceID) + "/" + REMOVE;
}

static string getUpdatePath(const long homeID, const long deviceID) {
    return getHomeDevicePath(homeID, deviceID) + "/" + UPDATE;
}

#endif  // BARTOS_HW_MQTT_PATH_H