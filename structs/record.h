#ifndef RECORD_H
#define RECORD_H

#include <string>
#include "../utils/utils.h"

struct record
{
    int sortKey;
    char value[SIZECHARINPUT];
    int key;
    bool dataOk;
    char listType[10];
};

record setRecord(int inputKey, char inputValue[SIZECHARINPUT], bool inputStatus)
{
    record r;
    r.sortKey = inputKey;
    strcpy(r.value, inputValue);
    r.dataOk = inputStatus;
    return r;
}

#endif
