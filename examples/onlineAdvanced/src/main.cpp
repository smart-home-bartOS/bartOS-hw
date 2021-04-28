#include <Arduino.h>
#include "Capabilities.h"

vector<shared_ptr<Capability>> Capabilities;

void setup() {
    Serial.begin(9600);
    delay(100);
    Device->disableAllCapabilities();
    KitchenMainLights->setEnabled(true);
    LivingRoomIrReceiver->setEnabled(true);

    addAllRules();
    Device->setCapabilities(Capabilities);
    Device->init();
}

void loop() {
    Device->loop();
}