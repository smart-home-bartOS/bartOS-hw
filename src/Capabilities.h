//
// Created by mabartos on 3/28/21.
//

#ifndef BARTOS_HW_CAPABILITIES_H
#define BARTOS_HW_CAPABILITIES_H

#include <vector>
#include <memory>
#include <core/callback/CallbackUtils.h>
#include <temp/default/DhtTempSensor.h>
#include <lights/default/DefaultLightsCap.h>
#include <button/default/twoWayButton/TwoWayButton.h>

/* KITCHEN */
auto tempKitchen = make_shared<DhtTempSensor>(D8, 22);
auto kitchenMainLights = make_shared<DefaultLightsCap>(LED_BUILTIN, "kitchenMain");
auto kitchenMainSwitch = make_shared<TwoWayButton>(D2, "kitchenMainSwitch");

/* LIVING ROOM */
auto tempLivingRoom = make_shared<DhtTempSensor>(D7, 22);
auto livingRoomLights = make_shared<DefaultLightsCap>(D3);

/* Capabilities */
const vector<shared_ptr<Capability>> CAPABILITIES{
        tempLivingRoom,
        livingRoomLights,
        tempKitchen,
        kitchenMainLights,
        kitchenMainSwitch
};

/* Rules for kitchen */
void kitchenRules() {
    tempKitchen->setEnabled(false);
    tempKitchen->executeEventHandler()->add("MAIN", []() -> void {
        handleCallback(tempKitchen->getTemperature() >= 25.0, []() -> void {
            kitchenMainLights->turnOn();
        });
    });

    kitchenMainLights->loopEventHandler()->period("period", 2000, []() -> void {
        kitchenMainLights->switchState();
    });

    kitchenMainSwitch->setSampleTime(100);
    kitchenMainSwitch->executeEventHandler()->add("CheckMainSwitch", []() -> void {
        bool isTurnedOn = kitchenMainSwitch->isOn();
        Serial.println(isTurnedOn);
    });
}

/* Callback */
void turnOffLivingRoomLights() {
    livingRoomLights->turnOff();
}

void livingRoomRules() {
    tempLivingRoom->setEnabled(false);
    tempLivingRoom->executeEventHandler()->add("MAIN", []() -> void {
        handleCallback(tempLivingRoom->getTemperature() >= 25.0, []() -> void {
            livingRoomLights->changeIntensity(75);
        });
    });

    tempLivingRoom->loopEventHandler()->add("LESS_TEMP", []() -> void {
        handleCallback(tempLivingRoom->getTemperature() <= 20.0, turnOffLivingRoomLights);
    });
}

void setupCapabilityEvent() {
    kitchenRules();
    livingRoomRules();
}

#endif //BARTOS_HW_CAPABILITIES_H
