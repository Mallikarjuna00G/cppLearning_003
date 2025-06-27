/**
 * @file seqContainerCompare.cpp
 * @brief Implementation for the `seqContainerCompare` function.
 *
 * This file provides the definition for the `seqContainerCompare` function,
 * which performs a three-way lexicographical comparison between a
 * `std::vector<int>` and a `std::list<int>`.
 *
 * @author Mallikarjuna00G
 * @date 2025-06-27
 */

#include "seqContainerCompare.hpp" // Include the header for function declaration

#include <vector>   // Included for std::vector definition
#include <list>     // Included for std::list definition

int seqContainerCompare(const std::vector<int>& vec, const std::list<int>& ls) {
    // Initialize constant iterators for both containers.
    // 'auto' correctly deduces the specific const_iterator type for each container.
    auto it_vec = vec.cbegin();
    auto it_ls = ls.cbegin();

    // Perform element-by-element lexicographical comparison.
    // The loop continues as long as both iterators are valid (haven't reached their end).
    for(; it_vec != vec.cend() && it_ls != ls.cend(); ++it_vec, ++it_ls) {
        if (*it_vec < *it_ls) {
            // Found an element in 'vec' that is less than the corresponding element in 'ls'
            return -1;
        } else if (*it_vec > *it_ls) {
            // Found an element in 'vec' that is greater than the corresponding element in 'ls'
            return 1;
        }
        // If elements are equal, continue to the next pair
    }

    // After the loop, one or both containers have been fully traversed.
    // Now, determine the result based on their remaining lengths.

    /**
     * @note **Why not use subtraction (e.g., `vec.size() - ls.size()`) here?**
     * The `size()` member function of standard containers returns `std::size_type`,
     * which is an `unsigned` integer type. If `ls.size()` were greater than `vec.size()`,
     * a direct subtraction like `vec.size() - ls.size()` would result in
     * **unsigned integer underflow**. This would wrap around and produce a very large
     * positive number instead of a negative one, leading to incorrect comparison results.
     *
     * Instead, we perform explicit comparisons (`<`, `>`) of the `size_type` values
     * to safely determine which container is longer if their common prefixes were equal.
     *
     */
    if (vec.size() < ls.size()) {
        // If 'vec' ended first and was a prefix of 'ls' (or they are equal up to vec's end)
        // 'vec' is shorter, so it is "less than" 'ls'.
        return -1;
    } else if (vec.size() > ls.size()) { // Corrected condition
        // If 'ls' ended first and was a prefix of 'vec' (or they are equal up to ls's end)
        // 'vec' is longer, so it is "greater than" 'ls'.
        return 1;
    } else {
        // Both iterators reached their ends at the same time, and no mismatch was found.
        // This means both containers have the same elements in the same order and same length.
        return 0; // Containers are equivalent
    }
}
