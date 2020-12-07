//
// Created by Nexxy on 07.12.2020.
//

#ifndef ADVENT2020_CHALLENGE_FILELOADER_H
#define ADVENT2020_CHALLENGE_FILELOADER_H

#include <list>
#include <string>

class FileLoader {
    public :
        static void sum(int a, int b);

        static std::list<int>         ReadIntListFromFile(std::string _filename);
        static std::list<std::string> ReadLinesFromFile(std::string _filename);

    private :

};


#endif //ADVENT2020_CHALLENGE_FILELOADER_H
