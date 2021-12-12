#ifndef REMOVEFROMFILE_H
#define REMOVEFROMFILE_H

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



/*
------------------------------------------------
# Description
## Method responsible for retrieving data from the file and loading 
   them into a Hash Table. Then, it searches the table for the key that 
   was informed by the user and removes the data from the table. At the end 
   of the operation, a temporary file is written with the changes made, the 
   previous file is removed and the temporary file is renamed, becoming the main file.
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

static void *removeFromFile(void *arguments)
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
            found = true;
        }
    }

    temp.close();
    indata.close();

    const char *p = pathToBD.c_str();
    remove(p);
    rename(pathToTemp.c_str(), pathToBD.c_str());

    if (!found)
        printf("The key %d was not found \n", args->com.commandRecord.key);
    else
        printf("The key %d was removed \n", args->com.commandRecord.key);

    return NULL;
}

#endif
