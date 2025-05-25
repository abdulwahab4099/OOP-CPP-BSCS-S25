#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Forward declaration
class Course;

class Person {
protected:
    string fullName;

public:
    Person(string name) : fullName(name) {}
    virtual ~Person() {}

    virtual void introduce() {
        cout << "Hi, I am " << fullName << endl;
    }
    string getName() const { return fullName; }
    friend class UniversityManager;
};

class User : public virtual Person {
protected:
    int userId;
    static int totalUsers;

public:
    User(string name, int id) : Person(name), userId(id) { totalUsers++; }
    virtual void displayInfo() = 0;
    virtual ~User() { totalUsers--; }
    static int getTotalUsers() { return totalUsers; }
    int getId() const { return userId; }
    friend class UniversityManager;
};

int User::totalUsers = 0;

class Student : public User {
private:
    string degreeProgram;
    int semester;
    string studentCourses[10];
    int courseCount;

public:
    static int totalStudents;

    Student(string name, int id, string program, int sem)
        : Person(name), User(name, id), degreeProgram(program), semester(sem), courseCount(0) {
        totalStudents++;
    }

    ~Student() { totalStudents--; }

    void displayInfo() override {
        cout << "===== Student Details =====" << endl;
        cout << "Full Name: " << fullName << endl;
        cout << "Student ID: " << userId << endl;
        cout << "Program: " << degreeProgram << endl;
        cout << "Semester: " << semester << endl;
        cout << "Courses Enrolled: ";
        if (courseCount == 0) {
            cout << "None" << endl;
        } else {
            for (int i = 0; i < courseCount; i++) {
                cout << studentCourses[i];
                if (i < courseCount - 1) cout << ", ";
            }
            cout << endl;
        }
        cout << "==========================" << endl;
    }

    void updateInfo(const string& newName, const string& newProgram, int newSemester) {
        fullName = newName;
        degreeProgram = newProgram;
        semester = newSemester;
    }

    friend void assignCourse(Student& student, Course& course);
};

int Student::totalStudents = 0;

class Professor : public User {
private:
    string facultyDept;
    string expertise;
    string professorCourses[10];
    int courseCount;
public:
    float rating;

    static int totalProfessors;

    Professor(string name, int id, string dept, string exp, float rat = 0.0f)
        : Person(name), User(name, id), facultyDept(dept), expertise(exp), courseCount(0), rating(rat) {
        totalProfessors++;
    }

    ~Professor() { totalProfessors--; }

    void addCourse(string course) {
        if (courseCount < 10) {
            professorCourses[courseCount++] = course;
        } else {
            cout << "[ERROR] Cannot add more courses to professor " << fullName << "." << endl;
        }
    }

    void displayInfo() override {
        cout << "===== Professor Details =====" << endl;
        cout << "Full Name: " << fullName << endl;
        cout << "Professor ID: " << userId << endl;
        cout << "Department: " << facultyDept << endl;
        cout << "Expertise: " << expertise << endl;
        cout << "Rating: " << fixed << setprecision(1) << rating << endl;
        cout << "Courses Teaching: ";
        if (courseCount == 0) {
            cout << "None" << endl;
        } else {
            for (int i = 0; i < courseCount; i++) {
                cout << professorCourses[i];
                if (i < courseCount - 1) cout << ", ";
            }
            cout << endl;
        }
        cout << "=============================" << endl;
    }
};

int Professor::totalProfessors = 0;

class Course {
private:
    string courseTitle;
    string courseId;

public:
    Course(string title, string id) : courseTitle(title), courseId(id) {}
    string getCourseName() const { return courseTitle; }
    string getCourseCode() const { return courseId; }
    bool operator==(const Course& other) const {
        return (courseId == other.courseId && courseTitle == other.courseTitle);
    }
    Course operator+(const Course& other) {
        return Course(courseTitle + " & " + other.courseTitle, courseId + "-" + other.courseId);
    }
    friend ostream& operator<<(ostream& out, const Course& c) {
        out << c.courseId << ": " << c.courseTitle;
        return out;
    }
    friend void assignCourse(Student&, Course&);
};

