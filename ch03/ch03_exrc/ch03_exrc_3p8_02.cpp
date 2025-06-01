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

    for (decltype(str.size()) i = 0; i < str.size(); ++i) {
        str[i] = 'X';
    }

    cout << "Now it is: " << str << endl;

    return 0;
}