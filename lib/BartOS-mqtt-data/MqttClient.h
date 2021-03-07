#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <ArduinoJson.h>
#include <PubSubClient.h>

#include "device/connector/DataConnector.h"
using namespace std;

class MqttClient : public DataConnector<void, DynamicJsonDocument> {
   private:
    const uint16_t PORT = 1883;

    string _uuid;
    string _brokerURL;

    char _msg[100];

    long _lastReconnectAttempt;

    PubSubClient &_mqttClient;

    void setupWifi();

   public:
    MqttClient(PubSubClient &mqttClient);
    ~MqttClient() = default;

    void connect();
    void disconnect();

    void sendData(const string &path, DynamicJsonDocument data);

    string getUUID();
    void setUUID(const string &UUID);

    void init(const string &brokerURL);
    bool reconnect();
    void checkAvailability();

    string getBrokerURL();
    void setBrokerURL(const string &brokerURL);

    PubSubClient &getMQTT();
};

#endif  //MQTT_CLIENT_H