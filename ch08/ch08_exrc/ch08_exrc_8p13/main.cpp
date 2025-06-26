#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <exception>

#include "personInfo.hpp"

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::runtime_error;

int main(int argc, char *argv[]) {

    try {
        ifstream fin("dataInFile.txt");

        if(!fin) {
            throw runtime_error("Failed to open the file" + string(argv[1]));
        }

        string line, word; // will hold a line and word from input, respectively
        vector<PersonInfo> people; // will hold all the records from the input

        while(getline(fin, line)) {
            PersonInfo temp;
            istringstream record(line);
            record >> temp.name;
            while (record >> word) {
                temp.phones.push_back(word);
            }
            people.push_back(temp);
        }

        for (const auto &entry : people) { // for each entry in people
            ostringstream formatted, badNums; // objects created on each loop
            for (const auto &nums : entry.phones) { // for each number
                if (!valid(nums)) {
                    badNums << " " << nums; // string in badNums
                } else
                // "writes" to formatted’s string
                formatted << " " << format(nums);
            }
            if (badNums.str().empty()) // there were no bad numbers
                cout << entry.name << " " << formatted.str() << endl; // and reformatted numbers
            else // otherwise, print the name and bad numbers
                cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
        }

    } catch (runtime_error& err) {
        cout << "ERROR: Runtime error \n";
        cout << "In " << __FILE__ << " : " << __func__ << "\n";
        cout << err.what();
    }
    
    return 0;
}