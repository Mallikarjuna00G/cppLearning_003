#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main() {
    string str1, str2;
    cout << "Enter two words: ";
    cin >> str1 >> str2;

    if (str1 == str2) {
        cout << "They are equal..." << endl;
    } else if (str1 > str2) {
        cout << "'"<< str1 << "' is larger than '" << str2 << "'" << endl; 
    } else {
        cout << "'"<< str2 << "' is larger than '" << str1 << "'" << endl; 
    }

    return 0;
}