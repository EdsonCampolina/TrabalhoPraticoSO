#ifndef TRANSLATELISTOPERATORARGS_H
#define TRANSLATELISTOPERATORARGS_H

#include <stdio.h>
#include <string.h>
#include <fstream>
#include "../structs/record.h"
#include "../utils/utils.h"

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
