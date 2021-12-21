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

   protected:
    unordered_multimap<string, shared_ptr<DataHandler>> getDataHandlers();
    vector<string> getDataHandlersKeys();

    virtual void subscribe(const string &path, shared_ptr<DataHandler> handler);
    virtual void subscribe(vector<string> paths, shared_ptr<DataHandler> handler);

    virtual void unsubscribe(vector<string> paths);
    virtual void unsubscribe(const string &path);

   public:
    DataConnector(const string &baseURL);
    DataConnector() = default;
    ~DataConnector() = default;

    virtual void sendData(const string &path, DynamicJsonDocument &data) = 0;

    virtual void notify(const string &path, DynamicJsonDocument &data);
};

#endif  // BARTOS_HW_DATA_CONNECTOR_H