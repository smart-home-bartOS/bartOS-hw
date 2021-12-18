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
    unordered_map <string, string> _authUsers;

    bool _printReceivedData = false;

    bool authenticateUser(const string &username, const string &password);

    bool authenticateUser(const char *username, const char *password);

protected:
    //void onData(String topic, const char *data, uint32_t length) override;

public:
    MqttClientBroker(uint16_t port = 1883,
                     uint16_t maxSubscriptions = 30,
                     uint16_t maxRetainedTopics = 30);

    ~MqttClientBroker() = default;

    bool subscribe(const string &topic) override;

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

    void addAuthUser(const string &username, const string &password);

    void removeAuthUser(const string &username);

    bool printReceivedData();

    void setPrintReceivedData(bool state);

    virtual bool onConnect(IPAddress addr, uint16_t client_count) {
        Serial.println(addr.toString() + " connected");
        Serial.println(client_count);
        return true;
    }

    virtual void onDisconnect(IPAddress addr, String client_id) {
        Serial.printf("%s (%s) disconnected\n", addr.toString().c_str(), client_id.c_str());
    }

    void onData(String topic, const char *data, uint32_t length){
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
    }

    virtual bool onAuth(String username, String password, String client_id) {
        if (authenticateUser(username.c_str(), password.c_str())) {
            Serial.printf("Username/ClientId: %s/%s connected.\n", username.c_str(), client_id.c_str());
            return true;
        }
        Serial.println("Access denied.");
        return false;
    }
};


#endif //BARTOS_HW_MQTTBROKER_H
