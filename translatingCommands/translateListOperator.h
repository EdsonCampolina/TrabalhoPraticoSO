#ifndef TRANSLATELISTOPERATORARGS_H
#define TRANSLATELISTOPERATORARGS_H

#include <stdio.h>
#include <string.h>
#include <fstream>
#include "../structs/record.h"
#include "../utils/utils.h"


/*
------------------------------------------------
# Description
## This method is responsible for separating the operators from the
   complete command that was previously provided by the user.
------------------------------------------------
# Parameters
## entrada, operador
### Type: char and char pointer
### Desc: input value entered by the user.
------------------------------------------------
# Return
## Type: None
### Var: None
### Desc: nothing is returned.

------------------------------------------------
*/

void translateListOperator(char entrada[SIZECHARINPUT], char* operador)
{
    // char* operador = malloc(2);
    int k = commandsSize[4] + 3;

    memset(operador, 0, sizeof operador);

    if (entrada[k] == '=')
        operador[0] = '=';
    if (entrada[k] == '>' && entrada[k + 1] != '=')
        operador[0] = '>';
    if (entrada[k] == '<' && entrada[k + 1] != '=')
        operador[0] = '<';
    if (entrada[k] == '>' && entrada[k + 1] == '=')
    {
        operador[0] = '>';
        operador[1] = '=';
    }
    if (entrada[k] == '<' && entrada[k + 1] == '=')
    {
        operador[0] = '<';
        operador[1] = '=';
    }
}

#endif
