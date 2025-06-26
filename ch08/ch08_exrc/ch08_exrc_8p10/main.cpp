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
        vector<string> vec1;
        ifstream fin("dataInFile.txt");

        if(!fin) {
            throw runtime_error("Failed to open the file" + string(argv[1]));
        }

        string line;
        while (getline(fin, line)) {
            vec1.push_back(line);
        }

        string word;
        for (auto &line: vec1) {
            cout << "The line is: " << line << "\n";

            istringstream record(line);
            cout << "Reading word to word: \n";
            while(record >> word) {
                cout << word << "\n";
            }
        }

    } catch (runtime_error& err) {
        cout << "ERROR: Runtime error \n";
        cout << "In " << __FILE__ << " : " << __func__ << "\n";
        cout << err.what();
    }
    
    return 0;
}