#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H
using namespace std;

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <callback/CallbackMap.h>

#include <string>
#include "HttpResponse.h"

enum class HttpMethod {
    GET,
    POST,
    PATCH,
    PUT,
    DELETE
};

class HttpClient {
private:
    string _serverURL = "";
    CallbackMap _callbacks;

    void setUpClient(HTTPClient &client, const string &path);

    HttpResponse execute(HttpMethod method, const string &path);

    HttpResponse execute(HttpMethod method, const string &path, const string &body);

public:
    HttpClient(const string &serverURL);

    HttpClient() = default;

    ~HttpClient() = default;

    string getServerURL();

    void setServerURL(const string &serverURL);

    HttpResponse doGet(const string &path);

    HttpResponse doPost(const string &path, const string &body);

    HttpResponse doPatch(const string &path, const string &body);

    HttpResponse doDelete(const string &path);

    HttpResponse doDelete(const string &path, const string &body);
};

#endif  //HTTP_CLIENT_H