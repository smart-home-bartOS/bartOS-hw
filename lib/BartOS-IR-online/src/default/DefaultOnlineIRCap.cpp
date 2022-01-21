//
// Created by mabartos on 4/19/21.
//

#include "default/DefaultOnlineIRCap.h"

DefaultOnlineIRCap::DefaultOnlineIRCap(const uint8_t &pin) : DefaultIRCap(pin),
                                                             InfraRedOnline(this) {
    getTargetCapability()->onDecode()->add("sendOnDecode", [this]() {
        DynamicJsonDocument doc(10);
        doc["value"] = "12345";  // TODO - specify callback with value
        getDataConnector()->sendData("/cap/ir/" + getID(), doc);
    });
}
