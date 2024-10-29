#include "main.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string filename = "employee.txt";

    // Writing to file
    int empNum = writeFile(filename);
    if (empNum > 0) {
        cout << "File created with " << empNum << " employee records.\n";
    }

    // Reading from file
    empNum = readFile(filename);
    cout << "The total number of employees read: " << empNum << endl;

    return 0;
}