#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Course;
class Person {
protected:
    string fullName;
public:
    Person(string name) : fullName(name) {}
    virtual ~Person() {}
    virtual void introduce() { cout << "Hi, I'm " << fullName << endl; }
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
    string degreeProgram;
    int semester;
    string studentCourses[10];
    int courseCount;
public:
    static int totalStudents;
    Student(string name, int id, string prog, int sem) : Person(name), User(name, id), degreeProgram(prog), semester(sem), courseCount(0) { totalStudents++; }
    ~Student() { totalStudents--; }
    void displayInfo() override {
        cout << "=== Student Info ===" << endl;
        cout << "Name: " << fullName << "\nID: " << userId << "\nProgram: " << degreeProgram << "\nSemester: " << semester << "\nCourses: ";
        if (courseCount == 0) cout << "None";
        else for (int i = 0; i < courseCount; i++) cout << studentCourses[i] << (i < courseCount - 1 ? ", " : "");
        cout << "\n=================" << endl;
    }
    void updateInfo(const string& name, const string& prog, int sem) { fullName = name; degreeProgram = prog; semester = sem; }
    friend void assignCourse(Student&, Course&);
};
int Student::totalStudents = 0;

class Professor : public User {
    string dept, expertise;
    string professorCourses[10];
    int courseCount;
public:
    float rating;
    static int totalProfessors;
    Professor(string name, int id, string d, string exp, float r) : Person(name), User(name, id), dept(d), expertise(exp), courseCount(0), rating(r) { totalProfessors++; }
    ~Professor() { totalProfessors--; }
    void addCourse(string course) { if (courseCount < 10) professorCourses[courseCount++] = course; }
    void displayInfo() override {
        cout << "=== Professor Info ===" << endl;
        cout << "Name: " << fullName << "\nID: " << userId << "\nDept: " << dept << "\nExpertise: " << expertise << "\nRating: " << fixed << setprecision(1) << rating << "\nCourses: ";
        if (courseCount == 0) cout << "None";
        else for (int i = 0; i < courseCount; i++) cout << professorCourses[i] << (i < courseCount - 1 ? ", " : "");
        cout << "\n===================" << endl;
    }
};
int Professor::totalProfessors = 0;

class Course {
    string courseTitle, courseId;
public:
    Course(string title, string id) : courseTitle(title), courseId(id) {}
    string getCourseName() const { return courseTitle; }
    string getCourseCode() const { return courseId; }
    friend void assignCourse(Student&, Course&);
};

void assignCourse(Student& s, Course& c) {
    for (int i = 0; i < s.courseCount; i++)
        if (s.studentCourses[i] == c.getCourseName()) { cout << "[ERR] Course already assigned.\n"; return; }
    if (s.courseCount < 10) {
        s.studentCourses[s.courseCount++] = c.getCourseName();
        cout << "[OK] Course assigned.\n";
    } else cout << "[ERR] Max courses reached.\n";
}

template <typename T>
class Calculator {
    T* grades;
    int size;
public:
    Calculator(const T* g, int s) : size(s) {
        grades = new T[s];
        for (int i = 0; i < s; i++) grades[i] = g[i];
    }
    ~Calculator() { delete[] grades; }
    T calculateGPA(int i = 0) { return i >= size ? 0 : (i == size - 1 ? grades[i] : grades[i] + calculateGPA(i + 1)); }
    T getGPA() { return size ? calculateGPA() / size : 0; }
};

int sumOfDigits(int n) { return n ? (n % 10) + sumOfDigits(n / 10) : 0; }
float power(float b, int e) { return e == 0 ? 1 : e % 2 == 0 ? power(b, e / 2) * power(b, e / 2) : b * power(b, e - 1); }

template <typename T>
class Ranker {
    struct ProfScore { Professor* prof; T score; };
    ProfScore* scores;
    int size;
    void merge(int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        ProfScore* L = new ProfScore[n1], *R = new ProfScore[n2];
        for (int i = 0; i < n1; i++) L[i] = scores[l + i];
        for (int i = 0; i < n2; i++) R[i] = scores[m + 1 + i];
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) scores[k++] = (L[i].score >= R[j].score) ? L[i++] : R[j++];
        while (i < n1) scores[k++] = L[i++];
        while (j < n2) scores[k++] = R[j++];
        delete[] L; delete[] R;
    }
    void mergeSort(int l, int r) { if (l < r) { int m = l + (r - l) / 2; mergeSort(l, m); mergeSort(m + 1, r); merge(l, m, r); } }
