#ifndef BARTOS_HW_DATA_CONNECTOR_H
#define BARTOS_HW_DATA_CONNECTOR_H

#include <ArduinoJson.h>

#include <memory>
#include <string>
#include <vector>

#include "connector/DataHandler.h"

using std::shared_ptr;
using std::string;
using std::unordered_map;
using std::vector;

class DataConnector : public OnlineConnector {
   private:
    unordered_map<string, shared_ptr<DataHandler>> _dataHandlers;

   public:
    DataConnector(const string &baseURL);
    DataConnector() = default;
    ~DataConnector() = default;

    virtual void sendData(string path, JsonObject data) = 0;

    virtual void subscribe(string path, DataHandler handler) = 0;
    virtual void subscribe(vector<string> paths, DataHandler handler) = 0;

    virtual void unsubscribe(DataHandler handler) = 0;
    virtual void unsubscribe(string path) = 0;

    virtual void notify(JsonObject data) = 0;
};

#endif  // BARTOS_HW_DATA_CONNECTOR_H