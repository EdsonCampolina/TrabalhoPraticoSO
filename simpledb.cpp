#include <iostream>
#include <stdio.h>
#include <string.h>
#include "./translatingCommands/translate.h"
#include "./actions/actions.h"
#include "./utils/utils.h"

using namespace std;

int main(int argc, char *argv[])
{

    // 1 - checking and adjusting args

    if (argc == 1)
    {
        printf("ERROR: Expected at least 1 argument\n");
        return 0;
    }

    char *allArgs;
    allArgs = concatAllArgs(argc, argv);


    // 2 - translating args into commands
    internalCommand com = translateCommand(allArgs);
    

    // 3 - action generated by the command

    nreaders = 0;
	MUTEX_INIT();
	SEMAPHORE_INIT();
    executeCommand(com);

    return 0;
}
