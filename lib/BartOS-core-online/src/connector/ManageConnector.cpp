#include "connector/ManageConnector.h"

#include <json/JsonKeys.h>
#include <json/JsonUtils.h>

#include "device/OnlineDevice.h"

string ManageConnector::CREATE_HANDLER = "deviceCreateHandler";
string ManageConnector::CONNECT_HANDLER = "deviceConnectHandler";
string ManageConnector::REMOVE_HANDLER = "deviceRemoveHandler";
string ManageConnector::UPDATE_HANDLER = "deviceUpdateHandler";
string ManageConnector::DISCONNECT_HANDLER = "deviceDisconnectHandler";

ManageConnector::ManageConnector(const string& baseURL) : OnlineConnector(baseURL) {}

void ManageConnector::init() {
    handleMessageConnect();
    handleMessageCreate();
    handleMessageRemove();
    handleMessageUpdate();
    handleMessageDisconnect();
}

void ManageConnector::handleMessageConnect() {
    getOnlineDevice()->onMessage(CONNECT_HANDLER, [this](DynamicJsonDocument& data) {
    });
}

void ManageConnector::handleMessageCreate() {
    getOnlineDevice()->onMessage(CREATE_HANDLER, [this](DynamicJsonDocument& data) {
        getOnlineDevice()->setID(data[JsonKeys::DEVICE_ID].as<long>());

        string name(data[JsonKeys::NAME].as<char*>());
        getOnlineDevice()->setName(name);

        getOnlineDevice()->setRoomID(data[JsonKeys::ROOM_ID].as<long>());
        setUpCapabilities(data);
    });
}

void ManageConnector::handleMessageRemove() {
    getOnlineDevice()->onMessage(REMOVE_HANDLER, [this](DynamicJsonDocument& data) {
    });
}

void ManageConnector::handleMessageUpdate() {
    getOnlineDevice()->onMessage(UPDATE_HANDLER, [this](DynamicJsonDocument& data) {
        getOnlineDevice()->setID(data[JsonKeys::DEVICE_ID].as<long>());

        string name(data[JsonKeys::NAME].as<char*>());
        getOnlineDevice()->setName(name);

        getOnlineDevice()->setRoomID(data[JsonKeys::ROOM_ID].as<long>());
        setUpCapabilities(data);
    });
}
void ManageConnector::handleMessageDisconnect() {
    getOnlineDevice()->onMessage(DISCONNECT_HANDLER, [this](DynamicJsonDocument& data) {
    });
}

void ManageConnector::setUpCapabilities(DynamicJsonDocument& doc) {
    const JsonObject& data = doc.as<JsonObject>();

    if (data.containsKey(JsonKeys::CAPABILITIES)) {
        JsonArray caps = data[JsonKeys::CAPABILITIES];
        const string KEYS[] = {JsonKeys::PIN, JsonKeys::TYPE};

        for (JsonObject capData : caps) {
            if (containsKeys(capData, KEYS)) {
                uint8_t pin = capData[JsonKeys::PIN];
                const char* type = capData[JsonKeys::TYPE];
            }
        }
    }
}