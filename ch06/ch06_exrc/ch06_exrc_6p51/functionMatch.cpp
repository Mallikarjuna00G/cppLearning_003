#include <iostream>

using std::cout;

#include "functionMatch.hpp"

void f() {
    cout << "I am in function: " << __func__ << "()\n";
}

void f(int) {
    cout << "I am in function: " << __func__ << "(int)\n";
}

void f(int, int) {
    cout << "I am in function: " << __func__ << "(int, int)\n";
}

void f(double, double) {
    cout << "I am in function: " << __func__ << "(double, double = 3.14)\n";
}