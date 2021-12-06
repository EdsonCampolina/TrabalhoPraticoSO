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
