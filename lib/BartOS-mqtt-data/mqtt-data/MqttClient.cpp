#include "MqttClient.h"

#include <online-device/utils/PubSubTopics.h>
#include <core/utils/RandomGenerator.h>

MqttClient::MqttClient(PubSubClient &mqttClient) : PubSubDataConnector(),
                                                   _mqttClient(mqttClient) {
    _uuid = "MqttClient-" + RandomGenerator::randomNumber(6);
}

void MqttClient::init() {
    if (getUrl() == "") {
        Serial.println("You have to define Broker URL");
        return;
    }
    printMqttInfo();
    _mqttClient.setServer(getUrl().c_str(), _port);
    reconnect();
}

void MqttClient::loop() {
    checkAvailability();
}

void MqttClient::connect() {
    reconnect();
}

void MqttClient::disconnect() {
    _mqttClient.disconnect();
}

void MqttClient::sendData(const string &path, DynamicJsonDocument data) {
    if (path.empty()) return;
    char buffer[600];

    size_t size = serializeJson(data, buffer);
    data.shrinkToFit();
    data.garbageCollect();

    getMqttClient().publish(path.c_str(), buffer, size);
}

string MqttClient::getUUID() {
    return _uuid;
}

void MqttClient::setUUID(const string &UUID) {
    _uuid = UUID;
}

bool MqttClient::reconnect() {
    Serial.printf("Attempting MQTT connection after %lu ms.\n", getTryConnectPeriodMs());
    Serial.printf("Client UUID: %s\n", getUUID().c_str());

    if (!_mqttClient.connect(getUUID().c_str()/*,       USE LATELY; DOESN'T WORK WITH MOSQUITTO
                             getLastWillMessage().c_str(),
                             getLastWillQos(),
                             isLastWillRetain(),
                             getLastWillMessage().c_str())*/)) {
        Serial.println("Cannot connect MQTT client");
        return false;
    }

    _mqttClient.setCallback([this](char *topic, uint8_t *payload, unsigned int length) -> void {
        StaticJsonDocument<MQTT_MESSAGE_SIZE> doc;
        DeserializationError err = deserializeJson(doc, payload, length);
        if (err) {
            Serial.println(err.c_str());
            return;
        }
        JsonObject obj = doc.as<JsonObject>();
        executeTopicContext(topic, obj);
    });

    Serial.print("MQTT Client Connected : ");
    Serial.println(getUUID().c_str());

    for (auto &topic:getTopicContext()) {
        Serial.printf("Subscribe '%s'\n", topic.first.c_str());
        _mqttClient.subscribe(topic.first.c_str());
    }

    return _mqttClient.connected();
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

void MqttClient::executeTopicContext(char *topic, JsonObject &doc) {
    PubSubDataConnector::executeTopicContext(topic, doc);
}

void MqttClient::addTopicContext(const string &topic, PubSubCallback callback) {
    getMqttClient().subscribe(topic.c_str());
    PubSubDataConnector::addTopicContext(topic, callback);
}

void MqttClient::removeTopicContext(const string &topic) {
    getMqttClient().unsubscribe(topic.c_str());
    PubSubDataConnector::removeTopicContext(topic);
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
    Serial.println(getUrl().c_str());
    Serial.print("Broker Port: ");
    Serial.println(_port);
}