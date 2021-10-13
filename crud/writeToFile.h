#ifndef WRITETOFILE_H
#define WRITETOFILE_H

#include <iostream>
#include "../structs/record.h"
#include "../log/writeToLog.h"
#include <fstream>
#include <string>

using namespace std;
using std::cerr;
using std::endl;
using std::ofstream;

void writeToFile(record r)
{
    ofstream outdata;
    outdata.open("./bd.txt", ios::app);
    if (!outdata)
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    outdata << r.sortKey << "," << r.value << "\n";
    outdata.close();
    printf("Key inserted: %d \n", r.sortKey);

    char message[] = "Insertion: ";

    writeToLog(message, r);

}

#endif
