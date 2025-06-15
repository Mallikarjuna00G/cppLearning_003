#include <iostream>
#include <iterator>
#include "myPrints.h"

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() {
    int i = 0, j[2] = {0, 1};

    
    print(&i, &i + 1);
    print(begin(j), end(j));

    print(&i, 1);
    print(j, (end(j) - (begin(j))));

    print(i);
    print(j);

    return 0;
}