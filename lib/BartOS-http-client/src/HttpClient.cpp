#include "HttpClient.h"

HttpClient::HttpClient(const string &serverURL) : _serverURL(serverURL) {
}

string HttpClient::getServerURL() {
    return _serverURL;
}

void HttpClient::setServerURL(const string &serverURL) {
    _serverURL = serverURL;
}

HttpResponse HttpClient::execute(HttpMethod method, const string &path) {
    return execute(method, path, "");
}

HttpResponse HttpClient::doGet(const string &path) {
    return execute(HttpMethod::GET, path);
}

HttpResponse HttpClient::doPost(const string &path, const string &body) {
    return execute(HttpMethod::POST, path, body);
}

HttpResponse HttpClient::doPatch(const string &path, const string &body) {
    return execute(HttpMethod::PATCH, path);
}

HttpResponse HttpClient::doDelete(const string &path, const string &body) {
    return execute(HttpMethod::DELETE, path, body);
}

HttpResponse HttpClient::doDelete(const string &path) {
    return doDelete(path, "");
}
