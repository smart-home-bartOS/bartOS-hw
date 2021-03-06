#ifndef HTTP_PATH_H
#define HTTP_PATH_H

using namespace std;
#include <string>

#include "device/DevicePath.h"

static const string& CONNECT_PATH = "connect";
static const string& CREATE_PATH = "create";

static string getConnectPath(const long homeID) {
    getHomePath(homeID) + "/" + CONNECT_PATH;
}

static string getCreatePath(const long homeID) {
    getHomePath(homeID) + "/" + CREATE_PATH;
}

#endif  //HTTP_PATH_H