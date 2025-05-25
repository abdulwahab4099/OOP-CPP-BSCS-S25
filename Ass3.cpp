#include <iostream> // For input/output
#include <string>   // For strings
#include <iomanip>  // For formatting numbers
using namespace std;

// Forward declarations
class Professor; // Forward declare Professor
int sumOfDigits(int n);
void assignCourse(Student& s, Course& c, Professor* p);

const int Max_courses = 6; // Max courses per student/professor

// Base class for anyone with a name
class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}
    virtual ~Person() {}
    string getName() const { return name; } // Public getter for name
};

// Abstract base class for users
class User : virtual public Person {
protected:
    int id;
    static int totalUsers;
public:
    User(string n, int i) : Person(n), id(i) { totalUsers++; }
    virtual void displayInfo() const = 0;
    virtual void calculatePerformance() const = 0;
    virtual ~User() { totalUsers--; }
    static int getTotalUsers() { return totalUsers; }
    int getId() const { return id; }
};
int User::totalUsers = 0;

// Professor class
class Professor : public User {
    string department;
    Course courses[Max_courses];
    int courseCount;
public:
    float rating;
    Professor(string n, int i, string d, float r) : Person(n), User(n, i), department(d), courseCount(0), rating(r) {
        if (n.empty() || d.empty() || i <= 0 || r < 0 || r > 5) {
            cout << "\n[ERR] Invalid professor data\n";
            throw 1;
        }
    }
    ~Professor() {}
    void displayInfo() const {
        cout << "\n--- Professor Info ---";
        cout << "\nName: " << getName() << "\nID: " << id << "\nDept: " << department << "\nRating: " << fixed << setprecision(1) << rating;
        for (int i = 0; i < courseCount; i++) cout << courses[i];
        cout << "\n----------------";
    }
    void calculatePerformance() const {
        cout << "\nProfessor Score: " << sumOfDigits(int(rating * 10));
    }
    friend void assignCourse(Student&, Course&, Professor*);
    const Course* getCourses() const { return courses; } // Getter for courses
    int getCourseCount() const { return courseCount; }   // Getter for courseCount
};

// Class for courses
class Course {
    string courseName, courseCode;
public:
    Course(string n = "", string c = "") : courseName(n), courseCode(c) {}
    string getName() const { return courseName; }
    bool operator==(const Course& other) const { return courseName == other.courseName; }
    friend ostream& operator<<(ostream& os, const Course& c) {
        os << "\nCourse: " << c.courseName << " (" << c.courseCode << ")";
        return os;
    }
    friend class Student;
    friend class Professor;
};

// Student class
class Student : public User {
    string department;
    int semester;
    double gpa;
    Course courses[Max_courses];
    int courseCount;
public:
    Student(string n, int i, string d, int s, double g) : Person(n), User(n, i), department(d), semester(s), gpa(g), courseCount(0) {
        if (n.empty() || d.empty() || i <= 0 || s < 1 || g < 0 || g > 4) {
            cout << "\n[ERR] Invalid student data\n";
            throw 1;
        }
    }
    ~Student() {}
    void displayInfo() const {
        cout << "\n--- Student Info ---";
        cout << "\nName: " << getName() << "\nID: " << id << "\nDept: " << department << "\nSemester: " << semester << "\nGPA: " << fixed << setprecision(2) << gpa;
        for (int i = 0; i < courseCount; i++) cout << courses[i];
        cout << "\n----------------";
    }
    void calculatePerformance() const {
        cout << "\nStudent Performance: " << (gpa > 3.0 ? "Excellent" : "Average");
    }
    friend void assignCourse(Student&, Course&, Professor*);
};

// Assign course to student and professor
void assignCourse(Student& s, Course& c, Professor* p) {
    for (int i = 0; i < s.courseCount; i++)
        if (s.courses[i] == c) { cout << "\n[ERR] Course already assigned to student\n"; return; }
    if (s.courseCount < Max_courses) {
        s.courses[s.courseCount++] = c;
        cout << "\n[OK] Assigned " << c.getName() << " to student " << s.getName() << "\n";
    } else {
        cout << "\n[ERR] Course limit reached for student " << s.getName() << "\n";
    }
    if (p) {
        for (int i = 0; i < p->courseCount; i++)
            if (p->getCourses()[i] == c) return;
        if (p->courseCount < Max_courses) {
            p->courses[p->courseCount++] = c;
            cout << "\n[OK] Assigned " << c.getName() << " to professor " << p->getName() << "\n";
        }
    }
}

