#include <iostream>
#include <string>
#include <list>
#include <algorithm>    // find
#include <utilslib/Fileloader.h>


using namespace std;

int main() {
    cout << "Hello, World!" << std::endl;
    auto retList = FileLoader::ReadIntListFromFile("day01-input.txt");

    for (auto it = retList.begin(); it != retList.end(); it++)
    {
        int value = (*it);
        int target_value = 2020 - value;

        auto find_it = std::find(retList.begin(), retList.end(), target_value);
        if (find_it != retList.end())
        {
            // found a value :
            cout << "found a value: " << value << " " << target_value << endl;
            cout << "muliplied : " << value * target_value << endl;
            exit(0);
        }

    }
    return 0;
}
