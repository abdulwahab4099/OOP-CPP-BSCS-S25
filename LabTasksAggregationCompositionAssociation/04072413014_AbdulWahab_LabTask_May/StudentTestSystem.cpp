/*
				Question 1: Association- Student Test Score System
 Create a simple grade system using Association between Student and Test classes.
 
 Requirements:
	 • Student class: name, roll number
	 • Test class: subject name, marks (out of 100)
	 • Students can take multiple tests
	 • Tests can be taken by multiple students
 Simple Math Operations:
 	(a) Calculate average marks: Average = Sum of all marks
 Number of tests
 	(b) Calculate percentage: Percentage = Marks obtained
 	100
	 (c) Find highest and lowest marks
	 (d) Count number of passed tests (marks ≥ 40)
 Tasks:
	 • Create 3 students and 4 tests
	 • Display each student’s average marks
	 • Show pass/fail status for each test
*/

#include <iostream>
#include <string>
using namespace std;

// Test class to store test details
class Test {
	public:
	    string subject; // Subject name
	    double marks;   // Marks out of 100
	
	    // Constructor to initialize test
	    Test(string s, double m) {
	        subject = s;
	        marks = m;
	    }
};

// Student class to store student details and tests
class Student {
	public:
	    string name;         // Student name
	    string roll;         // Roll number
	    Test* tests[10];     // Array to store test pointers (association)
	    int test_count;      // Number of tests taken
	
	    // Constructor to initialize student
	    Student(string n, string r) {
	        name = n;
	        roll = r;
	        test_count = 0;
	    }
	
	    // Add test to student's test list
	    void add_test(Test* t) {
	        tests[test_count] = t;
	        test_count++;
	    }
	
	    // Calculate average marks
	    double get_average() {
	        if (test_count == 0) return 0.0;
	        double sum = 0.0;
	        for (int i = 0; i < test_count; i++) 
			{
	            sum += tests[i]->marks;
	        }
	        return sum / test_count;
	    }
	
	    // Display student results
	    void show_results() {
	        cout << "\nStudent: " << name << ", Roll: " << roll << endl;
	        cout << "Average Marks: " << get_average() << endl;
	        cout << "Test Results:\n";
	        for (int i = 0; i < test_count; i++) 
			{
	            string status = (tests[i]->marks >= 40) ? "Pass" : "Fail";
	            cout << "  " << tests[i]->subject << ": " << tests[i]->marks << "% - " << status << endl;
	        }
	    }
};

// Main program
int main() 
{
    // Create 3 students
    Student s1("Abdul Wahab", "S001");
    Student s2("Abdul Raheem", "S002");
    Student s3("M Karam Dad", "S003");

    // Create 4 tests
    Test t1("Calculus", 85);
    Test t2("English", 92);
    Test t3("OOP", 75);
    Test t4("Physics", 78);

    // Assign tests to students (association)
    s1.add_test(&t1); // Student 1: all tests
    s1.add_test(&t2);
    s1.add_test(&t3);
    s1.add_test(&t4);

    s2.add_test(&t1); // Student 2: 3 tests
    s2.add_test(&t2);
    s2.add_test(&t4);

    s3.add_test(&t2); // Student 3: 2 tests
    s3.add_test(&t3);

    // Display results for each student
    s1.show_results();
    s2.show_results();
    s3.show_results();

    // Calculate highest, lowest, and pass count
    Test* all_tests[] = {&t1, &t2, &t3, &t4};
    int total_tests = 4;
    double highest = all_tests[0]->marks;
    double lowest = all_tests[0]->marks;
    int passed = 0;

    for (int i = 0; i < total_tests; i++) 
	{
        if (all_tests[i]->marks > highest) highest = all_tests[i]->marks;
        if (all_tests[i]->marks < lowest) lowest = all_tests[i]->marks;
        if (all_tests[i]->marks >= 40) passed++;
    }

    // Display overall statistics
    cout << "\nOverall Statistics:\n";
    cout << "Highest Marks: " << highest << "%\n";
    cout << "Lowest Marks: " << lowest << "%\n";
    cout << "Passed Tests (>=40): " << passed << " out of " << total_tests << endl;

    return 0;
}