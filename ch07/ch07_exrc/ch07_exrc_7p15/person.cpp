#include "person.hpp"

istream& read(istream& is, Person &p) {
    getline(is, p.name);
    getline(is, p.address);
    return is;
}

ostream& print(ostream& os, const Person &p) {
    os << "Name: " << p.name << "\nAddress: " << p.address << "\n";
    return os;
}