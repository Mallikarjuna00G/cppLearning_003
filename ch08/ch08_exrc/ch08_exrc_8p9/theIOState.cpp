#include "theIOState.hpp"

std::istream& readFile(std::istream& is) {
    int temp = 0;

    // Removed eof check in the while condition because 
    // it was skipping processing the last data.
    while(is >> temp) {
        std::cout << temp << "\n";
    }
    if(is.rdstate()) {
        std::cout << "File: " << __FILE__ << "\n\tFunction: " << __func__ << "(): \n";
        std::cout << "IO state of the input stream is " << is.rdstate() << "\n";
        if(is.eof()) {
            std::cout << "End-of-file detected. eofbit set\n";
        }
        if(is.fail()) {
            std::cout << "failbit set.\n";
        }
        if(is.bad()) {
            std::cout << "badbit set.\n";
        }
    }
    is.clear();
    return is;
}