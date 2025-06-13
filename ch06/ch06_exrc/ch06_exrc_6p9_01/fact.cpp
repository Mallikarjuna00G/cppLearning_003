#include "Chapter6.h"

int fact(int n) {
    int f = 1;
    while (n > 1) {
        f *= n--;
    }
    return f;
}