//
// Created by mabartos on 4/28/21.
//

#include <Arduino.h>
#include <default/DefaultLightsCap.h>
#include <default/DhtTempSensor.h>
#include <device/Device.h>

#include <memory>

shared_ptr<DhtTempSensor> tempSensor = make_shared<DhtTempSensor>(D5, 22);
shared_ptr<DefaultLightsCap> mainLights = make_shared<DefaultLightsCap>(D6);

vector<shared_ptr<Capability>> capabilities;
shared_ptr<Device> device;

inline void addRules() {
    tempSensor->scheduler()->period("PrintEach2s", 2000, []() {
        Serial.println(tempSensor->getTemperature());
    });

    tempSensor->actions()->add("Up25TurnLights", []() {
        if (tempSensor->getTemperature() > 25.0) {
            mainLights->turnOn();
        } else if (tempSensor->getTemperature() > 30.0) {
            mainLights->turnOff();
        }
    });

    mainLights->scheduler()->timer("TurnOffAfter1minute", 60000, []() {
        Serial.println("Lights are turned off");
        mainLights->turnOff();
    });

    capabilities.push_back(tempSensor);
    capabilities.push_back(mainLights);
}

void setup() {
    Serial.begin(9600);
    delay(100);

    addRules();

    device->setCapabilities(capabilities);
    device->init();
}

void loop() {
    device->loop();
}