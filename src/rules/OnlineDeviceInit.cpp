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
shared_ptr<DefaultWifiManager> WifiManager = make_shared<DefaultWifiManager>();

shared_ptr<BartFS> StorageManager = make_shared<BartFS>();

shared_ptr<OnlineDevice> Device = make_shared<OnlineDevice>(HttpDeviceConnector, MqttDataConnector);

void setUpWifiManager() {
    WifiManager->begin();

    Device->setCredentials(WifiManager->getCredentials());
    Device->getDataConnector()->setUrl(WifiManager->getBrokerUrl());
    Device->getManageConnector()->setUrl(WifiManager->getServerUrl());

    Device->setName(WifiManager->getDeviceName());
    Device->setHomeID(WifiManager->getHomeID());
    Device->setRoomID(WifiManager->getRoomID());
}
