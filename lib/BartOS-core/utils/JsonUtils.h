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

static bool containKeys(const JsonObject &obj, vector<string> &keys) {
    if (keys.size() == 0)
        return false;

    for (string &key : keys) {
        if (!obj.containsKey(key.c_str()))
            return false;
    }
    return true;
}