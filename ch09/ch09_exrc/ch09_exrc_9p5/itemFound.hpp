/**
 * @file itemFound.hpp
 * @brief Declaration of a utility function to search for an item in a vector range.
 *
 * This header file declares the `itemFound` function, which provides
 * functionality similar to `std::find` for integer vectors.
 *
 * @author Mallikarjuna00G
 * @date 26Jun2025
 */

#ifndef ITEM_FOUND_HPP
#define ITEM_FOUND_HPP

#include <vector>
#include <iterator>

/**
 * @brief Searches for a specified integer value within a range of a vector<int>.
 *
 * This function iterates through the elements of a vector<int>
 * from a starting iterator (`itBegin`) up to (but not including) an ending iterator (`itEnd`).
 * It returns an iterator to the first occurrence of the `value` if found.
 *
 * @param itBegin A constant iterator pointing to the beginning of the search range.
 * @param itEnd A constant iterator pointing one past the end of the search range.
 * @param value The integer value to search for.
 * @return A constant iterator to the first element in the range that matches `value`.
 * If `value` is not found, `itEnd` is returned.
 */
std::vector<int>::const_iterator itemFound(std::vector<int>::const_iterator itBegin, 
    std::vector<int>::const_iterator itEnd, 
    const int& a);

#endif