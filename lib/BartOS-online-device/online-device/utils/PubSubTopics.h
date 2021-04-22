//
// Created by mabartos on 4/20/21.
//

#ifndef BARTOS_HW_PUBSUBTOPICS_H
#define BARTOS_HW_PUBSUBTOPICS_H

#include <string>
#include <cstring>
#include <online-device/utils/JsonUtils.h>
#include <core/capability/Capability.h>

using namespace std;

class PubSubTopics {
public:
    static const string &HOME_TOPIC;
    static const string &ROOM_TOPIC;
    static const string &DEVICE_TOPIC;
    static const string &CAPS_BASIC_TOPIC;
    static const string &LOGOUT_TOPIC;

    /* HOME */
    static string getHomeTopic(const long homeID) {
        return concatTopicWithLong(HOME_TOPIC, homeID);
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
    static string getDeviceTopic(const long deviceID) {
        return concatTopicWithLong(DEVICE_TOPIC, deviceID);
    }

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

    /* CAPABILITY */
    static string getCapabilityNameTopic(Capability *capability) {
        if (capability == nullptr) return "";
        string capTypeNameTopic = concatTwoTopics(capability->getType(), capability->getName());
        return concatTwoTopics(CAPS_BASIC_TOPIC, capTypeNameTopic);
    }

    static string getCapabilityTopic(Capability *capability) {
        if (capability == nullptr) return "";
        return concatTopicWithLong(capability->getType(), capability->getID());
    }

    static string getCapabilityDeviceTopic(const long deviceID, Capability *capability) {
        return concatTwoTopics(getDeviceTopic(deviceID), getCapabilityTopic(capability));
    }

    static string getCapabilityRoomDeviceTopic(const long homeID,
                                               const long roomID,
                                               const long deviceID,
                                               Capability *capability) {
        return concatTwoTopics(getRoomTopic(homeID, roomID), getCapabilityDeviceTopic(deviceID, capability));
    }

    static string getCapabilityHomeTopic(const long homeID, Capability *capability) {
        return concatTwoTopics(getHomeTopic(homeID), getCapabilityTopic(capability));
    }

    static string getCapabilityHomeRoomTopic(const long homeID, const long roomID, Capability *capability) {
        return concatTwoTopics(getRoomTopic(homeID, roomID), getCapabilityTopic(capability));
    }


    /* UTILS */
    static string concatTopicWithLong(const string &topic, const long id) {
        return (id != -1) ? concatTwoTopics(topic, convertLongToString(id)) : "";
    }

    static bool isEmptyTopic(const string &topic) {
        return (strcmp(topic.c_str(), "") == 0);
    }

    static string concatTwoTopics(const string &first, const string &second, const string &delimiter = "/") {
        if (!isEmptyTopic(first) && !isEmptyTopic(second)) {
            return first + delimiter + second;
        }
        return "";
    }

    static string concatTwoTopicsWithLong(const string &firstTopic, const long firstID,
                                          const string &secondTopic, const long secondID) {
        const string &first = concatTopicWithLong(firstTopic, firstID);
        const string &second = concatTopicWithLong(secondTopic, secondID);

        return concatTwoTopics(first, second);
    }
};

#endif //BARTOS_HW_PUBSUBTOPICS_H
