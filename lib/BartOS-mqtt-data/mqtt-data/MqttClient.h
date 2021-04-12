#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H
using namespace std;

#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <string>
#include <online-device/device/connector/PubSubDataConnector.h>
#include <unordered_map>
#include <functional>
#include <core/callback/utils/CallbackType.h>

class MqttClient : public PubSubDataConnector {
private:
    string _uuid;

    string _brokerURL;
    uint16_t _port;

    string _lastWillTopic = "";
    uint8_t _lastWillQos = 1;
    bool _lastWillRetain = false;
    string _lastWillMessage = "";

    unsigned long _lastReconnectAttempt;
    PubSubClient &_mqttClient;
protected:
    void executeTopicContext(char *topic, DynamicJsonDocument doc);

public:
    explicit MqttClient(PubSubClient &mqttClient);

    ~MqttClient() = default;

    void connect() override;

    void disconnect() override;

    void sendData(const string &path, DynamicJsonDocument data) override;

    string getUUID();

    void setUUID(const string &UUID);

    void init(const string &brokerURL, const uint16_t &port = 1883);

    bool reconnect();

    void checkAvailability();

    string getBrokerURL();

    void setBrokerURL(const string &brokerURL);

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
};

#endif  //MQTT_CLIENT_H