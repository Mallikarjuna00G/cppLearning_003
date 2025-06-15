#include <iostream>
#include "myPrints.h"

using std::cout;
using std::endl;

void print(const int *beg, const int *end)
{
    // print every element starting at beg up to but not including end
    while (beg != end)
        cout << *beg++ << endl; // print the current element
    // and advance the pointer
}

// const int ia[] is equivalent to const int* ia
// size is passed explicitly and used to control access to elements of ia
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << endl;
    }
}

// ok: parameter is a reference to an array; the dimension is part of the type
void print(int (&arr)[2])
{
    for (auto elem : arr)
        cout << elem << endl;
}

void print(int &a) {
    cout << a << endl;
}