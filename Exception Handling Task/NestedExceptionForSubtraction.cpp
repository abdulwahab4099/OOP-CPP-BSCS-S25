/*
	Nested Exceptions for Subtraction

 Write a function int safeSubtract(int a, int b) that:
 • Returns a-b
 •Throws std::underflow_error if result is negative
 • In main(), use nested try-catch blocks:
–Inner block: Handle underflow error and return 0
–Outerblock: Handle other unexpected errors
 •Extension: If subtraction fails, return|a−b| instead
 
*/

#include <iostream>
#include <stdexcept>
using namespace std;

// Calculator class for safe subtraction
class Calculator 
{
	public:
	    // Function to subtract b from a with validation
	    int safeSubtract(int a, int b) 
		{
	        int result = a - b;
	        if (result < 0) 
			{
	            throw underflow_error("Error: Result is negative.");
	        }
	        return result;
	    }
};

int main() 
{
    int a, b;
    Calculator calc;

    while (true) 
	{
        // Get input for a
        cout << "Enter first number (a): ";
        cin >> a;
        if (cin.fail()) 
		{
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Enter a number." << endl;
            continue;
        }

        // Get input for b
        cout << "Enter second number (b): ";
        cin >> b;
        if (cin.fail()) 
		{
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Enter a number." << endl;
            continue;
        }

        try {
            // Outer try block for unexpected errors
            try {
                // Inner try block for underflow error
                int result = calc.safeSubtract(a, b);
                cout << a << " - " << b << " = " << result << endl;
                break; // Exit on success
            }
            catch (const underflow_error& e) 
			{
                // Handle negative result in inner block
                cout << e.what() << endl;
                // Fallback: return |a - b|
                int fallback = (a - b < 0) ? (b - a) : (a - b);
                cout << "Fallback: |" << a << " - " << b << "| = " << fallback << endl;
                break; // Exit after fallback
            }
        }
        catch (...) 
		{
            // Outer block catches unexpected errors
            cout << "An unexpected error occurred. Please try again." << endl;
        }
    }

    return 0;
}