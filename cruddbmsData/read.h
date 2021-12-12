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

/*
------------------------------------------------
# Description
## Method responsible for returning the last key assigned to a record, 
   so that the next record receives as a key an integer following the 
   one returned by the function.
------------------------------------------------
# Parameters
## None
### Type: None
### Desc: no parameters need to be passed.
------------------------------------------------
# Return
## Type: int
### Var: num
### Desc: the key assigned to the last record stored in the database.

------------------------------------------------
*/

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
