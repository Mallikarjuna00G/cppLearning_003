#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>

class Y;  // forward declaration

class X {
    Y* pY;
};

class Y {
    X pX;
};

#endif