#ifndef BARTOS_HW_CAPABILITIES_INIT_H
#define BARTOS_HW_CAPABILITIES_INIT_H

using namespace std;

#include <memory>
#include <callback/utils/CallbackType.h>
#include <callback/utils/CallbackUtils.h>
#include <OnlineDevice.h>
#include <default/DhtTempSensor.h>
#include <MqttClient.h>
#include <HttpManageDeviceConn.h>
#include <default/DefaultOnlineLightsCap.h>
#include <default/two-way-button/TwoWayButton.h>
#include <default/DefaultPowerCap.h>
#include <default/DefaultLightsCap.h>
#include <default/DhtTempOnline.h>
#include <default/BartFS.h>
#include <default/DefaultWifiManager.h>
#include <default/DefaultIRCap.h>

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

    setUpWifiManager();
}

#endif //BARTOS_HW_CAPABILITIES_INIT_H
