//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_CAPABILITIES_INIT_H
#define BARTOS_HW_CAPABILITIES_INIT_H

using namespace std;

#include <memory>
#include <core/callback/utils/CallbackType.h>
#include <core/callback/utils/CallbackUtils.h>

#include <online-device/device/OnlineDevice.h>
#include <temp/default/DhtTempSensor.h>
#include <mqtt-data/MqttClient.h>
#include <http-manage/HttpManageDeviceConn.h>
#include <lights-online/default/DefaultOnlineLightsCap.h>
#include <button/default/two-way-button/TwoWayButton.h>
#include <powerAble/default/DefaultPowerCap.h>
#include <lights/default/DefaultLightsCap.h>
#include <temp-online/default/DhtTempOnline.h>
#include <fs/BartFS.h>
#include <online-device/device/OnlineDevice.h>
#include <wifi-manager/default/DefaultWifiManager.h>
#include <ir/default/DefaultIRCap.h>

/* DEVICE */
extern shared_ptr<OnlineDevice> Device;
extern shared_ptr<BartFS> StorageManager;
extern shared_ptr<DefaultWifiManager> WifiManager;

void setUpWifiManager();

/* KITCHEN */
extern shared_ptr<DhtTempSensor> KitchenTemp;
extern shared_ptr<DefaultOnlineLightsCap> KitchenMainLights;
extern shared_ptr<TwoWayButton> KitchenMainSwitch;
extern shared_ptr<DhtTempOnline> KitchenOnlineTemp;

void setupKitchenRules();

/* LIVING ROOM */
extern shared_ptr<DhtTempSensor> LivingRoomTemp;
extern shared_ptr<DefaultLightsCap> LivingRoomLights;
extern shared_ptr<DefaultPowerCap> LivingRoomRelay;
extern shared_ptr<DefaultIRCap> LivingRoomIrReceiver;

void setupLivingRoomRules();

/* CONNECTOR */
extern shared_ptr<HttpManageDeviceConn> HttpDeviceConnector;
extern shared_ptr<MqttClient> MqttDataConnector;

/* CAPABILITIES */
extern vector<shared_ptr<Capability>> Capabilities;

inline void addAllRules() {
    setupKitchenRules();
    setupLivingRoomRules();

    //setUpWifiManager();
}

#endif //BARTOS_HW_CAPABILITIES_INIT_H
