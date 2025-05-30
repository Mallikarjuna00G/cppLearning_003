#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strcmp;

int main() {
    char str1[] = "Hello there";
    char str2[] = "Hello thereee";

    int i = strcmp(str1, str2);
    if (i == 0) {
        cout << "The given two strings are same." << endl;
    } else if (i < 0) {
        cout << "The first string is smaller than the second string" << endl;
    } else {
        cout << "The first string is larger than the second string" << endl;
    }

    return 0;
}