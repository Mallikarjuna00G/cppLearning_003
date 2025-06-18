#ifndef WINMGR_H
#define WINMGR_H

#include <string>
#include <iostream>
#include <vector>
#include "screen.hpp"

class Window_mgr {
    // START: friend
    
    // END: friend

    public:
    
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    
    private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

#endif