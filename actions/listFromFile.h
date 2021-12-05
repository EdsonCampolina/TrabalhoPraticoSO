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

void listFromFile(int key, char operatorIn[2])
{

    unsigned hash = HASH_FN(key);
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
        if (!strcmp(operatorIn, operators[0]) && stoi(line.c_str()) > hash)
        {
            records[listIdx++] = removingKey(line.c_str());
            found = true;
        }
        if (!strcmp(operatorIn, operators[1]) && stoi(line.c_str()) < hash)
        {
            records[listIdx++] = removingKey(line.c_str());
            found = true;
        }
        if (!strcmp(operatorIn, operators[2]) && stoi(line.c_str()) >= hash)
        {
            records[listIdx++] = removingKey(line.c_str());
            found = true;
        }
        if (!strcmp(operatorIn, operators[3]) && stoi(line.c_str()) <= hash)
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

    
    string messageStr = "Listing keys: ";
    messageStr.append(operatorIn);
    char message[100];
    strcpy(message, messageStr.c_str());
    writeToLogNumberOfRecords(message, hash);
}

#endif