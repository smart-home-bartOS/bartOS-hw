#ifndef MQTT_TOPICS_H
#define MQTT_TOPICS_H

#include <string>
#include <cstring>
#include <online-device/utils/JsonUtils.h>

using namespace std;

class MqttTopics {
public:
    static const string &HOME_TOPIC;
    static const string &ROOM_TOPIC;
    static const string &DEVICE_TOPIC;
    static const string &LOGOUT_TOPIC;

    /* HOME */
    static string getHomeTopic(const long homeID) {
        return getValidTopicWithLong(HOME_TOPIC, homeID);
    }

    static string getHomeTopicWildcard(const long homeID) {
        const string &homeTopic = getHomeTopic(homeID);
        return isEmptyTopic(homeTopic) ? "" : homeTopic + "/#";
    }

    /* ROOM */
    static string getRoomTopic(const long homeID, const long roomID) {
        return concatTwoTopicsWithLong(HOME_TOPIC, homeID, ROOM_TOPIC, roomID);
    }

    static string getRoomTopicWildcard(const long homeID, const long roomID) {
        const string &roomTopic = getRoomTopic(homeID, roomID);
        return isEmptyTopic(roomTopic) ? "" : roomTopic + "/#";
    }

    /* DEVICE */
    static string getDeviceHomeTopic(const long homeID, const long deviceID) {
        return concatTwoTopicsWithLong(HOME_TOPIC, homeID, DEVICE_TOPIC, deviceID);
    }

    static string getDeviceHomeTopicWildcard(const long homeID, const long deviceID) {
        const string &deviceTopic = getDeviceHomeTopic(homeID, deviceID);
        return isEmptyTopic(deviceTopic) ? "" : deviceTopic + "/#";
    }

    static string getLogoutHomeTopic(const long homeID) {
        return concatTwoTopics(getHomeTopic(homeID), LOGOUT_TOPIC);
    }

    /* UTILS */
    static string getValidTopicWithLong(const string &topic, const long id) {
        return (id != -1) ? (topic + convertLongToString(id)) : "";
    }

    static bool isEmptyTopic(const string &topic) {
        return (strcmp(topic.c_str(), "") == 0);
    }

    static string concatTwoTopics(const string &first, const string &second) {
        if (!isEmptyTopic(first) && !isEmptyTopic(second)) {
            return first + "/" + second;
        }
        return "";
    }

    static string concatTwoTopicsWithLong(const string &firstTopic, const long firstID,
                                          const string &secondTopic, const long secondID) {
        const string &first = getValidTopicWithLong(firstTopic, firstID);
        const string &second = getValidTopicWithLong(secondTopic, secondID);

        return concatTwoTopics(first, second);
    }
};

const string &MqttTopics::HOME_TOPIC = "homes";
const string &MqttTopics::ROOM_TOPIC = "rooms";
const string &MqttTopics::DEVICE_TOPIC = "devices";
const string &MqttTopics::LOGOUT_TOPIC = "logout";

#endif  //MQTT_TOPICS_H