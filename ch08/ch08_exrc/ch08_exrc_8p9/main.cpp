#include <iostream>
#include <string>
#include <sstream>

#include "theIOState.hpp"

using std::cout;
using std::cin;
using std::string;
using std::istringstream;

int main() {

    cout << "IO State of cin before calling readFile(): " << cin.rdstate() << "\n";

    string line;
    
    while (getline(cin, line)) {
        istringstream record(line);
        readFile(record);
    }
    // auto &temp = readFile(cin);  // since stream cannot be copied we have to have a reference variable.
    // cout << "IO State of cin after calling readFile(): " << temp.rdstate() << "\n";
    
    return 0;
}