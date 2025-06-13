#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main() {
    string str1, str2;
    bool repeated = false;
    if (cin >> str1) {
        while (cin >> str2) {
            if (str1 == str2) {
                cout << "Your last word appeared twice in succession.\nBye....\n";
                repeated = true;
                break;
            } else {
                str1 = str2;
            }
        }
    }
    
    if (!repeated) {
        cout << "Either you did not enter atleast two words properly\nor you entered all unique words.\n";
    } else {
        cout << "Your repeated word is " << str1 << endl;
    }

    return 0;
}