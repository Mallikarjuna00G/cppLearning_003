#ifndef WINMGR_H
#define WINMGR_H

#include <string>
#include <iostream>
#include <vector>
#include "screen.hpp"

using std::string;
using std::vector;
using std::istream;
using std::ostream;

class Window_mgr {
    // START: friend
    
    // END: friend

    public:
    
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
    
    private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

#endif