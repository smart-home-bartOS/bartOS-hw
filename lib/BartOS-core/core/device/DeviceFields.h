#ifndef DEVICE_FIELDS_H
#define DEVICE_FIELDS_H

#include <string>
#include <vector>
using namespace std;

class DeviceFields {
   public:
    static const string ID;
    static const string NAME;
    static const string CAPABILITIES;
    static const string HOME_ID;
    static const string ROOM_ID;
    static const string UUID;
    static const string DEVICE_ID;

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

const string DeviceFields::ID = "id";
const string DeviceFields::NAME = "name";
const string DeviceFields::CAPABILITIES = "capabilities";
const string DeviceFields::HOME_ID = "homeID";
const string DeviceFields::ROOM_ID = "roomID";
const string DeviceFields::UUID = "uuid";
const string DeviceFields::DEVICE_ID = "deviceID";

#endif  //DEVICE_FIELDS_H