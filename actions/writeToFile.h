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


/*
------------------------------------------------
# Description
## Method responsible for retrieving data from the file and loading 
   it into a hash table. Then, it inserts the data entered by the user 
   in the table into the table. At the end of the operation, a temporary 
   file is saved with the changes made, the previous file is removed and 
   the temporary file is renamed, becoming the main file.
------------------------------------------------
# Parameters
## *arguments
### Type: pointer
### Desc: Pointer to the struct containing the command and arguments entered by the user.
------------------------------------------------
# Return
## Type: None
### Var: None
### Desc: nothing is retured.

------------------------------------------------
*/

static void *writeToFile(void *arguments)
{
    struct arg_struct *args = (struct arg_struct *)arguments;
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
        if (HASH_FN(args->com.commandRecord.key) != stoi(line.c_str()))
        {
            temp << line << std::endl;
        }
        else
        {
            temp << HASH_FN(args->com.commandRecord.key) << "," << args->com.commandRecord.sortKey << "," << args->com.commandRecord.value << "\n";
            found = true;
        }
    }

    if (!found)
    {
        temp << HASH_FN(args->com.commandRecord.key) << "," << args->com.commandRecord.sortKey << "," << args->com.commandRecord.value << "\n";
    }
    const char *p = pathToBD.c_str();
    remove(p);
    rename(pathToTemp.c_str(), pathToBD.c_str());
    temp.close();
    printf("Key inserted: %d \n", args->com.commandRecord.key);
}

#endif
