#include <iostream>
#include <vector>
#include <string>

#include "exercise.hpp"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int exercise() {
    vector<char> vchar = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
    string str(vchar.begin(), vchar.end());
    cout << str << endl;

    return EXIT_SUCCESS;
}