void assignCourse(Student& student, Course& course) {
    for (int i = 0; i < student.courseCount; i++) {
        if (student.studentCourses[i] == course.getCourseName()) {
            cout << "[ERROR] Course '" << course.getCourseName() << "' already assigned to " << student.fullName << "." << endl;
            return;
        }
    }
    if (student.courseCount < 10) {
        student.studentCourses[student.courseCount++] = course.getCourseName();
        cout << "[SUCCESS] Course '" << course.getCourseName() << "' assigned to " << student.fullName << "." << endl;
    } else {
        cout << "[ERROR] Cannot assign more courses to " << student.fullName << "." << endl;
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
            cout << "[ERROR] Grade arrays must be the same size." << endl;
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
            cout << "[ERROR] Cannot divide by zero." << endl;
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
            cout << "[ERROR] No grades provided." << endl;
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
        cout << "===== Faculty Rankings =====" << endl;
        if (size == 0) {
            cout << "[INFO] No professors to rank." << endl;
        } else {
            cout << "Rank  Name                  Rating" << endl;
            cout << "--------------------------------" << endl;
            for (int i = 0; i < size; i++) {
                if (scores[i].prof) {
                    cout << left << setw(6) << (i + 1) << setw(22) << scores[i].prof->getName()
                         << fixed << setprecision(1) << scores[i].score << endl;
                }
            }
        }
        cout << "============================" << endl;
    }
};

float extractProfRating(Professor* p) {
    return p->rating;
}

class UniversityManager {
private:
    Student* students[100];
    Professor* professors[100];
    Course* courses[100];
    int totalStudents;
    int totalProfessors;
    int totalCourses;

    bool isStudentIdUnique(int id) {
        for (int i = 0; i < totalStudents; i++) {
            if (students[i] && students[i]->getId() == id) return false;
        }
        return true;
    }

    bool isProfessorIdUnique(int id) {
        for (int i = 0; i < totalProfessors; i++) {
            if (professors[i] && professors[i]->getId() == id) return false;
        }
        return true;
    }

    bool isCourseCodeUnique(const string& code) {
        for (int i = 0; i < totalCourses; i++) {
            if (courses[i] && courses[i]->getCourseCode() == code) return false;
        }
        return true;
    }

public:
    UniversityManager() : totalStudents(0), totalProfessors(0), totalCourses(0) {
        for (int i = 0; i < 100; i++) {
            students[i] = nullptr;
            professors[i] = nullptr;
            courses[i] = nullptr;
        }
    }

    ~UniversityManager() {
        for (int i = 0; i < totalStudents; i++) delete students[i];
        for (int i = 0; i < totalProfessors; i++) delete professors[i];
        for (int i = 0; i < totalCourses; i++) delete courses[i];
    }

    void enrollStudent(const string& name, int id, const string& program, int semester) {
        if (!isStudentIdUnique(id)) {
            cout << "[ERROR] Student ID " << id << " already exists." << endl;
            return;
        }
        if (totalStudents < 100) {
            students[totalStudents++] = new Student(name, id, program, semester);
            cout << "[SUCCESS] Student " << name << " enrolled." << endl;
        } else {
            cout << "[ERROR] Cannot enroll more students." << endl;
        }
    }

    void hireProfessor(const string& name, int id, const string& dept, const string& exp, float rating) {
        if (!isProfessorIdUnique(id)) {
            cout << "[ERROR] Professor ID " << id << " already exists." << endl;
            return;
        }
        if (rating < 0 || rating > 5) {
            cout << "[ERROR] Rating must be between 0 and 5." << endl;
            return;
        }
        if (totalProfessors < 100) {
            professors[totalProfessors++] = new Professor(name, id, dept, exp, rating);
            cout << "[SUCCESS] Professor " << name << " hired." << endl;
        } else {
            cout << "[ERROR] Cannot hire more professors." << endl;
        }
    }

    void createCourse(const string& title, const string& id) {
        if (!isCourseCodeUnique(id)) {
            cout << "[ERROR] Course ID " << id << " already exists." << endl;
            return;
        }
        if (totalCourses < 100) {
            courses[totalCourses++] = new Course(title, id);
            cout << "[SUCCESS] Course " << title << " created." << endl;
        } else {
            cout << "[ERROR] Cannot create more courses." << endl;
        }
    }

    void enrollStudentInCourse(int studentId, const string& courseId) {
        Student* student = nullptr;
        Course* course = nullptr;
        for (int i = 0; i < totalStudents; i++) {
            if (students[i] && students[i]->getId() == studentId) {
                student = students[i];
                break;
            }
        }
        for (int i = 0; i < totalCourses; i++) {
            if (courses[i] && courses[i]->getCourseCode() == courseId) {
                course = courses[i];
                break;
            }
        }
        if (student && course) {
            assignCourse(*student, *course);
        } else {
            cout << "[ERROR] Student or course not found." << endl;
        }
    }

