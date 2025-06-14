#include <iostream>
#include "swap.h"

using std::cout;
using std::endl;

int main() {
    int a = 10, b = 20;

    cout << "Before:\n";
    cout << "a = " << a << ", b = " << b << endl;
    swap(&a, &b);
    
    cout << "After:\n";
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}