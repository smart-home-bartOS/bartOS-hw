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
    Serial.println("MQTT Client Broker initialized");
    connect();
    PubSubDataConnector::init();
}

bool MqttClientBroker::subscribe(const string &topic) {
    Serial.printf("Subscribe topic '%s'\n", topic.c_str());
    uMQTTBroker::subscribe(topic.c_str());
}

void MqttClientBroker::connect() {
    uMQTTBroker::init();
}

void MqttClientBroker::disconnect() {
    uMQTTBroker::cleanupClientConnections();
}

bool MqttClientBroker::printReceivedData() {
    return _printReceivedData;
}

void MqttClientBroker::setPrintReceivedData(bool state) {
    _printReceivedData = state;
}
/*
void MqttClientBroker::onData(String topic, const char *data, uint32_t length) {
    char data_str[length+1];
    os_memcpy(data_str, data, length);
    data_str[length] = '\0';

    Serial.println("HERE");
    if (printReceivedData()) {
        Serial.println("-- DATA --");
        Serial.printf("Topic: %s\n", topic.c_str());
        Serial.printf("Length: %d\n", length);
        Serial.printf("Data: %s\n", data_str);
    }

    PubSubDataConnector::handleData(topic.c_str(), data_str, length);
}*/

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

void MqttClientBroker::addAuthUser(const string &username, const string &password) {
    _authUsers.insert({username, password});
}

void MqttClientBroker::removeAuthUser(const string &username) {
    _authUsers.erase(username);
}

bool MqttClientBroker::authenticateUser(const string &username, const string &password) {
    auto it = _authUsers.find(username);
    if (it != _authUsers.end()) {
        return it->second == password;
    }

    return false;
}

bool MqttClientBroker::authenticateUser(const char *username, const char *password) {
    string __username = username;
    string __password = password;
    return authenticateUser(__username, __password);
}