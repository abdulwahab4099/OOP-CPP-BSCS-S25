/*
						Assignment Title: Smart University Management System
	Assignment Description
		You are required to design and implement a C++ application titled Smart University
		Management System. This project will test your knowledge of Object-Oriented Pro
		gramming principles and recursion. You must apply class inheritance, polymorphism, virtual
		functions, operator overloading, friend and static members, and templates to complete the
		full system.

	Assignment Questions:
		 1. User Class Hierarchy
			 • Create a base class User with the attributes: name, id, and a pure virtual
			   function displayInfo().
			 • Create derived classes Student and Professor with their specific attributes.
			 • Override the displayInfo() function in both derived classes.
		 2. Friend Function Usage
		 	• Implement a friend function assignCourse(Student&, Course&) that as
			  signs a course to a student and accesses private members.
		 3. Static Members and Functions
			• Usestatic variables to keep count of total users and implement getTotalUsers().
		 4. Template-Based GPA Calculator
		 	• Create a template class Calculator<T> that overloads arithmetic operators
		 	  and includes a recursive GPA calculation method.
		 5. Course Class with Operator Overloading
		 	• Define a Course class and overload the == and << operators.
		 6. Recursive Functions
			• Write a recursive function sumOfDigits(int) to calculate the digit sum of a
			  number.
			• Write a recursive function power(float base, int exp) to calculate ex
			  ponential values using divide and conquer strategy.
		 7. Virtual and Abstract Functions
			• Implement it in Student and Professor classes differently.
		 8. Virtual Base Class (Advanced)
		 	• Create a base class Person and inherit it virtually into the User class to prevent
	Bonus Task (Optional)
		Develop a professor ranking system using recursive sorting and template functions for nu
		meric score types.
*/



#include <iostream>
#include <string>
using namespace std;

// Maximum number of courses a student or professor can handle
const int Max_courses = 6;
// Maximum number of students and professors in the system
const int Max_users = 100;

/*8. Virtual Base Class
 * Create a base class Person with a name attribute
 * Inherited virtually into User to prevent ambiguity in multiple inheritance
 */
class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}
    virtual ~Person() {} // Virtual destructor for proper cleanup
    string getName() const { return name; } // Getter for protected name
};

/*1. User Class Hierarchy
 * Create a base class User with attributes: name, id, and a pure virtual function displayInfo()
 * Inherits virtually from Person to avoid multiple inheritance issues
 * Includes static member to track total users
 */
class User : virtual public Person {
protected:
    int id;
    static int totalUsers; /*3. Static Members and Functions
                            * Static variable to count total users
                            * Incremented in constructor, decremented in destructor
                            */
public:
    User(string n, int i) : Person(n), id(i) {
        totalUsers++;
    }
    virtual ~User() {
        totalUsers--; // Decrease user count when object is destroyed
    }
    virtual void displayInfo() const = 0; /* Pure virtual function to display user info */
    virtual void calculatePerformance() const = 0; /*7. Virtual and Abstract Functions
                                                   * Pure virtual function to calculate performance
                                                   * Implemented differently in Student and Professor
                                                   */
    static int getTotalUsers() {
        return totalUsers;
    }
    int getId() const { return id; } // Getter for ID
};
int User::totalUsers = 0;

/*5. Course Class with Operator Overloading
 * Define a Course class with courseName and courseCode
 * Overload == to compare courses by courseCode
 * Overload << for formatted output
 */
class Course {
private:
    string courseName;
    string courseCode;
public:
    Course(string n = "", string code = "") : courseName(n), courseCode(code) {}
    string getName() const {
        return courseName;
    }
    string getCode() const {
        return courseCode;
    }
    bool operator==(const Course& other) const {
        return courseCode == other.courseCode; // Compare by course code
    }
    friend ostream& operator<<(ostream& os, const Course& c) {
        os << "\nCourse: " << c.courseName << " (" << c.courseCode << ")";
        return os;
    }
    friend class Student; // Allow Student to access private members
};

/*1. User Class Hierarchy (Student)
 * Derived from User, includes specific attributes: Department, Semester, GPA, courses
 * Overrides displayInfo() and calculatePerformance()
 */
