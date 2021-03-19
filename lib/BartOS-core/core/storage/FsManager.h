#ifndef FILE_SYSTEM_MANAGER_H
#define FILE_SYSTEM_MANAGER_H

#include <ArduinoJson.h>

#include <string>

using namespace std;

static const string READ_MODE = "r";
static const string WRITE_MODE = "w";

static const char *CONFIG_FILE = "/config.json";
static const int32_t DEFAULT_FILE_SIZE = 1520;

class FsManager {
public:
    FsManager();

    ~FsManager() = default;

    DynamicJsonDocument readConfigFile();

    DynamicJsonDocument readStorage(const string &filePath);

    bool saveToStorage(const string &filePath, const DynamicJsonDocument &doc);

    bool saveToConfigFile(const DynamicJsonDocument &doc);
};

#endif  //FILE_SYSTEM_MANAGER_H