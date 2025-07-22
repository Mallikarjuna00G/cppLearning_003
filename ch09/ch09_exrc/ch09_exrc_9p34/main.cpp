/**
 * @file main.cpp
 * @brief Exercise 9.34: Understand the behavior of the given code.
 *
 * @note Exercise 9.34: Assuming `vi` is a container of `int`s that includes even and
 * odd values, predict the behavior of the following loop. After you've analyzed this
 * loop, write a program to test whether your expectations were correct.
 *
 * @details
 * NA
 *
 * @author Mallikarjuna00G
 * @date 2025-07-22
 */

#include <iostream>
#include <vector>

#include "displaySeqContainer.hpp" // Assumes this header provides necessary displaySeqContainer overloads (including for forward_list<string>)

using std::cout;
using std::vector;

int main() {

    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};

    auto iter = vi.begin();
    // safer: recalculate end on each trip whenever the loop adds/erases elements
    while (iter != vi.end()) {
        cout << "Before insert call: \n";
        displaySeqContainer(vi);
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
        cout << "After insert call: \n";
        displaySeqContainer(vi);
        ++iter; // advance begin past the element we just added
        cout << "------------------------------------\n";
    }

    return 0;
}
