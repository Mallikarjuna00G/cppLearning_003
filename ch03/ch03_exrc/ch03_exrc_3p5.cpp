#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main() {
    string str1 = "", str2 = "", str3 = "";
    cout << "Enter words to concatenate (with and without space): " << endl;
    
    while (cin >> str3) {
        str1 += str3;
        str2 += " " + str3;
    }

    cout << "Without space: " << str1 << endl;
    cout << "With space: " << str2 << endl;

    return 0;
}