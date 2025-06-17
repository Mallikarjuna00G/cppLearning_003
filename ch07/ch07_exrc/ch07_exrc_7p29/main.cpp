#include <iostream>
#include <exception>
#include <stdexcept>

#include "screen.hpp"

using std::cout;
using std::cin;
using std::runtime_error;
using std::exception;

int main() {

    try {
        string hrLine = "----------------------------------\n";
        
        Screen myScreen(5, 5, 'X');
        myScreen.move(4, 0).set('#').display(cout);
        cout << "\n";
        myScreen.display(cout);
        cout << "\n";
        
    } catch (const runtime_error &err) {
        cout << "ERROR: runtime error:\n\t" << err.what();
    }

    return 0;
}