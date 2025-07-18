/**
 * @file main.cpp
 * @brief Exercise 9.28: Demonstrates a function to insert a string into a `forward_list<string>`.
 *
 * @note Exercise 9.28: Write a function that takes a forward_list<string> and two additional
 * string arguments. The function should find the first string and insert the
 * second immediately following the first. If the first string is not found, then insert the
 * second string at the end of the list.
 * 
 * @details
 * This file contains the main program entry point for Exercise 9.28.
 * It showcases the functionality of the `fl_insertStr2AfterStr1` function,
 * which is designed to modify a `std::forward_list<std::string>` based on
 * specific insertion rules.
 *
 * The program performs the following steps:
 * 1. Initializes a `std::forward_list<std::string>` named `fList` with
 * an initial set of color strings.
 * 2. Displays the initial content of `fList` using `displaySeqContainer`.
 * 3. Calls `fl_insertStr2AfterStr1` multiple times to demonstrate its behavior:
 * - `fl_insertStr2AfterStr1(fList, "red", "chillies");`: This call
 * attempts to find "red" and insert "chillies" after it. Based on the
 * `fl_insertStr2AfterStr1` function's logic, if "red" is found, "chillies"
 * will be inserted immediately after it. If "red" appears multiple times,
 * "chillies" will be inserted after each occurrence.
 * - `fl_insertStr2AfterStr1(fList, "black", "berries");`: This call
 * attempts to find "black" and insert "berries" after it.
 * - `fl_insertStr2AfterStr1(fList, "straw", "berries");`: This call
 * attempts to find "straw" and insert "berries" after it.
 * 4. Displays the final content of `fList` after all modifications,
 * again using `displaySeqContainer`.
 *
 * This example specifically tests scenarios where `str1` is found, leading
 * to insertions within the list. The `displaySeqContainer` function is assumed
 * to be appropriately overloaded to handle `std::forward_list<std::string>`.
 *
 * @author Mallikarjuna00G
 * @date 2025-07-16
 */

#include <iostream>
#include <string>
#include <forward_list>

#include "displaySeqContainer.hpp" // Assumes this header provides necessary displaySeqContainer overloads (including for forward_list<string>)
#include "support_forwardList.hpp" // Assumes this header declares fl_insertStr2AfterStr1

using std::cout;
using std::string;
using std::forward_list;

// Function prototype for fl_insertStr2AfterStr1 (defined in support_forwardList.hpp)
// void fl_insertStr2AfterStr1(std::forward_list<std::string> &container, std::string str1, std::string str2);

int main() {

    forward_list<string> fList = {"red", "green", "blue", "straw", "black"};

    cout << "Before: \n";
    displaySeqContainer(fList); // Assumes displaySeqContainer(const std::forward_list<std::string>&) is available

    fl_insertStr2AfterStr1(fList, "red", "chillies");
    fl_insertStr2AfterStr1(fList, "black", "berries");
    fl_insertStr2AfterStr1(fList, "straw", "berries");
    fl_insertStr2AfterStr1(fList, "bro", "code");

    cout << "After: \n";
    displaySeqContainer(fList); // Display the list after removal

    return 0;
}
