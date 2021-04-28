#include "FsManager.h"

#include <memory>

const string FsManager::READ_MODE = "r";
const string FsManager::WRITE_MODE = "w";
const string FsManager::APPEND_MODE = "a";

const string FsManager::READ_APPEND_MODE = "a+";
const string FsManager::READ_WRITE_MODE = "r+";
const string FsManager::READ_WRITE_TRUNC_MODE = "w+";

const int32_t FsManager::DEFAULT_FILE_SIZE = 1520;

FsManager::FsManager(const string &configFileName) :
        _configFile(configFileName) {
}

void FsManager::init() {}

bool FsManager::appendToStorage(const string &filePath, const DynamicJsonDocument &doc) {
    return saveToStorage(filePath, doc, APPEND_MODE);
}

string FsManager::getConfigFileName() {
    return _configFile;
}

void FsManager::setConfigFileName(const string &configFileName) {
    _configFile = configFileName;
}

DynamicJsonDocument FsManager::readConfigFile() {
    return readStorage(getConfigFileName());
}

bool FsManager::saveToConfigFile(const DynamicJsonDocument &doc) {
    return saveToStorage(getConfigFileName(), doc);
}

bool FsManager::appendToConfigFile(const DynamicJsonDocument &doc) {
    return saveToStorage(getConfigFileName(), doc, APPEND_MODE);
}