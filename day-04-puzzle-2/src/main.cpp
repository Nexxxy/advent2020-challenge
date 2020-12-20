#include <iostream>
#include <string>
#include <list>
#include <utilslib/Fileloader.h>
#include <utilslib/StringHelper.h>
#include <unordered_map>

#define DEBUG true

using namespace std;

bool isHex(string _val);

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
        string *value;
        // part -2- validation

        // byr (Birth Year) -  four digits; at least 1920 and at most 2002.*********************************************
        value = &((*record)["byr"]);
        if (value->length() != 4) // four digits;
            continue;
        if (isdigit(value->at(0)))
        {
            int byr = atoi(value->c_str());
            if (byr < 1920 || byr > 2002)  // at least 1920 and at most 2002.
            {
                if (DEBUG)
                    cout << "Error: byr not in range: " << byr << " " << endl;
                continue;
            }
        }

        // iyr (Issue Year) - four digits; at least 2010 and at most 2020.**********************************************
        // copy paste from byr
        value = &((*record)["iyr"]);
        if (value->length() != 4) // four digits;
            continue;
        if (isdigit(value->at(0)))
        {
            int iyr = atoi(value->c_str());
            if (iyr < 2010 || iyr > 2020)  // at least 1920 and at most 2002.
            {
                if (DEBUG) cout << "Error: iyr not in range: " << iyr << " " << endl;
                continue;
            }
        }
        // eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
        // copy paste from byr
        value = &((*record)["eyr"]);
        if (value->length() != 4) // four digits;
            continue;
        if (isdigit(value->at(0)))
        {
            int eyr = atoi(value->c_str());
            if (eyr < 2020 || eyr > 2030)  // at least 1920 and at most 2002.
            {
                if (DEBUG) cout << "Error: eyr not in range: " << eyr << " " << endl;
                continue;
            }
        }
        // hgt (Height) - a number followed by either cm or in:
        value = &((*record)["hgt"]);
        // first char must be a number
        if (!isdigit(value->at(0)))
            continue;
        int hgt = atoi(value->c_str());
        // should be longer than 3 digits
        if (value->length() < 3)
            continue;
        // get last 2 chars

        if (value->at(value->length() - 1) == 'm' && value->at(value->length() - 2) == 'c')
        {
            // If cm, the number must be at least 150 and at most 193.
            if (hgt < 150 || hgt > 193)
            {
                if (DEBUG) cout << "Error: hgt not in cm range: " << hgt << " " << endl;
                continue;
            }
        } else if (value->at(value->length() - 1) == 'n' && value->at(value->length() - 2) == 'i')
        {
            // If in, the number must be at least 59 and at most 76.
            if (hgt < 59 || hgt > 76)
            {
                if (DEBUG) cout << "Error: hgt not in in range: " << hgt << " " << endl;
                continue;
            }
        } else
        {
            if (DEBUG) cout << "Error: hgt got no in or cm " << *value << " " << endl;
            continue;
        }

        // hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
        value = &((*record)["hcl"]);
        // check for length, first char and then for beeing hex
        if (value->at(0) != '#')
            continue;
        if (value->length() != 7)
            continue;
        if (!isHex(value->substr(1)))
        {
            if (DEBUG) cout << "Error: no right hcl: " << *value << " " << endl;
            continue;
        }


        // ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
        value = &((*record)["ecl"]);
        // bunch of string tests :/
        if ((*value) != "amb" &&
            (*value) != "blu" &&
            (*value) != "brn" &&
            (*value) != "gry" &&
            (*value) != "grn" &&
            (*value) != "hzl" &&
            (*value) != "oth")
        {
            if (DEBUG) cout << "Error: no right ecl: " << *value << " " << endl;
            continue;
        }

        // pid (Passport ID) - a nine-digit number, including leading zeroes.
        value = &((*record)["pid"]);
        if (value->length() != 9)
            continue;

        for (auto it = value->begin(); it != value->end(); it++)
        {
            if (!isdigit((*it)))
            {
                if (DEBUG) cout << "Error: no right pid: " << *value << " " << endl;
                continue;
            }
        }

        // cid (Country ID) - ignored, missing or not.

        validCounter++;
    }

    cout << "Valid passports : " << validCounter << endl;
    return 0;
}

bool isHex(string _val)
{
    for(auto it = _val.begin(); it != _val.end(); it++)
    {
        if ((*it) >= 'a' && (*it) <= 'f')
            continue;
        if ((*it) >= '0' && (*it) <= '9')
            continue;
        return false;
    }
    return true;
}

