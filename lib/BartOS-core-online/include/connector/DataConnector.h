#ifndef BARTOS_HW_DATA_CONNECTOR_H
#define BARTOS_HW_DATA_CONNECTOR_H

#include <ArduinoJson.h>

#include <memory>
#include <string>
#include <vector>

#include "connector/DataHandler.h"
#include "connector/OnlineConnector.h"

using std::shared_ptr;
using std::string;
using std::unordered_multimap;
using std::vector;

class DataConnector : public OnlineConnector {
   private:
    unordered_multimap<string, shared_ptr<DataHandler>> _dataHandlers;

   public:
    DataConnector(const string &baseURL);
    DataConnector() = default;
    ~DataConnector() = default;

    virtual void sendData(string path, JsonObject data) = 0;

    virtual void subscribe(string path, DataHandler handler);
    virtual void subscribe(vector<string> paths, DataHandler handler);

    virtual void unsubscribe(vector<string> paths);
    virtual void unsubscribe(string path);

    virtual void notify(string path, JsonObject data);
};

#endif  // BARTOS_HW_DATA_CONNECTOR_H