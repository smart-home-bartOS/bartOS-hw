#ifndef FILE_SYSTEM_MANAGER_H
#define FILE_SYSTEM_MANAGER_H

#include <ArduinoJson.h>

#include <string>

using namespace std;

class FsManager {
private:
    string _configFile;

public:
    static const string READ_MODE;
    static const string WRITE_MODE;
    static const int32_t DEFAULT_FILE_SIZE;

    FsManager(const string &configFileName = "config.json");

    ~FsManager() = default;

    string getConfigFileName();

    void setConfigFileName(const string &configFileName);

    virtual DynamicJsonDocument readConfigFile();

    virtual bool saveToConfigFile(const DynamicJsonDocument &doc);

    virtual DynamicJsonDocument readStorage(const string &filePath) = 0;

    virtual bool saveToStorage(const string &filePath, const DynamicJsonDocument &doc) = 0;

};

#endif  //FILE_SYSTEM_MANAGER_H