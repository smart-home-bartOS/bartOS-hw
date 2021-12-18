#include <Arduino.h>
#include "Capabilities.h"
#include "BasicWifiManager.h"
#include "Credentials.h"

shared_ptr<BasicWifiManager> WifiManager = make_shared<BasicWifiManager>(SSID, WIFI_PASSWORD);
vector<shared_ptr<Capability>> Capabilities;
shared_ptr<Device> device = make_shared<Device>("Device");

void setup() {
    Serial.begin(9600);
    delay(100);

    device->disableAllCapabilities();
    WifiManager->connect();

    MqttBroker->addAuthUser(MQTT_USERNAME, MQTT_PASSWORD);
    MqttBroker->setPrintReceivedData(true);
    MqttBroker->addTopicContext("ahoj", [](JsonObject &data) -> void {
        Serial.println("HERE");
    });
    MqttBroker->subscribe("#");
    MqttBroker->init();

    addAllRules();
    device->setCapabilities(Capabilities);

    device->init();
}

void loop() {
    device->loop();
}