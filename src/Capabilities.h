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

/* KITCHEN */
auto tempKitchen = make_shared<DhtTempSensor>(D8, 22);
auto kitchenMainLights = make_shared<DefaultLightsCap>(D2, "kitchenMain");

/* LIVING ROOM */
auto tempLivingRoom = make_shared<DhtTempSensor>(D7, 22);
auto livingRoomLights = make_shared<DefaultLightsCap>(D3);

/* Capabilities */
const vector<shared_ptr<Capability>> CAPABILITIES{
        tempLivingRoom,
        livingRoomLights,
        tempKitchen,
        kitchenMainLights
};

void tempKitchenRules() {
    tempKitchen->eventHandlerExecute().add("MAIN", []() -> void {
        handleCallback(tempKitchen->getTemperature() >= 25.0, []() -> void {
            kitchenMainLights->turnOn();
        });
    });
}

void tempLivingRoomRules() {
    tempLivingRoom->eventHandlerExecute().add("MAIN", []() -> void {
        handleCallback(tempLivingRoom->getTemperature() >= 25.0, []() -> void {
            livingRoomLights->changeIntensity(75);
        });
    });

    tempLivingRoom->eventHandlerLoop().add("LESS_TEMP", []() -> void {
        handleCallback(tempLivingRoom->getTemperature() <= 20.0, []() -> void {
            livingRoomLights->turnOff();
        });
    });
}

void setupCapabilityEvent() {
    tempKitchenRules();
    tempLivingRoomRules();
}

#endif //BARTOS_HW_CAPABILITIES_H
