//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_PUBSUBCALLBACKMAP_H
#define BARTOS_HW_PUBSUBCALLBACKMAP_H

using namespace std;

#include <online-device/device/connector/OnlineCallbackUtils.h>
#include <string>
#include <unordered_map>

class PubSubCallbackMap {
private:
    unordered_map<string, PubSubCallback> _callbacks;
public:

    PubSubCallbackMap() = default;

    ~PubSubCallbackMap() = default;

    void handle(const string &topic, DynamicJsonDocument &doc);

    void clearAll();

    void add(const string &name, PubSubCallback callback);

    void remove(const string &name);

    uint32_t getSize();

};


#endif //BARTOS_HW_PUBSUBCALLBACKMAP_H
