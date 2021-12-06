#ifndef SEARCHFROMFILE_H
#define SEARCHFROMFILE_H

#include <iostream>
#include "../structs/record.h"
#include "../log/writeToLog.h"
#include <fstream>
#include <string>
#include "../utils/utils.h"

using namespace std;
using std::cerr;
using std::endl;
using std::ifstream;

static void *searchFomFile(void *arguments)
{
    struct arg_struct *args = (struct arg_struct *)arguments;
    ifstream indata;
    indata.open("./bd/bd.txt");
    int num, a;
    bool found = false;

    char message[] = "Search for key: ";

    std::string line;
    while (std::getline(indata, line))
    {
        if (HASH_FN(args->com.commandRecord.key) == stoi(line.c_str()))
        {
            printf("%s \n", line.c_str());
            found = true;
            break;
        }
    }
    if (!found)
        printf("The key %d was not found \n", args->com.commandRecord.key);

    return NULL;
}

#endif
