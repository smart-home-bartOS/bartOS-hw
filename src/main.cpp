using namespace std;

#include <Arduino.h>
#include <core/device/Device.h>
#include "Capabilities.h"

Device device(CAPABILITIES);

void setup() {
    Serial.begin(9600);
    delay(100);

    device.initAllCapabilities();
    setupCapabilityEvent();
}

void loop() {
    device.executeAllCapabilities();
}