/**
 * @file support_forwardList.hpp
 * @brief Declarations for utility functions and data types related to `std::forward_list`.
 *
 * @details
 * This header file provides declarations for functions, classes, or global variables
 * that are designed to support operations or interactions with `std::forward_list`
 * containers. It is intended to be included by source files that need to use these
 * functionalities.
 *
 * The header guard ensures that the contents of this file are included only once
 * during compilation, preventing redefinition errors.
 *
 * @author Mallikarjuna00G
 * @date 17Jul2025
 */

#ifndef SUPPORT_FORWARDLIST_HPP
#define SUPPORT_FORWARDLIST_HPP

// Include any necessary standard library headers that the declarations below might require
// For example, if you declare functions that take/return std::forward_list:
#include <forward_list> // For std::forward_list
#include <iostream>     // For basic I/O if functions involve printing
#include <string>     // For basic I/O if functions involve printing

// --- Function Prototypes ---

/**
 * @brief Inserts a string (`str2`) immediately after every occurrence of another string (`str1`)
 * in a `std::forward_list<std::string>`. If `str1` is not found anywhere in the list,
 * `str2` is inserted at the end of the list.
 *
 * @details
 * This function modifies the provided `std::forward_list<std::string>` in place.
 * It iterates through the list using two constant iterators, adapting to the
 * singly-linked nature of `std::forward_list` and its `insert_after` method:
 * - `cPrev`: An iterator that tracks the element *before* the current element being processed.
 * It is initialized to `container.cbefore_begin()`, which is a special iterator
 * pointing conceptually before the first element, allowing insertions at the beginning
 * of the list if needed (though not directly used for that purpose in this function).
 * - `cCurr`: An iterator that points to the current element being examined.
 *
 * The function proceeds through the list as follows:
 * 1. A boolean flag `foundStr1` is initialized to `false`. This flag will be set to `true`
 * if `str1` is found and `str2` is inserted at least once during the loop.
 * 2. The `while` loop iterates as long as `cCurr` has not reached the end of the list.
 * 3. Inside the loop:
 * - If the value pointed to by `cCurr` (`*cCurr`) matches `str1`:
 * - `str2` is inserted into the list immediately after the element pointed to by `cCurr`
 * using `container.insert_after(cCurr, str2)`.
 * - `cCurr` is then updated to point to the *newly inserted element*. This is the return
 * value of `insert_after`, ensuring that the iteration correctly continues from the
 * newly added node.
 * - The `foundStr1` flag is set to `true` to record that at least one match and insertion occurred.
 * - After checking (and potentially inserting), `cPrev` is updated to the position `cCurr`
 * was just at (or the newly inserted element if an insertion happened). This maintains
 * `cPrev` as the iterator to the element *before* the next `cCurr`.
 * - Finally, `cCurr` is advanced to the next element (`cCurr++`). This advancement is
 * placed outside the `if` block to ensure `cCurr` always moves forward, preventing
 * infinite loops in scenarios where `str1` and `str2` might be identical.
 *
 * 4. After the loop completes:
 * - If `foundStr1` is still `false` (meaning `str1` was never found during the entire iteration),
 * `str2` is inserted at the very end of the list. At this point, `cPrev` will have
 * advanced to point to the last element of the original list (or `cbefore_begin()` if
 * the list was initially empty). Calling `container.insert_after(cPrev, str2)` then
 * correctly appends `str2` to the end.
 *
 * @param container A non-constant reference to the `std::forward_list<std::string>` to be modified.
 * The function will insert elements into this list.
 * @param str1 The string value to search for within the container.
 * @param str2 The string value to insert after `str1` (or at the end if `str1` is not found).
 */
void fl_insertStr2AfterStr1(std::forward_list<std::string> &container,
                            std::string str1,
                            std::string str2);


/**
 * @brief Processes a `std::forward_list<int>` to duplicate odd elements and remove even elements.
 *
 * @details
 * This function iterates through the provided `std::forward_list<int>` and modifies it in place
 * according to the following rules:
 * - If an element is **odd**: A duplicate copy of that element is inserted immediately after it.
 * The iteration then skips both the original odd element and its newly inserted duplicate,
 * moving to the element that was originally two positions after the odd element.
 * - If an element is **even**: That element is removed from the list. The iteration then
 * continues from the element that was immediately after the removed even element.
 *
 * The function uses two iterators:
 * - `iterPrev`: Points to the element *before* the current element being processed. This is essential
 * for `std::forward_list`'s `insert_after` and `erase_after` methods, which operate on the element
 * *following* the provided iterator. It is initialized to `container.before_begin()`.
 * - `iter`: Points to the current element being examined.
 *
 * The loop continues until `iter` reaches `container.end()`.
 *
 * @param container A non-constant reference to the `std::forward_list<int>` to be modified.
 */
void removeEvenDupOdd(std::forward_list<int> &container);


#endif // SUPPORT_FORWARDLIST_HPP