public:
    Ranker(Professor* profs[], int s) : size(s) {
        scores = new ProfScore[s];
        for (int i = 0; i < s; i++) if (profs[i]) { scores[i].prof = profs[i]; scores[i].score = profs[i]->rating; }
    }
    ~Ranker() { delete[] scores; }
    void sortProfessors() { if (size > 0) mergeSort(0, size - 1); }
    void displayRankings() {
        cout << "=== Faculty Ranks ===\n";
        if (size == 0) cout << "[INFO] No professors.\n";
        else {
            cout << "Rank Name                Rating\n--- -------------------- ------\n";
            for (int i = 0; i < size; i++)
                if (scores[i].prof) cout << left << setw(5) << (i + 1) << setw(20) << scores[i].prof->getName() << fixed << setprecision(1) << scores[i].score << endl;
        }
        cout << "===================\n";
    }
};

class UniversityManager {
    Student* students[100];
    Professor* professors[100];
    Course* courses[100];
    int totalStudents, totalProfessors, totalCourses;
    bool isIdUnique(int id, bool isStudent) {
        auto& arr = isStudent ? students : professors;
        int n = isStudent ? totalStudents : totalProfessors;
        for (int i = 0; i < n; i++) if (arr[i] && arr[i]->getId() == id) return false;
        return true;
    }
    bool isCourseIdUnique(const string& id) {
        for (int i = 0; i < totalCourses; i++) if (courses[i] && courses[i]->getCourseCode() == id) return false;
        return true;
    }
public:
    UniversityManager() : totalStudents(0), totalProfessors(0), totalCourses(0) {
        for (int i = 0; i < 100; i++) students[i] = professors[i] = courses[i] = nullptr;
    }
    ~UniversityManager() {
        for (int i = 0; i < totalStudents; i++) delete students[i];
        for (int i = 0; i < totalProfessors; i++) delete professors[i];
        for (int i = 0; i < totalCourses; i++) delete courses[i];
    }
    void enrollStudent(string name, int id, string prog, int sem) {
        if (!isIdUnique(id, true)) { cout << "[ERR] Student ID exists.\n"; return; }
        if (totalStudents < 100) {
            students[totalStudents++] = new Student(name, id, prog, sem);
            cout << "[OK] Student enrolled.\n";
        } else cout << "[ERR] Max students reached.\n";
    }
    void hireProfessor(string name, int id, string d, string exp, float r) {
        if (!isIdUnique(id, false)) { cout << "[ERR] Professor ID exists.\n"; return; }
        if (r < 0 || r > 5) { cout << "[ERR] Rating must be 0-5.\n"; return; }
        if (totalProfessors < 100) {
            professors[totalProfessors++] = new Professor(name, id, d, exp, r);
            cout << "[OK] Professor hired.\n";
        } else cout << "[ERR] Max professors reached.\n";
    }
    void createCourse(string title, string id) {
        if (!isCourseIdUnique(id)) { cout << "[ERR] Course ID exists.\n"; return; }
        if (totalCourses < 100) {
            courses[totalCourses++] = new Course(title, id);
            cout << "[OK] Course created.\n";
        } else cout << "[ERR] Max courses reached.\n";
    }
    void enrollStudentInCourse(int sid, string cid) {
        Student* s = nullptr; Course* c = nullptr;
        for (int i = 0; i < totalStudents; i++) if (students[i] && students[i]->getId() == sid) { s = students[i]; break; }
        for (int i = 0; i < totalCourses; i++) if (courses[i] && courses[i]->getCourseCode() == cid) { c = courses[i]; break; }
        if (s && c) assignCourse(*s, *c); else cout << "[ERR] Student or course not found.\n";
    }
    void computeGPA(int sid) {
        for (int i = 0; i < totalStudents; i++) {
            if (students[i] && students[i]->getId() == sid) {
                float grades[10]; int n;
                cout << ">> Grades (1-10): "; cin >> n;
                if (cin.fail() || n < 1 || n > 10) { cout << "[ERR] Invalid grade count.\n"; cin.clear(); cin.ignore(1000, '\n'); return; }
                cout << ">> Enter " << n << " grades (0-4): ";
                for (int j = 0; j < n; j++) {
                    cin >> grades[j];
                    if (cin.fail() || grades[j] < 0 || grades[j] > 4) { cout << "[ERR] Invalid grade.\n"; cin.clear(); cin.ignore(1000, '\n'); return; }
                }
                Calculator<float> calc(grades, n);
                cout << "[OK] GPA: " << fixed << setprecision(2) << calc.getGPA() << endl;
                cin.ignore(1000, '\n');
                return;
            }
        }
        cout << "[ERR] Student not found.\n";
    }
    void displayUserDetails(int id, bool isStudent) {
        auto& arr = isStudent ? students : professors;
        int n = isStudent ? totalStudents : totalProfessors;
        for (int i = 0; i < n; i++) if (arr[i] && arr[i]->getId() == id) { arr[i]->displayInfo(); return; }
        cout << "[ERR] " << (isStudent ? "Student" : "Professor") << " not found.\n";
    }
    void removeUser(int id, bool isStudent) {
        auto& arr = isStudent ? students : professors;
        int& n = isStudent ? totalStudents : totalProfessors;
        for (int i = 0; i < n; i++) {
            if (arr[i] && arr[i]->getId() == id) {
                delete arr[i];
                arr[i] = arr[n - 1];
                arr[n - 1] = nullptr;
                n--;
                cout << "[OK] " << (isStudent ? "Student" : "Professor") << " removed.\n";
                return;
            }
        }
        cout << "[ERR] " << (isStudent ? "Student" : "Professor") << " not found.\n";
    }
    void updateStudentRecord(int id, string name, string prog, int sem) {
        if (sem < 1) { cout << "[ERR] Invalid semester.\n"; return; }
        for (int i = 0; i < totalStudents; i++) {
            if (students[i] && students[i]->getId() == id) {
                students[i]->updateInfo(name, prog, sem);
                cout << "[OK] Student updated.\n";
                return;
            }
        }
        cout << "[ERR] Student not found.\n";
    }
    void sortFacultyByRating() {
        if (totalProfessors == 0) { cout << "[INFO] No professors.\n"; return; }
        Ranker<float> ranker(professors, totalProfessors);
        ranker.sortProfessors();
        ranker.displayRankings();
    }
};

