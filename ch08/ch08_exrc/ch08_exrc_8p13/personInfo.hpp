#ifndef PERSON_INFO_HPP
#define PERSON_INFO_HPP

#include <iostream>
#include <string>
#include <vector>

bool valid(const std::string& phone);
std::string format(const std::string& nums);

// members are public by default; see § 7.2 (p. 268)
struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;

    void print(std::ostream& os) const{
        os << name << " ";
        for (const auto& phone: phones) {
            os << phone << " ";
        }
    }
};

#endif