#include "HttpResponse.h"

HttpResponse::HttpResponse(const int &code, const string &payload) : _code(code), _payload(payload) {
}

DynamicJsonDocument &HttpResponse::getPayloadJSON() {
    const size_t size = _payload.size();
    DynamicJsonDocument doc(size + 30);

    DeserializationError err = deserializeJson(doc, getPayload().c_str(), size);
    if (err != DeserializationError::Ok) {
        Serial.println(err.c_str());
        return doc;
    }

    return doc;
}

int HttpResponse::getResponseCode() {
    return _code;
}

void HttpResponse::setResponseCode(int code) {
    _code = code;
}

string &HttpResponse::getPayload() {
    return _payload;
}

void HttpResponse::setPayload(const string &payload) {
    _payload = payload;
}

void HttpResponse::setPayload(const char *payload) {
    _payload = string(payload);
}