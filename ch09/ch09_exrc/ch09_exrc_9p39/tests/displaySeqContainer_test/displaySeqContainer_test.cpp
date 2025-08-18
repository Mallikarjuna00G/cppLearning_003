#include <vector>
#include <iostream>

using std::vector;
using std::cout;

#include "gtest/gtest.h"
#include "displaySeqContainer.hpp"

TEST(test, test1) {
    ASSERT_EQ(1, 1);
}

TEST(test, test2) {
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};

    auto iter = vi.begin();
    int temp = 0;
    // safer: recalculate end on each trip whenever the loop adds/erases elements
    while (iter != vi.end() && temp++ < 20) {
        cout << "Before insert call: \n";
        displaySeqContainer(vi);
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
        cout << "After insert call: \n";
        displaySeqContainer(vi);
        ++iter; // advance begin past the element we just added
        cout << "------------------------------------\n";
    }
    ASSERT_EQ(1, 1);
}