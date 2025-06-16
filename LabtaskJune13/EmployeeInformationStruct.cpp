/*
Question1: 
	Wa menu driven program in C++ that will do the following tasks 

A. Define a structure to store employee information (e.g., emp_ID, emp_name, emp_salary). Write a 
   program to create a binary file and store multiple employee records into it. 
B. Write a function find() to search for an employee record in a binary file based on the employee ID.  
C. Write a function Modify() to update an employee record in a binary file. 
D. Write a function Insert() to insert a new record at a specific position in a binary file. 
E. Write a function delete() to delete a record from a binary file based on a specific criterion (e.g., 
   employee ID). 
F. Write a function sort() to sort the records in a binary file based on a specific field (e.g., employee 
   salary). 
G. Note: use appropriate stream/ file handling parameter or other parameter where needed.

*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    float salary;
};

void addEmployee() {
    ofstream file("employee.dat", ios::binary | ios::app);
    Employee emp;
    cout << "Enter ID: ";
    cin >> emp.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, emp.name);
    cout << "Enter Salary: ";
    cin >> emp.salary;
    file.write((char*)&emp, sizeof(emp));
    file.close();
    cout << "Employee added successfully.\n";
}

void findEmployee() {
    ifstream file("employee.dat", ios::binary);
    Employee emp;
    int id;
    bool found = false;
    cout << "Enter ID to find: ";
    cin >> id;
    while (file.read((char*)&emp, sizeof(emp))) {
        if (emp.id == id) {
            cout << "ID: " << emp.id << "\nName: " << emp.name << "\nSalary: " << emp.salary << endl;
            found = true;
            break;
        }
    }
    file.close();
    if (!found) cout << "Employee not found.\n";
}

void modifyEmployee() {
    fstream file("employee.dat", ios::binary | ios::in | ios::out);
    Employee emp;
    int id;
    bool found = false;
    cout << "Enter ID to modify: ";
    cin >> id;
    while (file.read((char*)&emp, sizeof(emp))) {
        if (emp.id == id) {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, emp.name);
            cout << "Enter new Salary: ";
            cin >> emp.salary;
            file.seekp(-sizeof(emp), ios::cur);
            file.write((char*)&emp, sizeof(emp));
            found = true;
            cout << "Employee modified successfully.\n";
            break;
        }
    }
    file.close();
    if (!found) cout << "Employee not found.\n";
}

void insertEmployee() {
    ifstream inFile("employee.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary);
    Employee emp;
    Employee newEmp;
    int pos, current = 1;

    cout << "Enter position to insert: ";
    cin >> pos;
    cout << "Enter ID: ";
    cin >> newEmp.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newEmp.name);
    cout << "Enter Salary: ";
    cin >> newEmp.salary;

    while (inFile.read((char*)&emp, sizeof(emp))) {
        if (current == pos)
            outFile.write((char*)&newEmp, sizeof(newEmp));
        outFile.write((char*)&emp, sizeof(emp));
        current++;
    }

    if (pos >= current) {
        outFile.write((char*)&newEmp, sizeof(newEmp));
    }

    inFile.close();
    outFile.close();

    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    cout << "Employee inserted successfully.\n";
}

void deleteRecord() {
    ifstream inFile("employee.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary);
    Employee emp;
    int id;
    bool found = false;

    cout << "Enter ID to delete: ";
    cin >> id;

    while (inFile.read((char*)&emp, sizeof(emp))) {
        if (emp.id != id) {
            outFile.write((char*)&emp, sizeof(emp));
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    if (found) cout << "Employee deleted successfully.\n";
    else cout << "Employee not found.\n";
}

void sortBySalary() {
    ifstream file("employee.dat", ios::binary);
    if (!file) {
        cout << "Error: Cannot open file!\n";
        return;
    }

    Employee empArray[100];
    int count = 0;

    while (file.read((char*)&empArray[count], sizeof(Employee))) {
        count++;
    }
    file.close();

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (empArray[j].salary > empArray[j + 1].salary) {
                Employee temp = empArray[j];
                empArray[j] = empArray[j + 1];
                empArray[j + 1] = temp;
            }
        }
    }

    ofstream outFile("employee.dat", ios::binary | ios::trunc);
    for (int i = 0; i < count; i++) {
        outFile.write((char*)&empArray[i], sizeof(Employee));
    }
    outFile.close();

    cout << "Employees sorted by salary successfully.\n";
}

void displayAllEmployees() {
    ifstream file("employee.dat", ios::binary);
    Employee emp;
    cout << "All Employees:\n";
    while (file.read((char*)&emp, sizeof(emp))) {
        cout << "ID: " << emp.id << "\nName: " << emp.name << "\nSalary: " << emp.salary << "\n\n";
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "\n===== Employee Record System =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Find Employee\n";
        cout << "3. Modify Employee\n";
        cout << "4. Insert Employee at Position\n";
        cout << "5. Delete Employee\n";
        cout << "6. Sort Employees by Salary\n";
        cout << "7. Display All Employees\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: findEmployee(); break;
            case 3: modifyEmployee(); break;
            case 4: insertEmployee(); break;
            case 5: deleteRecord(); break;
            case 6: sortBySalary(); break;
            case 7: displayAllEmployees(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
