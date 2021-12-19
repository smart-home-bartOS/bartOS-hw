#ifndef JSON_UTILS_H
#define JSON_UTILS_H

#include <ArduinoJson.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

static bool isAllowedKey(const string &key, const string keys[]) {
    for (unsigned int i = 0; i < keys->size(); i++) {
        if (strcmp(keys[i].c_str(), key.c_str()) == 0) {
            return true;
        }
    }

    return false;
}

static bool containOnlyAllowedKey(const JsonObject &obj, const string keys[]) {
    if (keys->size() == 0)
        return false;

    for (auto kvp : obj) {
        if (!isAllowedKey(kvp.key().c_str(), keys)) {
            return false;
        }
    }
    return true;
}

static bool containKey(const JsonObject &obj, const string key) {
    return obj.containsKey(key.c_str());
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

static DynamicJsonDocument reduceToAllowedKeys(DynamicJsonDocument &doc, const string keys[]) {
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

#endif  // JSON_UTILS_H