void resetInput() { cin.clear(); cin.ignore(1000, '\n'); }
void showMenu() {
    cout << "=== University System ===\n1. Add Student\n2. Add Professor\n3. Add Course\n4. Compute GPA\n5. Show Details\n6. Remove User\n7. Update Student\n8. Exit\n---\n>> Choice (1-8): ";
}

int main() {
    UniversityManager mgr;
    int choice, id, sem;
    string name, prog, dept, exp, cid, title;
    float rating;
    while (true) {
        showMenu();
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 8) { cout << "[ERR] Invalid choice.\n"; resetInput(); continue; }
        resetInput();
        if (choice == 8) { cout << "[INFO] Exiting.\n"; mgr.sortFacultyByRating(); break; }
        switch (choice) {
        case 1:
            cout << ">> Name: "; getline(cin, name);
            cout << ">> ID: "; cin >> id;
            if (cin.fail()) { cout << "[ERR] Invalid ID.\n"; resetInput(); break; }
            cout << ">> Program: "; resetInput(); getline(cin, prog);
            cout << ">> Semester: "; cin >> sem;
            if (cin.fail() || sem < 1) { cout << "[ERR] Invalid semester.\n"; resetInput(); break; }
            mgr.enrollStudent(name, id, prog, sem);
            break;
        case 2:
            cout << ">> Name: "; getline(cin, name);
            cout << ">> ID: "; cin >> id;
            if (cin.fail()) { cout << "[ERR] Invalid ID.\n"; resetInput(); break; }
            cout << ">> Dept: "; resetInput(); getline(cin, dept);
            cout << ">> Expertise: "; getline(cin, exp);
            cout << ">> Rating (0-5): "; cin >> rating;
            if (cin.fail()) { cout << "[ERR] Invalid rating.\n"; resetInput(); break; }
            mgr.hireProfessor(name, id, dept, exp, rating);
            break;
        case 3:
            cout << ">> Title: "; getline(cin, title);
            cout << ">> ID: "; getline(cin, cid);
            mgr.createCourse(title, cid);
            cout << ">> Student ID: "; cin >> id;
            if (cin.fail()) { cout << "[ERR] Invalid ID.\n"; resetInput(); break; }
            mgr.enrollStudentInCourse(id, cid);
            break;
        case 4:
            cout << ">> Student ID: "; cin >> id;
            if (cin.fail()) { cout << "[ERR] Invalid ID.\n"; resetInput(); break; }
            mgr.computeGPA(id);
            break;
        case 5: case 6:
            cout << ">> 1. Student\n>> 2. Professor\n>> Choice (1-2): "; cin >> choice;
            if (cin.fail() || choice < 1 || choice > 2) { cout << "[ERR] Invalid choice.\n"; resetInput(); break; }
            cout << ">> ID: "; cin >> id;
            if (cin.fail()) { cout << "[ERR] Invalid ID.\n"; resetInput(); break; }
            if (choice == 5) mgr.displayUserDetails(id, choice == 1);
            else mgr.removeUser(id, choice == 1);
            break;
        case 7:
            cout << ">> Student ID: "; cin >> id;
            if (cin.fail()) { cout << "[ERR] Invalid ID.\n"; resetInput(); break; }
            cout << ">> Name: "; resetInput(); getline(cin, name);
            cout << ">> Program: "; getline(cin, prog);
            cout << ">> Semester: "; cin >> sem;
            if (cin.fail()) { cout << "[ERR] Invalid semester.\n"; resetInput(); break; }
            mgr.updateStudentRecord(id, name, prog, sem);
            break;
        }
    }
    return 0;
}