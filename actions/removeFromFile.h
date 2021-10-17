#ifndef REMOVEFROMFILE_H
#define REMOVEFROMFILE_H

#include <iostream>
#include "../structs/record.h"
#include "../log/writeToLog.h"
#include <fstream>
#include <string>

using namespace std;
using std::cerr;
using std::endl;
using std::ifstream;

void removeFromFile(int key)
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
        if (key != stoi(line.c_str()))
        {
            temp << line << std::endl;
        }
        else
        {
            found = true;
        }
    }

    temp.close();
    indata.close();

    const char *p = pathToBD.c_str();
    remove(p);
    rename(pathToTemp.c_str(), pathToBD.c_str());

    char message[] = "Removing key: ";
    writeToLogNumberOfRecords(message, key);

    if (!found)
        printf("The key %d was not found \n", key);
    else
        printf("The key %d was removed \n", key);
}

#endif
