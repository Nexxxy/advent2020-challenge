#include <iostream>
#include <string>
#include <list>
#include <algorithm>    // find
#include <utilslib/Fileloader.h>


using namespace std;

#define CARRAYNAME cArray
#define getCharAt(y,x) (CARRAYNAME[y * size_x + x])
#define setCharAt(y,x,c) CARRAYNAME[y * size_x + x] = c

int main() {
    cout << "Day 03 Puzzle 1" << std::endl;
    auto retList = FileLoader::ReadLinesFromFile("input.txt");

    // create array to store data
    int size_x = retList.begin()->length();
    int size_y = retList.size();
    int playerpos_x = 0;
    int playerpos_y = 0;
    cout << "size_x: " << size_x << endl;
    cout << "size_y: " << size_y << endl;
    int x,y;
    char* cArray = (char*)malloc(sizeof(char) * size_x * size_y);

    y = 0;
    // copy data into array
    for (auto it = retList.begin(); it != retList.end(); it++)
    {
        // get the value
        string* value = &(*it);
        // convert to char
        const char* charData = value->c_str();

        for (int i = 0; i < value->length(); i++) {
            cArray[y*size_x + i] = charData[i];
        }
        y++;
    }


    // test
//    for (y = 0; y < size_y; y++) {
//        for (x = 0; x < size_x; x++)
//            cout << getCharAt(y,x);
//        cout << endl;
//    }

    // lets move first
    int encounteredTrees = 0;
    while (playerpos_y < size_y)
    {
        playerpos_x = (playerpos_x + 3) % size_x;       // size = 10 ; 8 + 3 = 11 ; 11 % 10 = 1;    // 7 + 3 % 10 = 0
        playerpos_y++;

        if (getCharAt(playerpos_y, playerpos_x) == '#') {
            setCharAt(playerpos_y, playerpos_x, 'X');
            encounteredTrees++;
        }
        else {
            setCharAt(playerpos_y, playerpos_x, 'O');
        }
    }


    for (y = 0; y < size_y; y++) {
        for (x = 0; x < size_x; x++)
            cout << getCharAt(y,x);
        cout << endl;
    }

    cout << "encountered Trees: " << encounteredTrees << endl;

    return 0;
}
