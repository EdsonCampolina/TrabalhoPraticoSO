#ifndef SEARCHFROMFILE_H
#define SEARCHFROMFILE_H

#include <iostream>
#include "../structs/record.h"
#include "../log/writeToLog.h"
#include <fstream>
#include <string>

using namespace std;
using std::cerr;
using std::endl;
using std::ifstream;

void searchFomFile(int key)
{
    ifstream indata;
    indata.open("./bd/bd.txt");
    int num, a;
    bool found = false;

    char message[] = "Search for key: ";
    writeToLogNumberOfRecords(message, key);

    std::string line;
    while (std::getline(indata, line))
    {
        if (key == stoi(line.c_str()))
        {
            printf("%s \n", line.c_str());
            found = true;
            break;
        }
    }
    if (!found)
        printf("The key %d was not found \n", key);
}

#endif