    void computeGPA(int studentId) {
        for (int i = 0; i < totalStudents; i++) {
            if (students[i] && students[i]->getId() == studentId) {
                float grades[10];
                int gradeCount = 0;
                cout << ">> Enter number of grades (1-10) for " << students[i]->getName() << ": ";
                cin >> gradeCount;
                if (cin.fail() || gradeCount < 1 || gradeCount > 10) {
                    cout << "[ERROR] Invalid number of grades. Must be 1-10." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    return;
                }
                cout << ">> Enter " << gradeCount << " grades (0-4.0): ";
                for (int j = 0; j < gradeCount; j++) {
                    cin >> grades[j];
                    if (cin.fail() || grades[j] < 0 || grades[j] > 4.0) {
                        cout << "[ERROR] Invalid grade. Must be 0-4.0." << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        return;
                    }
                }
                Calculator<float> calc(grades, gradeCount);
                cout << "[SUCCESS] GPA for " << students[i]->getName() << ": " << fixed << setprecision(2) << calc.getGPA() << endl;
                cin.ignore(1000, '\n');
                return;
            }
        }
        cout << "[ERROR] Student not found." << endl;
    }

    void displayStudentDetails(int studentId) {
        for (int i = 0; i < totalStudents; i++) {
            if (students[i] && students[i]->getId() == studentId) {
                students[i]->displayInfo();
                return;
            }
        }
        cout << "[ERROR] Student not found." << endl;
    }

    void displayProfessorDetails(int professorId) {
        for (int i = 0; i < totalProfessors; i++) {
            if (professors[i] && professors[i]->getId() == professorId) {
                professors[i]->displayInfo();
                return;
            }
        }
        cout << "[ERROR] Professor not found." << endl;
    }

    void removeStudent(int studentId) {
        for (int i = 0; i < totalStudents; i++) {
            if (students[i] && students[i]->getId() == studentId) {
                delete students[i];
                students[i] = students[totalStudents - 1];
                students[totalStudents - 1] = nullptr;
                totalStudents--;
                cout << "[SUCCESS] Student removed." << endl;
                return;
            }
        }
        cout << "[ERROR] Student not found." << endl;
    }

    void removeProfessor(int professorId) {
        for (int i = 0; i < totalProfessors; i++) {
            if (professors[i] && professors[i]->getId() == professorId) {
                delete professors[i];
                professors[i] = professors[totalProfessors - 1];
                professors[totalProfessors - 1] = nullptr;
                totalProfessors--;
                cout << "[SUCCESS] Professor removed." << endl;
                return;
            }
        }
        cout << "[ERROR] Professor not found." << endl;
    }

    void updateStudentRecord(int studentId, const string& name, const string& program, int semester) {
        if (semester < 1) {
            cout << "[ERROR] Invalid semester. Must be positive." << endl;
            return;
        }
        for (int i = 0; i < totalStudents; i++) {
            if (students[i] && students[i]->getId() == studentId) {
                students[i]->updateInfo(name, program, semester);
                cout << "[SUCCESS] Student record updated." << endl;
                return;
            }
        }
        cout << "[ERROR] Student not found." << endl;
    }

    void sortFacultyByRating() {
        if (totalProfessors == 0) {
            cout << "[INFO] No professors to rank." << endl;
            return;
        }
        Ranker<float> ranker(professors, totalProfessors, extractProfRating);
        ranker.sortProfessors();
        ranker.displayRankings();
    }
};

void resetInput() {
    cin.clear();
    cin.ignore(1000, '\n');
}

void showMainMenu() {
    cout << "===== Smart University Management System =====" << endl;
    cout << "1. Enroll Student" << endl;
    cout << "2. Hire Professor" << endl;
    cout << "3. Create and Assign Course" << endl;
    cout << "4. Compute GPA" << endl;
    cout << "5. Display User Details" << endl;
    cout << "   - Student" << endl;
    cout << "   - Professor" << endl;
    cout << "6. Remove User" << endl;
    cout << "   - Student" << endl;
    cout << "   - Professor" << endl;
    cout << "7. Update Student Record" << endl;
    cout << "8. Exit" << endl;
    cout << "----------------------------------------" << endl;
    cout << ">> Enter choice (1-8): ";
}

