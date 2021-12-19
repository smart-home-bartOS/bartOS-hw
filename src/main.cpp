#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFiClient.h>

#include <memory>

#include "HttpConnector.h"
#include "MqttClient.h"
#include "callback/ActionMap.h"
#include "default/DefaultHttpClient.h"
#include "default/DhtHumOnline.h"
#include "default/DhtTempOnline.h"
#include "default/two-way-button/OnlineTwoWayButton.h"
#include "device/Device.h"
#include "device/OnlineDevice.h"

using std::make_shared;

vector<shared_ptr<Capability>> capabilities;
shared_ptr<Device> device;
shared_ptr<OnlineDevice> onlineDevice;

shared_ptr<OnlineTwoWayButton> btn;
shared_ptr<DhtTempOnline> temp;
shared_ptr<DhtHumOnline> hum;

WiFiClient espClient;
PubSubClient clientPub(espClient);
shared_ptr<MqttClient> MqttDataConnector = make_shared<MqttClient>(clientPub, "url");
// shared_ptr<DefaultHttpClient> httpClient = make_shared<DefaultHttpClient>(espClient, "url");

DefaultHttpClient httpClient(espClient, "asd");
HttpConnector httpConnector(httpClient, "url");

void setup() {
    Serial.begin(9600);
    delay(100);
    device = make_shared<Device>();
    onlineDevice = make_shared<OnlineDevice>();
    btn = make_shared<OnlineTwoWayButton>(1);

    device->setCapabilities(capabilities);
    device->init();
}

void loop() {
    device->loop();
}