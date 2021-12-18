#ifndef CAPABILITY_FIELDS_H
#define CAPABILITY_FIELDS_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class CapabilityFields {
   public:
    static const char *ID;
    static const char *NAME;
    static const char *PIN;
    static const char *TYPE;
    static const char *CAPABILITIES;

    static vector<string> getFields() {
        return vector<string>{
            ID,
            NAME,
            PIN,
            TYPE};
    }
};

#endif  // CAPABILITY_FIELDS_H