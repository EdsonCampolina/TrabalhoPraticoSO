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

void writeToLogRecord(char message[SIZECHARMESSAGELOG], record r)
{
    ofstream outdata;
    outdata.open("./log/logs.txt", ios::app);
    if (!outdata)
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    outdata << message << r.sortKey << "," << r.value << "\n";
    outdata.close();
}

void writeToLogNumberOfRecords(char message[SIZECHARMESSAGELOG], int numberOfRecords)
{
    ofstream outdata;
    outdata.open("./log/logs.txt", ios::app);
    if (!outdata)
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    outdata << message << numberOfRecords << "\n";
    outdata.close();
}

#endif
