#ifndef DEVICE_FIELDS_H
#define DEVICE_FIELDS_H

#include <string>
#include <vector>

using namespace std;

class DeviceFields {
public:
    static const char* ID;
    static const char* NAME;
    static const char* CAPABILITIES;
    static const char* HOME_ID;
    static const char* ROOM_ID;
    static const char* UUID;
    static const char* DEVICE_ID;

    static const vector<string> getDeviceFields() {
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

const char* DeviceFields::ID = "id";
const char* DeviceFields::NAME = "name";
const char* DeviceFields::CAPABILITIES = "capabilities";
const char* DeviceFields::HOME_ID = "homeID";
const char* DeviceFields::ROOM_ID = "roomID";
const char* DeviceFields::UUID = "uuid";
const char* DeviceFields::DEVICE_ID = "deviceID";

#endif  //DEVICE_FIELDS_H