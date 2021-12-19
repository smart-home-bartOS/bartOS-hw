#ifndef BARTOS_HW_JSON_KEYS_H
#define BARTOS_HW_JSON_KEYS_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class JsonKeys {
   public:
    static const char *ENABLED;
    static const char *PIN;
    static const char *TYPE;
    static const char *NAME;

    static const char *ID;
    static const char *CAPABILITIES;
    static const char *COUNT_OF_CAPS;
    static const char *HOME_ID;
    static const char *ROOM_ID;
    static const char *UUID;
    static const char *DEVICE_ID;
};
#endif  // BARTOS_HW_JSON_KEYS_H