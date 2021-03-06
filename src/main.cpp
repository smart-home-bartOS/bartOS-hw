using namespace std;
#include <SPI.h>

#include <memory>

#include "GeneralDeps.h"
#include "HttpClient.h"
#include "HttpManageDeviceConn.h"
#include "capabilities.h"
#include "device/OnlineDevice.h"
#include "device/connector/DataConnector.h"
#include "mqtt/MessageForwarder.h"
#include "wifiUtils/WifiUtils.h"

WiFiClient espClient;
PubSubClient clientPub(espClient);
MqttClient client(clientPub);
WiFiManager wifiManager;
WifiUtils wifiUtils(wifiManager);
HttpClient httpClient;

const char *CONFIG_FILE = "/config.json";

Device device;
MessageForwarder forwarder;

shared_ptr<ManageConnector> manage = make_shared<HttpManageDeviceConn>();
OnlineDevice onlineDevice(manage);

void saveConfigCallback() {
    wifiUtils.setShouldSaveConfig(true);
}

void forwardMessages(char *topic, byte *payload, unsigned int length) {
    DynamicJsonDocument doc(1024);
    DeserializationError err = deserializeJson(doc, payload, length);
    if (err) {
        Serial.println(err.c_str());
        return;
    }

    forwarder.forwardMessage(topic, doc);
    doc.garbageCollect();
}

void setup() {
    Serial.begin(9600);

    wifiUtils.shouldClearStates(shouldClearState);
    wifiManager.setSaveConfigCallback(saveConfigCallback);
    wifiUtils.begin();

    client.init(device.getBrokerURL());
    client.getMQTT().setCallback(forwardMessages);

    httpClient.setServerURL(device.getServerURL());

    device.setCapabilities(createdCaps);
    device.initAllCapabilities();

    if (!wifiUtils.alreadyDeviceCreated()) {
        device.publishCreateMessage();
        wifiUtils.setShouldSaveConfig(false);
    } else {
        device.publishConnectMessage();
    }
}

void loop() {
    client.checkAvailability();
    device.executeAllCapabilities();
    delay(10);
}