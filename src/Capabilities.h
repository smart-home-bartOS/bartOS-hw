//
// Created by mabartos on 3/28/21.
//

#ifndef BARTOS_HW_CAPABILITIES_H
#define BARTOS_HW_CAPABILITIES_H

#include <vector>
#include <memory>
#include <core/callback/CallbackUtils.h>

auto tempLivingRoom = make_shared<DhtTempSensor>(D7, 22);
auto tempKitchen = make_shared<DhtTempSensor>(D8, 22);

/* Capabilities */
const vector<shared_ptr<Capability>> CAPABILITIES{
        tempLivingRoom,
        tempKitchen,
};

void setupCapabilityEvent() {
    tempLivingRoom->eventHandlerExecute().add("MAIN", []() -> void {
        handleCallback(tempLivingRoom->getTemperature() >= 25.0, []() -> void {
            //TEST
        });
    });

    tempLivingRoom->eventHandlerExecute().add("LESS_TEMP", []() -> void {
        handleCallback(tempLivingRoom->getTemperature() <= 20.0, []() -> void {
            // Execute something
        });
    });
}

#endif //BARTOS_HW_CAPABILITIES_H
