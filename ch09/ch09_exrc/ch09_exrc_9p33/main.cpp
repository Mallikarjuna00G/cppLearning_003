/**
 * @file main.cpp
 * @brief Exercise 9.33: Understand the behavior of the given code.
 *
 * @note Exercise 9.33: In the final example in this section what would happen if we
 * did not assign the result of `insert` to `begin`? Write a program that omits this
 * assignment to see if your expectation was correct.
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

    vector<int> v = {0,1,2,3,4,5,6,7,8,9};

    auto begin = v.begin();
    // safer: recalculate end on each trip whenever the loop adds/erases elements
    while (begin != v.end()) {
        // do some processing
        ++begin; // advance begin because we want to insert after this element
        cout << "Before insert call: \n";
        displaySeqContainer(v);
        v.insert(begin, 42); // insert the new value
        cout << "After insert call: \n";
        displaySeqContainer(v);
        ++begin; // advance begin past the element we just added
        cout << "------------------------------------\n";
    }

    return 0;
}
