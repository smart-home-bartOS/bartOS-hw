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

void DataConnector::executeMessageEvent(const char *path, DynamicJsonDocument &doc) {
    if (strlen(path) == 0) return;

    auto it = _messageCallbacks.find(path);
    if (it != _messageCallbacks.end()) {
        it->second(doc);
    }
}

void DataConnector::onMessage(const string &path, DataCallback callback) {
    if (path.empty()) return;

    _messageCallbacks.insert({path, callback});
}

void DataConnector::removeMessageEvent(const string &path) {
    if (path.empty()) return;
    _messageCallbacks.erase(path);
}

void DataConnector::removeMessageEvents() {
    _messageCallbacks.clear();
}