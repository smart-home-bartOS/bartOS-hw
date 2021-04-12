#ifndef CAPABILITY_TYPE_H
#define CAPABILITY_TYPE_H
using namespace std;

#include <string>
#include <vector>

class CapabilityType {
public:
    static const char *TEMPERATURE;
    static const char *HUMIDITY;
    static const char *HEATER;
    static const char *BUTTON;
    static const char *LIGHT;
    static const char *RELAY;
    static const char *SOCKET;
    static const char *PIR;
    static const char *GAS_SENSOR;
    static const char *AIR_CONDITIONER;
    static const char *INFRA_RED;
    static const char *OTHER;

    static const vector<string> getAllCapabilities() {
        return vector<string>{
                CapabilityType::TEMPERATURE,
                CapabilityType::HUMIDITY,
                CapabilityType::HEATER,
                CapabilityType::BUTTON,
                CapabilityType::LIGHT,
                CapabilityType::RELAY,
                CapabilityType::SOCKET,
                CapabilityType::PIR,
                CapabilityType::GAS_SENSOR,
                CapabilityType::AIR_CONDITIONER,
                CapabilityType::INFRA_RED,
                CapabilityType::OTHER};
    };
};


#endif  //CAPABILITY_TYPE_H