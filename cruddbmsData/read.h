#ifndef READFROMDATAFILE_H
#define READFROMDATAFILE_H

#include <iostream>
#include "../structs/record.h"
#include "../log/writeToLog.h"
#include <fstream>
#include <string>

using namespace std;
using std::cerr;
using std::endl;
using std::ifstream;

int readFromDataFile()
{
    ifstream indata;
    indata.open("./cruddbmsData/data.txt");
    int num;

    if (indata)
        indata >> num;

    return num;
}

#endif
