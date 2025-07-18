/**
 * @file main.cpp
 * @brief Exercise 9.27: Finds and removes odd-valued elements from a `std::forward_list<int>`.
 *
 * @note Exercise 9.27: Write a program to find and remove the odd-valued elements in a
 * forward_list<int>.
 * 
 * 
 * @details
 * This program demonstrates the specific techniques required to remove elements
 * from a `std::forward_list<int>`, which, as a singly-linked list, has different
 * iteration and erasure semantics compared to other sequence containers like `std::vector` or `std::list`.
 *
 * The problem requires finding and removing odd-valued elements. Due to the nature
 * of `std::forward_list`, its iterators are "forward iterators" and cannot be
 * decremented. Consequently, the `erase()` member function (which typically takes
 * an iterator to the element to be erased) is not available. Instead, `std::forward_list`
 * provides `erase_after()`, which removes the element *after* a given iterator.
 *
 * The program implements the following steps:
 * 1. Initializes a `std::forward_list<int>` with a set of integer values.
 * 2. Initializes two iterators:
 * - `cPrev`: A `const_iterator` pointing to the element *before* the current element.
 * It is initialized with `fList.cbefore_begin()`, a special iterator that
 * points to a mythical element before the first element, allowing `erase_after()`
 * to remove the actual first element if needed.
 * - `cCurr`: A `const_iterator` pointing to the current element being examined,
 * initialized with `fList.cbegin()`.
 * 3. Enters a `while` loop that continues as long as `cCurr` has not reached `fList.cend()`.
 * 4. Inside the loop:
 * - It checks if the element pointed to by `cCurr` is odd (`*cCurr % 2`).
 * - If it's odd: `cCurr = fList.erase_after(cPrev);`
 * The element pointed to by `cCurr` is removed. The `erase_after()` function
 * returns an iterator to the element that *was* after the removed element
 * (or `fList.cend()` if the last element was removed). This returned iterator
 * is assigned back to `cCurr`, effectively advancing it past the removed element.
 * `cPrev` remains unchanged, as it still correctly points to the element *before*
 * the new `cCurr`.
 * - If it's even: `cPrev = cCurr; cCurr++;`
 * The element is kept. Both `cPrev` and `cCurr` are advanced one step forward.
 * `cPrev` takes the position `cCurr` just had, and `cCurr` moves to the next element.
 *
 * The `displaySeqContainer` function is used to show the state of the `forward_list`
 * before and after the removal process.
 *
 * @author Mallikarjuna00G
 * @date 2025-06-29 (or current date if updated)
 */

#include <iostream>
#include <forward_list>
#include <iterator> // Required for std::begin and std::end (though not directly used for fList iteration here, good practice)

#include "displaySeqContainer.hpp" // Assumes this header provides necessary displaySeqContainer overloads (including for forward_list<int>)

using std::cout;
using std::forward_list;

int main() {

    forward_list<int> fList = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    cout << "Before: \n";
    displaySeqContainer(fList); // Assumes displaySeqContainer(const std::forward_list<int>&) is available

    // cbefore_begin() returns an iterator to the element *before* the first element.
    // This is necessary because erase_after() removes the element *after* the given iterator.
    auto cPrev = fList.cbefore_begin();
    auto cCurr = fList.cbegin(); // cbegin() returns a const_iterator to the first element

    // Iterate through the forward_list to find and remove odd-valued elements
    while (cCurr != fList.cend()) { // Using cend() for const_iterator consistency
        if (*cCurr % 2) { // If the current element is odd
            // Erase the element *after* cPrev (which is the element cCurr points to).
            // The erase_after function returns an iterator to the element that was
            // immediately after the erased element. Assign this to cCurr.
            cCurr = fList.erase_after(cPrev);
            // cPrev remains pointing to the element *before* the new cCurr.
        } else { // If the current element is even
            // Element is even, keep it. Advance both iterators.
            cPrev = cCurr; // cPrev now points to the current element (which is kept)
            cCurr++;       // cCurr moves to the next element
        }
    }

    cout << "After: \n";
    displaySeqContainer(fList); // Display the list after removal

    return 0;
}