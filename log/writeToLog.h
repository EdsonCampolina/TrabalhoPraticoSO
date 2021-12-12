#ifndef WRITETOLOG_H
#define WRITETOLOG_H

#include "../structs/record.h"
#include <iostream>
#include <fstream>
#include "../utils/utils.h"

using namespace std;
using std::cerr;
using std::endl;
using std::ofstream;

struct arg_struct
{
    string message;
    internalCommand com;
};


/*
------------------------------------------------
# Description
## Method responsible for saving the commands executed in the database 
   in a log file, as well as a message referring to that command.
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

static void *writeToLog(void *arguments)
{
    struct arg_struct *args = (struct arg_struct *)arguments;
    ofstream outdata;
    outdata.open("./log/logs.txt", ios::app);
    if (!outdata)
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    outdata << args->message << args->com.commandRecord.key << "\n";
    outdata.close();

    return NULL;
}

#endif
