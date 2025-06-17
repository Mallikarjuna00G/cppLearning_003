#include "winMgr.hpp"

void Window_mgr::clear(ScreenIndex i) {
    Screen s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}