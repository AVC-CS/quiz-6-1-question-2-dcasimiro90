/***************************************************
 * Code your program here
 ***************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct Employee {
    int id;
    string name;
    string department;
    double salary;
};

// Function to get employee details from the user
void getEmployeeData(vector<Employee>& employees, int numEmployees) {
    for (int i = 0; i < numEmployees; ++i) {
        Employee emp;
        cout << "Enter details for employee " << (i + 1) << endl;
        cout << "ID: ";
        cin >> emp.id;
        cout << "Name: ";
        cin >> emp.name;
        cout << "Department: ";
        cin >> emp.department;
        cout << "Salary: ";
        cin >> emp.salary;
        employees.push_back(emp);
    }
}

// Function to write employee data to a file
void writeToFile(const vector<Employee>& employees, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& emp : employees) {
            outFile << emp.id << " " << emp.name << " " << emp.department << " " << emp.salary << endl;
        }
        outFile.close();
        cout << "Data successfully written to " << filename << endl;
    } else {
        cout << "Error opening file for writing." << endl;
    }
}

// Function to read employee data from a file
vector<Employee> readFromFile(const string& filename) {
    vector<Employee> employees;
    ifstream inFile(filename);
    if (inFile.is_open()) {
        Employee emp;
        while (inFile >> emp.id >> emp.name >> emp.department >> emp.salary) {
            employees.push_back(emp);
        }
        inFile.close();
    } else {
        cout << "Error opening file for reading." << endl;
    }
    return employees;
}

// Function to display employee data and calculate total/average salary
void displayEmployeeData(const vector<Employee>& employees) {
    double totalSalary = 0;
    int numEmployees = employees.size();

    cout << left << setw(10) << "ID" 
         << setw(15) << "Name" 
         << setw(15) << "Department" 
         << setw(10) << "Salary" << endl;
    cout << "-------------------------------------------------" << endl;

    for (const auto& emp : employees) {
        cout << left << setw(10) << emp.id 
             << setw(15) << emp.name 
             << setw(15) << emp.department 
             << setw(10) << emp.salary << endl;
        totalSalary += emp.salary;
    }

    double averageSalary = numEmployees > 0 ? totalSalary / numEmployees : 0;

    cout << "\nTotal Salary: " << totalSalary << endl;
    cout << "Average Salary: " << averageSalary << endl;
}

int main() {
    string filename = "employee.txt";
    int numEmployees;
    vector<Employee> employees;

    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    // Get employee data from user
    getEmployeeData(employees, numEmployees);

    // Write data to file
    writeToFile(employees, filename);

    // Read data from file
    employees = readFromFile(filename);

    // Display data and calculate total/average salary
    displayEmployeeData(employees);

    return 0;
}
