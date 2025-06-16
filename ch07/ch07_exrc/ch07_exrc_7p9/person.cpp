#include "person.hpp"

istream& Person::read(istream& is, Person &p) {
    getline(is, p.name);
    getline(is, p.address);
    return is;
}

ostream& Person::print(ostream& os, const Person &p) const {
    os << "Name: " << p.name << "\nAddress: " << p.address << "\n";
    return os;
}