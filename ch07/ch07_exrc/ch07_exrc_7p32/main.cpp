#include <iostream>
#include <exception>
#include <stdexcept>

#include "screen.hpp"
#include "winMgr.hpp"

using std::cout;
using std::cin;
using std::runtime_error;
using std::exception;

int main() {

    try {
        string hrLine = "----------------------------------\n";
        
        Window_mgr wm1;

        wm1.clear(0);
        
    } catch (const runtime_error &err) {
        cout << "ERROR: runtime error:\n\t" << err.what();
    }

    return 0;
}