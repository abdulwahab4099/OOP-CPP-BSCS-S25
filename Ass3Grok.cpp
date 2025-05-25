#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class Course;

class Person {
protected:
    string name;

public:
    Person(string name) : name(name) {}
    virtual ~Person() {}

    virtual void introduce() {
        cout << "Hi, I am " << name << endl;
    }
    string getName() const { return name; }
    friend class Admin;
};

class User : public virtual Person {
protected:
    int id;
    static int totalUsers;

public:
    User(string name, int id) : Person(name), id(id) { totalUsers++; }
    virtual void displayInfo() = 0;
    virtual ~User() { totalUsers--; }
    static int getTotalUsers() { return totalUsers; }
    int getId() const { return id; }
    friend class Admin;
};

int User::totalUsers = 0;

class Student : public User {
private:
    string program;
    int semester;
    string studentCourses[10];
    int courseCount;

public:
    static int studentCount;

    Student(string name, int id, string program, int semester)
        : Person(name), User(name, id), program(program), semester(semester), courseCount(0) {
        studentCount++;
    }

    ~Student() { studentCount--; }

    void displayInfo() override {
        cout << "Student Name: " << name << endl;
        cout << "Student ID: " << id << endl;
        cout << "Program: " << program << endl;
        cout << "Semester: " << semester << endl;
        cout << "Courses Enrolled: ";
        if (courseCount == 0) {
            cout << "None";
        } else {
            for (int i = 0; i < courseCount; i++) {
                cout << studentCourses[i] << (i < courseCount - 1 ? ", " : "");
            }
        }
        cout << endl;
    }

    void updateInfo(const string& newName, const string& newProgram, int newSemester) {
        name = newName;
        program = newProgram;
        semester = newSemester;
    }

    friend void assignCourse(Student& student, Course& course);
};

int Student::studentCount = 0;

class Professor : public User {
private:
    string department;
    string specialization;
    string professorCourses[10];
    int courseCount;
public:
    float score;

    static int professorCount;

    Professor(string name, int id, string department, string specialization, float score = 0.0f)
        : Person(name), User(name, id), department(department), specialization(specialization), courseCount(0), score(score) {
        professorCount++;
    }

    ~Professor() { professorCount--; }

    void addCourse(string course) {
        if (courseCount < 10) {
            professorCourses[courseCount++] = course;
        } else {
            cout << "Cannot add more courses to professor " << name << ".\n";
        }
    }

    void displayInfo() override {
        cout << "Professor Name: " << name << endl;
        cout << "Professor ID: " << id << endl;
        cout << "Department: " << department << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Score: " << score << endl;
        cout << "Courses Teaching: ";
        if (courseCount == 0) {
            cout << "None";
        } else {
            for (int i = 0; i < courseCount; i++) {
                cout << professorCourses[i] << (i < courseCount - 1 ? ", " : "");
            }
        }
        cout << endl;
    }
};

int Professor::professorCount = 0;

class Course {
private:
    string courseName;
    string courseCode;

public:
    Course(string name, string code) : courseName(name), courseCode(code) {}
    string getCourseName() const { return courseName; }
    string getCourseCode() const { return courseCode; }
    bool operator==(const Course& other) const {
        return (courseCode == other.courseCode && courseName == other.courseName);
    }
    Course operator+(const Course& other) {
        return Course(courseName + " & " + other.courseName, courseCode + "-" + other.courseCode);
    }
    friend ostream& operator<<(ostream& out, const Course& c) {
        out << c.courseCode << ": " << c.courseName;
        return out;
    }
    friend void assignCourse(Student&, Course&);
};

void assignCourse(Student& student, Course& course) {
    for (int i = 0; i < student.courseCount; i++) {
        if (student.studentCourses[i] == course.getCourseName()) {
            cout << "Course '" << course.getCourseName() << "' already assigned to " << student.name << ".\n";
            return;
        }
    }
    if (student.courseCount < 10) {
        student.studentCourses[student.courseCount++] = course.getCourseName();
        cout << "Course '" << course.getCourseName() << "' assigned to " << student.name << ".\n";
    } else {
        cout << "Cannot assign more courses to " << student.name << ".\n";
    }
}

template <typename T>
class Calculator {
private:
    T* grades;
    int size;

public:
    Calculator(const T* grades, int size) : size(size) {
        this->grades = new T[size];
        for (int i = 0; i < size; i++) {
            this->grades[i] = grades[i];
        }
    }

    ~Calculator() { delete[] grades; }

    T add(const Calculator& other) {
        if (size != other.size) {
            cout << "Error: Grade arrays must be the same size.\n";
            return 0;
        }
        T total = 0;
        for (int i = 0; i < size; i++) {
            total += this->grades[i] + other.grades[i];
        }
        return total;
    }

    T divide(int divisor) {
        if (divisor == 0) {
            cout << "Error: Cannot divide by zero.\n";
            return 0;
        }
        T total = 0;
        for (int i = 0; i < size; i++) {
            total += grades[i];
        }
        return total / divisor;
    }

    T calculateGPA(int index = 0) {
        if (index >= size) return 0;
        if (index == size - 1) return grades[index];
        return grades[index] + calculateGPA(index + 1);
    }

    T getGPA() {
        if (size == 0) {
            cout << "Error: No grades provided.\n";
            return 0;
        }
        return calculateGPA() / size;
    }
};

int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

float power(float base, int exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        float half = power(base, exp / 2);
        return half * half;
    }
    return base * power(base, exp - 1);
}

