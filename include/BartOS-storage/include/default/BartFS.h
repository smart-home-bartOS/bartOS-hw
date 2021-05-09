//
// Created by mabartos on 4/21/21.
//

#ifndef BARTOS_HW_BARTOS_FS_H
#define BARTOS_HW_BARTOS_FS_H
using namespace std;

#include "FsManager.h"
#include <ArduinoJson.h>
#include <string>

class BartFS : public FsManager {
public:
    BartFS(const string &configFileName = "config.json");

    ~BartFS() = default;

    DynamicJsonDocument readStorage(const string &filePath,
                                    const string &mode = READ_MODE) override;

    bool saveToStorage(const string &filePath,
                       const DynamicJsonDocument &doc,
                       const string &mode = WRITE_MODE) override;
};


#endif //BARTOS_HW_BARTOS_FS_H
