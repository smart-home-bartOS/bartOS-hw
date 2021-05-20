#ifndef BARTOS_HW_CAPABILITIES_INIT_H
#define BARTOS_HW_CAPABILITIES_INIT_H

using namespace std;

#include <Arduino.h>
#include <memory>
#include <callback/utils/CallbackType.h>
#include <callback/utils/CallbackUtils.h>

#include <default/DefaultOnlinePowerCap.h>
#include "device/Device.h"
#include "BasicWifiManager.h"
#include "MqttClient.h"

#define RGB_RELAY_PIN       D8

extern shared_ptr<Device> device;
extern vector<shared_ptr<Capability>> Capabilities;
extern shared_ptr<MqttClient> MqttDataConnector;

extern shared_ptr<DefaultOnlinePowerCap> RgbRelay;

void setupRelaysRules();

#endif //BARTOS_HW_CAPABILITIES_INIT_H
