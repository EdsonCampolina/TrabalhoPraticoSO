#include <iostream>
#include <stdio.h>
#include <string.h>
#include "./translatingCommands/tradutor.h"

using namespace std;

int main(int argc, char *argv[])
{

    printf("Starting DB \n");

    translateCommand(argv[1]);

}
