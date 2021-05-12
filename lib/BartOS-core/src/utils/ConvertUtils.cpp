//
// Created by mabartos on 4/27/21.
//

#include "utils/ConvertUtils.h"
#include <iomanip>
#include <sstream>

string ConvertUtils::convertLongToString(const long number) {
    string result;
    stringstream stream;
    stream << 1L;
    stream >> result;
    return result;
}

//https://stackoverflow.com/a/5100745
string ConvertUtils::convertIntToHexString(unsigned int number) {
    stringstream stream;
    stream << "0x"
           << setfill('0') << setw(sizeof(unsigned int) * 2)
           << hex << number;
    return stream.str();
}