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
    char c = 'y';
        
    while (c == 'y') {
        try {
            cin >> a >> b;
        
            
            if (b == 0) {
                throw runtime_error("Division by zero.!!");
                // throw exception();
            }
            
            int q = a / b;
            cout << "Result: " << q << endl;
        } catch (runtime_error err) {
            cout << err.what();
        }
        cout << "\nTry again? (y/n): ";
        cin >> c;
        if (!cin || c == 'n') {
            break;  // break out of the while loop
        }
        if (c == 'y') {
            cout << "Enter two integers to perform divsion operation: \n";
        }
    }

    return 0;
}