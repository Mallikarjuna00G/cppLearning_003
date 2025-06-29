/**
 * @file main.cpp
 * @brief Copies elements from a `list<int>` into two `deque`s, separating odd and even values.
 *
 * @note Exercise 9.20: Write a programto copy elements froma list<int> into two deques.
 * The even-valued elements should go into one deque and the odd ones into the other.

 * This file serves as the main entry point for the program.
 * It demonstrates how to read a sequence of integers from standard input
 * and store them initially into a `std::list<int>`.
 *
 * Subsequently, the program iterates through this list to segregate its elements:
 * even-valued integers are copied into one `std::deque<int>`, and odd-valued
 * integers are copied into another `std::deque<int>`.
 *
 * The program then utilizes the `displaySeqContainer` function (from
 * `displaySeqContainer.hpp`) to print the contents of the initial list,
 * followed by the contents of the `deque`s containing odd and even numbers.
 * This exercise highlights data segregation and the use of different sequential
 * container types (`std::list` for input, `std::deque` for categorized output).
 *
 * @author Mallikarjuna00G
 * @date 2025-06-29
 */

#include <iostream>
#include <list>
#include <deque>

#include "displaySeqContainer.hpp" // Assumes this header provides necessary displaySeqContainer overloads

using std::cout;
using std::cin;
using std::list;
using std::deque;
using std::string; // Keep this if string type is still used elsewhere, otherwise remove

int main() {

    list<int> ls;    /// list to hold the sequence of integers

    /// Reading sequence of integers from standard input into list.
    int num;
    while(cin >> num) {
        ls.push_back(num);    // Adding integer to the end of the list.
    }

    // Displaying the `ls` container
    cout << "\nIntegers in the list:\n";
    displaySeqContainer(ls); // Assumes overload for list<int> is available

    // segregate odd and even integers
    deque<int> dq_even, dq_odd;

    for (const auto &item: ls) {
        if(item % 2) { // True if item is odd (remainder is 1)
            dq_odd.push_back(item);
        } else { // Remainder is 0, item is even
            dq_even.push_back(item);
        }
    }

    cout << "\ndeque with even integers: \n";
    displaySeqContainer(dq_even); // Assumes overload for deque<int> is available

    cout << "\ndeque with odd integers: \n";
    displaySeqContainer(dq_odd); // Assumes overload for deque<int> is available

    return 0;
}
