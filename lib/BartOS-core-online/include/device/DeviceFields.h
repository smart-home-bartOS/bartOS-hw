#ifndef DEVICE_FIELDS_H
#define DEVICE_FIELDS_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class DeviceFields {
   public:
    static const char *ID;
    static const char *NAME;
    static const char *CAPABILITIES;
    static const char *HOME_ID;
    static const char *ROOM_ID;
    static const char *UUID;
    static const char *DEVICE_ID;

    static vector<string> getDeviceFields() {
        return vector<string>{
            ID,
            NAME,
            CAPABILITIES,
            HOME_ID,
            ROOM_ID,
            UUID,
            DEVICE_ID};
    }
};

#endif  // DEVICE_FIELDS_H