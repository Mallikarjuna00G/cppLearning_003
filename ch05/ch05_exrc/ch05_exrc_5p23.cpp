#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int a, b;

    cout << "Enter two integers to perform divsion operation: \n";
    cin >> a >> b;

    int q = a / b;

    cout << "Result: " << q << endl;

    return 0;
}