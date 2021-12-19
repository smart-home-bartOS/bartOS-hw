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

    virtual DynamicJsonDocument getData() {
        DynamicJsonDocument doc(5);
        return doc;
    }

    virtual DynamicJsonDocument getInfo() = 0;

    virtual void handleData(DynamicJsonDocument &data){};

    virtual vector<string> getSubscribedPaths() {
        vector<string> v;
        return v;
    };
};

#endif  // BARTOS_HW_DATA_HANDLER_H