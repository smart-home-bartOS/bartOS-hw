//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_CAPABILITIES_INIT_H
#define BARTOS_HW_CAPABILITIES_INIT_H

using namespace std;

#include <memory>
#include <core/callback/utils/CallbackType.h>
#include <core/callback/utils/CallbackUtils.h>

#include <temp/default/DhtTempSensor.h>
#include <mqtt-data/MqttClient.h>
#include <http-manage/HttpManageDeviceConn.h>
#include <lights/default/DefaultLightsCap.h>
#include <button/default/two-way-button/TwoWayButton.h>
#include <powerAble/default/DefaultPowerCap.h>
#include <lights/default/DefaultLightsCap.h>
#include <temp-online/default/DhtTempOnline.h>

/* KITCHEN */
extern shared_ptr<DhtTempSensor> KitchenTemp;
extern shared_ptr<DefaultLightsCap> KitchenMainLights;
extern shared_ptr<TwoWayButton> KitchenMainSwitch;
extern shared_ptr<DhtTempOnline> KitchenOnlineTemp;

void setupKitchenRules();

/* LIVING ROOM */
extern shared_ptr<DhtTempSensor> LivingRoomTemp;
extern shared_ptr<DefaultLightsCap> LivingRoomLights;
extern shared_ptr<DefaultPowerCap> LivingRoomRelay;

void setupLivingRoomRules();

/* CONNECTOR */
extern shared_ptr<HttpManageDeviceConn> HttpDeviceConnector;
extern shared_ptr<MqttClient> MqttDataConnector;

/* CAPABILITIES */
extern vector<shared_ptr<Capability>> Capabilities;

inline void setupAllCapabilities() {
    setupKitchenRules();
    setupLivingRoomRules();
}

#endif //BARTOS_HW_CAPABILITIES_INIT_H
