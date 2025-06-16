#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

struct Person {
    std::string name = "";
    std::string address = "";

    inline string getName() const {return name;}
    inline string getAddress() const {return address;}

    istream& read(istream& is, Person &p);
    ostream& print(ostream& os, const Person &p) const;
};

#endif