/**
 * @file main.cpp
 * @brief Exercise 9.31: Demonstrates `removeEvenDupOdd` function across `std::vector`, `std::list`, and `std::forward_list`.
 *
 * @note Exercise 9.31: The program on page 354 to remove even-valued elements and duplicate odd
 * ones will not work on a `list` or `forward_list`. Why? Revise the program so that it works on
 * these types as well.
 *
 * @details
 * This program serves as the main entry point for Exercise 9.31. It showcases
 * the revised `removeEvenDupOdd` function, which is overloaded to correctly
 * remove even-valued elements and duplicate odd-valued elements for three
 * different standard sequential container types: `std::vector<int>`,
 * `std::list<int>`, and `std::forward_list<int>`.
 *
 * The program performs the following steps for each container type:
 * 1. Initializes a container (`std::vector`, `std::list`, or `std::forward_list`)
 * with a sequence of integers from 0 to 9.
 * 2. Prints a header and a horizontal rule for clear output formatting.
 * 3. Displays the "Before" state of the container using `displaySeqContainer`.
 * 4. Calls the appropriate overloaded `removeEvenDupOdd` function to modify the container.
 * 5. Displays the "After" state of the container, showing the results of the
 * removal and duplication operations.
 * 6. Prints another horizontal rule for separation.
 *
 * This example effectively demonstrates how the same logical operation (`removeEvenDupOdd`)
 * needs different implementation details (especially iterator handling) when adapted
 * to containers with different iterator categories and modification semantics.
 *
 * @author Mallikarjuna00G
 * @date 2025-07-18
 */

#include <iostream>
#include <forward_list>
#include <list>
#include <vector>
#include <string>

#include "displaySeqContainer.hpp" // Assumes this header provides necessary displaySeqContainer overloads (including for forward_list<string>)
#include "support_forwardList.hpp" // Assumes this header declares fl_insertStr2AfterStr1
#include "support_list.hpp" // Assumes this header declares fl_insertStr2AfterStr1
#include "support_vector.hpp" // Assumes this header declares fl_insertStr2AfterStr1

using std::cout;
using std::string;
using std::forward_list;
using std::list;
using std::vector;

int main() {

    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};

    string hrLine(70, '-');
    hrLine += '\n';

    cout << "Removing even ints and duplicating odd ints: \n";
    cout << hrLine << hrLine << "\n";

    cout << "Vector: \n";
    cout << hrLine << "\n";
    cout << "Before: \n";
    displaySeqContainer(vi); // Assumes displaySeqContainer(const std::vector<int>&) is available
    removeEvenDupOdd(vi);
    cout << "After: \n";
    displaySeqContainer(vi); // Display the list after removal
    cout << hrLine << "\n";

    list<int> li = {0,1,2,3,4,5,6,7,8,9};
    cout << "List: \n";
    cout << hrLine << "\n";
    cout << "Before: \n";
    displaySeqContainer(li); // Assumes displaySeqContainer(const std::list<int>&) is available
    removeEvenDupOdd(li);
    cout << "After: \n";
    displaySeqContainer(li); // Display the list after removal
    cout << hrLine << "\n";

    forward_list<int> fli = {0,1,2,3,4,5,6,7,8,9};
    cout << "Forward list: \n";
    cout << hrLine << "\n";
    cout << "Before: \n";
    displaySeqContainer(fli); // Assumes displaySeqContainer(const std::forward_list<int>&) is available
    removeEvenDupOdd(fli);
    cout << "After: \n";
    displaySeqContainer(fli); // Display the list after removal
    cout << hrLine << "\n";

    return 0;
}
