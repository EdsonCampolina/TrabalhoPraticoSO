#ifndef LISTFROMFILE_H
#define LISTFROMFILE_H

#include <iostream>
#include "../structs/record.h"
#include "../log/writeToLog.h"
#include "../utils/utils.h"
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include "../utils/utils.h"

bool compareStrs(string s1, string s2)
{
    return stoi(s1) < stoi(s2);
}

string removingKey(string s)
{
    int i = s.find_first_of(",");
    return s.erase(0, i + 1);
}


/*
------------------------------------------------
# Description
## Method responsible for retrieving the data present in the file 
   and loading them into a Hash Table. Then, it filters and prints 
   the list of records ordered by an operator informed by the user on the screen.
------------------------------------------------
# Parameters
## *arguments
### Type: pointer
### Desc: Pointer to the struct containing the command and arguments entered by the user.
------------------------------------------------
# Return
## Type: None
### Var: None
### Desc: nothing is retured.

------------------------------------------------
*/

static void *listFromFile(void *arguments)
{
    struct arg_struct *args = (struct arg_struct *)arguments;
    unsigned hash = HASH_FN(args->com.commandRecord.key);
    std::string line;
    std::ifstream indata;

    std::string pathToBD = "./bd/bd.txt";
    indata.open(pathToBD.c_str());

    bool found = false;
    char operators[4][3] = {">", "<", ">=", "<="};
    std::string records[LISTSIZE];
    int listIdx = 0;

    while (getline(indata, line))
    {
        if (!strcmp(args->com.commandOperator, operators[0]) && stoi(line.c_str()) > hash)
        {
            records[listIdx++] = removingKey(line.c_str());
            found = true;
        }
        if (!strcmp(args->com.commandOperator, operators[1]) && stoi(line.c_str()) < hash)
        {
            records[listIdx++] = removingKey(line.c_str());
            found = true;
        }
        if (!strcmp(args->com.commandOperator, operators[2]) && stoi(line.c_str()) >= hash)
        {
            records[listIdx++] = removingKey(line.c_str());
            found = true;
        }
        if (!strcmp(args->com.commandOperator, operators[3]) && stoi(line.c_str()) <= hash)
        {
            records[listIdx++] = removingKey(line.c_str());
            found = true;
        }
    }
    indata.close();

    if (found)
    {
        sort(records, records + listIdx, compareStrs);
        for (int j = 0; j < listIdx; j++)
        {
            cout << records[j] << "\n";
        }
    }
    else
    {
        printf("No data found. \n");
    }
}

#endif