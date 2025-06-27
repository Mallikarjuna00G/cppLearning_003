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

#endif