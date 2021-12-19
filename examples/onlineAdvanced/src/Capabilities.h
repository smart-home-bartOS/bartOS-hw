#ifndef BARTOS_HW_CAPABILITIES_INIT_H
#define BARTOS_HW_CAPABILITIES_INIT_H

#include <MqttClient.h>
#include <callback/utils/CallbackType.h>
#include <callback/utils/CallbackUtils.h>
#include <default/DefaultIRCap.h>
#include <default/DefaultLightsCap.h>
#include <default/DefaultOnlineLightsCap.h>
#include <default/DefaultPowerCap.h>
#include <default/DhtTempOnline.h>
#include <default/DhtTempSensor.h>
#include <default/two-way-button/TwoWayButton.h>
#include <device/OnlineDevice.h>

#include <memory>

/* DEVICE */
extern shared_ptr<OnlineDevice> device;

/* KITCHEN */
extern shared_ptr<DhtTempSensor> kitchenTemp;
extern shared_ptr<DefaultOnlineLightsCap> kitchenMainLights;
extern shared_ptr<TwoWayButton> kitchenMainSwitch;
extern shared_ptr<DhtTempOnline> kitchenOnlineTemp;

void setupKitchenRules();

/* LIVING ROOM */
extern shared_ptr<DhtTempSensor> LivingRoomTemp;
extern shared_ptr<DefaultLightsCap> LivingRoomLights;
extern shared_ptr<DefaultPowerCap> LivingRoomRelay;
extern shared_ptr<DefaultIRCap> LivingRoomIrReceiver;

void setupLivingRoomRules();

/* CONNECTOR */
extern shared_ptr<MqttClient> mqttDataConnector;

/* CAPABILITIES */
extern vector<shared_ptr<Capability>> capabilities;

inline void addAllRules() {
    setupKitchenRules();
    setupLivingRoomRules();
}

#endif  // BARTOS_HW_CAPABILITIES_INIT_H
