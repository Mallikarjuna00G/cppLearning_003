/**
 * @file main.cpp
 * @brief Exercise 9.18: Reads strings into a `deque` and prints elements using iterators.
 *
 * This file serves as the main entry point for the program.
 * It demonstrates how to read a sequence of `std::string`s from standard input
 * and store them into a `std::deque<std::string>`.
 *
 * Subsequently, it utilizes the `displaySeqContainer` function (declared in
 * `displaySeqContainer.hpp`), which accepts iterators to traverse and print
 * the elements of the `deque` to standard output.
 *
 * This exercise specifically focuses on the use of `std::deque` and iterators
 * for input and output operations.
 *
 * @author Mallikarjuna00G
 * @date 2025-06-29
 */

#include <iostream>
#include <deque>
#include <string>

#include "displaySeqContainer.hpp" // Assumes this header provides the displaySeqContainer function for deque iterators

using std::cout;
using std::cin;
using std::deque;
using std::string;

int main() {

    deque<string> deq;   /// deque to hold the sequence of strings

    /// Reading sequence of string from standard input into deque.
    string word;
    while(cin >> word) {
        deq.push_back(word);   // Adding string to the end of the deque.
    }

    // Displaying the `deq` container using iterators
    displaySeqContainer(deq.cbegin(), deq.cend());

    return 0;
}
