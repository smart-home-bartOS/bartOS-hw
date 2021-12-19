//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_HUMIDITYDATA_H
#define BARTOS_HW_HUMIDITYDATA_H

#include <HumidityCap.h>
#include <capability/OnlineCapability.h>

class HumidityOnline : public OnlineCapability<HumidityCap> {
   public:
    static const char *HUMIDITY;

    HumidityOnline(HumidityCap *capability);

    ~HumidityOnline() = default;

    DynamicJsonDocument getData() override;
    vector<string> getSubscribedPaths() override;
};

#endif  // BARTOS_HW_HUMIDITYDATA_H
