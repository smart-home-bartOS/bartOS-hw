using namespace std;

#include <Arduino.h>
#include <online-device/device/OnlineDevice.h>
#include "Capabilities.h"

vector<shared_ptr<Capability>> Capabilities;

OnlineDevice device(Capabilities, HttpDeviceConnector, MqttDataConnector);

void setup() {
    Serial.begin(9600);
    delay(100);

    device.initAllCapabilities();
    setupAllCapabilities();
}

void loop() {
    device.executeAllCapabilities();
}