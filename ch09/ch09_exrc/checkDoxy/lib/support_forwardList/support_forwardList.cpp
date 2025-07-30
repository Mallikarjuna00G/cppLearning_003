/**
 * @file support_forwardList.cpp
 * @brief Implements utility functions for `std::forward_list`.
 *
 * @details
 * This file contains the definitions for functions that operate on `std::forward_list`
 * containers, providing concrete implementations for prototypes declared in
 * `support_forwardList.hpp`.
 *
 * @author Mallikarjuna00G
 * @date 2025-07-16
 */

#include "support_forwardList.hpp"
#include <iterator>

void fl_insertStr2AfterStr1(std::forward_list<std::string> &container, 
    std::string str1, 
    std::string str2) {
    auto cPrev = container.cbefore_begin();  /// `cPrev` Needed to look at last valid element in the forward list.
    auto cCurr = container.cbegin();

    bool foundStr1 = false;

    while(cCurr != container.cend()) {
        if (*cCurr == str1) {
            cCurr = container.insert_after(cCurr, str2);
            foundStr1 = true;
        }
        cPrev = cCurr;
        cCurr++;  // Placing outside to avoid infinite looping in the case where str1 and str2 are same.
    }

    if (!foundStr1) {
        container.insert_after(cPrev, str2);
    }
}

void removeEvenDupOdd(std::forward_list<int> &container) {
    auto iterPrev = container.before_begin();
    auto iter = container.begin();
    while (iter != container.end()) {
        if (*iter % 2) {
            iter = container.insert_after(iterPrev, *iter); // duplicate the current element
            iter++; // advance past this element
            iter++; // and the one inserted before it
            iterPrev++;
            iterPrev++;
            // we could have used std::advance(iter, 2)
            // we could have used std::advance(iterPrev, 2)
        } else {
            iter = container.erase_after(iterPrev); // remove even elements
            // don’t advance the iterator; iter denotes the element after the one we erased
        }
    }
}