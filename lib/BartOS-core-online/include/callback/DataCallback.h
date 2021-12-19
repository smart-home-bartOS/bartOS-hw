#ifndef BARTOS_HW_DATA_CALLBACK_H
#define BARTOS_HW_DATA_CALLBACK_H

#include <ArduinoJson.h>

#include <functional>
using std::function;

typedef function<void(DynamicJsonDocument &)> DataCallback;

#endif  // BARTOS_HW_DATA_CALLBACK_H