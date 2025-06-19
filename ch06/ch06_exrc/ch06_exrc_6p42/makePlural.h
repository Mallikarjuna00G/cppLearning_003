#ifndef MAKE_PLURAL_H
#define MAKE_PLURAL_H

#include <string>
#include <cstddef>

std::string make_plural(std::string::size_type ctr, const std::string &word, const std::string &ending = "s");

#endif