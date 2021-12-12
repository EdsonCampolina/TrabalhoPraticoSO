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



/*
------------------------------------------------
# Description
## Method responsible for retrieving data from the file and 
   loading it into a hash table. Then, it looks in the table for 
   the key that was informed by the user and prints on the screen 
   the data that corresponds to that key.
------------------------------------------------
# Parameters
## *arguments
### Type: pointer
### Desc: Pointer to the struct containing the command and arguments entered by the user.
------------------------------------------------
# Return
## Type: NULL
### Var: None
### Desc: NULL is retured.

------------------------------------------------
*/

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
