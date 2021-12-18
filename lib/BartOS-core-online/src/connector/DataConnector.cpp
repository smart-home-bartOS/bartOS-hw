#include "connector/DataConnector.h"

using std::make_shared;

DataConnector::DataConnector(const string &baseURL) : OnlineConnector(baseURL) {
}

void DataConnector::notify(string path, JsonObject data) {
    auto it = _dataHandlers.equal_range(path);

    for (auto itr = it.first; itr != it.second; ++itr) {
        itr->second->handleData(data);
    }
}

void DataConnector::subscribe(string path, DataHandler handler) {
    _dataHandlers.insert({path, make_shared<DataHandler>(handler)});
}

void DataConnector::subscribe(vector<string> paths, DataHandler handler) {
    for (auto &path : paths) {
        subscribe(path, handler);
    }
}

void DataConnector::unsubscribe(vector<string> paths) {
    for (auto &path : paths) {
        unsubscribe(path);
    }
}

void DataConnector::unsubscribe(string path) {
    _dataHandlers.erase(path);
}