#ifndef TRANSLATEUPDATEARGSH
#define TRANSLATEUPDATEARGSH

#include <stdio.h>
#include <string.h>
#include <fstream>
#include "../structs/record.h"
#include "../utils/utils.h"


/*
------------------------------------------------
# Description
## The method is responsible for separating each part of the 
   command from the string informed by the user before performing 
   the data update itself.
------------------------------------------------
# Parameters
## entrada
### Type: char
### Desc: input value entered by the user.
------------------------------------------------
# Return
## Type: record
### Var: r
### Desc: int of the key entered by the user.

------------------------------------------------
*/


record translateUpdateArgs(char entrada[SIZECHARINPUT])
{
    char inputs[3][SIZECHARINPUT], value[SIZECHARINPUT];
    int sizeInputs[3];
    sizeInputs[1] = 0;
    int i, j = 0, k = commandsSize[0], sortKey, key;
    bool argRecognized = false;
    record r;

    memset(inputs[0], 0, sizeof inputs[0]);
    memset(inputs[1], 0, sizeof inputs[1]);
    memset(inputs[2], 0, sizeof inputs[2]);

    for (i = k; i < SIZECHARINPUT; i++)
    {

        switch (entrada[i])
        {
        case ',':
            j++;
            sizeInputs[j] = i - k;
            k = i + 1;
            break;
        default:
            inputs[j][i - k] = entrada[i];
            if (j == 2)
            {
                sizeInputs[j]++;
                if (!argRecognized)
                    argRecognized = true;
            }
        }
    }

    if (argRecognized)
    {
        key = atoi(inputs[0]);
        sortKey = atoi(inputs[1]);
        strncpy(value, inputs[2], sizeInputs[2]);
        r = setRecord(sortKey, value, true);
        r.key = key;
    }
    else
    {
        printf("Update message not well formatted. \n");
        r = setRecord(sortKey, value, false);
    }
    return r;
}

#endif
