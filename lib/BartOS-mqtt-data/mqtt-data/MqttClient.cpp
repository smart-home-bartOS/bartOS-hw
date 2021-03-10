#include "MqttClient.h"

#include "ESP8266TrueRandom.h"
#include "MqttTopics.h"

MqttClient::MqttClient(PubSubClient &mqttClient) : _mqttClient(mqttClient) {
    _lastReconnectAttempt = 0;
}

void MqttClient::init(const string &brokerURL) {
    _brokerURL = brokerURL;
    _mqttClient.setServer(_brokerURL.c_str(), PORT);
    reconnect();
}

void MqttClient::connect() {
    reconnect();
}

void MqttClient::disconnect() {
    _mqttClient.disconnect();
}

void MqttClient::sendData(const string &path, DynamicJsonDocument data) {
    if (path == "")
        return;
    char buffer[600];

    size_t size = serializeJson(data, buffer);
    data.shrinkToFit();
    data.garbageCollect();

    getMQTT().publish(path.c_str(), buffer, size);
}

string MqttClient::getUUID() {
    return _uuid;
}
void MqttClient::setUUID(const string &UUID) {
    _uuid = UUID;
}

bool MqttClient::reconnect() {
    Device *dev = getDevice().get();
    if (!_mqttClient.connect(getUUID().c_str(), getLogoutHomeTopic(dev->getHomeID()).c_str(), 1, false, "")) {
        Serial.println("Cannot connect MQTT client");
        return false;
    }
    Serial.print(".");

    return _mqttClient.connected();
}

void MqttClient::checkAvailability() {
    if (!_mqttClient.connected()) {
        long now = millis();
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

PubSubClient &MqttClient::getMQTT() {
    return _mqttClient;
}