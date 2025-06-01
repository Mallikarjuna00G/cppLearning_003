#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::toupper;

int main() {
    vector<string> vstr;
    string str;
    string hrLine = "\n---------------------------------------------\n";

    cout << "Enter strings: " << endl;
    while (cin >> str) {
        vstr.push_back(str);
    }

    cout << hrLine;
    cout << "Strings as received: " << endl;

    int i = 0;
    for (const auto &a: vstr) {
        cout << a;
        ++i;
        if (i == 8) {
            cout << endl;
            i = 0;
        } else {
            cout << " ";
        }
    }

    for (auto &a: vstr) {
        for (auto &c: a) {
            c = toupper(c);
        }
    }
    cout << hrLine;

    cout << "After uppercasing: " << endl;

    i = 0;
    for (const auto &a: vstr) {
        cout << a;
        ++i;
        if (i == 8) {
            cout << endl;
            i = 0;
        } else {
            cout << " ";
        }
    }


    return 0;
}