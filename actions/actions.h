#ifndef ACTIONS_H
#define ACTIONS_H

#include <stdio.h>
#include <string.h>

// actions
#include "./searchFromFile.h"
#include "./writeToFile.h"
#include "./removeFromFile.h"
#include "./updateFile.h"


#include "../structs/internalCommand.h"
#include "../cruddbmsData/read.h"
#include "../cruddbmsData/save.h"

void executeCommand(internalCommand com)
{

    // insert

    if (com.commandOk && !strcmp(com.commandName, commandsTypes[0]))
    {
        if (com.commandRecord.dataOk)
        {
            int numberOfRecords = readFromDataFile();
            numberOfRecords++;
            com.commandRecord.key = numberOfRecords;
            writeToFile(com.commandRecord);
            writeToDataFile(numberOfRecords);
        }
    }

    // search

    if (com.commandOk && !strcmp(com.commandName, commandsTypes[1]))
    {
        if (com.commandRecord.dataOk)
            searchFomFile(com.commandRecord.key);
    }

    // remove

    if (com.commandOk && !strcmp(com.commandName, commandsTypes[2]))
    {
        if (com.commandRecord.dataOk)
            removeFromFile(com.commandRecord.key);
    }

    // update

    if (com.commandOk && !strcmp(com.commandName, commandsTypes[3]))
    {
        if (com.commandRecord.dataOk)
            updateFile(com.commandRecord);
    }

    // list

    // unknown command
    if (!strcmp(com.commandName, commandsTypes[5]))
    {
        printf("%s \n", commandsRes[5]);
    }
}

#endif