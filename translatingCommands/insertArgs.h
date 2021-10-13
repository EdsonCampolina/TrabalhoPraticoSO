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
    int i, j = 0, k = 10, sortKey;
    bool argRecognized = false;
    record r;

    for (i = k; i < 100; i++)
    {
        switch (entrada[i])
        {
        case ',':
            j++;
            k = i + 1;
            sizeInputs[0] = i - 10;
            break;
        case '>':
            sizeInputs[1] = i - sizeInputs[0] - 10;
            argRecognized = true;
            break;
        default:
            inputs[j][i - k] = entrada[i];
        }
        if (argRecognized)
            break;
    }

    if (argRecognized)
    {

        sortKey = atoi(inputs[0]);
        strncpy(value, inputs[1], sizeInputs[1]);

        // printf("sort-key: %d \n", sortKey);
        // printf("value: %s \n", value);
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
