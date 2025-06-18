#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

struct Person;  // forward declaration
std::istream& read(std::istream& is, Person &p);

class Person {
    // START: friend
    friend std::istream& read(std::istream& is, Person &p);
    // END: friend

    public:
    // START: constructors
    Person() = default;
    Person(const std::string &name): name(name) {}
    Person(const std::string &name, const std::string &address): name(name), address(address) {}
    Person(std::istream &is) {
        read(is, *this);
    }
    // END: constructors

    inline std::string getName() const {return name;}
    inline std::string getAddress() const {return address;}
    
    private:
    std::string name = "";
    std::string address = "";
};

std::ostream& print(std::ostream& os, const Person &p);

#endif