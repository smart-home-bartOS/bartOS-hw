#ifndef ONLINE_DEVICE_FIELDS_H
#define ONLINE_DEVICE_FIELDS_H

#include <string>
#include <core/device/DeviceFields.h>

using namespace std;

class OnlineDeviceFields : public DeviceFields {
public:
    static const char *CONNECT;
    static const char *DISCONNECT;
    static const char *CREATE;

    static vector<string> getCreateFields() {
        return vector<string>{
                ID,
                NAME,
                CAPABILITIES};
    }

    static string[] getConnectFields() {
        return {};
    }
};

#endif  //ONLINE_DEVICE_FIELDS_H