/**
 * @file main.cpp
 * @brief Exercise 9.24: Demonstrates various ways to access `std::vector` elements and tests behavior with an empty vector.
 *
 * @note Exercise 9.24: Write a program that fetches the first element in a vector using at, the subscript operator, front, and begin.
 * Test your program on an empty vector.
 * 
 * @details
 * This program serves as the main entry point for Exercise 9.24.
 * It is designed to illustrate and compare four different methods of accessing
 * elements in a `std::vector<int>`:
 * 1. `at()` member function
 * 2. `operator[]` (subscript operator)
 * 3. `front()` member function
 * 4. `back()` member function
 *
 * The program first demonstrates these access methods on a **non-empty vector**.
 *
 * Subsequently, it tests the same access methods on an **empty `std::vector<int>`**.
 * This part of the exercise is crucial for understanding the safety and behavior
 * of each access method when the container is empty:
 * - `vec_empty.at(0)`: This call is **safe** in terms of catching errors. It performs
 * a bounds check and will throw an `std::out_of_range` exception if the index
 * is out of bounds (which it is for an empty vector). The program will terminate
 * with an exception, indicating the error gracefully.
 * - `vec_empty[0]`, `vec_empty.front()`, `vec_empty.back()`: These calls
 * **do not perform bounds checks**. Accessing elements on an empty vector
 * using these methods results in **undefined behavior**. This typically leads
 * to a program crash, such as a segmentation fault, as they attempt to access
 * memory that does not belong to the program or contains invalid data.
 *
 * This exercise highlights the importance of checking `!container.empty()`
 * before using `operator[]`, `front()`, or `back()`, and the defensive nature
 * of `at()` for safer element access when bounds are uncertain.
 *
 * @author Mallikarjuna00G
 * @date 2025-06-29
 */

#include <iostream>
#include <vector>
#include <string> // Only include if used by other displaySeqContainer overloads. Otherwise, it's not strictly needed for this main.cpp.

#include "displaySeqContainer.hpp" // Assumes this header provides necessary displaySeqContainer overloads

using std::cout;
using std::cin;    // Not used in this program, can be removed
using std::vector;
using std::string; // Not strictly used for data, can be removed if not needed by displaySeqContainer.

int main() {

    cout << "With non-empty vector vec: \n";
    vector<int> vec = {32, 67, 45, 89, 12, 89, 56, 77};
    displaySeqContainer(vec); // Assuming displaySeqContainer(const std::vector<int>&) overload exists.

    cout << "first element using `at`: " << vec.at(0) << "\n";
    cout << "first element using `[]`: " << vec[0] << "\n";
    cout << "first element using `front`: " << vec.front() << "\n";
    cout << "last element using `back`: " << vec.back() << "\n"; // Corrected comment: this is `back()`, not `front()`

    cout << "\nWith empty vector vec_empty: \n";
    vector<int> vec_empty;
    displaySeqContainer(vec_empty); // Assuming displaySeqContainer(const std::vector<int>&) overload exists.

    // The following calls on vec_empty will lead to runtime errors:
    // - at(0) throws std::out_of_range
    // - [], front(), back() lead to undefined behavior (often segmentation faults)
    // The program is designed to crash here to demonstrate the problem as per the exercise.
    cout << "Attempting to access elements of an empty vector (expecting runtime errors below):\n";
    cout << "first element using `at`: " << vec_empty.at(0) << "\n";
    cout << "first element using `[]`: " << vec_empty[0] << "\n";
    cout << "first element using `front`: " << vec_empty.front() << "\n";
    cout << "last element using `back`: " << vec_empty.back() << "\n"; // Corrected comment: this is `back()`, not `front()`

    return 0;
}
