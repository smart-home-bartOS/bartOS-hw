#include "MqttClient.h"

#include "ESP8266TrueRandom.h"
#include "MqttTopics.h"

MqttClient::MqttClient(PubSubClient &mqttClient) : PubSubDataConnector(), _mqttClient(mqttClient) {
    _lastReconnectAttempt = 0;
}

void MqttClient::init(const string &brokerURL, const uint16_t &port) {
    _brokerURL = brokerURL;
    _port = port;
    _mqttClient.setServer(_brokerURL.c_str(), _port);
    reconnect();
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
    if (!_mqttClient.connect(getUUID().c_str(),
                             getLastWillMessage().c_str(),
                             getLastWillQos(),
                             isLastWillRetain(),
                             getLastWillMessage().c_str())) {
        Serial.println("Cannot connect MQTT client");
        return false;
    }
    Serial.print(".");

    _mqttClient.setCallback([this](char *topic, uint8_t *payload, unsigned int length) -> void {
        DynamicJsonDocument doc(length + 50);
        DeserializationError err = deserializeJson(doc, payload, length);
        if (err) {
            Serial.println(err.c_str());
            return;
        }

        executeTopicContext(topic, doc);
        doc.garbageCollect();
    });

    return _mqttClient.connected();
}

void MqttClient::checkAvailability() {
    if (!_mqttClient.connected()) {
        unsigned long now = millis();
        if (now - _lastReconnectAttempt > 3000) {
            _lastReconnectAttempt = now;
            if (reconnect()) {
                _lastReconnectAttempt = 0;

                //TODO check validity
            }
        }
    } else {
        _mqttClient.loop();
    }
}

string MqttClient::getBrokerURL() {
    return _brokerURL;
}

void MqttClient::setBrokerURL(const string &brokerURL) {
    _brokerURL = brokerURL;
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

void MqttClient::executeTopicContext(char *topic, DynamicJsonDocument doc) {
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