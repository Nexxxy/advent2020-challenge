#include <iostream>
#include <string>
#include <list>
#include <algorithm>    // find
#include <utilslib/Fileloader.h>


using namespace std;

int main() {

    int value_1 = 0;
    int value_2 = 0;
    int target_value = 0;

    cout << "Hello, World!" << std::endl;
    auto numList = FileLoader::ReadIntListFromFile("day01-input.txt");

    for (auto first_num_it = numList.begin(); first_num_it != numList.end(); first_num_it++)
    {
        value_1 = (*first_num_it);

        for (auto second_num_it = numList.begin(); second_num_it != numList.end(); second_num_it++)
        {
            value_2 = (*second_num_it);
            target_value = 2020 - value_1 - value_2;

            if (target_value <= 0)
                continue;

            auto find_it = std::find(numList.begin(), numList.end(), target_value);
            if (find_it != numList.end())
            {
                // found a value :
                cout << "found a value: " << value_1 << " " << value_2 << " " << target_value << endl;
                cout << "muliplied : " << value_1 * value_2 * target_value << endl;
                exit(0);
            }

        }
    }
    return 0;
}
