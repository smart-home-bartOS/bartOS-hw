#include "connector/DataConnector.h"

#include <map>
using std::make_shared;
using std::multimap;

DataConnector::DataConnector(const string &baseURL) : OnlineConnector(baseURL) {
}

void DataConnector::notify(const string &path, DynamicJsonDocument &data) {
    auto it = _dataHandlers.equal_range(path);

    for (auto itr = it.first; itr != it.second; ++itr) {
        itr->second->handleData(data);
    }
}

void DataConnector::subscribe(const string &path, shared_ptr<DataHandler> handler) {
    _dataHandlers.insert({path, handler});
}

void DataConnector::subscribe(vector<string> paths, shared_ptr<DataHandler> handler) {
    for (auto &path : paths) {
        subscribe(path, handler);
    }
}

void DataConnector::unsubscribe(vector<string> paths) {
    for (auto &path : paths) {
        unsubscribe(path);
    }
}

void DataConnector::unsubscribe(const string &path) {
    _dataHandlers.erase(path);
}

unordered_multimap<string, shared_ptr<DataHandler>> DataConnector::getDataHandlers() {
    return _dataHandlers;
}

vector<string> DataConnector::getDataHandlersKeys() {
    vector<string> keys;

    for (auto const &item : getDataHandlers()) {
        keys.push_back(item.first);
    }
    return keys;
}