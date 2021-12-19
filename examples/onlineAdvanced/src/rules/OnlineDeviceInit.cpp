//
// Created by mabartos on 4/19/21.
//

#include <PubSubClient.h>
#include <WiFiClient.h>

#include "Capabilities.h"

WiFiClient espClient;
PubSubClient clientPub(espClient);

shared_ptr<MqttClient> mqttDataConnector = make_shared<MqttClient>(clientPub, "url");

shared_ptr<OnlineDevice> device = make_shared<OnlineDevice>();
