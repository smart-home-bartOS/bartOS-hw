#ifndef BARTOS_HW_CAPABILITIES_INIT_H
#define BARTOS_HW_CAPABILITIES_INIT_H

using namespace std;

#include <Arduino.h>
#include <memory>
#include <core/callback/utils/CallbackType.h>
#include <core/callback/utils/CallbackUtils.h>

#include <temp/default/DhtTempSensor.h>
#include <humidity/default/DhtHumSensor.h>
#include <button/default/two-way-button/TwoWayButton.h>
#include <powerAble/default/DefaultPowerCap.h>
#include <lights/default/DefaultLightsCap.h>
#include <ir/default/DefaultIRCap.h>
#include <core/device/Device.h>

/* PINS */
#define ROOM_TEMP_PIN       D8
#define ROOM_HUM_PIN        D8
#define MAIN_LIGHTS_PIN     D5
#define UNDER_LIGHTS_PIN    D6
#define RELAY_1_PIN         D1
#define RELAY_2_PIN         D2
#define IR_RECEIVER_PIN     D4
#define LEFT_MAIN_BTN_PIN   D3
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
extern shared_ptr<DefaultPowerCap> Relay1;
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
