/*
 				Question 4: Mixed System- School Management
 Create a school system combining all three relationships with basic math.
 System Design:
	 • Aggregation: School has Teachers (teachers exist independently)
	 • Association: Teacher teaches Students (many-to-many)
	 • Composition: Student has Report Card (report card belongs to student)
	 Basic Math Requirements:
	 (a) Student average: Average = Sum of subject marks
	 Number of subjects
	 (b) Class average: Class Average = Sum of all student averages
	 Number of students
	 (c) Teacher workload: Workload = Number of students taught
	 (d) Grade assignment:
		 • A: marks ≥ 90
		 • B: marks ≥ 80 and < 90
		 • C: marks ≥ 70 and < 80
		 • D: marks ≥ 60 and < 70
		 • F: marks < 60
 Implementation Requirements:
	 • Create 1 school, 2 teachers, 4 students
	 • Each student has 3 subject marks
	 • Calculate and display:
	 	– Individual student averages and grades
		- Class average for each teacher
		– School overall performance
	 • Show proper relationship implementation for all three types
*/


#include <iostream>
#include <string>
using namespace std;

// Forward declaration of Teacher class to allow Student to use Teacher*
class Teacher;

// ReportCard class: Part of Student (composition) to store marks and subjects
class ReportCard {
public:
    double marks[3]; // Marks for Math, English, Science
    string subjects[3]; // Subject names: Math, English, Science

    // Constructor to initialize report card with 3 subject marks
    ReportCard(double m1, double m2, double m3, string s1, string s2, string s3) {
        marks[0] = m1; marks[1] = m2; marks[2] = m3;
        subjects[0] = s1; subjects[1] = s2; subjects[2] = s3;
    }

    // Calculate average marks (sum of 3 subjects ÷ 3)
    double get_average() {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    // Assign grade based on marks (A: ≥90, B: ≥80, C: ≥70, D: ≥60, F: <60)
    char get_grade(double mark) {
        if (mark >= 90) return 'A';
        if (mark >= 80) return 'B';
        if (mark >= 70) return 'C';
        if (mark >= 60) return 'D';
        return 'F';
    }
};

// Student class: Contains ReportCard (composition) and associates with Teachers
class Student {
public:
    string name;          // Student name (e.g., Abdul Wahab, Wahaj Taimoor)
    ReportCard report;    // Report card with 3 subjects (destroyed with student)
    Teacher* teachers[2];  // Association: Stores up to 2 teachers (e.g., Sir Faisal Javed, Sir Sajid Faraz)
    int teacher_count;    // Number of teachers assigned to this student

    // Constructor to initialize student and report card (e.g., Abdul Wahab with marks 85, 90, 78)
    Student(string n, double m1, double m2, double m3, string s1, string s2, string s3)
        : name(n), report(m1, m2, m3, s1, s2, s3), teacher_count(0) {} // Initialize teacher_count to 0

    // Add teacher to student's teacher list with bounds checking (max 2 teachers)
    void add_teacher(Teacher* t) {
        if (teacher_count < 2) {
            teachers[teacher_count] = t;
            teacher_count++;
        } else {
            cout << "Error: Cannot add more teachers to " << name << endl;
        }
    }

    // Display student details: name, average marks, and grades for each subject
    void display_results() {
        cout << "\nStudent: " << name << endl;
        cout << "Average Marks: " << report.get_average() << endl;
        cout << "Subject Grades:\n";
        for (int i = 0; i < 3; i++) {
            cout << "  " << report.subjects[i] << ": " << report.marks[i]
                 << " (" << report.get_grade(report.marks[i]) << ")" << endl;
        }
    }
};

// Teacher class: Associated with Students (many-to-many relationship)
class Teacher {
public:
    string name;          // Teacher name (e.g., Sir Faisal Javed, Sir Sajid Faraz)
    Student* students[10]; // Association: Stores up to 10 students (e.g., Abdul Wahab, Wahaj Taimoor)
    int student_count;    // Number of students taught by this teacher

