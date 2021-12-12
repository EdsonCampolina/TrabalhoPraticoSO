#ifndef TRANSLATEARGSFROMKEY_H
#define TRANSLATEARGSFROMKEY_H

#include <stdio.h>
#include <string.h>
#include <fstream>
#include "../structs/record.h"
#include "../utils/utils.h"


/*
------------------------------------------------
# Description
## method responsible for converting the key informed by the user to int,
   where it is received as a char vector.
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


record translateArgsFromKey(char entrada[SIZECHARINPUT])
{
    record r;

    std::string str = entrada;
    std::string value = str.substr(commandsSize[1]);
    try
    {
        r.key = stoi(value);
        printf("Searching for key: %d \n", r.key);
        r.dataOk = true;
    }
    catch (const std::invalid_argument &ia)
    {
        printf("Invalid argument for search\n");
        r.dataOk = false;
    }

    return r;
}

#endif
