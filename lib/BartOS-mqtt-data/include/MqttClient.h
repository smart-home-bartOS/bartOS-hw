#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H
using namespace std;

#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <string>
#include <connector/PubSubDataConnector.h>
#include <unordered_map>
#include <functional>
#include <callback/utils/CallbackType.h>

class MqttClient : public PubSubDataConnector {
private:
    string _uuid;

    uint16_t _port = 1883;

    string _lastWillTopic = "";
    uint8_t _lastWillQos = 1;
    bool _lastWillRetain = false;
    string _lastWillMessage = "";

    unsigned long _lastReconnectAttempt = 0;
    unsigned long _tryConnectPeriodMs = 200000;
    PubSubClient &_mqttClient;

    string _username;
    string _password;

protected:
    void executeTopicContext(char *topic, JsonObject &doc);

    void printMqttInfo();

public:
    explicit MqttClient(PubSubClient &mqttClient, const string &username="", const string &password="");

    ~MqttClient() = default;

    void init() override;

    void loop() override;

    void connect() override;

    void disconnect() override;

    void sendData(const string &path, DynamicJsonDocument data) override;

    string getUUID();

    void setUUID(const string &UUID);

    bool reconnect();

    void checkAvailability();

    PubSubClient &getMqttClient();

    /* Last Will */
    string getLastWillTopic();

    void setLastWillTopic(const string &topic);

    uint8_t getLastWillQos();

    void setLastWillQos(uint8_t qos);

    bool isLastWillRetain();

    void setLastWillRetain(bool state);

    string getLastWillMessage();

    void setLastWillMessage(const string &message);

    void addTopicContext(const string &topic, PubSubCallback callback) override;

    void removeTopicContext(const string &topic) override;

    unsigned long getTryConnectPeriodMs();

    void setTryConnectPeriodMs(unsigned long period);

    void setUsername(const string &username);

    void setPassword(const string &password);
};

#endif  //MQTT_CLIENT_H