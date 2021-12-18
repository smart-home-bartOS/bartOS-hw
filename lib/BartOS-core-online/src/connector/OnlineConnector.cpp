#include "connector/OnlineConnector.h"

OnlineConnector::OnlineConnector(const string &url) : _baseURL(url) {
}

string OnlineConnector::getBaseURL() {
    return _baseURL;
}

void OnlineConnector::setBaseURL(const string &baseURL) {
    _baseURL = baseURL;
}
