#ifndef INTERNALCOMMAND_H
#define INTERNALCOMMAND_H

#include <string>
#include "../structs/record.h"
#include "../translatingCommands/setCommandTypes.h"
#include "../utils/utils.h"


struct internalCommand
{
    char commandName[10];
    char input[SIZECHARINPUT];
    bool commandOk;
    char commandOperator[3];
    record commandRecord;
};

internalCommand setInternalCommand(char commandName[10], char input[SIZECHARINPUT], bool commandOk)
{
    internalCommand c;
    strcpy(c.commandName, commandName);
    strcpy(c.input, input);
    c.commandOperator;
    c.commandOk = commandOk;
    return c;
}

#endif