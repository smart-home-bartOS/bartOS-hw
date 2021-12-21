#include "connector/DataHandler.h"

DynamicJsonDocument DataHandler::getData() {
    DynamicJsonDocument doc(5);
    return doc;
}

void DataHandler::handleData(DynamicJsonDocument &data){};

vector<string> DataHandler::getSubscribedPaths() {
    vector<string> v;
    return v;
};

void DataHandler::handleData(const string &path, DynamicJsonDocument &data) {
    if (strlen(path.c_str()) == 0) return;

    auto it = _messageCallbacks.equal_range(path);
    for (auto itr = it.first; itr != it.second; ++itr) {
        itr->second(data);
    }
}

void DataHandler::onMessage(const string &path, DataCallback callback) {
    if (path.empty()) return;
    _messageCallbacks.insert({path, callback});
}

void DataHandler::removeMessageEvent(const string &path) {
    if (path.empty()) return;
    _messageCallbacks.erase(path);
}

void DataHandler::removeMessageEvents() {
    _messageCallbacks.clear();
}