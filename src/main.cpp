using namespace std;
#include <SPI.h>

#include <memory>

#include "http-manage/HttpClient.h"
#include "http-manage/HttpManageDeviceConn.h"
#include "mqtt-data/MqttClient.h"
#include "online-device/device/OnlineDevice.h"
#include "wifi-manager/BartOsWifiManager.h"

WiFiClient espClient;
PubSubClient clientPub(espClient);
MqttClient client(clientPub);
HttpClient httpClient;
BartOsWifiManager wifiManager;

const char *CONFIG_FILE = "/config.json";

shared_ptr<DataConnector> dataConnector = make_shared<MqttClient>(clientPub);
shared_ptr<ManageConnector> manageConnector = make_shared<HttpManageDeviceConn>("serverURL");

OnlineDevice onlineDevice(manageConnector, dataConnector);

void forwardMessages(char *topic, byte *payload, unsigned int length) {
    DynamicJsonDocument doc(1024);
    DeserializationError err = deserializeJson(doc, payload, length);
    if (err) {
        Serial.println(err.c_str());
        return;
    }

    //forwarder.forwardMessage(topic, doc);
    doc.garbageCollect();
}

void setup() {
    Serial.begin(9600);

    wifiManager.begin();

    onlineDevice.setCapabilities(createdCaps);
    onlineDevice.initAllCapabilities();
}

void loop() {
    onlineDevice.executeAllCapabilities();
    delay(10);
}