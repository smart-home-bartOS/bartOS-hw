#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <ESP8266HTTPClient.h>

#include <string>

#include "HttpResponse.h"

using std::string;

enum class HttpMethod {
    GET,
    POST,
    PATCH,
    PUT,
    DELETE
};

class BartHttpClient {
   private:
    string _serverURL = "";

    void setUpClient(HTTPClient &client, const string &path);

    HttpResponse execute(HttpMethod method, const string &path);

    HttpResponse execute(HttpMethod method, const string &path, const string &body);

   public:
    BartHttpClient(const string &serverURL);

    BartHttpClient() = default;

    ~BartHttpClient() = default;

    string getServerURL();

    void setServerURL(const string &serverURL);

    HttpResponse doGet(const string &path);

    HttpResponse doPost(const string &path, const string &body);

    HttpResponse doPatch(const string &path, const string &body);

    HttpResponse doDelete(const string &path);

    HttpResponse doDelete(const string &path, const string &body);
};

#endif  // HTTP_CLIENT_H