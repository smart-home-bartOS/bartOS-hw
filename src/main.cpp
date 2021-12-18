#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFiClient.h>

#include <memory>

#include "HttpConnector.h"
#include "MqttClient.h"
#include "callback/ActionMap.h"
#include "device/Device.h"
#include "device/OnlineDevice.h"

using std::make_shared;

vector<shared_ptr<Capability>> capabilities;
shared_ptr<Device> device;
shared_ptr<OnlineDevice> onlineDevice;

WiFiClient espClient;
PubSubClient clientPub(espClient);
shared_ptr<MqttClient> MqttDataConnector = make_shared<MqttClient>(clientPub, "url");
shared_ptr<HttpConnector> connector = make_shared<HttpConnector>("asd");

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