#include <Arduino.h>
#include <online-device/device/OnlineDevice.h>
#include <wifi-manager/BartOsWifiManager.h>
#include "Capabilities.h"

vector<shared_ptr<Capability>> Capabilities;
shared_ptr<BartOsWifiManager> WifiManager = make_shared<BartOsWifiManager>();
shared_ptr<OnlineDevice> Device = make_shared<OnlineDevice>(Capabilities, HttpDeviceConnector, MqttDataConnector);

void setup() {
    Serial.begin(9600);
    delay(100);

    WifiManager->begin();
    Device->setCredentials(WifiManager->getCredentials());
    addAllRules();
    Device->init();
}

void loop() {
    Device->loop();
}