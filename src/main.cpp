using namespace std;
#include <SPI.h>

#include <memory>

#include "http-manage/HttpClient.h"
#include "http-manage/HttpManageDeviceConn.h"
#include "mqtt-data/MqttClient.h"
#include "online-device/device/OnlineDevice.h"
#include "temp-online/TemperatureOnline.h"
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

vector<shared_ptr<Capability>> capabilities{
    make_shared<TemperatureOnline>("temp", 10, dataConnector)};

void setup() {
    Serial.begin(9600);

    wifiManager.begin();

    onlineDevice.setCapabilities(capabilities);
    onlineDevice.initAllCapabilities();
}

void loop() {
    onlineDevice.executeAllCapabilities();
}