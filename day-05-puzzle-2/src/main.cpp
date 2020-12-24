#include <iostream>
#include <list>
#include <math.h>
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
    cout << "Day 05 Puzzle 2" << std::endl;
    auto retList = FileLoader::ReadLinesFromFile("input.txt");


    byte seatArray[127];

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

        // write into our array
        seatArray[row] = seatArray[row] | 1 << column;

        seatID = row * 8 + column;

        if (DEBUG) cout << "SeatID : " << seatID << endl;

        if (maxSeatID < seatID)
            maxSeatID = seatID;

    }

    for (index = 0; index < 128; index++)
    {
        if (seatArray[index] != 255)
        {
            column = seatArray[index];
            column = (~column) & (0x000000FF);
            column = log(column) / log(2);
            if (seatArray[index] == 0)
            {
                cout << "index: " << index << " EMPTY ROW" << endl;
            }
            else
            {
                cout << "index: " << index << "\tData : " << (int) (seatArray[index]) << "\tSeat: " << column << "\t\tseatID: " << index*8 + column <<  endl;
            }
            // Notes
            if (index == 0)
                cout << "(This is the front line, we are not sitting here)" << endl;
            else if (index == 1)
                cout << "(231 = 1110 0111) -- this looks like the middle seats are not there - thus only 3 - 3)"<< endl;
            else if (index == 90)
                cout << "(127 = 0111 1111 -- i think we found our place .. looks like someone is missing there)" << endl;
            else if (index == 122)
                cout << "this is the last line because the nextline is full empty" << endl;
            else
            {
                // nothing to say
            }
        }
    }

    cout << "Max Seat ID : " << maxSeatID << endl;

    return 0;
}
