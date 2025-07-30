/**
 * @file support_list.hpp
 * @brief Declarations for utility functions and data types related to `std::list`.
 *
 * @details
 * This header file provides declarations for functions, classes, or global variables
 * that are designed to support operations or interactions with `std::list`
 * containers. It is intended to be included by source files that need to use these
 * functionalities.
 *
 * The header guard ensures that the contents of this file are included only once
 * during compilation, preventing redefinition errors.
 *
 * @author Mallikarjuna00G
 * @date 18Jul2025
 */

#ifndef SUPPORT_LIST_HPP
#define SUPPORT_LIST_HPP

// Include any necessary standard library headers that the declarations below might require
// For example, if you declare functions that take/return std::list:
#include <list>     // For basic I/O if functions involve printing

// --- Function Prototypes ---


/**
 * @brief Processes a `std::list<int>` to duplicate odd elements and remove even elements.
 *
 * @details
 * This function iterates through the provided `std::list<int>` and modifies it in place
 * according to the following rules:
 * - If an element is **odd**: A duplicate copy of that element is inserted immediately before
 * the original element. The iteration then advances past both the newly inserted duplicate
 * and the original odd element, moving two positions forward in the list.
 * - If an element is **even**: That element is removed from the list. The iteration then
 * continues from the element that was immediately after the removed even element.
 *
 * The function uses a single iterator, `iter`, which points to the current element being examined.
 * Unlike `std::forward_list`, `std::list` iterators are bidirectional and allow direct
 * `insert()` (inserts before) and `erase()` (removes at iterator position) operations.
 *
 * The loop continues until `iter` reaches `container.end()`.
 *
 * @param container A non-constant reference to the `std::list<int>` to be modified.
 * @return void
 */
void removeEvenDupOdd(std::list<int> &container);


#endif // SUPPORT_LIST_HPP
