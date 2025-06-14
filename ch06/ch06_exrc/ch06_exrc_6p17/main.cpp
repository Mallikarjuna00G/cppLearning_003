#include <iostream>
#include <string>
#include "myString.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    string str1 = "Karunaada Thaayi Sadaa Chinmayiiii";

    cout << "Given string is: " << str1 << endl;
    cout << "Given string has capital letters (false: 0, true: 1): " << hasCapLetters(str1) << endl;
    fullLower(str1);
    cout << "Given string in all lower case letters: " << str1 << endl;

    return 0;
}