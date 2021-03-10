#include "OnlineCapability.h"
OnlineCapability::OnlineCapability(const uint8_t &pin, CapabilityType type) : Capability(pin, type) {
    setConnectionType(ConnectionType::ONLINE);
}
/*
void OnlineCapability::publishValues(CapabilityData &data) {
    if (getTopic() == "")
        return;
    char buffer[600];

    DynamicJsonDocument doc = data.toJSON();
    size_t size = serializeJson(doc, buffer);
    doc.shrinkToFit();
    doc.garbageCollect();

    client.getMQTT().publish(getTopic().c_str(), buffer, size);
}

string OnlineCapability::getTopic() {
    if (device.getRoomTopic() != "" && _ID != -1) {
        CapabilityUtils util(_type);
        string capID = NumberGenerator::longToString(_ID);
        string topic = device.getRoomTopic();
        string capTopic = util.getTopic();
        string result(topic + "/" + capTopic + "/" + capID);
        return result;
    }
    return "";
}


void OnlineCapability::editCreateCapNested(JsonObject &nested) {
    nested.clear();
    const uint8_t pin = getPin();
    nested["pin"] = pin;
    CapabilityUtils::setTypeJSON(nested, _type);
}
*/