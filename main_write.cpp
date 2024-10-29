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