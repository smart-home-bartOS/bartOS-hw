//
// Created by mabartos on 4/19/21.
//
#include "Capabilities.h"

shared_ptr<DhtTempSensor> LivingRoomTemp = make_shared<DhtTempSensor>(D7, 22);
shared_ptr<DefaultLightsCap> LivingRoomLights = make_shared<DefaultLightsCap>(D3);
shared_ptr<DefaultPowerCap> LivingRoomRelay = make_shared<DefaultPowerCap>(D1, "relay");

void turnOffLivingRoomLights() {
    LivingRoomLights->turnOff();
}

void setupLivingRoomRules() {
    LivingRoomTemp->setEnabled(false);
    LivingRoomLights->setEnabled(false);

    LivingRoomTemp->executeEventHandler()->add("MAIN", []() -> void {
        handleCallback(LivingRoomTemp->getTemperature() >= 25.0, []() -> void {
            LivingRoomLights->changeIntensity(75);
        });
    });

    LivingRoomTemp->loopEventHandler()->add("LESS_TEMP", []() -> void {
        handleCallback(LivingRoomTemp->getTemperature() <= 20.0, turnOffLivingRoomLights);
    });

    LivingRoomRelay->loopEventHandler()->period("changeRelayState", 10000, []() -> void {
        LivingRoomRelay->switchState();
    });

    LivingRoomRelay->loopEventHandler()->period("printRelayState", 1000, []() -> void {
        Serial.println("State");
        Serial.println(LivingRoomRelay->isTurnedOn());
    });

    Capabilities.push_back(LivingRoomTemp);
    Capabilities.push_back(LivingRoomLights);
    Capabilities.push_back(LivingRoomRelay);
}