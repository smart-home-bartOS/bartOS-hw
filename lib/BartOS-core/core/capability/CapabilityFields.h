#ifndef CAPABILITY_FIELDS_H
#define CAPABILITY_FIELDS_H

#include <string>
#include <vector>
using namespace std;

class CapabilityFields {
   public:
    static const string ID;
    static const string NAME;
    static const string PIN;
    static const string TYPE;
    static const string CAPABILITIES;

    static const vector<string> getFields() {
        return vector<string>{
            ID,
            NAME,
            PIN,
            TYPE};
    }
};

const string CapabilityFields::ID = "id";
const string CapabilityFields::NAME = "name";
const string CapabilityFields::PIN = "pin";
const string CapabilityFields::TYPE = "type";
const string CapabilityFields::CAPABILITIES = "capabilities";

#endif  //CAPABILITY_FIELDS_H