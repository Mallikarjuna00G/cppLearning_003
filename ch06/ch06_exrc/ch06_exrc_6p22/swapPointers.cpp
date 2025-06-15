#include "swapPointers.h"

void swapPointers(int *&a, int *&b) {
    int *c = a;
    a = b;
    b = c;
}