// Template class for GPA calculation
template <typename T>
class Calculator {
    T grades[Max_courses];
    int count;
public:
    Calculator() : count(0) {}
    void addGrade(T grade) {
        if (count < Max_courses && grade >= 0 && grade <= 4) grades[count++] = grade;
        else cout << "\n[ERR] Invalid grade\n";
    }
    T recursiveGPA(int i = 0) {
        return i >= count ? 0 : grades[i] + recursiveGPA(i + 1);
    }
    T calculateGPA() { return count ? recursiveGPA() / count : 0; }
    Calculator& operator+(T value) { addGrade(value); return *this; }
};

// Recursive sum of digits
int sumOfDigits(int n) { return n < 10 ? n : (n % 10) + sumOfDigits(n / 10); }

// Template class for ranking
template <typename T>
class Ranker {
    struct Score { T value; string name; };
    void merge(Score arr[], int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        Score L[10], R[10];
        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) arr[k++] = (L[i].value >= R[j].value) ? L[i++] : R[j++];
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }
    void mergeSort(Score arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
public:
    void sortScores(Score arr[], int n) { if (n > 0) mergeSort(arr, 0, n - 1); }
};

// Show menu
void showMenu() {
    cout << "\n=== University System ===\n1. Add Student\n2. Add Professor\n3. Add Course\n4. Display Info\n5. Calculate GPA/Performance\n6. Rank Professors\n7. Exit\nChoice (1-7): ";
}

