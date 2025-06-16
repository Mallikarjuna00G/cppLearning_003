#ifndef MAKE_PLURAL_H
#define MAKE_PLURAL_H

#include <string>

using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s");

#endif