#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string str = "";
    cout << "Enter a string: " << endl;
    cin >> str;
    
    cout << "You entered: " << str << endl;

    decltype(str.size()) i = 0;
    while (i < str.size()) {
        str[i] = 'X';
        ++i;
    }

    cout << "Now it is: " << str << endl;

    return 0;
}