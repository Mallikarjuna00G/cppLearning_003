#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    // if grade is less than 60 it's an F, otherwise compute a subscript
    string lettergrade;
    int grade;
    cin >> grade;

    lettergrade = (grade < 60) ? scores[0] : (
        (grade == 100) ? scores[(grade - 50)/10] : (
            scores[(grade - 50)/10] + (
                (grade % 10 > 7) ? "+" : (
                    (grade % 10 < 3) ? "-" : ""
                )
            )
        )
    );

    cout << "Your grade is " << lettergrade << "\n";

    return 0;
}