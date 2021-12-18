//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_ONLINECALLBACKUTILS_H
#define BARTOS_HW_ONLINECALLBACKUTILS_H
using namespace std;

#include <ArduinoJson.h>
#include <functional>

typedef function<void(JsonObject &)> PubSubCallback;

#endif //BARTOS_HW_ONLINECALLBACKUTILS_H
