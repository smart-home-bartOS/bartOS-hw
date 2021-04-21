#include <Arduino.h>
#include "Capabilities.h"

void setup() {
    Serial.begin(9600);
    delay(100);
    WifiManager->reset();
    Device->disableAllCapabilities();
    KitchenMainLights->setEnabled(true);

    setUpWifiManager();
    /*addAllRules();

    Device->init();*/
}

void loop() {
    Device->loop();
}