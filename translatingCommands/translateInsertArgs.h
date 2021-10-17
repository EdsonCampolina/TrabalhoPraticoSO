#ifndef TRANSLATEINSERTARGS_H
#define TRANSLATEINSERTARGS_H

#include <stdio.h>
#include <string.h>
#include <fstream>
#include "../structs/record.h"
#include "../utils/utils.h"

record translateInsertArgs(char entrada[SIZECHARINPUT])
{
    char inputs[2][SIZECHARINPUT], value[SIZECHARINPUT];
    int sizeInputs[2];
    sizeInputs[1] = 0;
    int i, j = 0, k = commandsSize[0], sortKey;
    bool argRecognized = false;
    record r;

    memset(inputs[0], 0, sizeof inputs[0]);
    memset(inputs[1], 0, sizeof inputs[1]);

    for (i = k; i < SIZECHARINPUT; i++)
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
