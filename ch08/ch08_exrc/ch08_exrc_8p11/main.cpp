#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <exception>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::runtime_error;

int main(int argc, char *argv[]) {

    try {
        ifstream fin("dataInFile.txt");

        if(!fin) {
            throw runtime_error("Failed to open the file" + string(argv[1]));
        }

        // members are public by default; see § 7.2 (p. 268)
        struct PersonInfo {
            string name;
            vector<string> phones;
        };

        string line, word; // will hold a line and word from input, respectively
        vector<PersonInfo> people; // will hold all the records from the input
        // read the input a line at a time until cin hits end-of-file (or another error)
        istringstream record; // bind record to the line we just read
        while (getline(fin, line)) {cout << line << "\n";
            PersonInfo info; // create an object to hold this record's data
            record.clear();   // *** Crucial fix: Clear the stream's error state from the previous iteration.***
            record.str(line);
            record >> info.name; // read the name
            while (record >> word) // read the phone numbers
                info.phones.push_back(word); // and store them
                // Note that when record completes with the line, eof bit is set and obstructs next iteration.
                // So we need to clear the flag manually (handled at the start of each iteration).
            people.push_back(info); // append this record to people
        }
        cout << people.size() << "-------\n";
        for (auto &person : people) {
            cout << person.name << " ";
            for (auto &phone : person.phones) {
                cout << phone << " ";
            }
            cout << "\n";
        }

    } catch (runtime_error& err) {
        cout << "ERROR: Runtime error \n";
        cout << "In " << __FILE__ << " : " << __func__ << "\n";
        cout << err.what();
    }
    
    return 0;
}