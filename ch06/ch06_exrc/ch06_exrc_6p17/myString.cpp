#include <cctype>
#include "myString.h"

using std::string;
using std::isupper;
using std::tolower;

bool hasCapLetters(const string &s) {
    for (auto &a : s) {  // const char &a : s
        if (isupper(a)) {
            return true;
        }
    }
    return false;
}

void fullLower(string &s) {
    for (auto &a : s) {  // char &a : s
        a = tolower(a);
    }
}