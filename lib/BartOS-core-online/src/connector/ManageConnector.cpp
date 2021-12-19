#include "connector/ManageConnector.h"

ManageConnector::ManageConnector(const string& baseURL) : OnlineConnector(baseURL) {}

OnlineDevice* ManageConnector::getOnlineDevice() {
    return _device;
}

void ManageConnector::setOnlineDevice(OnlineDevice* device) {
    _device = device;
}