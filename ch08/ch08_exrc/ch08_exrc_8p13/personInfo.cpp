#include <string>
#include "personInfo.hpp"

using std::string;

bool valid(const string& phone) {
    return phone.size() == 10 ? true : false;
}

string format(const string& nums) {
    return "+91-" + nums;
}