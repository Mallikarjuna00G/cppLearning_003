/**
 * @file main.cpp
 * @brief Exercise 9.15: Write a program to determine whether two `vector<int>`s are equal.
 *
 * This file contains the main program entry point.
 * It initializes several `std::vector<int>` objects and then
 * demonstrates the use of the equality operator (`==`) to compare them.
 * The program prints the contents of each vector and the boolean
 * result of various comparisons.
 *
 * @author Mallikarjuna00G
 * @date 2025-06-27
 */

#include <iostream>
#include <vector>

#include "displaySeqContainer.hpp"

using std::cout;
using std::vector;

int main() {

    vector<int> v1 = { 1, 3, 5, 7, 9, 12 };
    vector<int> v2 = { 1, 3, 9 };
    vector<int> v3 = { 1, 3, 5, 7 };
    vector<int> v4 = { 1, 3, 5, 7, 9, 12 };

    cout << "v1 ==> ";
    displaySeqContainer(v1);
    cout << "v2 ==> ";
    displaySeqContainer(v2);
    cout << "v3 ==> ";
    displaySeqContainer(v3);
    cout << "v4 ==> ";
    displaySeqContainer(v4);

    cout << "\nNOTE: 1 is true, 0 is false\n";
    cout << "v1 == v2: " << (v1 == v2) << "\n";
    cout << "v1 == v3: " << (v1 == v3) << "\n";
    cout << "v1 == v4: " << (v1 == v4) << "\n";
    cout << "v3 == v4: " << (v3 == v4) << "\n";
    cout << "v2 == v4: " << (v2 == v4) << "\n";
    cout << "v1 < v2: " << (v1 < v2) << "\n";
    cout << "v1 < v3: " << (v1 < v3) << "\n";
    
    return 0;
}