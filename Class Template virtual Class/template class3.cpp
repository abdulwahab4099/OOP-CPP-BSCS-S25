 #include <conio.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// defining a class template
template <class T> 
class info {
public:
	info(T A) // constructor of type template
	{
		cout << "\n"
			<< "A = " << A
			<< "\t size of data in bytes:" << sizeof(A);
	} // end of info()
}; // end of class

// Main Function
int main()
{
	// clrscr();

	// passing character value by creating an objects
	info<char> p('x');

	// passing integer value by creating an object
	info<int> q(22);

	// passing float value by creating an object
	info<float> r(2.25);
	
	// passing string value by creating an objects
	info<string> s("I'm preparing for final exams.");

	return 0;
} // end of Main Function

