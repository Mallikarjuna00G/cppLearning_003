#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class Screen {
    // START: friend
    
    // END: friend

    public:
    typedef string::size_type pos;
    // using pos = string::size_type;

    // START: constructors
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}
    // END: constructors

    char get() const {return contents[cursor];}  // get the character at the cursor. implicitly inline
    inline char get(pos r, pos c) const;  // explicitly inline. get charcter from specific position
    Screen &move(pos r, pos c);  // can be made inline outside.
    Screen &set(char c);
    Screen &set(pos row, pos col, char ch);

    Screen &display(ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;
    }

    
    private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;

    void do_display(ostream &os) const {
        os << contents;
    }
};

inline Screen& Screen::move(pos r, pos c) {
    pos row = r * width;  // compute the row location
    cursor = row + c;  // move cursor to the column within that row.
    return *this;  // return this object as an lvalue
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;  // set the new value at the current cursor location
    return *this;  // return this object as an lvalue. Note that dereference happens here.
}

inline Screen &Screen::set(pos row, pos col, char ch) {
    contents[row * width + col] = ch;  // set specified location to given value
    return *this;  // return this object as an lvalue
}

#endif