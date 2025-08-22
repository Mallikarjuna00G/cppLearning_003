/**
 * @file displaySeqContainer.hpp
 * @brief Declarations for utility functions to display sequential containers.
 *
 * This header declares overloaded functions for `displaySeqContainer`.
 * These functions are designed to print the elements of various standard
 * sequential containers to standard output.
 *
 * @author Mallikarjuna00G
 * @date 2025-06-27
 */

#ifndef DISPLAY_SEQ_CONTAINER_HPP
#define DISPLAY_SEQ_CONTAINER_HPP

#include <iostream>
#include <vector>
#include <deque>  // For std::deque and its iterators
#include <string>  // For std::string
#include <list>  // For std::list and its iterators
#include <forward_list>  // For std::forward_list and its iterators

/**
 * @brief Prints the elements of a `vector<int>` to standard output.
 *
 * This function iterates through the given vector and prints each `string`
 * element followed by a space. After all elements are printed, it
 * outputs a newline character.
 *
 * @param container A constant reference to the `vector<int>` to be displayed.
 * The vector's elements will not be modified by this function.
 * 
 */
void displaySeqContainer(const std::vector<int> &container);

/**
 * @brief Prints the elements of a `std::deque<int>` to standard output.
 *
 * This function iterates through the given `std::deque<int>` and prints each `int`
 * element followed by a space. After all elements are printed, it
 * outputs a newline character.
 *
 * @param container A constant reference to the `std::deque<int>` to be displayed.
 * The deque's elements will not be modified by this function.
 *
 */
void displaySeqContainer(const std::deque<int> &container);

/**
 * @brief Prints the elements within a specified `std::deque<std::string>` range to standard output.
 *
 * This function iterates through a range of elements in a `std::deque<std::string>`,
 * defined by a pair of constant iterators. It prints each `std::string` element
 * followed by a space. After traversing the entire specified range, it outputs a newline character.
 *
 * @note **Iterator Parameterization:**
 * This function takes `std::deque<std::string>::const_iterator` parameters by **value**.
 * This is the standard and recommended practice for algorithms that traverse a range
 * but do not need to modify the caller's original iterator objects. Passing by value
 * ensures that any internal advancement of `it_container_beg` within the loop
 * does not affect the iterator used in the calling code, maintaining const-correctness
 * and avoiding unintended side effects on the caller's iterators.
 *
 * @param it_container_beg A `const_iterator` pointing to the first element of the range to display.
 * This iterator will be advanced internally but the caller's original
 * iterator remains unchanged.
 * @param it_container_end A `const_iterator` pointing one past the last element of the range to display.
 * This marks the end of the iteration.
 */
void displaySeqContainer(std::deque<std::string>::const_iterator it_container_beg,
    std::deque<std::string>::const_iterator it_container_end);

    /**
 * @brief Prints the elements within a specified `std::list<std::string>` range to standard output.
 *
 * This function iterates through a range of elements in a `std::list<std::string>`,
 * defined by a pair of constant iterators. It prints each `std::string` element
 * followed by a space. After traversing the entire specified range, it outputs a newline character.
 *
 * @note **Iterator Parameterization:**
 * This function takes `std::list<std::string>::const_iterator` parameters by **value**.
 * This is the standard and recommended practice for algorithms that traverse a range
 * but do not need to modify the caller's original iterator objects. Passing by value
 * ensures that any internal advancement of `it_container_beg` within the loop
 * does not affect the iterator used in the calling code, maintaining const-correctness
 * and avoiding unintended side effects on the caller's iterators.
 *
 * @param it_container_beg A `const_iterator` pointing to the first element of the range to display.
 * This iterator will be advanced internally but the caller's original
 * iterator remains unchanged.
 * @param it_container_end A `const_iterator` pointing one past the last element of the range to display.
 * This marks the end of the iteration.
 */
void displaySeqContainer(std::list<std::string>::const_iterator it_container_beg,
    std::list<std::string>::const_iterator it_container_end);

/**
 * @brief Prints the elements of a `std::list<int>` to standard output.
 *
 * This function iterates through the given `std::list<int>` and prints each `int`
 * element followed by a space. After all elements are printed, it
 * outputs a newline character.
 *
 * @param container A constant reference to the `std::list<int>` to be displayed.
 * The list's elements will not be modified by this function.
 *
 */
void displaySeqContainer(const std::list<int> &container); // New overload declaration

/**
 * @brief Displays the elements of a `std::forward_list<int>` to standard output.
 *
 * @details
 * This function iterates through the provided `std::forward_list<int>` and prints
 * each integer element to the standard output stream (`std::cout`),
 * followed by a space. After all elements are printed, a newline character
 * (`std::endl`) is output, ensuring that subsequent output starts on a new line.
 * This overload is specifically designed for `std::forward_list<int>`.
 *
 * @param container A constant reference to the `std::forward_list<int>` to be displayed.
 * The function does not modify the container.
 */
void displaySeqContainer(const std::forward_list<int> &container);

/**
 * @brief Displays the elements of a `std::forward_list<string>` to standard output.
 *
 * @details
 * This function iterates through the provided `std::forward_list<string>` and prints
 * each integer element to the standard output stream (`std::cout`),
 * followed by a space. After all elements are printed, a newline character
 * (`std::endl`) is output, ensuring that subsequent output starts on a new line.
 * This overload is specifically designed for `std::forward_list<string>`.
 *
 * @param container A constant reference to the `std::forward_list<int>` to be displayed.
 * The function does not modify the container.
 */
void displaySeqContainer(const std::forward_list<std::string> &container);

/**
 * @brief Displays the current size and capacity of a constant `std::vector<int>`.
 *
 * This helper function provides a concise way to output the `size()` and
 * `capacity()` of a given vector to standard output. It is intended for
 * debugging and educational purposes.
 *
 * @param vec A constant reference to the vector whose size and capacity will be
 * displayed.
 */
void dispVectorSizeAndCapacity(const std::vector<int>& vec);

/**
 * @brief Displays the current size and capacity of a constant `std::vector<std::string>`.
 *
 * This helper function provides a concise way to output the `size()` and
 * `capacity()` of a given vector to standard output. It is intended for
 * debugging and educational purposes.
 *
 * @param vec A constant reference to the vector whose size and capacity will be
 * displayed.
 */
void dispVectorSizeAndCapacity(const std::vector<std::string>& vec);

#endif