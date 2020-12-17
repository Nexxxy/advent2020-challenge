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

std::size_t StringHelper::GetPosInString(string& _inputString, char _searchChar)
{
    const char* str = _inputString.c_str();
    for (int i = 0; i < _inputString.length(); i++)
    {
        if (str[i] == _searchChar)
            return i;
    }
    return -1;
}
