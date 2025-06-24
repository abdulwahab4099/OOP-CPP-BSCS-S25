// C++ program to copy marks of Student 2 to Student 1
#include <iostream>
using namespace std;

class student {
private:
	int english;
	int math;

public:
	student(int e, int m)
	{
		english = e;
		math = m;
	}
	void operator=(const student& s)
	{
		english = s.english;
		math = s.math;
	}

	// method to display marks
	void marks()
	{
		cout << "English: " << english << ", Math: " << math
			<< endl;
	}
};

int main()
{
	student s1(6, 2), s2(5, 10);

	cout << "Student 1 marks : ";
	s1.marks();

	cout << "Student 2 marks : ";
	s2.marks();

	// use assignment operator
	s1 = s2;

	cout << endl;

	cout << "Student 1 marks : ";
	s1.marks();

	cout << "Student 2 marks : ";
	s2.marks();

	return 0;
}

