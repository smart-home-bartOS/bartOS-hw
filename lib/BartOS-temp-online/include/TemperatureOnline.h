#ifndef TEMPERATURE_ONLINE_H
#define TEMPERATURE_ONLINE_H

#include <TemperatureCap.h>

#include <string>
using std::string;

class TemperatureOnline : public OnlineCapability<TemperatureCap> {
   public:
    static const char *TEMP;
    static const char *UNITS;

    TemperatureOnline(TemperatureCap *capability);

    ~TemperatureOnline() = default;

    DynamicJsonDocument getData() override;
    void handleData(DynamicJsonDocument &data) override;
    vector<string> getSubscribedPaths() override;
};

#endif  // TEMPERATURE_ONLINE_H