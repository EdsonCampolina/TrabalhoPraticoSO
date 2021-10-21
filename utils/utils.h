#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string.h>


// Char sizes

const int SIZECHARINPUT = 100;
const int SIZECHARMESSAGELOG = 100;


// Commands definitions

const int NOCOMMANDS = 6;
char commandsStr[NOCOMMANDS][10] = {"--insert=", "--search=", "--remove=", "--update=", "--list=", "undefined"};
char commandsTypes[NOCOMMANDS][10] = {"insert", "search", "remove", "update", "list", "undefined"};
int commandsSize[NOCOMMANDS] = {9, 9, 9, 9, 7, 1};
char commandsRes[NOCOMMANDS][20] = {"Inserting data.", "Searching data.", "Removing data.", "Updating data.", "Listing data.", "Unknown command"};


// Putting all args in a char

char *concatAllArgs(int argc, char *argv[])
{
    int i, v = 0, size = argc - 1;
    char *str = (char *)malloc(v);

    for (i = 1; i <= size; i++)
    {
        str = (char *)realloc(str, (v + strlen(argv[i])));
        strcat(str, argv[i]);
        strcat(str, " ");
    }
    return str;
}


#endif