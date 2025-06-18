#ifndef MAKE_PLURAL_H
#define MAKE_PLURAL_H

#include <string>
#include <cstddef>

std::string make_plural(std::size_t ctr, const std::string &word, const std::string &ending = "s");

#endif