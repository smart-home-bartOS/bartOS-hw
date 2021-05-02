#include <Arduino.h>
#include "Capabilities.h"
#include <wifi-basic/BasicWifiManager.h>

shared_ptr<BasicWifiManager> WifiManager = make_shared<BasicWifiManager>();
vector<shared_ptr<Capability>> Capabilities;
shared_ptr<Device> device = make_shared<Device>("Device");

void setup() {
    Serial.begin(9600);
    delay(100);

    WifiManager->disableWifi();

    addAllRules();
    device->setCapabilities(Capabilities);

    device->init();
}

void loop() {
    device->loop();
}