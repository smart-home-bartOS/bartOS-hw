#ifndef ONLINE_DEVICE_FIELDS_H
#define ONLINE_DEVICE_FIELDS_H

#include <string>

#include "core/device/DeviceFields.h"
using namespace std;

class OnlineDeviceFields : public DeviceFields {
   public:
    static const string CONNECT;
    static const string DISCONNECT;
    static const string CREATE;

    static const vector<string> getCreateFields() {
        return vector<string>{
            ID,
            NAME,
            CAPABILITIES};
    }

    static const vector<string> getConnectFields() {
        return vector<string>{
            ID,
            NAME,
            CAPABILITIES};
    }
};

const string OnlineDeviceFields::CONNECT = "connect";
const string OnlineDeviceFields::DISCONNECT = "disconnect";
const string OnlineDeviceFields::CREATE = "create";

#endif  //ONLINE_DEVICE_FIELDS_H