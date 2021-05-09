#ifndef BARTOS_HW_CAPABILITIES_INIT_H
#define BARTOS_HW_CAPABILITIES_INIT_H

using namespace std;

#include <Arduino.h>
#include <memory>
#include <callback/utils/CallbackType.h>
#include <callback/utils/CallbackUtils.h>

#include <default/DhtTempSensor.h>
#include <default/DhtHumSensor.h>
#include <default/two-way-button/TwoWayButton.h>
#include <default/DefaultPowerCap.h>
#include <default/DefaultLightsCap.h>
#include <default/DefaultIRCap.h>
#include <device/Device.h>

/* PINS */
#define ROOM_TEMP_PIN       D8
#define ROOM_HUM_PIN        D8
#define MAIN_LIGHTS_PIN     D5
#define UNDER_LIGHTS_PIN    D6
#define RGB_RELAY_PIN       D1
#define RELAY_2_PIN         D2
#define IR_RECEIVER_PIN     D4
#define LEFT_MAIN_BTN_PIN   D7
#define RIGHT_MAIN_BTN_PIN  D0

/* DEVICE */
extern shared_ptr<Device> device;

/* TEMPERATURE, HUMIDITY */
extern shared_ptr<DhtTempSensor> RoomTemp;
extern shared_ptr<DhtHumSensor> RoomHum;

void setupTempHumRules();

/* LIGHTS */
extern shared_ptr<DefaultLightsCap> MainLights;
extern shared_ptr<DefaultLightsCap> UnderLights;

void setupLightsRules();

/* RELAYS */
extern shared_ptr<DefaultPowerCap> RgbRelay;
extern shared_ptr<DefaultPowerCap> Relay2;

void setupRelaysRules();

/* IR RECEIVER */
extern shared_ptr<DefaultIRCap> RoomIrReceiver;

void setupIrReceiver();

/* BUTTONS */
extern shared_ptr<TwoWayButton> LeftMainButton;
extern shared_ptr<TwoWayButton> RightMainButton;

void setupButtonsRules();

/* CAPABILITIES */
extern vector<shared_ptr<Capability>> Capabilities;

inline void addAllRules() {
    setupLightsRules();
    setupTempHumRules();
    setupRelaysRules();
    setupIrReceiver();
    setupButtonsRules();
}

#endif //BARTOS_HW_CAPABILITIES_INIT_H
