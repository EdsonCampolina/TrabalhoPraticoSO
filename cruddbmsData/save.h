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
