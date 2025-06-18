#include "myString.h"

using std::string;

bool hasCapLetters(const string &s) {
    bool ret = false;

    for (auto &a : s) {  // const char &a : s
        if (a >= 'A' && a <= 'Z') {
            ret = true;
            break;
        }
    }
    return ret;
}

void fullLower(string &s) {
    for (auto &a : s) {  // char &a : s
        if (a >= 'A' && a <= 'Z') {
            a += ('a' - 'A');
        }
    }
}