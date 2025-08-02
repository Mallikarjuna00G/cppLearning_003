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

/**
 * @brief Main function to demonstrate iterator invalidation and safe vector modification.
 *
 * @details This function initializes a vector of integers and iterates through it.
 * When an odd number is encountered, a duplicate of that number is inserted
 * at the current iterator position. The iterator is then correctly updated
 * with the new iterator returned by the `std::vector::insert` call.
 * The loop includes a counter (`temp`) to ensure it terminates and avoids an
 * infinite loop scenario if all inserted elements were also odd.
 *
 * @return 0 on successful execution.
 * 
 * @includedoc temp.puml
 */

int main() {

    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};

    auto iter = vi.begin();
    int temp = 0;
    // safer: recalculate end on each trip whenever the loop adds/erases elements
    while (iter != vi.end() && temp++ < 20) {
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
