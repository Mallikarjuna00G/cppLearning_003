#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strcpy;
using std::strcat;

int main() {
    char str1[] = "Hello there";
    char str2[] = "Hello thereee";
    char str3[25];

    strcpy(str3, str1);
    strcat(str3, str2);

    cout << str3 << endl;

    return 0;
}