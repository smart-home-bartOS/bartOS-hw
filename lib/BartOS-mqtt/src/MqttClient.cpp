#include "MqttClient.h"

#include <utils/RandomGenerator.h>

#include "MqttPath.h"
#include "device/OnlineDevice.h"

MqttClient::MqttClient(PubSubClient &mqttClient,
                       const string &baseURL,
                       const string &username,
                       const string &password)
    : DataConnector(baseURL),
      ManageConnector(baseURL),
      _mqttClient(mqttClient),
      _username(username),
      _password(password) {
    _uuid = "MqttClient-" + RandomGenerator::randomNumber(6);
}

void MqttClient::init() {
    if (DataConnector::getBaseURL() == "") {
        Serial.println("You have to define Broker URL");
        return;
    }
    printMqttInfo();
    _mqttClient.setServer(DataConnector::getBaseURL().c_str(), _port);
    reconnect();
}

void MqttClient::loop() {
    checkAvailability();
}

OnlineDevice *MqttClient::device() {
    return DataConnector::getOnlineDevice();
}

void MqttClient::sendData(const string &path, DynamicJsonDocument &data) {
    if (path.empty()) return;
    char buffer[600];

    size_t size = serializeJson(data, buffer);
    data.shrinkToFit();
    data.garbageCollect();

    getMqttClient().publish(path.c_str(), buffer, size);
}

void MqttClient::subscribe(const string &path, shared_ptr<DataHandler> handler) {
    DataConnector::subscribe(path, handler);
    getMqttClient().subscribe(path.c_str());
};

void MqttClient::unsubscribe(const string &path) {
    DataConnector::unsubscribe(path);
    getMqttClient().unsubscribe(path.c_str());
};

string MqttClient::getUUID() {
    return _uuid;
}

void MqttClient::setUUID(const string &UUID) {
    _uuid = UUID;
}

bool MqttClient::reconnect() {
    Serial.printf("Attempting MQTT connection after %lu ms.\n", getTryConnectPeriodMs());
    Serial.printf("Client UUID: %s\n", getUUID().c_str());

    if (!_mqttClient.connect(getUUID().c_str(),
                             _username.c_str(),
                             _password.c_str()
                             /* USE LATELY; DOESN'T WORK WITH MOSQUITTO
                             getLastWillMessage().c_str(),
                             getLastWillQos(),
                             isLastWillRetain(),
                             getLastWillMessage().c_str())*/
                             )) {
        Serial.println("Cannot connect MQTT client");
        return false;
    }

    _mqttClient.setCallback([this](char *topic, uint8_t *payload, unsigned int length) -> void {
        DynamicJsonDocument doc(length);
        deserializeJson(doc, payload);
        doc.shrinkToFit();
        doc.garbageCollect();

        notify(topic, doc);
    });

    Serial.print("MQTT Client Connected : ");
    Serial.println(getUUID().c_str());

    for (auto &item : getDataHandlersKeys()) {
        Serial.printf("Subscribe '%s'\n", item.c_str());
        _mqttClient.subscribe(item.c_str());
    }

    return _mqttClient.connected();
}

void MqttClient::disconnectClient() {
    _mqttClient.disconnect();
}

void MqttClient::checkAvailability() {
    if (!_mqttClient.connected()) {
        unsigned long now = millis();
        if (now - _lastReconnectAttempt > getTryConnectPeriodMs()) {
            _lastReconnectAttempt = now;
            if (reconnect()) {
                _lastReconnectAttempt = 0;
            }
        }
    } else {
        _mqttClient.loop();
    }
}

PubSubClient &MqttClient::getMqttClient() {
    return _mqttClient;
}

string MqttClient::getLastWillTopic() {
    return _lastWillTopic;
}

void MqttClient::setLastWillTopic(const string &topic) {
    _lastWillTopic = topic;
}

uint8_t MqttClient::getLastWillQos() {
    return _lastWillQos;
}

void MqttClient::setLastWillQos(uint8_t qos) {
    _lastWillQos = qos;
}

bool MqttClient::isLastWillRetain() {
    return _lastWillRetain;
}

void MqttClient::setLastWillRetain(bool state) {
    _lastWillRetain = state;
}

string MqttClient::getLastWillMessage() {
    return _lastWillMessage;
}

void MqttClient::setLastWillMessage(const string &message) {
    _lastWillMessage = message;
}

unsigned long MqttClient::getTryConnectPeriodMs() {
    return _tryConnectPeriodMs;
}

void MqttClient::setTryConnectPeriodMs(unsigned long period) {
    _tryConnectPeriodMs = period;
}

void MqttClient::printMqttInfo() {
    Serial.println("MQTT Info");
    Serial.print("Broker URL: ");
    Serial.println(DataConnector::getBaseURL().c_str());
    Serial.print("Broker Port: ");
    Serial.println(_port);
}

void MqttClient::setUsername(const string &username) {
    _username = username;
}

void MqttClient::setPassword(const string &password) {
    _password = password;
}

void MqttClient::connect() {
    DynamicJsonDocument data = device()->getInfo();
    const string &connectPath = getConnectPath(device()->getHomeID(), device()->getID());
    sendData(connectPath, data);
}

void MqttClient::disconnect() {
    DynamicJsonDocument data(5);
    const string &disconnectPath = getDisconnectPath(device()->getHomeID(), device()->getID());
    sendData(disconnectPath, data);
}

void MqttClient::create() {
    DynamicJsonDocument data = device()->getInfoWithCaps();
    const string &createPath = getCreatePath(device()->getHomeID());
    sendData(createPath, data);
};

void MqttClient::remove() {
    DynamicJsonDocument data(5);
    const string &removePath = getRemovePath(device()->getHomeID(), device()->getID());
    sendData(removePath, data);
};

void MqttClient::update() {
    DynamicJsonDocument data = device()->getInfoWithCaps();
    const string &updatePath = getUpdatePath(device()->getHomeID(), device()->getID());
    sendData(updatePath, data);
};