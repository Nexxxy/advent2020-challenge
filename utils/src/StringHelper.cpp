//
// Created by Nexxy on 08.12.2020.
//

#include <utilslib/StringHelper.h>

using namespace std;

/***************************************************************************************************************
* Find a SubString inside a String and return its 0-based position
* Exception if the substring was not found
* @param _inputString
* @param _searchString
* @return
*/
size_t StringHelper::GetPosInString(string& _inputString, string _searchString)
{
    return _inputString.find(_searchString);
}

/***
 * This function splits a String on a certain position. Caution, this function alters the input String!
 * It returns the front side through ret-parameter and removes this string from the _inputString.
 * @param _inputString
 * @param _splitPos
 * @return
 */
string StringHelper::SplitStringOnPos(string& _inputString, int _splitPos, bool withoutSep)
{
    string retString = _inputString.substr(0, _splitPos);
    _inputString = _inputString.substr(withoutSep?_splitPos+1:_splitPos);
    return retString;
}

/***************************************************************************************************************
* Find a Char inside a String and return its 0-based position
* -1 if the substring was not found
* @param _inputString
* @param _searchChar
* @return
*/
std::size_t StringHelper::GetPosInString(string& _inputString, char _searchChar)
{
    const char* str = _inputString.c_str();
    for (int i = 0; i < _inputString.length(); i++)
    {
        if (str[i] == _searchChar)
            return i;
    }
    return CHAR_NOT_FOUND;
}


/***************************************************************************************************************
* Split a String into a String List with a given Separator
* @param _inputString
* @param _separatorChar
* @return
*/
std::list<std::string> StringHelper::SplitStringWithSeparator(string &_inputString, char _separatorChar)
{
    int curScanPos;
    list<string> retList;
    string singleRecord;

    // search for pos of _sepChar
    curScanPos = StringHelper::GetPosInString(_inputString, _separatorChar);
    while (curScanPos != -1)
    {
        retList.push_back(StringHelper::SplitStringOnPos(_inputString, curScanPos));
        // try to find next item
        curScanPos = StringHelper::GetPosInString(_inputString, _separatorChar);
    }
    // dont forget the last item
    if (!_inputString.empty())
        retList.push_back(_inputString);

    return retList;
}
