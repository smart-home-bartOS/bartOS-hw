#include "default/DefaultHttpClient.h"

DefaultHttpClient::DefaultHttpClient(WiFiClient &wifiClient, const string &serverURL) : HttpClient(serverURL), _wifiClient(wifiClient) {}

HttpResponse DefaultHttpClient::execute(HttpMethod method, const string &path, const string &body) {
    HTTPClient http;

    string resultPath = _serverURL + "/" + path;
    http.begin(_wifiClient, resultPath.c_str());
    http.addHeader("Content-Type", "application/json");

    HttpResponse resp;

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