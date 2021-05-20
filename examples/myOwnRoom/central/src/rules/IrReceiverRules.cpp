//
// Created by mabartos on 4/28/21.
//

#include "Capabilities.h"

/* Codes */
static const string LG_TV_GREEN_BUTTON = "0x20df8e71";
static const string LG_TV_YELLOW_BUTTON = "0x20dfc639";
static const string LG_DVD_POWER = "0xb4b40cf3";
static const string LG_DVD_ENTER = "0xb4b41ae5";
static const string LG_DVD_UP = "0xb4b4e21d";
static const string LG_DVD_DOWN = "0xb4b412ed";

shared_ptr <DefaultIRCap> RoomIrReceiver = make_shared<DefaultIRCap>(IR_RECEIVER_PIN);

void changeIntensityUnderLights() {
    if (UnderLights->isTurnedOn()) {
        UnderLights->decreaseIntensity();
        Serial.printf("Decrease Under lights. Intensity: %d\n", UnderLights->getActualIntensity());
        if (!UnderLights->isTurnedOn()) {
            RgbRelay->turnOff();
        }
    } else {
        UnderLights->turnOn();
        Serial.printf("Turn on Under lights. Current State: %s\n", UnderLights->isTurnedOn() ? "ON" : "OFF");
        RgbRelay->turnOn();
    }
}

void changeStateMainLights() {
    MainLights->switchState();
    Serial.printf("Main Lights - switch state. Current State: %s\n", MainLights->isTurnedOn() ? "ON" : "OFF");
}

void setupIrReceiver() {
    RoomIrReceiver->callbacks()->add(LG_TV_GREEN_BUTTON, changeIntensityUnderLights);

    RoomIrReceiver->callbacks()->add(LG_TV_YELLOW_BUTTON, changeStateMainLights);
    RoomIrReceiver->callbacks()->add(LG_DVD_POWER, changeStateMainLights);

    RoomIrReceiver->callbacks()->add(LG_DVD_ENTER, changeIntensityUnderLights);

    RoomIrReceiver->callbacks()->add(LG_DVD_UP, []() {
        if (!UnderLights->isTurnedOn()) {
            RgbRelay->turnOn();
        }
        UnderLights->increaseIntensity();
        Serial.printf("Increase Under lights. Intensity: %d\n", UnderLights->getActualIntensity());
    });

    RoomIrReceiver->callbacks()->add(LG_DVD_DOWN, []() {
        UnderLights->decreaseIntensity();
        if (!UnderLights->isTurnedOn()) {
            RgbRelay->turnOff();
        }
        Serial.printf("Decrease Under lights. Intensity: %d\n", UnderLights->getActualIntensity());
    });

    Capabilities.push_back(RoomIrReceiver);
}