#ifndef DEVICE_FIELDS_H
#define DEVICE_FIELDS_H

#include <string>
using namespace std;

const string& ID = "id";
const string& NAME = "name";
const string& CAPABILITIES = "capabilities";
const string& HOME_ID = "homeID";
const string& ROOM_ID = "roomID";
const string& UUID = "uuid";
const string& DEVICE_ID = "deviceID";

const vector<string> DEVICE_FIELDS{
    ID,
    NAME,
    CAPABILITIES,
    HOME_ID,
    ROOM_ID,
    UUID,
    DEVICE_ID};

#endif  //DEVICE_FIELDS_H