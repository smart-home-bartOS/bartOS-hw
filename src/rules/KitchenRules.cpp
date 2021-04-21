//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_KITCHENRULES_H
#define BARTOS_HW_KITCHENRULES_H

#include "Capabilities.h"

#include <memory>

/* Capabilities */
shared_ptr<DhtTempSensor> KitchenTemp = make_shared<DhtTempSensor>(D8, 22);
shared_ptr<DefaultLightsCap> KitchenMainLights = make_shared<DefaultLightsCap>(LED_BUILTIN, "kitchenMain");
shared_ptr<TwoWayButton> KitchenMainSwitch = make_shared<TwoWayButton>(D2, "kitchenMainSwitch");
shared_ptr<DhtTempOnline> KitchenOnlineTemp = make_shared<DhtTempOnline>(MqttDataConnector, D5, 22);

void setupKitchenRules() {
    KitchenTemp->setEnabled(false);
    KitchenMainSwitch->setEnabled(false);

    KitchenTemp->executeEventHandler()->add("MAIN", []() -> void {
        handleCallback(KitchenTemp->getTemperature() >= 25.0, []() -> void {
            KitchenMainLights->turnOn();
        });
    });

    KitchenMainLights->loopEventHandler()->period("period", 2000, []() -> void {
        KitchenMainLights->switchState();
    });

    KitchenMainSwitch->setSampleTime(100);
    KitchenMainSwitch->executeEventHandler()->add("CheckMainSwitch", []() -> void {
        bool isTurnedOn = KitchenMainSwitch->isOn();
    });

    KitchenOnlineTemp->topicCallbacks()->add("devices/12", [](DynamicJsonDocument doc) -> void {
        const vector<string> KEYS{TemperatureData::TEMPERATURE_FIELD, TemperatureData::UNITS_FIELD};
        if (containKeys(doc, KEYS)) {
            KitchenOnlineTemp->getTemperature();
            KitchenOnlineTemp->setTemperature(23.0);
        }
    });

    KitchenOnlineTemp->loopEventHandler()->period("periodicSending", 1000, []() -> void {
        KitchenOnlineTemp->sendData();
        DynamicJsonDocument doc(100);
        Device->getDataConnector()->sendData("ahoj", doc);
    });

    // Add capabilities
    Capabilities.push_back(KitchenTemp);
    Capabilities.push_back(KitchenOnlineTemp);
    Capabilities.push_back(KitchenMainSwitch);
    Capabilities.push_back(KitchenOnlineTemp);
}


#endif //BARTOS_HW_KITCHENRULES_H
