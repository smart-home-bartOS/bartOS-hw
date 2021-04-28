//
// Created by mabartos on 4/28/21.
//

#include <Arduino.h>
#include <memory>
#include <core/device/Device.h>
#include <temp/default/DhtTempSensor.h>
#include <lights/default/DefaultLightsCap.h>

shared_ptr<DhtTempSensor> TempSensor = make_shared<DhtTempSensor>(D5, 22);
shared_ptr<DefaultLightsCap> MainLights = make_shared<DefaultLightsCap>(D6, "MainLights");

using namespace std;

vector<shared_ptr<Capability>> Capabilities;
shared_ptr<Device> Device;

inline void addRules() {
    TempSensor->loopEventHandler()->period("PrintEach2s", 2000, []() {
        Serial.println(TempSensor->getTemperature());
    });

    TempSensor->executeEventHandler()->add("Up25TurnLights", []() {
        if (TempSensor->getTemperature() > 25.0) {
            MainLights->turnOn();
        } else if (TempSensor->getTemperature() > 30.0) {
            MainLights->turnOff();
        }
    });

    MainLights->loopEventHandler()->timer("TurnOffAfter1minute", 60000, []() {
        Serial.println("Lights are turned off");
        MainLights->turnOff();
    });
    
    Capabilities.push_back(TempSensor);
    Capabilities.push_back(MainLights);
}

void setup() {
    Serial.begin(9600);
    delay(100);

    addRules();

    Device->setCapabilities(Capabilities);
    Device->init();
}

void loop() {
    Device->loop();
}