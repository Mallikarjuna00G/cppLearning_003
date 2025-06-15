#include "sumIniList.h"

int sumIniList(initializer_list<int> myInts) {
    int sum = 0;
    for (const auto &a : myInts) {
        sum += a;
    }

    return sum;
}