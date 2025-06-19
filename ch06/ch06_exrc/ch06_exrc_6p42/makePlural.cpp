#include "makePlural.h"

using std::string;

// return the plural version of word if ctr is greater than 1
string make_plural(std::string::size_type ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}