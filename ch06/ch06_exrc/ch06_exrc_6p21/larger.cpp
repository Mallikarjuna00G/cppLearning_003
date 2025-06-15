#include "larger.h"

int larger(const int a, const int *const b) {
    return a > *b ? a : *b;
}