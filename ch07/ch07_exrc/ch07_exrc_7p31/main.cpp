#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

#include "classDecl.hpp"

using std::string;
using std::cout;
using std::cin;
using std::runtime_error;
using std::exception;

int main() {

    try {
        string hrLine = "----------------------------------\n";
        
        X x1;
        Y y1;
        
    } catch (const runtime_error &err) {
        cout << "ERROR: runtime error:\n\t" << err.what();
    }

    return 0;
}