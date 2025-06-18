#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

#include "person.hpp"

using std::string;
using std::cout;
using std::cin;
using std::runtime_error;
using std::exception;

int main() {

    try {
        string hrLine = "----------------------------------\n";
        cout << "With default constructor:\n";
        Person p1;
        print(cout, p1);
        cout << hrLine;

        cout << "With one parameter constructor:\n";
        Person p2("Mallikarjuna00G");
        print(cout, p2);
        cout << hrLine;
        
        cout << "With all parameter constructor:\n";
        Person p3("Mallikarjuna00G", "India");
        print(cout, p3);
        cout << hrLine;
        
        cout << "With istream as parameter for constructor:\n";
        Person p4(cin);
        print(cout, p4);
        cout << hrLine;
        
    } catch (const runtime_error &err) {
        cout << "ERROR: runtime error:\n\t" << err.what();
    }

    return 0;
}