#ifndef CAPABILITY_FIELDS_H
#define CAPABILITY_FIELDS_H

#include <string>
#include <vector>
using namespace std;

const string& PIN = "pin";
const string& TYPE = "type";

const vector<string> CAPABILITY_FIELDS{
    PIN,
    TYPE};

#endif  //CAPABILITY_FIELDS_H