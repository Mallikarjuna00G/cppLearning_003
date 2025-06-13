#include <iostream>
#include "Chapter6.h"

using std::cout;
using std::cin;
using std::endl;

int fact(int n) {
    int f = 1;
    while (n > 1) {
        f *= n--;
    }
    return f;
}

void factOp() {
    int n;
    cout << "Enter a positive integer to find a factorial: ";
    cin >> n;
    cout << "Factorial of the given number is " << fact(n) << endl;
}