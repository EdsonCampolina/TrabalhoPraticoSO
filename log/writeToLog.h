#ifndef WRITETOLOG_H
#define WRITETOLOG_H

#include "../structs/record.h"
#include <iostream>
#include <fstream>
using namespace std;
using std::cerr;
using std::endl;
using std::ofstream;

void writeToLog(char message[100], record r)
{
    ofstream outdata;
    outdata.open("./logs.txt", ios::app);
    if (!outdata)
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    outdata << message << r.sortKey << "," << r.value << "\n";
    outdata.close();
}


#endif
