//
// Created by mabartos on 4/29/21.
//

#include "MqttClientBroker.h"

MqttClientBroker::MqttClientBroker(uint16_t port,
                                   uint16_t maxSubscriptions,
                                   uint16_t maxRetainedTopics) :
        uMQTTBroker(port, maxSubscriptions, maxRetainedTopics), PubSubDataConnector() {
}

void MqttClientBroker::init() {
    Serial.println("MQTT Client Broker initialize");
    uMQTTBroker::init();
    PubSubDataConnector::init();
}

void MqttClientBroker::connect() {
    uMQTTBroker::init();
}

void MqttClientBroker::disconnect() {
    uMQTTBroker::cleanupClientConnections();
}

void MqttClientBroker::onData(String topic, const char *data, uint32_t length) {
    PubSubDataConnector::handleData(topic.c_str(), data, length);
}

void MqttClientBroker::sendData(const string &path, DynamicJsonDocument data) {
    String output;
    String pathString(path.c_str());
    serializeJson(data, output);
    uMQTTBroker::publish(pathString, output);
}

uint16_t MqttClientBroker::getPort() {
    return _port;
}

void MqttClientBroker::setPort(uint16_t port) {
    if (_port == port)return;
    _port = port;
    uMQTTBroker::init();
}

uint16_t MqttClientBroker::getMaxSubscriptions() {
    return _maxSubscriptions;
}

void MqttClientBroker::setMaxSubscriptions(uint16_t maxSubs) {
    if (_maxSubscriptions == maxSubs) return;
    _maxSubscriptions = maxSubs;
    uMQTTBroker::init();
}

uint16_t MqttClientBroker::getMaxRetainedTopics() {
    return _maxRetainedTopics;
}

void MqttClientBroker::setMaxRetainedTopics(uint16_t maxRetainedTopics) {
    if (_maxRetainedTopics == maxRetainedTopics) return;
    _maxRetainedTopics = maxRetainedTopics;
    uMQTTBroker::init();
}

void MqttClientBroker::setAllowedUsername(const string &username) {
    _allowedUsername = username;
}

void MqttClientBroker::setAllowedPassword(const string &password) {
    _allowedPassword = password;
}