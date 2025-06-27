/**
 * @file main.cpp
 * @brief Demonstrates initialization of `std::vector<double>` from other integer-based containers.
 *
 * This file contains the main program entry point and a utility function
 * to display vector contents. It showcases two primary ways to initialize
 * a `vector` of `double`s:
 * 1. From a `std::list<int>` using iterator range construction.
 * 2. From a `std::vector<int>` using iterator range construction.
 * The program then prints the contents of the initialized `double` vectors.
 *
 * @author Mallikarjuna00G
 * @date 2025-06-26
 */

#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;

/**
 * @brief Prints the elements of a vector<double> to standard output.
 *
 * This function iterates through the given vector and prints each double
 * element followed by a space. After all elements are printed, it
 * outputs a newline character.
 *
 * @param v A constant reference to the ``vector<double>`` to be displayed.
 * The vector's elements will not be modified by this function.
 * 
 */
void displayVector(const vector<double> &v) {
    for (const auto &item : v) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {

    list<int> l1 = {10, 23, 4, 45, 67};
    vector<double> d1(l1.begin(), l1.end());

    displayVector(d1);
    
    vector<int> v1 = {23, 45, 67, 77, 33};
    vector<double> d2(v1.begin(), v1.end());
    displayVector(d2);
    
    return 0;
}