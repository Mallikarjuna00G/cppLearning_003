/**
 * @file support_list.cpp
 * @brief Implements utility functions for `std::list`.
 *
 * @details
 * This file contains the definitions for functions that operate on `std::list`
 * containers, providing concrete implementations for prototypes declared in
 * `support_list.hpp`.
 *
 * @author Mallikarjuna00G
 * @date 2025-07-18
 */

#include "support_list.hpp"
#include <iterator>

void removeEvenDupOdd(std::list<int> &container) {
    auto iter = container.begin(); // call begin, not cbegin because we’re changing vi
    while (iter != container.end()) {
        if (*iter % 2) {
            iter = container.insert(iter, *iter); // duplicate the current element
            iter++; // advance past this element
            iter++; // and the one inserted before it
            // we could have used std::advance(iter, 2)
        } else {
            iter = container.erase(iter); // remove even elements
            // don’t advance the iterator; iter denotes the element after the one we erased
        }
    }
}