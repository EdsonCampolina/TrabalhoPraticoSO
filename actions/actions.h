#ifndef ACTIONS_H
#define ACTIONS_H

#include <stdio.h>
#include <string.h>

// actions
#include "./searchFromFile.h"
#include "./writeToFile.h"
#include "./removeFromFile.h"
#include "./listFromFile.h"

#include "../structs/internalCommand.h"
#include "../cruddbmsData/read.h"
#include "../cruddbmsData/save.h"
#include <assert.h>


/*
------------------------------------------------
# Description
## Method responsible for receiving a command informed by the user 
   that is already formatted in the struct of type internalCommand 
   to be processed. The method will create two threads for each call 
   of that command, one to execute the action in the database and the 
   other to write the log file with the executed action. In addition, 
   the method protects the critical region to avoid inconsistencies.
------------------------------------------------
# Parameters
## com
### Type: internalCommand
### Desc: Struct with the user-entered command formatted for processing.

------------------------------------------------
# Return
## Type: None
### Var: None
### Desc: nothing is retured.

------------------------------------------------
*/

void executeCommand(internalCommand com)
{
    pthread_t workers[2];
    struct arg_struct args;
    args.com = com;

    // insert

    if (com.commandOk && !strcmp(com.commandName, commandsTypes[0]))
    {
        if (com.commandRecord.dataOk)
        {
            SEMAPHORE_DOWN();

            unsigned numberOfRecords = readFromDataFile();
            numberOfRecords++;
            com.commandRecord.key = numberOfRecords;
            writeToDataFile(numberOfRecords);
            args.com = com;

            // Thread sobre o banco

            assert(pthread_create(&workers[1], NULL,
                                  writeToFile, (void *)&args) == 0);

            // Thread do log

            args.message = "Inserting key: ";
            assert(pthread_create(&workers[0], NULL,
                                  writeToLog, (void *)&args) == 0);

            assert(pthread_join(workers[0], NULL) == 0);
            assert(pthread_join(workers[1], NULL) == 0);

            SEMAPHORE_UP();
        }
    }

    // search

    if (com.commandOk && !strcmp(com.commandName, commandsTypes[1]))
    {
        if (com.commandRecord.dataOk)
        {
            reader_enter();

            // Thread sobre o banco

            assert(pthread_create(&workers[1], NULL,
                                  searchFomFile, (void *)&args) == 0);

            // Thread do log

            args.message = "Reading key: ";
            assert(pthread_create(&workers[0], NULL,
                                  writeToLog, (void *)&args) == 0);

            assert(pthread_join(workers[0], NULL) == 0);
            assert(pthread_join(workers[1], NULL) == 0);

            reader_leave();
        }
    }

    // remove

    if (com.commandOk && !strcmp(com.commandName, commandsTypes[2]))
    {
        if (com.commandRecord.dataOk)
        {
            SEMAPHORE_DOWN();

            // Thread sobre o banco

            assert(pthread_create(&workers[1], NULL,
                                  removeFromFile, (void *)&args) == 0);

            // Thread do log

            args.message = "Removing key: ";
            assert(pthread_create(&workers[0], NULL,
                                  writeToLog, (void *)&args) == 0);

            assert(pthread_join(workers[0], NULL) == 0);
            assert(pthread_join(workers[1], NULL) == 0);

            SEMAPHORE_UP();
        }
    }

    // update

    if (com.commandOk && !strcmp(com.commandName, commandsTypes[3]))
    {
        if (com.commandRecord.dataOk)
        {
            SEMAPHORE_DOWN();

            // Thread sobre o banco

            assert(pthread_create(&workers[1], NULL,
                                  writeToFile, (void *)&args) == 0);

            // Thread do log

            args.message = "Updating key: ";

            assert(pthread_create(&workers[0], NULL,
                                  writeToLog, (void *)&args) == 0);

            assert(pthread_join(workers[0], NULL) == 0);
            assert(pthread_join(workers[1], NULL) == 0);

            SEMAPHORE_UP();
        }
    }

    // list
    if (!strcmp(com.commandName, commandsTypes[4]))
    {
        printf("%s \n", commandsRes[4]);
        if (com.commandRecord.dataOk)
        {
            reader_enter();

            // Thread sobre o banco

            assert(pthread_create(&workers[1], NULL,
                                  listFromFile, (void *)&args) == 0);

            // Thread do log

            args.message = "Listing keys: ";
            args.message.append(com.commandOperator);

            assert(pthread_create(&workers[0], NULL,
                                  writeToLog, (void *)&args) == 0);

            assert(pthread_join(workers[0], NULL) == 0);
            assert(pthread_join(workers[1], NULL) == 0);

            reader_leave();
        }
    }

    // unknown command
    if (!strcmp(com.commandName, commandsTypes[5]))
    {
        printf("%s \n", commandsRes[5]);
    }
}

#endif