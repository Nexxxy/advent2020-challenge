//
// Created by Nexxy on 07.12.2020.
//

#include <utilslib/FileLoader.h>
#include <utilslib/StringHelper.h>
#include <iostream>
#include <fstream>

using namespace std;

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
    list<int> retList;          // return list
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

std::list<std::string> FileLoader::ReadRecordFromFileWithBlankSpaceSeparator(std::string _filename)
{
    list<string> retList;       // return list
    string dataLine;                // string line buffer
    string record;

    // open file
    ifstream file (_filename);

    if (file.is_open())
    {
        record = "";
        while (getline(file, dataLine))
        {
            if (!dataLine.empty())
            {
                if (record.empty())
                    record = record + dataLine ;
                else
                    record = record + " " + dataLine ;
            }
            else
            {
                retList.push_back(record);
                record = "";
            }
        }
        // special case : no empty line at the end of file :
        if (!record.empty())
            retList.push_back(record);
    }
    else
    {
        cout << "File not found : " << _filename << endl;
    }

    return retList;
}
