#ifndef CAPABILITY_FIELDS_H
#define CAPABILITY_FIELDS_H

#include <string>
#include <vector>

using namespace std;

class CapabilityFields {
public:
    static const char* ID;
    static const char* NAME;
    static const char* PIN;
    static const char* TYPE;
    static const char* CAPABILITIES;

    static vector<string> getFields() {
        return vector<string>{
                ID,
                NAME,
                PIN,
                TYPE};
    }
};

const char* CapabilityFields::ID = "id";
const char* CapabilityFields::NAME = "name";
const char* CapabilityFields::PIN = "pin";
const char* CapabilityFields::TYPE = "type";
const char* CapabilityFields::CAPABILITIES = "capabilities";

#endif  //CAPABILITY_FIELDS_H