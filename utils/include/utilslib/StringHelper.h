//
// Created by Nexxy on 08.12.2020.
//

#ifndef ADVENT2020_CHALLENGE_STRINGHELPER_H
#define ADVENT2020_CHALLENGE_STRINGHELPER_H

#include <string>
#include <iostream>
#include <list>

#define CHAR_NOT_FOUND -1

class StringHelper
{
    public :
        /***************************************************************************************************************
        * Find a SubString inside a String and return its 0-based position
        * Exception if the substring was not found
        * @param _inputString
        * @param _searchString
        * @return
        */
        static std::size_t GetPosInString(std::string& _inputString, std::string _searchString);


        /***
         * This function splits a String on a certain position. Caution, this function alters the input String!
         * It returns the front side through ret-parameter and removes this string from the _inputString.
         * @param _inputString
         * @param _splitPos
         * @return
         */
        static std::string SplitStringOnPos(std::string& _inputString, int _splitPos, bool withoutSep = true);

        /***************************************************************************************************************
        * Find a Char inside a String and return its 0-based position
        * -1 if the substring was not found
        * @param _inputString
        * @param _searchChar
        * @return
        */
        static std::size_t GetPosInString(std::string& _inputString, char _searchChar);

        /***************************************************************************************************************
        * Split a String into a String List with a given Separator
        * @param _inputString
        * @param _separatorChar
        * @return
        */
        static std::list<std::string> SplitStringWithSeparator(std::string& _inputString, char _separatorChar);

    private :

};

#endif //ADVENT2020_CHALLENGE_STRINGHELPER_H
