#include <iostream>
#include "larger.h"

using std::cout;
using std::endl;

int main() {
    int a = 10;
    int b = 25;

    int *c = &b;

    cout << "Given: a is " << a << " and b is " << b << endl;
    cout << "Greater value is: " << larger(a, c) << endl;

    return 0;
}