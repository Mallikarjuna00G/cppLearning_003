#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main() {
    do {
        string str1, str2;
        cout << "Enter two strings to compare (EOF to stop): \n";
        if (cin >> str1 >> str2) {
            if (str1 == str2) {
                cout << "Both the strings are same\n";
            } else if (str1 < str2) {
                cout << str1 << " is less than " << str2 << "\n";
            } else {
                cout << str2 << " is less than " << str1 << "\n";
            }
        }
    } while (cin);

    return 0;
}