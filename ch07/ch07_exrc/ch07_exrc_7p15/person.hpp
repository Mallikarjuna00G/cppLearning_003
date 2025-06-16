#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

struct Person;  // forward declaration
istream& read(istream& is, Person &p);

struct Person {
    // START: constructors
    Person() = default;
    Person(const string &name): name(name) {}
    Person(const string &name, const string &address): name(name), address(address) {}
    Person(istream &is) {
        read(is, *this);
    }
    // END: constructors

    std::string name = "";
    std::string address = "";

    inline string getName() const {return name;}
    inline string getAddress() const {return address;}

};

ostream& print(ostream& os, const Person &p);

#endif