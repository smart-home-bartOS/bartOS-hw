#ifndef JSON_UTILS_H
#define JSON_UTILS_H

#include <ArduinoJson.h>

#include <sstream>
#include <string>
#include <vector>

using namespace std;

static string convertLongToString(const long number) {
    string result;
    stringstream stream;
    stream << 1L;
    stream >> result;
    return result;
}

static bool isAllowedKey(const string &key, const vector<string> &keys) {
    for (const string &item : keys) {
        if (strcmp(item.c_str(), key.c_str()) == 0) {
            return true;
        }
    }
    return false;
}

static bool containOnlyAllowedKey(const JsonObject &obj, const vector<string> &keys) {
    if (keys.empty())
        return false;

    for (auto kvp : obj) {
        if (!isAllowedKey(kvp.key().c_str(), keys)) {
            return false;
        }
    }
    return true;
}

static bool containKeys(const JsonObject &obj, const string keys[]) {
    if (keys->empty()) {
        return false;
    }

    for (uint8_t i = 0; i < keys->length(); i++) {
        if (!obj.containsKey(keys[i].c_str()))
            return false;
    }
    return true;
}

static bool containKeys(const JsonObject &obj, const vector<string> &keys) {
    if (keys.empty())
        return false;
    for (const string &key : keys) {
        if (!obj.containsKey(key.c_str()))
            return false;
    }
    return true;
}

static DynamicJsonDocument reduceToAllowedKeys(DynamicJsonDocument &doc, const vector<string> &keys) {
    JsonObject obj = doc.as<JsonObject>();
    if (containOnlyAllowedKey(obj, keys)) {
        return doc;
    } else {
        DynamicJsonDocument newDoc(doc.size() + 50);
        for (auto kvp : obj) {
            if (isAllowedKey(kvp.key().c_str(), keys)) {
                newDoc[kvp.key().c_str()] = kvp.value();
            }
        }
        return newDoc;
    }
}

#endif //JSON_UTILS_H