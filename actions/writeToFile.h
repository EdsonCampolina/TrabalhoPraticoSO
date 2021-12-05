#ifndef WRITETOFILE_H
#define WRITETOFILE_H

#include <iostream>
#include "../structs/record.h"
#include "../log/writeToLog.h"
#include <fstream>
#include <string>
#include "../utils/utils.h"

using namespace std;
using std::cerr;
using std::endl;
using std::ofstream;

void writeToFile(record r)
{
    std::string line;
    std::ifstream indata;

    std::string pathToBD = "./bd/bd.txt";
    std::string pathToTemp = "./bd/temp.txt";

    indata.open(pathToBD.c_str());
    std::ofstream temp;
    temp.open(pathToTemp.c_str());
    bool found = false;

    while (getline(indata, line))
    {
        if (HASH_FN(r.key) != stoi(line.c_str()))
        {
            temp << line << std::endl;
        }
        else
        {
            temp << HASH_FN(r.key) << "," << r.sortKey << "," << r.value << "\n";
            found = true;
        }
    }

    if (!found)
    {
        temp << HASH_FN(r.key) << "," << r.sortKey << "," << r.value << "\n";
    }
    const char *p = pathToBD.c_str();
    remove(p);
    rename(pathToTemp.c_str(), pathToBD.c_str());
    temp.close();
    printf("Key inserted: %d \n", r.key);
}

#endif
