#include <vector>
#include <iostream>

using std::vector;
using std::cout;

#include "gtest/gtest.h"
#include "exercise.hpp"

TEST(test, test1) {
    ASSERT_EQ(1, 1);
}

TEST(test, test2) {
    exercise();
    ASSERT_EQ(1, 1);
}