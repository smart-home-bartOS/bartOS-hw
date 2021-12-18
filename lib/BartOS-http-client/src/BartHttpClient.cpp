#include "BartHttpClient.h"

BartHttpClient::BartHttpClient(const string &serverURL) : _serverURL(serverURL) {
}

void BartHttpClient::setUpClient(HTTPClient &client, const string &path) {
    string resultPath = _serverURL + "/" + path;

    client.begin(resultPath.c_str());

    client.addHeader("Content-Type", "application/json");
}

string BartHttpClient::getServerURL() {
    return _serverURL;
}

void BartHttpClient::setServerURL(const string &serverURL) {
    _serverURL = serverURL;
}

HttpResponse BartHttpClient::execute(HttpMethod method, const string &path) {
    return execute(method, path, "");
}

HttpResponse BartHttpClient::execute(HttpMethod method, const string &path, const string &body) {
    HTTPClient http;
    HttpResponse resp;

    setUpClient(http, path);
    int code = 0;

    switch (method) {
        case HttpMethod::GET:
            code = http.GET();
            break;
        case HttpMethod::POST:
            code = http.POST(body.c_str());
            break;
        case HttpMethod::PATCH:
            code = http.PATCH(body.c_str());
            break;
        case HttpMethod::PUT:
            code = http.PUT(body.c_str());
            break;
        case HttpMethod::DELETE:
            code = http.sendRequest("DELETE", body.c_str());
            break;
    }

    resp.setResponseCode(code);
    if (code > 0) {
        resp.setPayload(http.getString().c_str());
    }

    http.end();
    return resp;
}

HttpResponse BartHttpClient::doGet(const string &path) {
    return execute(HttpMethod::GET, path);
}

HttpResponse BartHttpClient::doPost(const string &path, const string &body) {
    return execute(HttpMethod::POST, path, body);
}

HttpResponse BartHttpClient::doPatch(const string &path, const string &body) {
    return execute(HttpMethod::PATCH, path);
}

HttpResponse BartHttpClient::doDelete(const string &path, const string &body) {
    return execute(HttpMethod::DELETE, path, body);
}

HttpResponse BartHttpClient::doDelete(const string &path) {
    return doDelete(path, "");
}
