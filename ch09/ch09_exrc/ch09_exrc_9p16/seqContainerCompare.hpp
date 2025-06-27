/**
 * @file seqContainerCompare.hpp
 * @brief Declaration for a function to lexicographically compare two sequential containers.
 *
 * This header declares the compare functions, which provide a
 * three-way comparison between the containers.
 * The comparison is performed element-by-element (lexicographically) first.
 * If the common prefixes are equal, the shorter container is considered "less than"
 * the longer one.
 *
 * This function returns:
 * - A negative value (-1) if the first container (`vec`) is less than the second (`ls`).
 * - Zero (0) if the containers are equivalent.
 * - A positive value (1) if the first container (`vec`) is greater than the second (`ls`).
 *
 * @author Mallikarjuna00G
 * @date 2025-06-27
 */

#ifndef SEQ_CONTAINER_COMPARE_HPP
#define SEQ_CONTAINER_COMPARE_HPP

#include <vector> // Required for std::vector
#include <list>   // Required for std::list

/**
 * @brief Performs a three-way lexicographical comparison between a `std::vector<int>` and a `std::list<int>`.
 *
 * This function compares `vec` and `ls` element by element.
 * The comparison proceeds until a mismatch is found or the end of one (or both)
 * containers is reached.
 *
 * If a mismatch is found, the container with the smaller element at the
 * first differing position is considered "less than".
 *
 * If no mismatch is found (i.e., one container is a prefix of the other,
 * or they are identical), the comparison is then based on size:
 * The shorter container is considered "less than" the longer one.
 * If both containers have the same elements and same size, they are equivalent.
 *
 * @note **Why iterators instead of indexing?**
 * Many sequential containers, such as `std::list` and `std::forward_list`,
 * do not support direct random access using the `operator[]` (indexing).
 * Accessing elements by index in these containers would be inefficient (linear time)
 * or simply not allowed by the compiler. Iterators (`cbegin()`, `cend()`) provide a
 * uniform and efficient way to traverse elements in all standard library containers,
 * allowing this function to be written generically for different sequential types
 * without relying on a specific access method.
 *
 * @param vec A constant reference to the `std::vector<int>` to be compared.
 * @param ls  A constant reference to the `std::list<int>` to be compared.
 *
 * @return
 * - `-1` if `vec` is lexicographically less than `ls`.
 * - `0` if `vec` is lexicographically equivalent to `ls` (same elements, same length).
 * - `1` if `vec` is lexicographically greater than `ls`.
 */
int seqContainerCompare(const std::vector<int>& vec, const std::list<int>& ls);

#endif // SEQ_CONTAINER_COMPARE_HPP
