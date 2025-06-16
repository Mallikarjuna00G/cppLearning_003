#ifndef PERSON_H
#define PERSON_H

#include <string>

using std::string;

struct Person {
    std::string name = "";
    std::string address = "";

    string getName() const {return name;}
    string getAddress() const {return address;}
};

#endif