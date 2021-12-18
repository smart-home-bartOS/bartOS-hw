#include <Arduino.h>

#include <memory>

#include "callback/ActionMap.h"
#include "device/Device.h"
#include "device/OnlineDevice.h"

using namespace std;

vector<shared_ptr<Capability>> capabilities;
shared_ptr<Device> device;
shared_ptr<OnlineDevice> onlineDevice;

void setup() {
    Serial.begin(9600);
    delay(100);
    device = make_shared<Device>();
    onlineDevice = make_shared<OnlineDevice>();

    device->setCapabilities(capabilities);
    device->init();
}

void loop() {
    device->loop();
}