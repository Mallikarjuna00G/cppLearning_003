/**
 * @file main.cpp
 * @brief Exercise 9.19: Reads strings into a `list` and prints elements using iterators.
 *
 * Exercise 9.19: Rewrite the program from the previous exercise to use a list. List the
 * changes you needed to make.

 * This file serves as the main entry point for the program.
 * It demonstrates how to read a sequence of `std::string`s from standard input
 * and store them into a `std::list<std::string>`.
 *
 * Subsequently, it utilizes the `displaySeqContainer` function (declared in
 * `displaySeqContainer.hpp`), which accepts iterators to traverse and print
 * the elements of the `list` to standard output.
 *
 * This exercise specifically focuses on the use of `std::list` and iterators
 * for input and output operations, highlighting its usage compared to `std::deque`.
 *
 * @section Changes Changes from Exercise 9.18 (using `std::deque`):
 * - Changed the container type from `std::deque<std::string>` to `std::list<std::string>`.
 * - Updated include directive from `<deque>` to `<list>`.
 * - Changed `using` declaration from `deque` to `list`.
 * - Changed the variable name from `deq` to `ls` (consistent with `list`).
 * - No changes were required in the `displaySeqContainer` function call itself,
 * as it accepts iterators, demonstrating the flexibility of iterator-based functions
 * across different sequential container types.
 *
 * @author Mallikarjuna00G
 * @date 2025-06-29
 */

#include <iostream>
#include <list>
#include <string>

#include "displaySeqContainer.hpp" // Assumes this header provides the displaySeqContainer function for list iterators

using std::cout;
using std::cin;
using std::list;
using std::string;

int main() {

    list<string> ls;    /// list to hold the sequence of strings

    /// Reading sequence of string from standard input into list.
    string word;
    while(cin >> word) {
        ls.push_back(word);    // Adding string to the end of the list.
    }

    // Displaying the `ls` container using iterators
    displaySeqContainer(ls.cbegin(), ls.cend());

    return 0;
}
