#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int abs(int n) {
    return n < 0 ? -n : n;
}

int main() {
    int n = 10;

    cout << "Absolute value of the given number " << n << " is " << abs(n) << endl;
}