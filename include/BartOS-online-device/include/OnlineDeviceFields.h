#ifndef ONLINE_DEVICE_FIELDS_H
#define ONLINE_DEVICE_FIELDS_H
using namespace std;

#include <string>
#include <device/DeviceFields.h>

class OnlineDeviceFields : public DeviceFields {
public:
    static const char *CONNECT;
    static const char *DISCONNECT;
    static const char *CREATE;

    static vector <string> getCreateFields() {
        return vector < string > {
                ID,
                NAME,
                CAPABILITIES};
    };

    static vector <string> getConnectFields() {
        return vector < string > {
                ID,
                NAME,
                CAPABILITIES};
    };
};

#endif  //ONLINE_DEVICE_FIELDS_H