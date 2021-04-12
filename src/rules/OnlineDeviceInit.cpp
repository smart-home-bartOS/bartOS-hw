//
// Created by mabartos on 4/19/21.
//

#include "Capabilities.h"
#include <PubSubClient.h>
#include <WiFiClient.h>

WiFiClient espClient;
PubSubClient clientPub(espClient);

shared_ptr<HttpManageDeviceConn> HttpDeviceConnector = make_shared<HttpManageDeviceConn>("serverURL");
shared_ptr<MqttClient> MqttDataConnector = make_shared<MqttClient>(clientPub);
