#include <Arduino.h>
#include <memory>
#include <core/device/Device.h>

using namespace std;

vector<shared_ptr<Capability>> Capabilities;
shared_ptr<Device> Device=make_shared<Device>();

void setup() {
    Serial.begin(9600);
    delay(100);

    Device->setCapabilities(Capabilities);
    Device->init();
}

void loop() {
    Device->loop();
}