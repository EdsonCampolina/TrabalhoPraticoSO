#include <iostream>
#include <stdio.h>
#include <string.h>
#include "./translatingCommands/tradutor.h"

using namespace std;

int main()
{
    char arg[100];
    int check = 1, i = 0;
    char fim[] = "FIM";

    printf("Starting DB \n");

    do
    {
        scanf(" %[^\n]", arg);
        check = strcmp(arg, fim);
        if (check != 0)
        {
            printf(".. \n");
            translateCommand(arg);
        }
    } while (check != 0);
    
    
}
