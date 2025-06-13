#include <iostream>
#include <exception>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::runtime_error;

int main() {
    int a, b;

    cout << "Enter two integers to perform divsion operation: \n";
    cin >> a >> b;

    
    if (b == 0) {
        throw runtime_error("Division by zero.!!");
        // throw exception();
    }

    int q = a / b;
    cout << "Result: " << q << endl;

    return 0;
}