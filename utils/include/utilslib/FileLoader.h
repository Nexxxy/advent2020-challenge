//
// Created by Nexxy on 07.12.2020.
//

#ifndef ADVENT2020_CHALLENGE_FILELOADER_H
#define ADVENT2020_CHALLENGE_FILELOADER_H

#include <list>
#include <string>

class FileLoader {
    public :

        /*****
         * Reads 1 Int from each line into a std::list
         * @param _filename
         * @return
         */
        static std::list<int>         ReadIntListFromFile(std::string _filename);

        /******
         * Read 1 String from each line into a std::list
         * @param _filename
         * @return
         */
        static std::list<std::string> ReadLinesFromFile(std::string _filename);

        /*****
         * Reads a String from each Record witch are separated with Black-Lines
         * @param _filename
         * @return
         */
        static std::list<std::string> ReadRecordFromFileWithBlankSpaceSeparator(std::string _filename);

    private :

};


#endif //ADVENT2020_CHALLENGE_FILELOADER_H
