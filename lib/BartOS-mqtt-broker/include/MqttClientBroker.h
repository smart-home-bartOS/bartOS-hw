//
// Created by mabartos on 4/29/21.
//

#ifndef BARTOS_HW_MQTTBROKER_H
#define BARTOS_HW_MQTTBROKER_H
using namespace std;

#include <string>
#include <uMQTTBroker.h>
#include <stdint.h>
#include <connector/PubSubDataConnector.h>

class MqttClientBroker : public uMQTTBroker, public PubSubDataConnector {
private:
    uint16_t _port;
    uint16_t _maxSubscriptions;
    uint16_t _maxRetainedTopics;
    string _allowedUsername;
    string _allowedPassword;

protected:
    void onData(String topic, const char *data, uint32_t length) override;

public:
    MqttClientBroker(uint16_t port = 1883,
                     uint16_t maxSubscriptions = 30,
                     uint16_t maxRetainedTopics = 30);

    ~MqttClientBroker() = default;

    void init() override;

    void sendData(const string &path, DynamicJsonDocument data) override;

    void connect() override;

    void disconnect() override;

    uint16_t getPort();

    void setPort(uint16_t port);

    uint16_t getMaxSubscriptions();

    void setMaxSubscriptions(uint16_t maxSubs);

    uint16_t getMaxRetainedTopics();

    void setMaxRetainedTopics(uint16_t maxRetainedTopics);

    void setAllowedUsername(const string &username);

    void setAllowedPassword(const string &password);

    virtual bool onConnect(IPAddress addr, uint16_t client_count) {
        Serial.println(addr.toString() + " connected");
        return true;
    }

    virtual void onDisconnect(IPAddress addr, String client_id) {
        Serial.println(addr.toString() + " (" + client_id + ") disconnected");
    }

    virtual bool onAuth(String username, String password, String client_id) {
        if (username == _allowedUsername && password == _allowedPassword) {
            Serial.printf("Username/ClientId: %s/%s connected.\n", username, client_id);
            return true;
        }
        Serial.println("Access denied.");
        return false;
    }
};


#endif //BARTOS_HW_MQTTBROKER_H
