#include "TemperatureCap.h"

#include <Adafruit_Sensor.h>
#include <DHT.h>

DHT dht;

TemperatureCap::TemperatureCap(const uint8_t &pin) {
}
TemperatureCap(const uint8_t &pin, const string &name);
TemperatureCap(const uint8_t &pin, const unsigned sampleTime);
TemperatureCap::TemperatureCap(const uint8_t &pin, const string &name, const unsigned sampleTime){
    

}

TemperatureCap::TemperatureCap(const string &name,
                               const uint8_t &pin,
                               const unsigned sampleTime) : Capability(name, pin, CapabilityType::TEMPERATURE, sampleTime) {
    setUnits("°C");
}
TemperatureCap::TemperatureCap(const string &name, const uint8_t &pin) : Capability(name, pin, CapabilityType::TEMPERATURE, DEFAULT_SAMPLE_TIME_MS) {
    setUnits("°C");
}

void TemperatureCap::init() {
    dht.begin();
    Serial.print("INIT TEMP = ");
    Serial.println(getName().c_str());
}

void TemperatureCap::execute() {
    float temp = dht.readTemperature();

    if (!isnan(temp)) {
        setTemperature(temp);
    }
}

float TemperatureCap::getTemperature() {
    return _temp;
}

void TemperatureCap::setTemperature(const float &temp) {
    _temp = temp;
}

string TemperatureCap::getUnits() {
    return _units;
}

void TemperatureCap::setUnits(const string &units) {
    _units = units;
}