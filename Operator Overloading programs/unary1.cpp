// C++ program to show unary operator overloading
#include <iostream>

using namespace std;

class Distance {
public:

	// Member Object
	int feet, inch;

	// Constructor to initialize the object's value
	Distance(int f, int i)
	{
		this->feet = f;
		this->inch = i;
	}

	// Overloading(-) operator to perform decrement operation of Distance object
	void operator-()
	{
		feet=-feet;
		inch=-inch;
		cout << "\nFeet & Inches(Decrement): " << feet << "'" << inch;
	}
};

// Driver Code
int main()
{
	// Declare and Initialize the constructor
	Distance d1(8, 9);
	Distance d2(10,20);

	// Use (-) unary operator by single operand
	-d1;
	-d2;
	return 0;
}

