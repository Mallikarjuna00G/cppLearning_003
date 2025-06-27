#include "itemFound.hpp"

using std::vector;

bool itemFound(std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd, const int& a) {
    while(itBegin != itEnd) {
        if (*itBegin == a) {
            return true;
        }
        itBegin++;
    }

    return false;
}