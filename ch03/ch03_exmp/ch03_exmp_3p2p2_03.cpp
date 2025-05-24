#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string line;
    while (getline(cin, line))  // read until end-of-file
        cout << line << endl;  // write each word followed by a name.
    
    return 0;
}