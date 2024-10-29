#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int readFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return -1;
    }

    int id;
    string name, department;
    double salary;
    int empCount = 0;
    double totalSalary = 0.0;

    cout << "Employee Records:\n";
    cout << "ID\tName\t\tDepartment\tSalary\n";
    cout << "------------------------------------------\n";

    while (file >> id >> name >> department >> salary) {
        cout << id << "\t" << name << "\t\t" << department << "\t\t" 
             << fixed << setprecision(2) << salary << endl;
        totalSalary += salary;
        empCount++;
    }

    file.close();

    if (empCount > 0) {
        double averageSalary = totalSalary / empCount;
        cout << "\nTotal Salary: " << totalSalary << "\n";
        cout << "Average Salary: " << averageSalary << "\n";
    } else {
        cout << "No employee records found.\n";
    }

    return empCount;
}
