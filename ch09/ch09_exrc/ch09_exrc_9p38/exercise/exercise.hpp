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

#endif // EXERCISE_HPP