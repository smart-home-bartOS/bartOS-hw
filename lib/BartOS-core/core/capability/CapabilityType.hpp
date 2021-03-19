#ifndef CAPABILITY_TYPE_H
#define CAPABILITY_TYPE_H
using namespace std;

#include <string>
#include <vector>

class CapabilityType {
public:
    static const string TEMPERATURE;
    static const string HUMIDITY;
    static const string HEATER;
    static const string EXTERN_BTN;
    static const string LIGHT;
    static const string RELAY;
    static const string SOCKET;
    static const string PIR;
    static const string GAS_SENSOR;
    static const string AIR_CONDITIONER;
    static const string OTHER;

    static const vector<string> getAllCapabilities() {
        return vector<string>{
                CapabilityType::TEMPERATURE,
                CapabilityType::HUMIDITY,
                CapabilityType::HEATER,
                CapabilityType::EXTERN_BTN,
                CapabilityType::LIGHT,
                CapabilityType::RELAY,
                CapabilityType::SOCKET,
                CapabilityType::PIR,
                CapabilityType::GAS_SENSOR,
                CapabilityType::AIR_CONDITIONER,
                CapabilityType::OTHER};
    };
};

const string CapabilityType::HUMIDITY = "hum";
const string CapabilityType::HEATER = "heat";
const string CapabilityType::EXTERN_BTN = "btn";
const string CapabilityType::LIGHT = "light";
const string CapabilityType::RELAY = "relay";
const string CapabilityType::SOCKET = "socket";
const string CapabilityType::PIR = "pir";
const string CapabilityType::GAS_SENSOR = "gas";
const string CapabilityType::AIR_CONDITIONER = "ac";
const string CapabilityType::OTHER = "other";

#endif  //CAPABILITY_TYPE_H