#include <Arduino.h>

#include "Capabilities.h"

vector<shared_ptr<Capability>> capabilities;

void setup() {
    Serial.begin(9600);
    delay(100);

    device->disableCapabilities();

    kitchenMainLights->setEnabled(true);
    LivingRoomIrReceiver->setEnabled(true);

    addAllRules();

    device->setCapabilities(capabilities);
    device->setDataConnector(mqttDataConnector);
    device->init();
}

void loop() {
    device->loop();
}