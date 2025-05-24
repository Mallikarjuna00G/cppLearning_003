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

    if (str1.size() == str2.size()) {
        cout << "They are of equal length..." << endl;
    } else if (str1.size() > str2.size()) {
        cout << "'"<< str1 << "' is longer than '" << str2 << "'" << endl; 
    } else {
        cout << "'"<< str2 << "' is longer than '" << str1 << "'" << endl; 
    }

    return 0;
}