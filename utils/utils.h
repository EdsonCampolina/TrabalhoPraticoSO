#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string.h>


// Char sizes

const int SIZECHARINPUT = 100;
const int SIZECHARMESSAGELOG = 100;
const int LISTSIZE = 100;
const int __HASHTABLE_LENGTH = 1024;

/**
 *@brief Simple Hash Function
 */
int HASH_FN(int x)
{
    return (x) % __HASHTABLE_LENGTH;
}

// Commands definitions

const int NOCOMMANDS = 7;
char commandsStr[NOCOMMANDS][20] = {"--insert=", "--search=", "--remove=", "--update=", "--list=", "undefined", "--reverse-list="};
char commandsTypes[NOCOMMANDS][20] = {"insert", "search", "remove", "update", "list", "undefined", "reverse-list"};
int commandsSize[NOCOMMANDS] = {9, 9, 9, 9, 7, 1, 15};
char commandsRes[NOCOMMANDS][25] = {"Inserting data.", "Searching data.", "Removing data.", "Updating data.", "Listing data.", "Unknown command", "Reverse listing data"};


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