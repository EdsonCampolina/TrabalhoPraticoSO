#ifndef WRITETODATAFILE_H
#define WRITETODATAFILE_H

#include <iostream>
#include "../structs/record.h"
#include "../log/writeToLog.h"
#include <fstream>
#include <string>

using namespace std;
using std::cerr;
using std::endl;
using std::ofstream;


/*
------------------------------------------------
# Description
## Method responsible for updating the last key assigned to a record in 
   the 'data.txt' file, so that the next record receives as a key an 
   integer following it.
------------------------------------------------
# Parameters
## numberOfRecords
### Type: int
### Desc: the key assigned to the last record stored in the database.
------------------------------------------------
# Return
## Type: None
### Var: None
### Desc: nothing is retured.

------------------------------------------------
*/

void writeToDataFile(int numberOfRecords)
{
    ofstream outdata;
    outdata.open("./cruddbmsData/data.txt");
    if (!outdata)
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    outdata << numberOfRecords;
    outdata.close();

}

#endif
