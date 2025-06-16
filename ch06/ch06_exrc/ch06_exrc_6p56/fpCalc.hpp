#ifndef FP_CALC_HPP
#define FP_CALC_HPP

#include <iostream>
#include <exception>
#include <stdexcept>

using std::runtime_error;
using std::exception;
using std::cout;

using fp = int(*)(int, int); // fp is a pointer to a function that takes two ints and returns an int

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int divi(int a, int b);

#endif