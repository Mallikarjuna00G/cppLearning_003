#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

#include "screen.hpp"

using std::string;
using std::cout;
using std::cin;
using std::runtime_error;
using std::exception;

int main() {

    try {
        string hrLine = "----------------------------------\n";
        
        Screen s1;
        Screen s2(10, 10, 'A');
        
    } catch (const runtime_error &err) {
        cout << "ERROR: runtime error:\n\t" << err.what();
    }

    return 0;
}