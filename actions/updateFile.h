#ifndef UPDATETOFILE_H
#define UPDATETOFILE_H

#include <iostream>
#include "../structs/record.h"
#include "../log/writeToLog.h"
#include <fstream>
#include <string>
#include "../utils/utils.h"

void updateFile(record r)
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

    temp.close();
    indata.close();

    const char *p = pathToBD.c_str();
    remove(p);
    rename(pathToTemp.c_str(), pathToBD.c_str());

    char message[] = "Updating key: ";
    writeToLogNumberOfRecords(message, r.key);

    if (!found)
        printf("The key %d was not found \n", r.key);
    else
        printf("The key %d was updated \n", r.key);
}

#endif