#ifndef MQTT_TOPICS_H
#define MQTT_TOPICS_H

#include <string>

#include "utils/JsonUtils.h"
using namespace std;

const string& HOME_TOPIC = "homes";
const string& ROOM_TOPIC = "rooms";
const string& DEVICE_TOPIC = "devices";
const string& LOGOUT_TOPIC = "logout";

const string& getValidTopicWithLong(const string& topic, const long id) {
    return (id != -1) ? (topic + convertLongToString(id)) : "";
}

const bool isEmptyTopic(const string& topic) {
    return (strcmp(topic.c_str(), "") == 0);
}

const string& concatTwoTopics(const string& first, const string& second) {
    if (!isEmptyTopic(first) && !isEmptyTopic(second)) {
        return first + "/" + second;
    }
    return "";
}

const string& concatTwoTopicsWithLong(const string& firstTopic, const long firstID,
                                      const string& secondTopic, const long secondID) {
    const string& first = getValidTopicWithLong(firstTopic, firstID);
    const string& second = getValidTopicWithLong(secondTopic, secondID);

    return concatTwoTopics(first, second);
}

// HOME
const string& getHomeTopic(const long homeID) {
    return getValidTopicWithLong(HOME_TOPIC, homeID);
}

const string& getHomeTopicWildcard(const long homeID) {
    const string& homeTopic = getHomeTopic(homeID);
    return isEmptyTopic(homeTopic) ? "" : homeTopic + "/#";
}

// ROOM
const string& getRoomTopic(const long homeID, const long roomID) {
    return concatTwoTopicsWithLong(HOME_TOPIC, homeID, ROOM_TOPIC, roomID);
}

const string& getRoomTopicWildcard(const long homeID, const long roomID) {
    const string& roomTopic = getRoomTopic(homeID, roomID);
    return isEmptyTopic(roomTopic) ? "" : roomTopic + "/#";
}

//DEVICE
const string& getDeviceHomeTopic(const long homeID, const long deviceID) {
    return concatTwoTopicsWithLong(HOME_TOPIC, homeID, DEVICE_TOPIC, deviceID);
}

const string& getDeviceHomeTopicWildcard(const long homeID, const long deviceID) {
    const string& deviceTopic = getDeviceHomeTopic(homeID, deviceID);
    return isEmptyTopic(deviceTopic) ? "" : deviceTopic + "/#";
}

const string& getLogoutHomeTopic(const long homeID) {
    return concatTwoTopics(getHomeTopic(homeID), LOGOUT_TOPIC);
}

#endif  //MQTT_TOPICS_H