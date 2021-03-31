using namespace std;

#include <Arduino.h>

#include <PubSubClient.h>
#include <WiFiClient.h>
#include <mqtt-data/MqttClient.h>
#include <wifi-manager/BartOsWifiManager.h>
#include <http-manage/HttpManageDeviceConn.h>
#include <online-device/device/OnlineDevice.h>
#include <temp/default/DhtTempSensor.h>
#include "Capabilities.h"

WiFiClient espClient;
PubSubClient clientPub(espClient);

/* Connectors */
HttpManageDeviceConn httpDeviceConnector("serverURL");
MqttClient mqttDataConnector(clientPub);

/* WiFi Management */
WiFiManager externalWifiManager;
BartOsWifiManager wifiManager(externalWifiManager);

OnlineDevice onlineDevice(CAPABILITIES, httpDeviceConnector, mqttDataConnector);

void setup() {
    Serial.begin(9600);
    wifiManager.begin();
    onlineDevice.initAllCapabilities();
    setupCapabilityEvent();
}

void loop() {
    onlineDevice.executeAllCapabilities();
}