#include <Arduino.h>
#include "Capabilities.h"

vector<shared_ptr<Capability>> Capabilities;
shared_ptr<Device> device = make_shared<Device>("Device");

void setup() {
    Serial.begin(9600);
    delay(100);

    addAllRules();
    device->setCapabilities(Capabilities);
    device->init();
}

void loop() {
    device->loop();
}