// Main function
int main() {
    Student* students[10] = {0};
    Professor* professors[10] = {0};
    Course* courses[10] = {0};
    int studentCount = 0, profCount = 7, courseCount = 7;
    int choice, id, sem;
    string name, dept, courseName, courseCode;
    float gpa, rating;

    // Pre-populate professors and courses
    try {
        professors[0] = new Professor("Dr. Ghazanfar Farooq", 201, "CS", 4.8);
        courses[0] = new Course("OOP", "CS-120");
        assignCourse(*students[0], *courses[0], professors[0]); // Assign course
        professors[1] = new Professor("Dr. Waseem", 202, "Math", 4.5);
        courses[1] = new Course("Multivariable Calculus", "MA-202");
        assignCourse(*students[0], *courses[1], professors[1]);
        professors[2] = new Professor("Dr. Abdul Rasheed", 203, "Social Sciences", 4.2);
        courses[2] = new Course("Social Sciences", "SO-101");
        assignCourse(*students[0], *courses[2], professors[2]);
        professors[3] = new Professor("Mrs. M. Mehmood", 204, "Physics", 4.6);
        courses[3] = new Course("Physics", "PH-110");
        assignCourse(*students[0], *courses[3], professors[3]);
        professors[4] = new Professor("Ms. Saima Noor", 205, "English", 4.3);
        courses[4] = new Course("Expository Writing", "EN-200");
        assignCourse(*students[0], *courses[4], professors[4]);
        professors[5] = new Professor("Dr. Abdul Wahid", 206, "Islamic Studies", 4.0);
        courses[5] = new Course("Islamic Studies", "IS-100");
        assignCourse(*students[0], *courses[5], professors[5]);
        professors[6] = new Professor("Dr. Syed M Naqi", 207, "CS", 4.7);
        courses[6] = new Course("PSP", "CS-104");
        assignCourse(*students[0], *courses[6], professors[6]);
    } catch (int e) {
        cout << "\n[ERR] Failed to initialize professors\n";
        return 1;
    }

    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore(1000, '\n');
        if (cin.fail() || choice < 1 || choice > 7) {
            cout << "\n[ERR] Invalid choice\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (choice == 7) {
            cout << "\n[INFO] Exiting\n";
            for (int i = 0; i < studentCount; i++) delete students[i];
            for (int i = 0; i < profCount; i++) delete professors[i];
            for (int i = 0; i < courseCount; i++) delete courses[i];
            break;
        }
        try {
            switch (choice) {
            case 1: // Add student
                cout << "Name: "; getline(cin, name);
                cout << "ID: "; cin >> id;
                cout << "Dept: "; cin.ignore(1000, '\n'); getline(cin, dept);
                cout << "Semester: "; cin >> sem;
                cout << "GPA (0-4): "; cin >> gpa;
                if (cin.fail()) throw 1;
                students[studentCount++] = new Student(name, id, dept, sem, gpa);
                cout << "\n[OK] Student added\n";
                break;
            case 2: // Add professor
                cout << "Name: "; getline(cin, name);
                cout << "ID: "; cin >> id;
                cout << "Dept: "; cin.ignore(1000, '\n'); getline(cin, dept);
                cout << "Rating (0-5): "; cin >> rating;
                if (cin.fail()) throw 1;
                professors[profCount++] = new Professor(name, id, dept, rating);
                cout << "\n[OK] Professor added\n";
                break;
            case 3: // Add course
                cout << "Course Name: "; getline(cin, courseName);
                cout << "Course Code: "; getline(cin, courseCode);
                cout << "Student ID: "; cin >> id;
                cout << "Professor ID (0 to skip): "; cin >> sem;
                if (cin.fail()) throw 1;
                courses[courseCount] = new Course(courseName, courseCode);
                for (int i = 0; i < studentCount; i++) {
                    if (students[i] && students[i]->getId() == id) {
                        Professor* p = 0;
                        for (int j = 0; j < profCount; j++)
                            if (sem != 0 && professors[j] && professors[j]->getId() == sem) { p = professors[j]; break; }
                        assignCourse(*students[i], *courses[courseCount], p);
                        courseCount++;
                        break;
                    }
                }
                break;
            case 4: // Display info
                cout << "1. Student  2. Professor\nChoice: "; cin >> choice;
                cout << "ID: "; cin >> id;
                if (cin.fail()) throw 1;
                if (choice == 1)
                    for (int i = 0; i < studentCount; i++)
                        if (students[i] && students[i]->getId() == id) { students[i]->displayInfo(); break; }
                else
                    for (int i = 0; i < profCount; i++)
                        if (professors[i] && professors[i]->getId() == id) { professors[i]->displayInfo(); break; }
                cout << "\n";
                break;
            case 5: // Calculate GPA/performance
                cout << "1. Student GPA  2. Performance\nChoice: "; cin >> choice;
                cout << "ID: "; cin >> id;
                if (cin.fail()) throw 1;
                if (choice == 1) {
                    Calculator<float> calc;
                    float grade;
                    cout << "Enter up to 6 grades (0-4, -1 to stop): ";
                    for (int i = 0; i < Max_courses; i++) {
                        cin >> grade;
                        if (grade == -1) break;
                        calc + grade;
                    }
                    cout << "\n[OK] GPA: " << fixed << setprecision(2) << calc.calculateGPA() << "\n";
                } else {
                    for (int i = 0; i < studentCount; i++)
                        if (students[i] && students[i]->getId() == id) { students[i]->calculatePerformance(); break; }
                    for (int i = 0; i < profCount; i++)
                        if (professors[i] && professors[i]->getId() == id) { professors[i]->calculatePerformance(); break; }
                    cout << "\n";
                }
                break;
            case 6: // Rank professors
                if (profCount == 0) { cout << "\n[ERR] No professors\n"; break; }
                Ranker<float> ranker;
                Ranker<float>::Score scores[10];
                for (int i = 0; i < profCount; i++) {
                    scores[i].value = professors[i]->rating;
                    scores[i].name = professors[i]->getName();
                }
                ranker.sortScores(scores, profCount);
                cout << "\n--- Professor Ranking ---";
                for (int i = 0; i < profCount; i++)
                    cout << "\nRank " << i + 1 << ": " << scores[i].name << " (" << fixed << setprecision(1) << scores[i].value << ")";
                cout << "\n";
                break;
            }
        } catch (int e) {
            cout << "\n[ERR] Operation failed\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return 0;
}