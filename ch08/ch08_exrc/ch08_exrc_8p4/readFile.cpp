#include "readFile.hpp"

#include <fstream>
#include <vector>
#include <string>

using std::ifstream;
using std::cout;
using std::vector;
using std::string;
using std::getline;

void readFile(const std::string& theFile) {
    ifstream fin(theFile);

    if (fin) {
        cout << "The file successfully opened.\n";

        vector<string> lines;
        string temp;
        while (getline(fin, temp)) {
            lines.push_back(temp);
        }

        cout << "Fetched content from " << theFile << " and fed to a vector.\n";
        cout << "The content is as follows:\n";

        for (auto &line : lines) {
            cout << line << "\n";
        }
    } else {
        cout << "Failed to open the file.\n";
    }
}