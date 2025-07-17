/**
 * @file main.cpp
 * @brief Exercise 9.26: Copies an array into a vector and a list, then removes elements based on parity.
 *
 * @note Exercise 9.26: Using the following definition of ia, copy ia into a vector and into a list. 
 * Use the single-iterator form of erase to remove the elements with odd values 
 * from your list and the even values from your vector.
 * `int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };`
 * 
 * @details
 * This program demonstrates manipulating `std::vector<int>` and `std::list<int>`
 * containers based on the values of their elements, specifically focusing on the
 * use of the single-iterator `erase` member function.
 *
 * The program performs the following steps:
 * 1. Initializes a C-style integer array `ia`.
 * 2. Copies the elements from `ia` into a new `std::vector<int>` named `vec`
 * and a `std::list<int>` named `ls`, utilizing `std::begin()` and `std::end()`
 * non-member functions for convenient range construction.
 * 3. **For the `vec` (vector):** It iterates through `vec` and removes all
 * **even-valued** elements. The `erase` operation for `std::vector`
 * returns an iterator to the element immediately following the erased element,
 * which is crucial for maintaining a valid iterator for the next step of the loop.
 * @warning While functionally correct, repeatedly erasing from the middle of a
 * `std::vector` in a loop (as done here) is generally inefficient (O(N^2) complexity
 * in the worst case) due to element shifting. For production code, `std::remove_if`
 * followed by `vector::erase` (the "erase-remove idiom") is preferred for performance.
 * 4. **For the `ls` (list):** It iterates through `ls` and removes all
 * **odd-valued** elements. The `erase` operation for `std::list` also
 * returns an iterator to the element immediately following the erased element.
 * Erasing from a `std::list` is an efficient O(1) operation, as it only
 * involves pointer manipulation, making this pattern highly suitable for lists.
 *
 * The program uses `displaySeqContainer` to show the contents of `vec` and `ls`
 * before and after the removal operations, illustrating the results.
 *
 * @author Mallikarjuna00G
 * @date 2025-06-29
 */

#include <iostream>
#include <vector>
#include <list>
#include <iterator> // Required for std::begin and std::end

#include "displaySeqContainer.hpp" // Assumes this header provides necessary displaySeqContainer overloads (for vector<int> and list<int>)

using std::cout;
using std::vector;
using std::list;
using std::begin; // Using directive for std::begin
using std::end;   // Using directive for std::end

int main() {

    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    // Copy elements from C-style array ia into a vector and a list
    vector<int> vec(begin(ia), end(ia)); // Construct vec from range
    list<int> ls(begin(ia), end(ia));   // Construct ls from range

    // --- Process vector: remove even values ---
    cout << "`vec` Before: \n";
    displaySeqContainer(vec); // Display initial vector

    auto it = vec.begin(); // Iterator for vector traversal
    while(it != vec.end()) {
        if (*it % 2) { // Check if the element is odd (remainder is 1)
            // Element is odd, do not remove, just move to the next
            it++;
        } else { // Element is even (remainder is 0)
            // Element is even, erase it.
            // Erasing from vector invalidates iterators from 'it' onwards.
            // The erase function returns a valid iterator to the element *after* the erased one.
            // Assign this returned iterator back to 'it' to continue iteration correctly.
            it = vec.erase(it);
        }
    }
    cout << "`vec` After: \n";
    displaySeqContainer(vec); // Display vector after removing even values

    // --- Process list: remove odd values ---
    cout << "`ls` Before: \n";
    displaySeqContainer(ls); // Display initial list

    auto it2 = ls.begin(); // Iterator for list traversal
    while(it2 != ls.end()) {
        if (*it2 % 2) { // Check if the element is odd (remainder is 1)
            // Element is odd, erase it.
            // Erasing from list does *not* invalidate other iterators (except the one being erased).
            // The erase function returns a valid iterator to the element *after* the erased one.
            // Assign this returned iterator back to 'it2' to continue iteration correctly.
            it2 = ls.erase(it2);
        } else { // Element is even (remainder is 0)
            // Element is even, do not remove, just move to the next
            it2++;
        }
    }
    cout << "`ls` After: \n";
    displaySeqContainer(ls); // Display list after removing odd values

    return 0;
}
