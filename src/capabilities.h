#ifndef CAPABILITIES_H
#define CAPABILITIES_H

#include <memory>
#include <vector>
#include <examples/dht-temp-sensor/DhtTempSensor.h>

vector<shared_ptr<Capability>> CAPABILITIES{
        make_shared<DhtTempSensor>(D7)
};

#endif //CAPABILITIES_H