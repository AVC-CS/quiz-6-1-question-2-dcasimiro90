#include "main.hpp"
#include <fstream>
#include <iostream>
using namespace std;

// Function to write employee data to a file
int writeFile(const vector<Employee>& employees, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return -1;
    }

    for (const auto& emp : employees) {
        outFile << emp.id << " " << emp.name << " " << emp.department << " " << emp.salary << endl;
    }
    outFile.close();
    return employees.size(); // Return the number of employees written
}

// Function to read employee data from a file
int readFile(const string& filename, vector<Employee>& employees) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return -1;
    }

    Employee emp;
    while (inFile >> emp.id >> emp.name >> emp.department >> emp.salary) {
        employees.push_back(emp);
    }
    inFile.close();
    return employees.size(); // Return the number of employees read
}
