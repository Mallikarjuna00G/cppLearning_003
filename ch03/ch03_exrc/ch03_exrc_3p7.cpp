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

    for (char &c: str) {
        c = 'X';
    }

    cout << "Now it is: " << str << endl;

    return 0;
}