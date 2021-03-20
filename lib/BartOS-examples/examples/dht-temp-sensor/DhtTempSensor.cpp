//
// Created by mabartos on 3/20/21.
//
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include "DhtTempSensor.h"

//DHT dht;

DhtTempSensor::DhtTempSensor(const uint8_t &pin) : TemperatureCap(pin, "DHT") {}

void DhtTempSensor::init() {
    //dht.begin();
}

void DhtTempSensor::execute() {
    /*float temp = dht.readTemperature();

    if (!isnan(temp)) {
        setTemperature(temp);
    }*/
}