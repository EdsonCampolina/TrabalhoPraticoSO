#ifndef COMMANDTYPES_H
#define COMMANDTYPES_H

#include <stdio.h>
#include <string>

struct commandType
{
    char inputParams[10];
    char commandName[10];
    int commandsSize;
    char commandRes[20];
};

commandType
setCommandType(char inputParams[10], char commandName[10], int commandsSize, char commandRes[20])
{
    commandType rc;
    strcpy(rc.inputParams, inputParams);
    strcpy(rc.commandName, commandName);
    rc.commandsSize = commandsSize;
    strcpy(rc.commandRes, commandRes);
    return rc;
}

#endif