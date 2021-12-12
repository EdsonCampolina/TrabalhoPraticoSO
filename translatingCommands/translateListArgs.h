#ifndef TRANSLATELISTARGS_H
#define TRANSLATELISTARGS_H

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
   any action with the informed arguments.
------------------------------------------------
# Parameters
## entrada
### Type: char vector
### Desc: input value entered by the user.
------------------------------------------------
# Return
## Type: record
### Var: r
### Desc: int of the key entered by the user.

------------------------------------------------
*/

record translateListArgs(char entrada[SIZECHARINPUT])
{
    char inputKey[SIZECHARINPUT], value[SIZECHARINPUT];
    int sizeInput = 0;
    int i, j = 0, k = commandsSize[0] + 2, key;
    record r;

    memset(inputKey, 0, sizeof inputKey);

    for (i = k; i < SIZECHARINPUT; i++)
    {
        if (entrada[i] != '=' && entrada[i] != '>' && entrada[i] != '<')
        {
            inputKey[j++] = entrada[i];
        }
    }

    key = atoi(inputKey);
    r.dataOk = true;
    r.key = key;
    return r;
}

#endif
