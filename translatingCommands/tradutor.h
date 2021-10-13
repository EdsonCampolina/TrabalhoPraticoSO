#ifndef TRADUTOR_H
#define TRADUTOR_H

#include <stdio.h>
#include <string.h>
#include "insertArgs.h"
#include "../crud/writeToFile.h"

void translateCommand(char entrada[100])
{
    char insert[] = "--insert=<";
    char search[] = "--search=<";
    char remove[] = "--remove=<";
    char update[] = "--update=<";
    char list[] = "--list=<";
    bool argRecongnized = false;
    char c[100];
    int i;
    record r;

    memset(c, 0, sizeof c);
    strncpy(c, entrada, 10);

    if (strcmp(c, insert) == 0)
    {
        argRecongnized = true;
        printf("Inserting data. \n");
        r = translateInsertArgs(entrada);
        if(r.dataOk) writeToFile(r);
        // implement insert function
    }

    if (strcmp(c, search) == 0)
    {
        argRecongnized = true;
        // implement search function
        printf("Searching data. \n");
    }

    if (strcmp(c, remove) == 0)
    {
        argRecongnized = true;
        // implement remove function
        printf("Removing data. \n");
    }

    if (strcmp(c, update) == 0)
    {
        argRecongnized = true;
        // implement update function
        printf("Updating data. \n");
    }

    memset(c, 0, sizeof c);
    strncpy(c, entrada, 8);

    if (strcmp(c, list) == 0)
    {
        argRecongnized = true;
        // implement listing function
        printf("Listing data. \n");
    }

    if (!argRecongnized)
    {
        printf("Unknown command: %s \n", c);
    }

    memset(c, 0, sizeof c);
}

#endif
