//
// Created by mabartos on 4/19/21.
//
#include "Capabilities.h"

static const string LG_TV_GREEN_BUTTON = "0x20dfc639";

shared_ptr<DhtTempSensor> LivingRoomTemp = make_shared<DhtTempSensor>(D7, 22);
shared_ptr<DefaultLightsCap> LivingRoomLights = make_shared<DefaultLightsCap>(D3);
shared_ptr<DefaultPowerCap> LivingRoomRelay = make_shared<DefaultPowerCap>(D1, "relay");
shared_ptr<DefaultIRCap> LivingRoomIrReceiver = make_shared<DefaultIRCap>(D6);

void turnOffLivingRoomLights() {
    LivingRoomLights->turnOff();
}

void setupLivingRoomRules() {
    LivingRoomTemp->setEnabled(false);
    LivingRoomLights->setEnabled(false);

    LivingRoomIrReceiver->callbacks()->add(LG_TV_GREEN_BUTTON, []() -> void {
        Serial.println("Heere");
    });

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

    Capabilities.push_back(LivingRoomTemp);
    Capabilities.push_back(LivingRoomLights);
    Capabilities.push_back(LivingRoomRelay);
    Capabilities.push_back(LivingRoomIrReceiver);
}