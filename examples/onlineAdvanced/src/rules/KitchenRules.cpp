//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_KITCHENRULES_H
#define BARTOS_HW_KITCHENRULES_H

#include "Capabilities.h"

#include <memory>

/* Capabilities */
shared_ptr <DhtTempSensor> KitchenTemp = make_shared<DhtTempSensor>(D8, 22);
shared_ptr <DefaultOnlineLightsCap> KitchenMainLights = make_shared<DefaultOnlineLightsCap>(MqttDataConnector,
                                                                                            LED_BUILTIN, "kitchenMain");
shared_ptr <TwoWayButton> KitchenMainSwitch = make_shared<TwoWayButton>(D2, "kitchenMainSwitch");
shared_ptr <DhtTempOnline> KitchenOnlineTemp = make_shared<DhtTempOnline>(MqttDataConnector, D5, 22);

void setupKitchenRules() {
    KitchenTemp->setEnabled(false);
    KitchenMainSwitch->setEnabled(false);
    KitchenMainLights->setInverseOutput(true);

    KitchenTemp->executeEventHandler()->add("MAIN", []() -> void {
        handleCallback(KitchenTemp->getTemperature() >= 25.0, []() -> void {
            KitchenMainLights->turnOn();
        });
    });

    Serial.println("STARTED");
    KitchenMainLights->loopEventHandler()->timer("timer123", 3000, []() -> void {
        Serial.print("FINISHED");
    });

    KitchenMainLights->loopEventHandler()->period("period", 2000, []() -> void {
        Serial.print("Lights state: ");
        Serial.println(KitchenMainLights->isTurnedOn());
    });

    KitchenMainSwitch->setSampleTime(100);
    KitchenMainSwitch->executeEventHandler()->add("CheckMainSwitch", []() -> void {
        bool isTurnedOn = KitchenMainSwitch->isOn();
    });

    KitchenOnlineTemp->getDataConnector()->addTopicContext("devices/12", [](JsonObject &doc) -> void {
        const string KEYS[] = {TemperatureData::TEMPERATURE_FIELD, TemperatureData::UNITS_FIELD};
        if (containKeys(doc, KEYS)) {
            KitchenOnlineTemp->getTemperature();
            KitchenOnlineTemp->setTemperature(23.0);
            Serial.println("Set temperature");
        }
    });

    KitchenOnlineTemp->loopEventHandler()->period("periodicSending", 2000, []() -> void {
        KitchenOnlineTemp->sendData();
        DynamicJsonDocument doc(100);
        doc["test"] = "ahoj";
        doc.shrinkToFit();
        Device->getDataConnector()->sendData("ahoj", doc);
        doc.garbageCollect();
    });

    // Add capabilities
    Capabilities.push_back(KitchenTemp);
    Capabilities.push_back(KitchenMainLights);
    Capabilities.push_back(KitchenMainSwitch);
    Capabilities.push_back(KitchenOnlineTemp);
}


#endif //BARTOS_HW_KITCHENRULES_H