class Student : public User {
private:
    string Department;
    int Semester;
    double GPA;
    Course courses[Max_courses];
    int courseCount;
public:
    // Default constructor for array declaration
    Student() : Person(""), User("", 0), Department(""), Semester(0), GPA(0.0), courseCount(0) {}
    // Parameterized constructor for creating students
    Student(string n, int i, string d, int s, double g) : Person(n), User(n, i), Department(d), Semester(s), GPA(g), courseCount(0) {}
    void displayInfo() const {
        cout << "\nStudent Name: " << getName();
        cout << "\nID: " << id;
        cout << "\nDepartment: " << Department;
        cout << "\nSemester: " << Semester;
        cout << "\nGPA: " << GPA;
        cout << "\nEnrolled Courses:";
        if (courseCount == 0) {
            cout << " None";
        } else {
            for (int i = 0; i < courseCount; i++) {
                cout << courses[i];
            }
        }
        cout << endl;
    }
    void calculatePerformance() const {
        cout << "\nStudent Performance: " << (GPA > 3.0 ? "Excellent" : "Average") << endl;
    }
    friend void assignCourse(Student&, Course&);
    // Getter and setter for GPA
    double getGPA() const { return GPA; }
    void setGPA(double g) { GPA = g; }
};

/*2. Friend Function Usage
 * Friend function to assign a course to a student
 * Accesses private courses array and checks for duplicates
 */
void assignCourse(Student& s, Course& c) {
    if (s.courseCount < Max_courses) {
        // Check for duplicate course
        for (int i = 0; i < s.courseCount; i++) {
            if (s.courses[i] == c) {
                cout << "\nCourse " << c.getName() << " already assigned to student: " << s.getName() << endl;
                return;
            }
        }
        s.courses[s.courseCount++] = c;
        cout << "\nAssigned " << c.getName() << " (" << c.getCode() << ") to student: " << s.getName() << endl;
    } else {
        cout << "\nCourse limit reached for student: " << s.getName() << endl;
    }
}

/*1. User Class Hierarchy (Professor)
 * Derived from User, includes specific attribute: Department
 * Stores teaching courses
 * Overrides displayInfo() and calculatePerformance()
 */
class Professor : public User {
private:
    string Department;
    Course teachingCourses[Max_courses];
    int courseCount;
public:
    // Default constructor for array declaration
    Professor() : Person(""), User("", 0), Department(""), courseCount(0) {}
    // Parameterized constructor for creating professors
    Professor(string n, int i, string d) : Person(n), User(n, i), Department(d), courseCount(0) {}
    void addCourse(const Course& c) {
        if (courseCount < Max_courses) {
            teachingCourses[courseCount++] = c;
        }
    }
    void displayInfo() const {
        cout << "\nProfessor Name: " << getName();
        cout << "\nID: " << id;
        cout << "\nDepartment: " << Department;
        cout << "\nTeaching Courses:";
        if (courseCount == 0) {
            cout << " None";
        } else {
            for (int i = 0; i < courseCount; i++) {
                cout << teachingCourses[i];
            }
        }
        cout << endl;
    }
    void calculatePerformance() const {
        cout << "\nProfessor ranking: Based on publications" << endl;
    }
    // Setter for department
    void setDepartment(const string& d) { Department = d; }
};

/*4. Template-Based GPA Calculator
 * Template class Calculator<T> to store grades and calculate GPA
 * Overloads + operator to add grades
 * Uses recursive method to sum grades
 */
template <typename T>
class Calculator {
private:
    T grades[Max_courses];
    int count;
public:
    Calculator() : count(0) {}
    void addGrade(T grade) {
        if (count < Max_courses) {
            grades[count++] = grade;
        }
    }
    T recursiveGPA(int index = 0) const {
        if (index >= count) {
            return T(0);
        }
        return grades[index] + recursiveGPA(index + 1);
    }
    T calculateGPA() const {
        if (count == 0) {
            return T(0);
        }
        return recursiveGPA() / T(count); // Divide total by number of grades
    }
    Calculator& operator+(T value) {
        addGrade(value);
        return *this;
    }
};

/*6. Recursive Functions
 * sumOfDigits: Recursively calculates the sum of digits in a number
 */
int sumOfDigits(int n) {
    if (n < 10) {
        return n;
    }
    return (n % 10) + sumOfDigits(n / 10);
}

