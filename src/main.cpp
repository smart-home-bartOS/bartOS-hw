using namespace std;

#include <Arduino.h>

#include <memory>
#include <vector>
#include <PubSubClient.h>
#include <WiFiClient.h>
#include <mqtt-data/MqttClient.h>
#include <http-manage/HttpClient.h>
#include <wifi-manager/BartOsWifiManager.h>
#include <online-device/device/connector/DataConnector.h>
#include <online-device/device/connector/ManageConnector.h>
#include <http-manage/HttpManageDeviceConn.h>
#include <online-device/device/OnlineDevice.h>
#include <temp-online/TemperatureOnline.h>
#include <core/capability/Capability.h>

WiFiClient espClient;
PubSubClient clientPub(espClient);

// Connectors
HttpManageDeviceConn httpDeviceConnector("serverURL");
MqttClient mqttDataConnector(clientPub);

BartOsWifiManager wifiManager;

const char *CONFIG_FILE = "/config.json";

OnlineDevice onlineDevice(httpDeviceConnector, mqttDataConnector);
TemperatureCap temp(D7);

vector<reference_wrapper<Capability>> createdCaps{temp};

void setup() {
    Serial.begin(9600);



    wifiManager.begin();

    onlineDevice.initAllCapabilities();
}

void loop() {
    onlineDevice.executeAllCapabilities();
}