#include "itemFound.hpp"

using std::vector;

std::vector<int>::const_iterator itemFound(std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd, const int& a) {
    while(itBegin != itEnd) {
        if (*itBegin == a) {
            return itBegin;
        }
        itBegin++;
    }

    return itEnd;
}