#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

using namespace std;

struct record {
    int id;
    char name[50];
    float marks;
};

void add();
void display();
void modify(int);
void search(int);
void deletedata(int);
void sort();

int main() {
    int choice, ID;
    do {
        cout << "\nDatabase Menu:\n";
        cout << "1. Add Data\n2. Display Data\n3. Modify Data\n4. Search Data\n5. Delete Data\n6. Sort Data\n7. Exit\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1-7.\n";
            continue;
        }

        switch (choice) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: cout << "\nEnter ID to modify: "; cin >> ID; modify(ID); break;
            case 4: cout << "\nEnter ID to search: "; cin >> ID; search(ID); break;
            case 5: cout << "\nEnter ID to delete: "; cin >> ID; deletedata(ID); break;
            case 6: sort(); break;
            case 7: cout << "\nExiting...\n"; break;
            default: cout << "\nInvalid Input!\n";
        }
    } while (choice != 7);
    return 0;
}

// Function to add new record
void add() {
    ofstream file("database.dat", ios::binary | ios::app);
    if (!file) {
        cout << "\nError opening file!\n";
        return;
    }

    record rec;
    do {
        cout << "\nEnter ID: ";
        cin >> rec.id;
        if (cin.fail() || rec.id <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid ID! Please enter a positive integer.\n";
        }
    } while (rec.id <= 0);

    cin.ignore();
    cout << "Enter Name: ";
    cin.getline(rec.name, 50);
    
    cout << "Enter Marks: ";
    while (!(cin >> rec.marks)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a valid float value for marks: ";
    }

    file.write(reinterpret_cast<char*>(&rec), sizeof(record));
    file.close();
    cout << "Record added successfully!\n";
}

// Function to display records
void display() {
    ifstream file("database.dat", ios::binary);
    if (!file) {
        cout << "\nError opening file!\n";
        return;
    }

    record rec;
    cout << "\nRecords in Database:\n";
    while (file.read(reinterpret_cast<char*>(&rec), sizeof(record))) {
        cout << "ID: " << rec.id << ", Name: " << rec.name << ", Marks: " << rec.marks << endl;
    }
    file.close();
}

// Function to modify record
void modify(int searchID) {
    fstream file("database.dat", ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "\nError opening file!\n";
        return;
    }

    record rec;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&rec), sizeof(record))) {
        if (rec.id == searchID) {
            cout << "\nEnter new Name: ";
            cin.ignore();
            cin.getline(rec.name, 50);
            
            cout << "Enter new Marks: ";
            while (!(cin >> rec.marks)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter a valid float value for marks: ";
            }
            
            file.seekp(-sizeof(record), ios::cur);
            file.write(reinterpret_cast<char*>(&rec), sizeof(record));
            found = true;
            break;
        }
    }
    file.close();
    cout << (found ? "\nRecord updated successfully!\n" : "\nRecord not found!\n");
}

// Function to search record
void search(int searchID) {
    ifstream file("database.dat", ios::binary);
    if (!file) {
        cout << "\nError opening file!\n";
        return;
    }

    record rec;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&rec), sizeof(record))) {
        if (rec.id == searchID) {
            cout << "\nID: " << rec.id << ", Name: " << rec.name << " Marks: " << rec.marks << endl;
            found = true;
            break;
        }
    }
    file.close();
    cout << (found ? "" : "\nRecord not found!\n");
}

// Function to delete record
void deletedata(int deleteID) {
    ifstream file("database.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);
    if (!file || !temp) {
        cout << "\nError opening file!\n";
        return;
    }

    record rec;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&rec), sizeof(record))) {
        if (rec.id == deleteID) {
            found = true;
            continue;
        }
        temp.write(reinterpret_cast<char*>(&rec), sizeof(record));
    }
    file.close();
    temp.close();

    remove("database.dat");
    rename("temp.dat", "database.dat");
    cout << (found ? "\nRecord deleted successfully!\n" : "\nRecord not found!\n");
}

// Function to sort records
void sort() {
    ifstream file("database.dat", ios::binary);
    if (!file) {
        cout << "\nError opening file!\n";
        return;
    }

    record records[100];
    int count = 0;
    while (file.read(reinterpret_cast<char*>(&records[count]), sizeof(record))) {
        count++;
    }
    file.close();

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (records[j].id > records[j + 1].id) {
                swap(records[j], records[j + 1]);
            }
        }
    }

    ofstream sortedFile("database.dat", ios::binary | ios::out);
    for (int i = 0; i < count; i++) {
        sortedFile.write(reinterpret_cast<char*>(&records[i]), sizeof(record));
    }
    sortedFile.close();
    cout << "\nRecords sorted successfully!\n";
}

