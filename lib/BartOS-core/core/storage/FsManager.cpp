#include "FsManager.h"

#include <memory>

#include "FS.h"

const string FsManager::READ_MODE = "r";
const string FsManager::WRITE_MODE = "w";

const int32_t FsManager::DEFAULT_FILE_SIZE = 1520;

FsManager::FsManager(const string &configFileName) :
        _configFile(configFileName) {
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