template <typename T>
class Ranker {
private:
    struct ProfessorScore {
        Professor* prof;
        T score;
    };
    ProfessorScore* scores;
    int size;

    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        ProfessorScore* L = new ProfessorScore[n1];
        ProfessorScore* R = new ProfessorScore[n2];
        for (int i = 0; i < n1; i++) L[i] = scores[left + i];
        for (int i = 0; i < n2; i++) R[i] = scores[mid + 1 + i];
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i].score >= R[j].score) {
                scores[k] = L[i];
                i++;
            } else {
                scores[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) scores[k++] = L[i++];
        while (j < n2) scores[k++] = R[j++];
        delete[] L;
        delete[] R;
    }

    void mergeSort(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }

public:
    Ranker(Professor* profs[], int size, T (*getScore)(Professor*)) : size(size) {
        scores = new ProfessorScore[size];
        for (int i = 0; i < size; i++) {
            if (profs[i]) {
                scores[i].prof = profs[i];
                scores[i].score = getScore(profs[i]);
            }
        }
    }

    ~Ranker() { delete[] scores; }

    void sortProfessors() {
        if (size > 0) mergeSort(0, size - 1);
    }

    void displayRankings() {
        cout << "\nProfessor Rankings:\n";
        for (int i = 0; i < size; i++) {
            if (scores[i].prof) {
                cout << i + 1 << ". " << scores[i].prof->getName() << " (Score: " << scores[i].score << ")\n";
            }
        }
    }
};

fumain() {
    Admin admin;
    int choice, id, semester;
    string name, program, department, specialization, courseName, courseCode;
    float score;

    while (true) {
        displayMenu();
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 8) {
            cout << "Invalid choice. Enter 1-8.\n";
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        if (choice == 8) {
            cout << "Exiting Smart University Management System.\n";
            break;
        }

        switch (choice) {
        case 1: // Create Student
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Enter student ID: ";
            cin >> id;
            if (cin.fail()) {
                cout << "Invalid ID. Must be a number.\n";
                clearInputBuffer();
                break;
            }
            cout << "Enter program: ";
            clearInputBuffer();
            getline(cin, program);
            cout << "Enter semester: ";
            cin >> semester;
            if (cin.fail() || semester < 1) {
                cout << "Invalid semester. Must be positive.\n";
                clearInputBuffer();
                break;
            }
            admin.addStudent(name, id, program, semester);
            break;

        case 2: // Create Professor
            cout << "Enter professor name: ";
            getline(cin, name);
            cout << "Enter professor ID: ";
            cin >> id;
            if (cin.fail()) {
                cout << "Invalid ID. Must be a number.\n";
                clearInputBuffer();
                break;
            }
            cout << "Enter department: ";
            clearInputBuffer();
            getline(cin, department);
            cout << "Enter specialization: ";
            getline(cin, specialization);
            cout << "Enter professor score (0-5): ";
            cin >> score;
            if (cin.fail()) {
                cout << "Invalid score. Must be a number.\n";
                clearInputBuffer();
                break;
            }
            admin.addProfessor(name, id, department, specialization, score);
            break;

        case 3: // Assign Course
            cout << "Enter course name: ";
            getline(cin, courseName);
            cout << "Enter course code: ";
            getline(cin, courseCode);
            admin.addCourse(courseName, courseCode);
            cout << "Enter student ID: ";
            cin >> id;
            if (cin.fail()) {
                cout << "Invalid ID. Must be a number.\n";
                clearInputBuffer();
                break;
            }
            admin.assignCourseToStudent(id, courseCode);
            break;

        case 4: // Calculate GPA
            cout << "Enter student ID: ";
            cin >> id;
            if (cin.fail()) {
                cout << "Invalid ID. Must be a number.\n";
                clearInputBuffer();
                break;
            }
            admin.calculateGPA(id);
            break;

        case 5: // Show User Info
            cout << "1. Show Student Info\n2. Show Professor Info\nEnter choice: ";
            cin >> choice;
            if (cin.fail() || (choice != 1 && choice != 2)) {
                cout << "Invalid choice. Enter 1 or 2.\n";
                clearInputBuffer();
                break;
            }
            cout << "Enter ID: ";
            cin >> id;
            if (cin.fail()) {
                cout << "Invalid ID. Must be a number.\n";
                clearInputBuffer();
                break;
            }
            if (choice == 1) {
                admin.showStudentInfo(id);
            } else {
                admin.showProfessorInfo(id);
            }
            break;

        case 6: // Delete User
            cout << "1. Delete Student\n2. Delete Professor\nEnter choice: ";
            cin >> choice;
            if (cin.fail() || (choice != 1 && choice != 2)) {
                cout << "Invalid choice. Enter 1 or 2.\n";
                clearInputBuffer();
                break;
            }
            cout << "Enter ID: ";
            cin >> id;
            if (cin.fail()) {
                cout << "Invalid ID. Must be a number.\n";
                clearInputBuffer();
                break;
            }
            if (choice == 1) {
                admin.deleteStudent(id);
            } else {
                admin.deleteProfessor(id);
            }
            break;

        case 7: // Update Student Info
            cout << "Enter student ID: ";
            cin >> id;
            if (cin.fail()) {
                cout << "Invalid ID. Must be a number.\n";
                clearInputBuffer();
                break;
            }
            cout << "Enter new name: ";
            clearInputBuffer();
            getline(cin, name);
            cout << "Enter new program: ";
            getline(cin, program);
            cout << "Enter new semester: ";
            cin >> semester;
            if (cin.fail()) {
                cout << "Invalid semester. Must be a number.\n";
                clearInputBuffer();
                break;
            }
            admin.updateStudentInfo(id, name, program, semester);
            break;
        }
    }

    admin.rankProfessors();

    return 0;
}