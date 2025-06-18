#include "fpCalc.hpp"

using std::runtime_error;
using std::exception;

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int divi(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero detected...");
        return -1;  // This line will never be executed
    }
    return a / b;
}