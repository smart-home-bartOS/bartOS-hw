//
// Created by mabartos on 4/19/21.
//
#include "Capabilities.h"

static const string LG_TV_GREEN_BUTTON = "0x20dfc639";

shared_ptr<DhtTempSensor> LivingRoomTemp = make_shared<DhtTempSensor>(D7, 22);
shared_ptr<DefaultLightsCap> LivingRoomLights = make_shared<DefaultLightsCap>(D3);
shared_ptr<DefaultPowerCap> LivingRoomRelay = make_shared<DefaultPowerCap>(D1);
shared_ptr<DefaultIRCap> LivingRoomIrReceiver = make_shared<DefaultIRCap>(D6);

void turnOffLivingRoomLights() {
    LivingRoomLights->turnOff();
}

void setupLivingRoomRules() {
    LivingRoomTemp->setEnabled(false);
    LivingRoomLights->setEnabled(false);

    LivingRoomIrReceiver->codeHandler()->add(LG_TV_GREEN_BUTTON, []() -> void {
        Serial.println("Heere");
    });

    LivingRoomTemp->actions()->add("MAIN", []() -> void {
        handleCallback(LivingRoomTemp->getTemperature() >= 25.0, []() -> void {
            LivingRoomLights->changeIntensity(75);
        });
    });

    LivingRoomTemp->actions()->add("LESS_TEMP", []() -> void {
        handleCallback(LivingRoomTemp->getTemperature() <= 20.0, turnOffLivingRoomLights);
    });

    LivingRoomRelay->scheduler()->period("changeRelayState", 10000, []() -> void {
        LivingRoomRelay->switchState();
    });

    capabilities.push_back(LivingRoomTemp);
    capabilities.push_back(LivingRoomLights);
    capabilities.push_back(LivingRoomRelay);
    capabilities.push_back(LivingRoomIrReceiver);
}