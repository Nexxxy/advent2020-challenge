#include <iostream>
#include <string>
#include <list>
#include <algorithm>    // find
#include <utilslib/Fileloader.h>
#include <utilslib/StringHelper.h>

using namespace std;

int checkOccsInString(const char* _inputString, char _checkChar, int _checkLength);

int main() {
    cout << "Day 2.0" << std::endl;
    auto retList = FileLoader::ReadLinesFromFile("input.txt");

    string* curLine;                // pointer to current Scan Line
    int minOccNo = 0;               // lower end
    int maxOccNo = 0;               // upper end
    int numOccInPwd = 0;            // counter for real Occs in pwd
    char assignedChar = ' ';        // Char
    string password;                // the password itself
    int counterValidPwds = 0;       // counter++ if password is valid
    int curScanPos = 0;             // Scanpos in ScanLine
    string tmpString;               // Current ScanString for Numbers
    bool pwdOk;


    for (auto it = retList.begin(); it != retList.end(); it++) {
        curLine = &(*it);
        // Step 1 : get first number
        curScanPos = StringHelper::GetPosInString(*curLine, "-");
        tmpString = StringHelper::SplitStringOnPos(*curLine, curScanPos);
        minOccNo = stoi(tmpString);

        // Step 2 : get sec number
        curScanPos = StringHelper::GetPosInString(*curLine, " ");
        tmpString = StringHelper::SplitStringOnPos(*curLine, curScanPos);
        maxOccNo = stoi(tmpString);

        // Step 3 : get char
        curScanPos = StringHelper::GetPosInString(*curLine, ":");
        tmpString = StringHelper::SplitStringOnPos(*curLine, curScanPos);
        assignedChar = tmpString[0];

        // Step 4 : get password
        // remove the leading space
        password = curLine->substr(1);

        // Step 5 : check pwd
        numOccInPwd = checkOccsInString(password.c_str(), assignedChar, password.length());
        pwdOk = false;
        if (numOccInPwd >= minOccNo && numOccInPwd <= maxOccNo) {
            pwdOk = true;
            counterValidPwds++;
        }
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

int checkOccsInString(const char* _inputString, char _checkChar, int _checkLength)
{
    int counter = 0;
    for (int i = 0; i < _checkLength; i++)
        if (_inputString[i] == _checkChar)
            counter++;
    return counter;
}
