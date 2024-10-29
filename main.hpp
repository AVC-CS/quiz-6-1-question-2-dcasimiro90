#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int writeFile(const string &filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return -1;
    }

    int empNum;
    cout << "Enter the number of employees: ";
    cin >> empNum;

    for (int i = 0; i < empNum; i++) {
        int id;
        string name, department;
        double salary;

        cout << "Enter details for employee " << (i + 1) << ":\n";
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Department: ";
        getline(cin, department);
        cout << "Salary: ";
        cin >> salary;

        // Write employee details to the file
        file << id << " " << name << " " << department << " " << salary << endl;
    }

    file.close();
    return empNum;
}

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
        cout << id << "\t" << name << "\t\t" << department << "\t\t" << salary << endl;
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