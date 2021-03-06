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
    if (keys.size() == 0)
        return false;

    for (auto kvp : obj) {
        bool isAllowed = false;

        for (const string &key : keys) {
            if (strcmp(kvp.key().c_str(), key.c_str()) == 0) {
                isAllowed = true;
                break;
            }
        }

        if (!isAllowed) {
            return false;
        }
    }
    return true;
}

static bool containKeys(const JsonObject &obj, const vector<string> &keys) {
    if (keys.size() == 0)
        return false;

    for (const string &key : keys) {
        if (!obj.containsKey(key.c_str()))
            return false;
    }
    return true;
}