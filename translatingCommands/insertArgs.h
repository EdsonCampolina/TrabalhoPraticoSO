#ifndef INSERTARGS_H
#define INSERTARGS_H

#include <stdio.h>
#include <string.h>
#include <fstream>
#include "../structs/record.h"

record translateInsertArgs(char entrada[100])
{
    char inputs[2][100], value[100];
    int sizeInputs[2];
    sizeInputs[1] = 0;
    int i, j = 0, k = 9, sortKey;
    bool argRecognized = false;
    record r;

    for (i = k; i < 100; i++)
    {
        switch (entrada[i])
        {
        case ',':
            j++;
            sizeInputs[0] = i - k;
            k = i + 1;
            break;
        default:
            inputs[j][i - k] = entrada[i];
            if (j == 1)
            {
                sizeInputs[1]++;
                if (!argRecognized)
                    argRecognized = true;
            }
        }
    }

    if (argRecognized)
    {
        sortKey = atoi(inputs[0]);
        strncpy(value, inputs[1], sizeInputs[1]);
        r = setRecord(sortKey, value, true);
    }
    else
    {
        printf("Insert message not well formatted. \n");
        r = setRecord(sortKey, value, false);
    }
    return r;
}

#endif
