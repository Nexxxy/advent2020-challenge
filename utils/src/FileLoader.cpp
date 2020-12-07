//
// Created by Nexxy on 07.12.2020.
//

#include <utilslib/FileLoader.h>
#include <iostream>
#include <fstream>

using namespace std;

void FileLoader::sum(int a, int b)
{
    cout << "Hello from FileLoader";
}

std::list<std::string> FileLoader::ReadLinesFromFile(std::string _filename)
{
    list<string> retList;       // return list
    string line;                // string line buffer

    // open file
    ifstream file (_filename);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            retList.push_back(line);
        }
    }
    else
    {
        cout << "File not found : " << _filename << endl;
    }

    return retList;
}

std::list<int> FileLoader::ReadIntListFromFile(std::string _filename)
{
    list<int> retList;       // return list
    string line;                // string line buffer

    // open file
    ifstream file (_filename);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            retList.push_back(stoi(line));
        }
    }
    else
    {
        cout << "File not found : " << _filename << endl;
    }

    return retList;
}