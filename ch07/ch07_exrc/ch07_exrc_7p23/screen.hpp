#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen {
    // START: friend
    
    // END: friend

    public:
    typedef std::string::size_type pos;
    // using pos = std::string::size_type;

    // START: constructors
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}
    // END: constructors

    char get() const {return contents[cursor];}  // get the character at the cursor. implicitly inline
    inline char get(pos r, pos c) const;  // explicitly inline. get charcter from specific position
    Screen &move(pos r, pos c);  // can be made inline outside.
    
    
    private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline Screen& Screen::move(pos r, pos c) {
    pos row = r * width;  // compute the row location
    cursor = row + c;  // move cursor to the column within that row.
    return *this;  // return this object as an lvalue
}

#endif