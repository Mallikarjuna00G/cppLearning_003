#include "screen.hpp"

/**
 * Declared as inline in the class
 * Return character at given position(row, column)
 */
char Screen::get(pos r, pos c) const {
    pos row = r * width;  // compute row location
    return contents[row + c];  // return character at the given column
}