/*6. Recursive Functions
 * power: Recursively calculates base^exp using divide-and-conquer
 */
float power(float base, int exp) {
    if (exp == 0) {
        return 1;
    } else if (exp % 2 == 0) {
        float half = power(base, exp / 2);
        return half * half;
    } else {
        return base * power(base, exp - 1);
    }
}

/* Main function
 * Implements a menu-driven interface for the Smart University Management System
 * Initializes specified professors and courses
 * Handles user input for creating, updating, and displaying users
 */
int main() {
    // Initialize courses with names and codes
    Course courses[7] = {
        Course("Object Oriented Programming", "CS-120"),
        Course("Multivariable Calculus", "MA-202"),
        Course("Social Sciences", "SO-101"),
        Course("Physics", "PH-110"),
        Course("Expository Writing", "EN-200"),
        Course("Islamic Studies", "IS-100"),
        Course("Problem Solving and Programming", "CS-104")
    };

    // Initialize professors with their courses
    Professor professors[Max_users];
    int professorCount = 0;
    // Add the six specified professors one by one
    professors[professorCount] = Professor("Dr. Ghazanfar Farooq", 1001, "CS");
    professors[professorCount++].addCourse(courses[0]); // OOP, CS-120
    professors[professorCount] = Professor("Dr. Waseem", 1002, "Mathematics");
    professors[professorCount++].addCourse(courses[1]); // Multivariable Calculus, MA-202
    professors[professorCount] = Professor("Dr. Abdul Rasheed", 1003, "Social Sciences");
    professors[professorCount++].addCourse(courses[2]); // Social Sciences, SO-101
    professors[professorCount] = Professor("Misses M. Mehmood", 1004, "Physics");
    professors[professorCount++].addCourse(courses[3]); // Physics, PH-110
    professors[professorCount] = Professor("Ms. Saima Noor", 1005, "English");
    professors[professorCount++].addCourse(courses[4]); // Expository Writing, EN-200
    professors[professorCount] = Professor("Dr. Syed M Naqi", 1006, "CS");
    professors[professorCount++].addCourse(courses[6]); // Problem Solving and Programming, CS-104
    // Note: Islamic Studies (IS-100) not assigned to any professor as per input

    // Array to store students
    Student students[Max_users];
    int studentCount = 0;

    int choice;
    while (true) {
        // Display menu matching sample output
        cout << "\n\nWelcome to Smart University Management System\n========================================================\n";
        cout << "1. Create Student\n";
        cout << "2. Create Professor\n";
        cout << "3. Assign Course\n";
        cout << "4. Calculate GPA\n";
        cout << "5. Show User Info\n";
        cout << "\t>Student\n";
        cout << "\t>Professor\n";
        cout << "7. Update User\n";
        cout << "\t>Professor\n";
        cout << "\t>Student\n";
        cout << "8. Exit\n========================================================\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer

        if (choice == 8) {
            cout << "\nExiting Smart University Management System.\n";
            break;
        }

        switch (choice) {
        case 1: {
            // Create a new student
            string name, dept;
            int id, semester;
            double gpa;
            cout << "\nEnter student name: ";
            getline(cin, name);
            cout << "Enter student ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter department: ";
            getline(cin, dept);
            cout << "Enter semester: ";
            cin >> semester;
            cout << "Enter GPA: ";
            cin >> gpa;
            cin.ignore();
            if (studentCount < Max_users) {
                students[studentCount++] = Student(name, id, dept, semester, gpa);
                cout << "\nStudent created. Total users: " << User::getTotalUsers() << endl;
            } else {
                cout << "\nMaximum student limit reached.\n";
            }
            break;
        }
        case 2: {
            // Create a new professor
            string name, dept;
            int id;
            cout << "\nEnter professor name: ";
            getline(cin, name);
            cout << "Enter professor ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter department: ";
            getline(cin, dept);
            if (professorCount < Max_users) {
                professors[professorCount++] = Professor(name, id, dept);
                cout << "\nProfessor created. Total users: " << User::getTotalUsers() << endl;
            } else {
                cout << "\nMaximum professor limit reached.\n";
            }
            break;
        }
        case 3: {
            // Assign a course to a student
            int id, courseNum;
            cout << "\nEnter student ID: ";
            cin >> id;
            cout << "Available courses:\n";
            for (int i = 0; i < 7; i++) {
                cout << i + 1 << ". " << courses[i] << endl;
            }
            cout << "Enter course number (1-7): ";
            cin >> courseNum;
            cin.ignore();
            if (courseNum >= 1 && courseNum <= 7) {
                bool found = false;
                for (int i = 0; i < studentCount; i++) {
                    if (students[i].getId() == id) {
                        assignCourse(students[i], courses[courseNum - 1]);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "\nStudent with ID " << id << " not found.\n";
                }
            } else {
                cout << "\nInvalid course number.\n";
            }
            break;
        }
        case 4: {
            // Calculate GPA for a student
            int id;
            cout << "\nEnter student ID: ";
            cin >> id;
            cin.ignore();
            bool found = false;
            for (int i = 0; i < studentCount; i++) {
                if (students[i].getId() == id) {
                    Calculator<double> calc;
                    double grade;
                    cout << "Enter grades (enter -1 to stop):\n";
                    while (true) {
                        cin >> grade;
                        if (grade == -1) break;
                        if (grade >= 0 && grade <= 4.0) {
                            calc + grade;
                        } else {
                            cout << "Invalid grade, enter between 0.0 and 4.0\n";
                        }
                    }
                    double newGPA = calc.calculateGPA();
                    cout << "Calculated GPA: " << newGPA << endl;
                    students[i].setGPA(newGPA); // Update student's GPA
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "\nStudent with ID " << id << " not found.\n";
            }
            break;
        }
        case 5: {
            // Show user information
            int subChoice;
            cout << "\n1. Student\n2. Professor\nEnter choice: ";
            cin >> subChoice;
            cin.ignore();
            if (subChoice == 1) {
                int id;
                cout << "Enter student ID: ";
                cin >> id;
                cin.ignore();
                bool found = false;
                for (int i = 0; i < studentCount; i++) {
                    if (students[i].getId() == id) {
                        students[i].displayInfo();
                        students[i].calculatePerformance();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "\nStudent with ID " << id << " not found.\n";
                }
            } else if (subChoice == 2) {
                int id;
                cout << "Enter professor ID: ";
                cin >> id;
                cin.ignore();
                bool found = false;
                for (int i = 0; i < professorCount; i++) {
                    if (professors[i].getId() == id) {
                        professors[i].displayInfo();
                        professors[i].calculatePerformance();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "\nProfessor with ID " << id << " not found.\n";
                }
            } else {
                cout << "\nInvalid choice.\n";
            }
            break;
        }
        case 7: {
            // Update user information
            int subChoice;
            cout << "\n1. Professor\n2. Student\nEnter choice: ";
            cin >> subChoice;
            cin.ignore();
            if (subChoice == 1) {
                int id;
                string dept;
                cout << "Enter professor ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter new department: ";
                getline(cin, dept);
                bool found = false;
                for (int i = 0; i < professorCount; i++) {
                    if (professors[i].getId() == id) {
                        professors[i].setDepartment(dept);
                        cout << "\nProfessor updated.\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "\nProfessor with ID " << id << " not found.\n";
                }
            } else if (subChoice == 2) {
                int id;
                string name, dept;
                int semester;
                double gpa;
                cout << "Enter student ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter new name: ";
                getline(cin, name);
                cout << "Enter new department: ";
                getline(cin, dept);
                cout << "Enter new semester: ";
                cin >> semester;
                cout << "Enter new GPA: ";
                cin >> gpa;
                cin.ignore();
                bool found = false;
                for (int i = 0; i < studentCount; i++) {
                    if (students[i].getId() == id) {
                        students[i] = Student(name, id, dept, semester, gpa);
                        cout << "\nStudent updated.\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "\nStudent with ID " << id << " not found.\n";
                }
            } else {
                cout << "\nInvalid choice.\n";
            }
            break;
        }
        default:
            cout << "\nInvalid choice.\n";
        }
    }

    // Test recursive functions
    cout << "\n--- Recursive Functions ---\n";
    cout << "Sum of digits (1234): " << sumOfDigits(1234) << endl;
    cout << "Power (2, 5): " << power(2, 5) << endl;

    return 0;
}