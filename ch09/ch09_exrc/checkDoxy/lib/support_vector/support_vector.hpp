/**
 * @file support_vector.hpp
 * @brief Declarations for utility functions and data types related to `std::vector`.
 *
 * @details
 * This header file provides declarations for functions, classes, or global variables
 * that are designed to support operations or interactions with `std::vector`
 * containers. It is intended to be included by source files that need to use these
 * functionalities.
 *
 * The header guard ensures that the contents of this file are included only once
 * during compilation, preventing redefinition errors.
 *
 * @author Mallikarjuna00G
 * @date 18Jul2025
 */

#ifndef SUPPORT_VECTOR_HPP
#define SUPPORT_VECTOR_HPP

// Include any necessary standard library headers that the declarations below might require
// For example, if you declare functions that take/return std::vector:
#include <vector>     // For basic I/O if functions involve printing

// --- Function Prototypes ---


/**
 * @brief Processes a `std::vector<int>` to duplicate odd elements and remove even elements.
 *
 * @details
 * This function iterates through the provided `std::vector<int>` and modifies it in place
 * according to the following rules:
 * - If an element is **odd**: A duplicate copy of that element is inserted immediately before
 * the original element. The iteration then advances past both the newly inserted duplicate
 * and the original odd element, moving two positions forward in the vector.
 * - If an element is **even**: That element is removed from the vector. The iteration then
 * continues from the element that was immediately after the removed even element.
 *
 * The function uses a single iterator, `iter`, which points to the current element being examined.
 * `std::vector` iterators are random-access, allowing for direct addition/subtraction
 * (`iter += 2`).
 *
 * The loop continues until `iter` reaches `container.end()`.
 *
 * @param container A non-constant reference to the `std::vector<int>` to be modified.
 */
void removeEvenDupOdd(std::vector<int> &container);


#endif // SUPPORT_VECTOR_HPP
