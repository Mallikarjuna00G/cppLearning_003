#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include "fpCalc.hpp"

using std::cout;
using std::vector;
using std::runtime_error;
using std::exception;

int main() {
    
    try {
        std::vector<fp> vfp = {add, sub, mul, divi};
    
        int a = 10, b = 2;
    
        for (auto f : vfp) {
            cout << f(a, b) << "\n";
        }
    
        a = 100, b = 0;
    
        for (auto f : vfp) {
            cout << f(a, b) << "\n";
        }
    } catch (const runtime_error &err) {
        cout << "ERROR: runtime_error: " << err.what();
    }

    return 0;
}