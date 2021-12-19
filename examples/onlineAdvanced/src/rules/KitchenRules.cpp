//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_KITCHENRULES_H
#define BARTOS_HW_KITCHENRULES_H

#include <memory>

#include "Capabilities.h"

/* Capabilities */
shared_ptr<DhtTempSensor> kitchenTemp = make_shared<DhtTempSensor>(D8, 22);
shared_ptr<DefaultOnlineLightsCap> kitchenMainLights = make_shared<DefaultOnlineLightsCap>(LED_BUILTIN, "kitchenMain");
shared_ptr<TwoWayButton> kitchenMainSwitch = make_shared<TwoWayButton>(D2, "kitchenMainSwitch");
shared_ptr<DhtTempOnline> kitchenOnlineTemp = make_shared<DhtTempOnline>(D5, 22);

void setupKitchenRules() {
    kitchenTemp->setEnabled(false);
    kitchenMainSwitch->setEnabled(false);
    kitchenMainLights->setInverseOutput(true);

    kitchenTemp->actions()->add("MAIN", []() {
        handleCallback(kitchenTemp->getTemperature() >= 25.0, []() {
            kitchenMainLights->turnOn();
        });
    });

    Serial.println("STARTED");
    kitchenMainLights->scheduler()->timer("timer123", 3000, []() {
        Serial.print("FINISHED");
    });

    kitchenMainLights->scheduler()->period("period", 2000, []() {
        Serial.print("Lights state: ");
        Serial.println(kitchenMainLights->isTurnedOn());
    });

    kitchenMainSwitch->setSampleTime(100);
    kitchenMainSwitch->actions()->add("CheckMainSwitch", []() -> void {
        bool isTurnedOn = kitchenMainSwitch->isOn();
    });

    kitchenOnlineTemp->getDataConnector()->onMessage("devices/12", [](DynamicJsonDocument &document) -> void {
        JsonObject doc = document.as<JsonObject>();

        const string KEYS[] = {TemperatureOnline::TEMP, TemperatureOnline::UNITS};
        if (containsKeys(doc, KEYS)) {
            kitchenOnlineTemp->getTemperature();
            kitchenOnlineTemp->setTemperature(23.0);
            Serial.println("Set temperature");
        }
    });

    kitchenOnlineTemp->scheduler()->period("periodicSending", 2000, []() -> void {
        DynamicJsonDocument doc(100);
        doc["test"] = "ahoj";
        doc.shrinkToFit();
        device->getDataConnector()->sendData("ahoj", doc);
        doc.garbageCollect();
    });

    // Add capabilities
    capabilities.push_back(kitchenTemp);
    capabilities.push_back(kitchenMainLights);
    capabilities.push_back(kitchenMainSwitch);
    capabilities.push_back(kitchenOnlineTemp);
}

#endif  // BARTOS_HW_KITCHENRULES_H
