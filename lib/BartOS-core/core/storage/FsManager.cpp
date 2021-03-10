#include "FsManager.h"

#include <LittleFS.h>

#include "FS.h"

FsManager::FsManager() {
}

DynamicJsonDocument FsManager::readStorage(const string& filePath) {
    DynamicJsonDocument doc(DEFAULT_FILE_SIZE);

    if (LittleFS.begin() && LittleFS.exists(filePath.c_str())) {
        File file = LittleFS.open(filePath.c_str(), READ_MODE.c_str());
        if (file) {
            size_t size = file.size();

            std::unique_ptr<char[]> buf(new char[size + 100]);
            file.readBytes(buf.get(), size);

            DeserializationError err = deserializeJson(doc, buf.get());
            if (err != DeserializationError::Ok) {
                Serial.println("Cannot deserialize file");
            }

            file.close();
        } else {
            Serial.println("Cannot open file");
        }
    } else {
        Serial.println("Cannot find file");
    }

    return doc;
}

DynamicJsonDocument FsManager::readConfigFile() {
    return readStorage(CONFIG_FILE);
}

bool FsManager::saveToStorage(const string& filePath, const DynamicJsonDocument& doc) {
    File file = LittleFS.open(filePath.c_str(), WRITE_MODE.c_str());
    if (!file) {
        Serial.println("Cannot save to storage.");
        return false;
    }

    if (serializeJson(doc, file) == 0) {
        Serial.println("Cannot serialize storage file.");
        file.close();
        return false;
    }
    file.close();
    return true;
}

bool FsManager::saveToConfigFile(const DynamicJsonDocument& doc) {
    return saveToStorage(CONFIG_FILE, doc);
}