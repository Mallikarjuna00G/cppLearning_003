#include <iostream>

#include "theIOState.hpp"

using std::cout;
using std::cin;

int main() {

    cout << "IO State of cin before calling readFile(): " << cin.rdstate() << "\n";
    auto &temp = readFile(cin);  // since stream cannot be copied we have to have a reference variable.
    cout << "IO State of cin after calling readFile(): " << temp.rdstate() << "\n";
    
    return 0;
}