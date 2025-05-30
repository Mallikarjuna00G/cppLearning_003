#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
    string str1 = "Hello there";
    string str2 = "Hello there";

    if (str1 == str2) {
        cout << "The given two strings are same." << endl;
    } else if (str1 < str2) {
        cout << "The first string is smaller than the second string" << endl;
    } else {
        cout << "The first string is larger than the second string" << endl;
    }

    return 0;
}