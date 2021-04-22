#include <Arduino.h>
#include "Capabilities.h"
vector<shared_ptr<Capability>> Capabilities;
void setup() {
    Serial.begin(9600);
    delay(100);
    //WifiManager->reset();
    Device->disableAllCapabilities();
    KitchenMainLights->setEnabled(true);

    addAllRules();
    Device->getDataConnector()->setUrl("192.168.0.158");
    Device->setName("MyDevice");
    Device->setHomeID(10);
    Device->setRoomID(25);
    Device->setCapabilities(Capabilities);
    Device->init();
}

void loop() {
    Device->loop();
}