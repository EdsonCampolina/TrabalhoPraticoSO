#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <stdio.h>
#include <string.h>
#include "translateInsertArgs.h"
#include "translateArgsFromKey.h"
#include "translateUpdateArgs.h"
#include "translateListArgs.h"
#include "translateListOperator.h"
#include "setCommandTypes.h"

#include "../structs/internalCommand.h"
#include "../structs/commandType.h"
#include "../utils/utils.h"


/*
------------------------------------------------
# Description
## Method responsible for receiving an input via the terminal and verifying 
   if the command informed is valid. Once a valid command is detected, the 
   arguments are formatted into a struct for further processing.

------------------------------------------------
# Parameters
## input[SIZECHARINPUT]
### Type: char
### Desc: Input parameter 1 that must have a string entered by the user.

------------------------------------------------
# Return
## Type: internalCommand
### Var: com
### Desc: This structure is composed of the command name, data, a bool to 
    enable or not the command to run, operator field (such as >, <,> =, <=) and
    a 'record' structure to aid in sorting of the data, containing the sort key, and so on.

------------------------------------------------
*/

internalCommand translateCommand(char input[SIZECHARINPUT])
{

    char c[SIZECHARINPUT];
    int i;
    record r;
    commandType *rcs;
    rcs = setCommandTypes();                                                    // An array with all the commands
    internalCommand com = setInternalCommand(rcs[5].commandName, input, false); // Defines the command as unknown

    // Checks if the provided args match any of the known commands

    // printf("inputParams: %s \n", c);

    for (int i = 0; i < NOCOMMANDS; i++)
    {
        memset(c, 0, sizeof c);
        strncpy(c, input, rcs[i].commandsSize);
        if (!strcmp(c, rcs[i].inputParams))
        {
            com = setInternalCommand(rcs[i].commandName, input, true);
        }
    }

    // Each kind of command will have a different set of arguments
    // how to inherit in c++?

    if (!strcmp(com.commandName, commandsTypes[0]))
        com.commandRecord = translateInsertArgs(input);
    if (!strcmp(com.commandName, commandsTypes[1]))
        com.commandRecord = translateArgsFromKey(input);
    if (!strcmp(com.commandName, commandsTypes[2]))
        com.commandRecord = translateArgsFromKey(input);
    if (!strcmp(com.commandName, commandsTypes[3]))
        com.commandRecord = translateUpdateArgs(input);
    if (!strcmp(com.commandName, commandsTypes[4]))
    {
        translateListOperator(input, com.commandOperator);
        com.commandRecord = translateListArgs(input);
    }
    if (!strcmp(com.commandName, commandsTypes[6]))
    {
        translateListOperator(input, com.commandOperator);
        com.commandRecord = translateListArgs(input);
    }

    return com;
}

#endif
