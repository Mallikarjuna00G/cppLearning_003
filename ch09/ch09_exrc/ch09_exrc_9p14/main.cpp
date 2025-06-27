/**
 * @file main.cpp
 * @brief Demonstrates initialization and assignment of `std::vector<string>` from `list` of `char *` pointers.
 *
 * This file contains the main program entry point and an utility function
 * to display vector contents. It showcases a way to initialize
 * a `vector` of `string`s:
 * 1. From a `std::list<const char*>` using iterator range construction.
 * The program then prints the contents of the initialized/assigned `string` vectors.
 *
 * @author Mallikarjuna00G
 * @date 2025-06-27
 */

#include <iostream>
#include <vector>
#include <list>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::string;

/**
 * @brief Prints the elements of a `vector<string>` to standard output.
 *
 * This function iterates through the given vector and prints each `string`
 * element followed by a space. After all elements are printed, it
 * outputs a newline character.
 *
 * @param v A constant reference to the `vector<string>` to be displayed.
 * The vector's elements will not be modified by this function.
 * 
 */
void displayVector(const vector<string> &v) {
    for (const auto &item : v) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {

    list<const char*> oldStyle = {"Hello", "there", "How", "are", "you?"};
    vector<string> d1(oldStyle.cbegin(), oldStyle.cend());  /// Initialization of `vector` `string` with `list` of `char*` pointers.

    displayVector(d1);
    
    list<const char*> oldStyle2 = {"Hello", "again", "How", "are", "you", "today?"};
    vector<string> d2;
    d2.assign(oldStyle2.cbegin(), oldStyle2.cend());  /// Assignment. Using `assign` member

    displayVector(d2);
    
    return 0;
}