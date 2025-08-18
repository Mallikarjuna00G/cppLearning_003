/**
 * @file exercise.hpp
 */

#ifndef EXERCISE_HPP
#define EXERCISE_HPP

#include <vector>

/**
 * @brief Demonstrates the concepts of vector `size`, `capacity`, `reserve`, and `shrink_to_fit`.
 * 
 * @details Exercise 9.38: Write a program to explore how vectors grow in the library you use.
 *
 * This function serves as an educational example to illustrate key differences
 * in how a `std::vector` manages its internal memory. It populates a vector
 * to show how its capacity grows dynamically. It then uses `reserve` to
 * pre-allocate memory and `shrink_to_fit` to reduce the vector's capacity
 * to its size.
 *
 * @note This function requires a `dispVectorSizeAndCapacity` helper function
 * for output.
 *
 * @return `EXIT_SUCCESS` on successful completion.
 */
int exercise();

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

#endif // EXERCISE_HPP