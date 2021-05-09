#ifndef DEVICE_PATH_H
#define DEVICE_PATH_H

#include <string>
#include <utils/ConvertUtils.h>

using namespace std;

static const string HOMES_PATH = "homes";
static const string ROOMS_PATH = "rooms";
static const string DEVICES_PATH = "devices";

static string getHomePath(const long homeID) {
    return "/" + HOMES_PATH + ConvertUtils::convertLongToString(homeID);
}

static string getRoomPath(const long homeID, const long roomID) {
    return getHomePath(homeID) + "/" + ROOMS_PATH + ConvertUtils::convertLongToString(roomID);
}

static string getHomeDevicePath(const long homeID, const long deviceID) {
    return getHomePath(homeID) + "/" + ConvertUtils::convertLongToString(deviceID);
}

#endif  //DEVICE_PATH_H