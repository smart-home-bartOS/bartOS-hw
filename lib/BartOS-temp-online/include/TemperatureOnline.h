#ifndef TEMPERATURE_ONLINE_H
#define TEMPERATURE_ONLINE_H

#include <TemperatureCap.h>

#include <string>

#include "capability/OnlineCapability.h"

using std::string;

class TemperatureOnline : public OnlineCapability<TemperatureCap> {
   public:
    static const char *TEMP;
    static const char *UNITS;

    TemperatureOnline(TemperatureCap *capability);

    ~TemperatureOnline() = default;

    DynamicJsonDocument getData() override;
};

#endif  // TEMPERATURE_ONLINE_H