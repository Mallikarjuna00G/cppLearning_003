#include <iostream>
#include "swapPointers.h"

using std::cout;
using std::endl;

int main() {
    int a = 10;
    int b = 25;

    int *c = &a;
    int *d = &b;

    cout << "Before: pointer c is " << c << " and pointer d is " << d << endl;
    swapPointers(c, d);
    cout << "After: pointer c is " << c << " and pointer d is " << d << endl;

    return 0;
}