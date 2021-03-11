#include "TemperatureCap.h"

#include <Adafruit_Sensor.h>
#include <DHT.h>

DHT dht;

TemperatureCap::TemperatureCap(const string &name,
                               const uint8_t &pin,
                               const unsigned sampleTime) : CapabilityWithValue(name, pin, CapabilityType::TEMPERATURE, sampleTime) {
    setUnits("°C");
}
TemperatureCap::TemperatureCap(const string &name, const uint8_t &pin) : CapabilityWithValue(name, pin, CapabilityType::TEMPERATURE, DEFAULT_SAMPLE_TIME_MS) {
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
        setValue((double)temp);
    }
}