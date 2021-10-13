#ifndef RECORD_H
#define RECORD_H

#include <string>

struct record
{
    int sortKey;
    char value[100];
    bool dataOk;
};

record setRecord(int inputKey, char inputValue[100], bool inputStatus)
{
    record r;
    r.sortKey = inputKey;
    strcpy(r.value, inputValue);
    r.dataOk = inputStatus;
    return r;
}

#endif
