#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <stdio.h>
#include <string.h>
#include "translateInsertArgs.h"
#include "translateArgsFromKey.h"
#include "translateUpdateArgs.h"
#include "setCommandTypes.h"

#include "../structs/internalCommand.h"
#include "../structs/commandType.h"
#include "../utils/utils.h"

internalCommand translateCommand(char input[SIZECHARINPUT])
{

    char c[SIZECHARINPUT];
    int i;
    record r;
    commandType *rcs;
    rcs = setCommandTypes();
    internalCommand com = setInternalCommand(rcs[5].commandName, input, false);

    for (int i = 0; i < NOCOMMANDS; i++)
    {
        memset(c, 0, sizeof c);
        strncpy(c, input, rcs[i].commandsSize);
        if (!strcmp(c, rcs[i].inputParams))
        {
            com = setInternalCommand(rcs[i].commandName, input, true);
        }
    }

    if(!strcmp(com.commandName, commandsTypes[0])) com.commandRecord = translateInsertArgs(input);
    if(!strcmp(com.commandName, commandsTypes[1])) com.commandRecord = translateArgsFromKey(input);
    if(!strcmp(com.commandName, commandsTypes[2])) com.commandRecord = translateArgsFromKey(input);
    if(!strcmp(com.commandName, commandsTypes[3])) com.commandRecord = translateUpdateArgs(input);

    return com;
}

#endif
