#include <iostream>
#include <exception>
#include <stdexcept>

#include "person.hpp"

using std::cout;
using std::cin;
using std::runtime_error;
using std::exception;

int main() {

    try {
        if (true) {
            
        } else {
            // no input! terminate with error
            throw runtime_error("Soemthing went wrong");
        }
    } catch (const runtime_error &err) {
        cout << "ERROR: runtime error:\n\t" << err.what();
    }

    return 0;
}