#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

struct Person {
    std::string name = "";
    std::string address = "";

    inline std::string getName() const {return name;}
    inline std::string getAddress() const {return address;}

};

std::istream& read(std::istream& is, Person &p);
std::ostream& print(std::ostream& os, const Person &p);

#endif