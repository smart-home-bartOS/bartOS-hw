//
// Created by mabartos on 4/21/21.
//

#include "BartFS.h"
#include <Arduino.h>
#include "LittleFS.h"

BartFS::BartFS(const string &configFileName) :
        FsManager(configFileName) {
}

DynamicJsonDocument BartFS::readStorage(const string &filePath, const string &mode) {
    DynamicJsonDocument empty(5);
    if (LittleFS.begin() && LittleFS.exists(filePath.c_str())) {
        File file = LittleFS.open(filePath.c_str(), mode.c_str());
        if (file) {
            size_t size = file.size();
            DynamicJsonDocument doc(size + 50);
            std::unique_ptr<char[]> buf(new char[size + 50]);
            file.readBytes(buf.get(), size);

            DeserializationError err = deserializeJson(doc, buf.get());
            if (err != DeserializationError::Ok) {
                Serial.println("Cannot deserialize file");
                file.close();
                return empty;
            }
            file.close();
            LittleFS.end();
            return doc;
        } else {
            Serial.println("Cannot open file");
            LittleFS.end();
            return empty;
        }
    } else {
        Serial.println("Cannot find file");
    }
    return empty;
}

bool BartFS::saveToStorage(const string &filePath,
                           const DynamicJsonDocument &doc,
                           const string &mode) {
    if (!LittleFS.begin()) return false;

    File file = LittleFS.open(filePath.c_str(), mode.c_str());
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
    LittleFS.end();
    return true;
}