    // Constructor to initialize teacher (e.g., Sir Faisal Javed)
    Teacher(string n) : name(n), student_count(0) {}

    // Add student to teacher's student list with bounds checking (max 10 students)
    void add_student(Student* s) {
        if (student_count < 10) {
            students[student_count] = s;
            student_count++;
        } else {
            cout << "Error: Cannot add more students to " << name << endl;
        }
    }

    // Calculate class average (sum of student averages ÷ number of students)
    double class_average() {
        if (student_count == 0) return 0.0;
        double sum = 0.0;
        for (int i = 0; i < student_count; i++) {
            sum += students[i]->report.get_average();
        }
        return sum / student_count;
    }

    // Display teacher details: name, workload (student count), and class average
    void display_details() {
        cout << "\nTeacher: " << name << endl;
        cout << "Workload: " << student_count << " students" << endl;
        cout << "Class Average: " << class_average() << endl;
    }
};

// School class: Aggregates Teachers (teachers exist independently)
class School {
public:
    string name;          // School name (e.g., Al Faisal Grammar High School)
    Teacher* teachers[5]; // Aggregation: Stores up to 5 teachers (e.g., Sir Faisal Javed, Sir Sajid Faraz)
    int teacher_count;    // Number of teachers in the school

    // Constructor to initialize school (e.g., Al Faisal Grammar High School)
    School(string n) : name(n), teacher_count(0) {}

    // Add teacher to school's teacher list with bounds checking (max 5 teachers)
    void add_teacher(Teacher* t) {
        if (teacher_count < 5) {
            teachers[teacher_count] = t;
            teacher_count++;
        } else {
            cout << "Error: Cannot add more teachers to " << name << endl;
        }
    }

    // Calculate school overall average (sum of class averages ÷ number of teachers)
    double school_average() {
        if (teacher_count == 0) return 0.0;
        double sum = 0.0;
        for (int i = 0; i < teacher_count; i++) {
            sum += teachers[i]->class_average();
        }
        return sum / teacher_count;
    }

    // Display school performance: name and overall average
    void display_performance() {
        cout << "\nSchool: " << name << endl;
        cout << "Overall Performance (Average): " << school_average() << endl;
    }
};

// Main program
int main() {
    // Create 4 students with report cards (composition)
    Student s1("Abdul Wahab", 85, 90, 78, "Math", "Physics", "Computer Science");
    Student s2("Wahaj Taimoor", 92, 88, 65, "Math", "Physics", "Computer Science");
    Student s3("Muneeb ur Rehman", 75, 82, 90, "Math", "Physics", "Computer Science");
    Student s4("Muhammad Umair", 60, 55, 70, "Math", "Physics", "Computer Science");

    // Create 2 teachers
    Teacher t1("Sir Faisal Javed");
    Teacher t2("Sir Sajid Faraz");

    // Create school (aggregation)
    School school("Al Faisal Grammar High School");
    school.add_teacher(&t1);
    school.add_teacher(&t2);

    // Establish teacher-student associations
    t1.add_student(&s1); // Sir Faisal Javed teaches Abdul Wahab, Wahaj Taimoor, Muneeb ur Rehman
    t1.add_student(&s2);
    t1.add_student(&s3);
    t2.add_student(&s3); // Sir Sajid Faraz teaches Muneeb ur Rehman, Muhammad Umair
    t2.add_student(&s4);

    s1.add_teacher(&t1); // Set associations: Abdul Wahab taught by Sir Faisal Javed
    s2.add_teacher(&t1); // Wahaj Taimoor taught by Sir Faisal Javed
    s3.add_teacher(&t1); // Muneeb ur Rehman taught by both teachers
    s3.add_teacher(&t2);
    s4.add_teacher(&t2); // Muhammad Umair taught by Sir Sajid Faraz

    // Display individual student results
    s1.display_results();
    s2.display_results();
    s3.display_results();
    s4.display_results();

    // Display teacher details
    t1.display_details();
    t2.display_details();

    // Display school performance
    school.display_performance();

    return 0;
}