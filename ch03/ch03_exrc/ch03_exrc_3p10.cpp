#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string s = "";
    cout << "Enter a string: " << endl;
    cin >> s;
    cout << "You entered (with punctuation): " << s << endl;

    cout << "Without punctuation it is: ";
    for (auto c: s) {
        if (!ispunct(c)) {
            cout << c;
        }
    }

    cout << endl;

    return 0;
}