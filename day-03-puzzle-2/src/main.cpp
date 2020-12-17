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

    // this time we have serveral deltas lets do this in an array
    int delta_x[] = {1,3,5,7,1};
    int delta_y[] = {1,1,1,1,2};
    int encounteredTrees[] = {0, 0, 0, 0, 0};
    for (int route = 0; route < 5; route++)
    {
        playerpos_x = 0;
        playerpos_y = 0;

        while (playerpos_y < size_y)
        {
            playerpos_x = (playerpos_x + delta_x[route]) % size_x;       // size = 10 ; 8 + 3 = 11 ; 11 % 10 = 1;    // 7 + 3 % 10 = 0
            playerpos_y = (playerpos_y + delta_y[route]);

            if (getCharAt(playerpos_y, playerpos_x) == '#') {
                //setCharAt(playerpos_y, playerpos_x, 'X');
                encounteredTrees[route]++;
            } else {
                //setCharAt(playerpos_y, playerpos_x, 'O');
            }
        }
    }


//    for (y = 0; y < size_y; y++) {
//        for (x = 0; x < size_x; x++)
//            cout << getCharAt(y,x);
//        cout << endl;
//    }

    unsigned int multRoutes = 1;
    for (int route = 0; route < 5; route++) {
        cout << "[ " << route << " ] " << "encountered Trees: " << encounteredTrees[route] << endl;
        multRoutes = multRoutes * encounteredTrees[route];
    }

    cout << "multiplied: " << multRoutes << endl;


    return 0;
}