int main() {
    UniversityManager manager;
    int choice, userId, semester;
    string fullName, degreeProgram, facultyDept, expertise, courseTitle, courseId;
    float rating;

    while (true) {
        showMainMenu();
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 8) {
            cout << "[ERROR] Invalid choice. Enter 1-8." << endl;
            resetInput();
            continue;
        }
        resetInput();

        if (choice == 8) {
            cout << "[INFO] Exiting Smart University Management System." << endl;
            break;
        }

        switch (choice) {
        case 1: // Enroll Student
            cout << ">> Enter student's full name: ";
            getline(cin, fullName);
            cout << ">> Enter student ID: ";
            cin >> userId;
            if (cin.fail()) {
                cout << "[ERROR] Invalid ID. Must be a number." << endl;
                resetInput();
                break;
            }
            cout << ">> Enter degree program: ";
            resetInput();
            getline(cin, degreeProgram);
            cout << ">> Enter semester: ";
            cin >> semester;
            if (cin.fail() || semester < 1) {
                cout << "[ERROR] Invalid semester. Must be positive." << endl;
                resetInput();
                break;
            }
            manager.enrollStudent(fullName, userId, degreeProgram, semester);
            break;

        case 2: // Hire Professor
            cout << ">> Enter professor's full name: ";
            getline(cin, fullName);
            cout << ">> Enter professor ID: ";
            cin >> userId;
            if (cin.fail()) {
                cout << "[ERROR] Invalid ID. Must be a number." << endl;
                resetInput();
                break;
            }
            cout << ">> Enter department: ";
            resetInput();
            getline(cin, facultyDept);
            cout << ">> Enter expertise: ";
            getline(cin, expertise);
            cout << ">> Enter professor rating (0-5): ";
            cin >> rating;
            if (cin.fail()) {
                cout << "[ERROR] Invalid rating. Must be a number." << endl;
                resetInput();
                break;
            }
            manager.hireProfessor(fullName, userId, facultyDept, expertise, rating);
            break;

        case 3: // Create and Assign Course
            cout << ">> Enter course title: ";
            getline(cin, courseTitle);
            cout << ">> Enter course ID: ";
            getline(cin, courseId);
            manager.createCourse(courseTitle, courseId);
            cout << ">> Enter student ID: ";
            cin >> userId;
            if (cin.fail()) {
                cout << "[ERROR] Invalid ID. Must be a number." << endl;
                resetInput();
                break;
            }
            manager.enrollStudentInCourse(userId, courseId);
            break;

        case 4: // Compute GPA
            cout << ">> Enter student ID: ";
            cin >> userId;
            if (cin.fail()) {
                cout << "[ERROR] Invalid ID. Must be a number." << endl;
                resetInput();
                break;
            }
            manager.computeGPA(userId);
            break;

        case 5: // Display User Details
            cout << ">> 1. Display Student Details" << endl;
            cout << ">> 2. Display Professor Details" << endl;
            cout << ">> Enter choice (1-2): ";
            cin >> choice;
            if (cin.fail() || (choice != 1 && choice != 2)) {
                cout << "[ERROR] Invalid choice. Enter 1 or 2." << endl;
                resetInput();
                break;
            }
            cout << ">> Enter ID: ";
            cin >> userId;
            if (cin.fail()) {
                cout << "[ERROR] Invalid ID. Must be a number." << endl;
                resetInput();
                break;
            }
            if (choice == 1) {
                manager.displayStudentDetails(userId);
            } else {
                manager.displayProfessorDetails(userId);
            }
            break;

        case 6: // Remove User
            cout << ">> 1. Remove Student" << endl;
            cout << ">> 2. Remove Professor" << endl;
            cout << ">> Enter choice (1-2): ";
            cin >> choice;
            if (cin.fail() || (choice != 1 && choice != 2)) {
                cout << "[ERROR] Invalid choice. Enter 1 or 2." << endl;
                resetInput();
                break;
            }
            cout << ">> Enter ID: ";
            cin >> userId;
            if (cin.fail()) {
                cout << "[ERROR] Invalid ID. Must be a number." << endl;
                resetInput();
                break;
            }
            if (choice == 1) {
                manager.removeStudent(userId);
            } else {
                manager.removeProfessor(userId);
            }
            break;

        case 7: // Update Student Record
            cout << ">> Enter student ID: ";
            cin >> userId;
            if (cin.fail()) {
                cout << "[ERROR] Invalid ID. Must be a number." << endl;
                resetInput();
                break;
            }
            cout << ">> Enter new full name: ";
            resetInput();
            getline(cin, fullName);
            cout << ">> Enter new degree program: ";
            getline(cin, degreeProgram);
            cout << ">> Enter new semester: ";
            cin >> semester;
            if (cin.fail()) {
                cout << "[ERROR] Invalid semester. Must be a number." << endl;
                resetInput();
                break;
            }
            manager.updateStudentRecord(userId, fullName, degreeProgram, semester);
            break;
        }
    }

    manager.sortFacultyByRating();

    return 0;
}