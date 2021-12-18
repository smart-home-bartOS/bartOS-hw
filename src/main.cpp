#include <Arduino.h>

#include <memory>

#include "callback/ActionMap.h"
#include "device/Device.h"

using namespace std;

vector<shared_ptr<Capability>> capabilities;
shared_ptr<Device> device;

void setup() {
    Serial.begin(9600);
    delay(100);
    device = make_shared<Device>();

    device->setCapabilities(capabilities);
    device->init();
}

void loop() {
    device->loop();
}