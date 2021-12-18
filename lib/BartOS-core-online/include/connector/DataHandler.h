#ifndef BARTOS_HW_DATA_HANDLER_H
#define BARTOS_HW_DATA_HANDLER_H

#include <ArduinoJson.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

class DataHandler {
   public:
    DataHandler() = default;
    ~DataHandler() = default;

    virtual JsonObject getData();
    virtual void handleData(JsonObject data);
    virtual vector<string> getSubscribedPaths();
};

#endif  // BARTOS_HW_DATA_HANDLER_H