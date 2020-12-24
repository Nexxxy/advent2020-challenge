#include <iostream>
#include <string>
#include <list>
#include <algorithm>    // find
#include <utilslib/Fileloader.h>

#define DEBUG false

using namespace std;

/*
 * Start by considering the whole range, rows 0 through 127.
    F means to take the lower half, keeping rows 0 through 63.
    B means to take the upper half, keeping rows 32 through 63.
    F means to take the lower half, keeping rows 32 through 47.
    B means to take the upper half, keeping rows 40 through 47.
    B keeps rows 44 through 47.
    F keeps rows 44 through 45.
    The final F keeps the lower of the two, row 44.
 */

typedef unsigned char byte;

/**
 * returns new upperBoundary
 */
inline byte TakeLowerHalf(byte _lowerBoundary, byte _upperBoundary)
{
    return ((_lowerBoundary + _upperBoundary) >> 1);
}

/**
 * returns new lowerBoundary
 */
inline byte TakeUpperHalf(byte _lowerBoundary, byte _upperBoundary)
{
    return ((_lowerBoundary + _upperBoundary + 1) >> 1);
}


int main() {
    cout << "Day 05 Puzzle 1" << std::endl;
    auto retList = FileLoader::ReadLinesFromFile("input.txt");

    byte lowerBoundary;
    byte upperBoundary;
    int index;
    int row;
    int column;
    int seatID;
    int maxSeatID = 0;

    for (auto value = retList.begin(); value != retList.end(); value++)
    {
        // Row now
        upperBoundary = 127;
        lowerBoundary = 0;
        for (index = 0; index < 7; index ++)
        {
            if (value->at(index) == 'F') // take lower half
            {
                // lowerBoundary stays
                upperBoundary = TakeLowerHalf(lowerBoundary, upperBoundary);
                if (DEBUG) cout << "F :" << (int)lowerBoundary << " - " << (int)upperBoundary << endl;
            }
            else // assuming B      // take upper half
            {
                // lowerBoundary stays
                lowerBoundary = TakeUpperHalf(lowerBoundary, upperBoundary);
                if (DEBUG) cout << "B :" << (int)lowerBoundary << " - " << (int)upperBoundary << endl;
            }
        }
        row = lowerBoundary;

        // Column now
        upperBoundary = 7;
        lowerBoundary = 0;

        for (index = 7; index < 10; index ++)
        {
            if (value->at(index) == 'L') // take lower half
            {
                // lowerBoundary stays
                upperBoundary = TakeLowerHalf(lowerBoundary, upperBoundary);
                if (DEBUG) cout << "L :" << (int)lowerBoundary << " - " << (int)upperBoundary << endl;
            }
            else // assuming R      // take upper half
            {
                // lowerBoundary stays
                lowerBoundary = TakeUpperHalf(lowerBoundary, upperBoundary);
                if (DEBUG) cout << "R :" << (int)lowerBoundary << " - " << (int)upperBoundary << endl;
            }
        }
        column = lowerBoundary;
        seatID = row * 8 + column;

        if (DEBUG) cout << "SeatID : " << seatID << endl;

        if (maxSeatID < seatID)
            maxSeatID = seatID;
    }

    cout << "Max Seat ID : " << maxSeatID << endl;

    return 0;
}
