#ifndef BARTOS_HW_DATA_HANDLER_H
#define BARTOS_HW_DATA_HANDLER_H

#include <ArduinoJson.h>

#include <string>
#include <vector>

#include "callback/DataCallback.h"

using std::string;
using std::unordered_multimap;
using std::vector;

class DataHandler {
   private:
    unordered_multimap<string, DataCallback> _messageCallbacks;

   public:
    DataHandler() = default;
    ~DataHandler() = default;

    virtual DynamicJsonDocument getInfo() = 0;
    virtual DynamicJsonDocument getData();
    virtual void handleData(DynamicJsonDocument &data);
    virtual vector<string> getSubscribedPaths();

    void handleData(const string &path, DynamicJsonDocument &data);
    void onMessage(const string &path, DataCallback callback);
    void removeMessageEvent(const string &path);
    void removeMessageEvents();
};

#endif  // BARTOS_HW_DATA_HANDLER_H