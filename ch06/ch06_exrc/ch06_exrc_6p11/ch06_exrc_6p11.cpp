#include <iostream>
#include "reset.h"

using std::cout;
using std::endl;

int main() {
    int a = 25;

    cout << "Before calling reset, a is : " << a << endl;
    reset(a);
    cout << "After calling reset, a is : " << a << endl;

    return 0;
}