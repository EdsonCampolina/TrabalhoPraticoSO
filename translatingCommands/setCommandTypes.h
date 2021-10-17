#ifndef SETCOMMANDTYPES_H
#define SETCOMMANDTYPES_H

#include <stdio.h>
#include <string>
#include "../structs/commandType.h"
#include "../utils/utils.h"

commandType *setCommandTypes()
{
    static commandType rcs[NOCOMMANDS];

    for (int i = 0; i < NOCOMMANDS; i++)
    {
        rcs[i] = setCommandType(commandsStr[i], commandsTypes[i], commandsSize[i], commandsRes[i]);
    }

    return rcs;
}

#endif