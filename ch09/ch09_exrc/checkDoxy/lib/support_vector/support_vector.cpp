/**
 * @file support_vector.cpp
 * @brief Implements utility functions for `std::vector`.
 *
 * @details
 * This file contains the definitions for functions that operate on `std::vector`
 * containers, providing concrete implementations for prototypes declared in
 * `support_vector.hpp`.
 *
 * @author Mallikarjuna00G
 * @date 2025-07-18
 */

#include "support_vector.hpp"
#include <iterator>

void removeEvenDupOdd(std::vector<int> &container) {
    auto iter = container.begin(); // call begin, not cbegin because we’re changing vi
    while (iter != container.end()) {
        if (*iter % 2) {
            iter = container.insert(iter, *iter); // duplicate the current element
            iter += 2; // advance past this element and the one inserted before it
        } else {
            iter = container.erase(iter); // remove even elements
            // don’t advance the iterator; iter denotes the element after the one we erased
        }
    }
}