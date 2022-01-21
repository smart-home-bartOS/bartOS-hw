#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFiClient.h>

#include "Capabilities.h"
#include "Credentials.h"

WiFiClient espClient;
PubSubClient clientPub(espClient);
shared_ptr<MqttClient> MqttDataConnector = make_shared<MqttClient>(clientPub, MQTT_USERNAME, MQTT_PASSWORD);

shared_ptr<BasicWifiManager> WifiManager = make_shared<BasicWifiManager>(SSID, WIFI_PASSWORD);
vector<shared_ptr<Capability>> Capabilities;
shared_ptr<Device> device = make_shared<Device>("RGB-relay-device");
shared_ptr<DefaultOnlinePowerCap> RgbRelay = make_shared<DefaultOnlinePowerCap>(MqttDataConnector,
                                                                                RGB_RELAY_PIN);

void setup() {
    Serial.begin(9600);
    delay(100);

    device->setCapabilities(Capabilities);

    device->init();
}

void loop() {
    device->loop();
}