#include <iostream>

using std::cout;
using std::endl;

int fact(int n) {
    int f = 1;
    while (n > 1) {
        f *= n--;
    }
    return f;
}

int main() {
    int n = 6;
    cout << n << "! = " << fact(n) << endl;

    return 0;
}