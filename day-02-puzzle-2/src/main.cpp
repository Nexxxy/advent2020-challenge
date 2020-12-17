#include <iostream>
#include <string>
#include <list>
#include <algorithm>    // find
#include <utilslib/Fileloader.h>
#include <utilslib/StringHelper.h>

using namespace std;

bool checkOccsInString(const char* _inputString, char _checkChar, int _pos1, int _pos2);

int main() {
    cout << "Day 2.1" << std::endl;
    auto retList = FileLoader::ReadLinesFromFile("input.txt");

    string* curLine;                // pointer to current Scan Line
    int pos1 = 0;               // lower end
    int pos2 = 0;               // upper end
    int numOccInPwd = 0;            // counter for real Occs in pwd
    char assignedChar = ' ';        // Char
    string password;                // the password itself
    int counterValidPwds = 0;       // counter++ if password is valid
    int curScanPos = 0;             // Scanpos in ScanLine
    string tmpString;               // Current ScanString for Numbers
    bool pwdOk;


    for (auto it = retList.begin(); it != retList.end(); it++) {
        curLine = &(*it);

        // cout << "line: " << (*it) << endl;

        // Step 1 : get first number
        curScanPos = StringHelper::GetPosInString(*curLine, "-");
        tmpString = StringHelper::SplitStringOnPos(*curLine, curScanPos);
        pos1 = stoi(tmpString);
        pos1--;

        // Step 2 : get sec number
        curScanPos = StringHelper::GetPosInString(*curLine, " ");
        tmpString = StringHelper::SplitStringOnPos(*curLine, curScanPos);
        pos2 = stoi(tmpString);
        pos2--;

        // Step 3 : get char
        curScanPos = StringHelper::GetPosInString(*curLine, ":");
        tmpString = StringHelper::SplitStringOnPos(*curLine, curScanPos);
        assignedChar = tmpString[0];

        // Step 4 : get password
        // remove the leading space
        password = curLine->substr(1);

        // Step 5 : check pwd
        pwdOk = checkOccsInString(password.c_str(), assignedChar, pos1, pos2);
        if (pwdOk) {
            counterValidPwds++;
        }

//            cout << "lowerEnd:  " << pos1 << endl;
//            cout << "upperEnd:  " << pos2 << endl;
//            cout << "char:      " << assignedChar << endl;
//            cout << "password:  " << password << endl;
//            cout << "num occs:  " << numOccInPwd << endl;
//            cout << "OK status: " << (pwdOk?"yes":"no") << endl;
    }

    cout << "good pwds: " << counterValidPwds << endl;


//    cout << "lowerEnd:  " << minOccNo << endl;
//    cout << "upperEnd:  " << maxOccNo << endl;
//    cout << "char:      " << assignedChar << endl;
//    cout << "password:  " << password << endl;
//    cout << "num occs:  " << numOccInPwd << endl;
//    cout << "OK status: " << (pwdOk?"yes":"no") << endl;


    return 0;
}

bool checkOccsInString(const char* _inputString, char _checkChar, int _pos1, int _pos2)
{
    if (_inputString[_pos1] == _checkChar && _inputString[_pos2] != _checkChar)
        return true;
    if (_inputString[_pos1] != _checkChar && _inputString[_pos2] == _checkChar)
        return true;
    return false;
}
