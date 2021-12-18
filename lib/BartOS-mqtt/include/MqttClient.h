#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <callback/utils/CallbackType.h>
#include <connector/DataConnector.h>
#include <connector/DataHandler.h>
#include <connector/ManageConnector.h>

#include <functional>
#include <string>
#include <unordered_map>

using std::shared_ptr;
using std::string;

class MqttClient : public DataConnector, public ManageConnector {
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

    string _username = "";
    string _password = "";

   protected:
    void checkAvailability();

   public:
    explicit MqttClient(PubSubClient &mqttClient, const string &baseURL, const string &username = "", const string &password = "");

    ~MqttClient() = default;

    // Online Connector
    void init() override;
    void loop() override;

    // Manage Connector
    void connect() override;
    void disconnect() override;
    void create() override;
    void remove() override;
    void update() override;

    // DataConnector
    void sendData(const string &path, DynamicJsonDocument &data) override;
    void subscribe(const string &path, shared_ptr<DataHandler> handler) override;
    void unsubscribe(const string &path) override;

    string getUUID();

    void setUUID(const string &UUID);

    bool reconnect();

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

    /* Other */
    unsigned long getTryConnectPeriodMs();

    void setTryConnectPeriodMs(unsigned long period);

    void setUsername(const string &username);

    void setPassword(const string &password);

    void printMqttInfo();
};

#endif  // MQTT_CLIENT_H