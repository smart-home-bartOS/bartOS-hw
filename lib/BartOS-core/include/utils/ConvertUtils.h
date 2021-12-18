//
// Created by mabartos on 4/27/21.
//

#ifndef BARTOS_HW_CONVERTUTILS_H
#define BARTOS_HW_CONVERTUTILS_H

#include <string>
using std::string;

class ConvertUtils {
   public:
    static string convertLongToString(const long number);

    static string convertIntToHexString(unsigned int);
};

#endif  // BARTOS_HW_CONVERTUTILS_H
