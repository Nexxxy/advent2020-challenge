#include <iostream>
#include <string>
#include <list>
#include <utilslib/Fileloader.h>
#include <utilslib/StringHelper.h>
#include <unordered_map>

#define debug(x)

using namespace std;

int main() {
    cout << "Day 04 Puzzle 1" << std::endl;
    auto retList = FileLoader::ReadRecordFromFileWithBlankSpaceSeparator("input.txt");

    list<unordered_map<string,string>*> database;
    unordered_map<string,string>* record;
    string key;                                         // to store the key

    // step 1 : read whole file into inmem-database
    for (auto it = retList.begin(); it != retList.end(); it++)
    {
        // cout << (*it) << endl;
        // try to separate everything
        auto strList = StringHelper::SplitStringWithSeparator(*it, ' ');

        record = new unordered_map<string, string>();
        for (auto listIt = strList.begin(); listIt != strList.end(); listIt++)
        {
            // we assume that there is a ':'
            // -> we will destroy *listIt string val -> but its not needed anymore -> no problem tho
            key = StringHelper::SplitStringOnPos(*listIt, StringHelper::GetPosInString(*listIt, ':'));
            (*record)[key] = *listIt;
            // cout << "< " << key << " - " << (*record)[key] << " >" << endl;
        }
        database.push_back(record);
    }

    // step 2 : check valid data-records
    // Mandatory :
        // byr (Birth Year)
        // iyr (Issue Year)
        // eyr (Expiration Year)
        // hgt (Height)
        // hcl (Hair Color)
        // ecl (Eye Color)
        // pid (Passport ID)
    // optional
        // cid (Country ID) is optional

    int validCounter = 0;
    for (auto it = database.begin(); it != database.end(); it++)
    {
        record = (*it);

        // check everything
        if (record->find("byr") == record->end())
            continue;
        if (record->find("iyr") == record->end())
            continue;
        if (record->find("eyr") == record->end())
            continue;
        if (record->find("hgt") == record->end())
            continue;
        if (record->find("hcl") == record->end())
            continue;
        if (record->find("ecl") == record->end())
            continue;
        if (record->find("pid") == record->end())
            continue;
        // dont care for cid :)
        // valid ++
        validCounter++;
    }

    cout << "Valid passports : " << validCounter << endl;
    return 0;
}
