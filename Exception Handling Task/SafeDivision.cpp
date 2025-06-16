/*
		1. Safe Division with Built-in Exception

Write a function double divide(int a, int b) that:
 • Returns a/ b
 • Throwsaconst char*exception if b = 0(e.g., "Error: Division by zero!")
 • In main(), call this function inside a try-catch block and print the result or
 error
 • Extension: If division fails, return a/(b+1) as a fallback

*/

#include <iostream>
#include <stdexcept>  // for std::runtime_error
using namespace std;

class Calculator 
{
	public:
	    double divide(int a, int b) 
		{
	        if (b == 0) 
			{
	            // Fallback logic inside the function
	            if (b + 1 == 0) 
				{
	                throw runtime_error("Error: Division by zero and fallback also invalid.");
	            } 
				else 
				{
	                cout << "Warning: Division by zero. Applying fallback (b + 1).\n";
	                return (double)a / (b + 1);
	            }
	        }
	        return (double)a / b;
	    }
};

int main() 
{
    int a, b;
    Calculator calc;

    while (true) 
	{
        cout << "Enter numerator (a): ";
        cin >> a;
        if (cin.fail()) 
		{
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Enter a number.\n";
            continue;
        }

        cout << "Enter denominator (b): ";
        cin >> b;
        if (cin.fail()) 
		{
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Enter a number.\n";
            continue;
        }

        try 
		{
            double result = calc.divide(a, b);
            cout << "Result: " << result << endl;
            break;
        } 
		catch (const exception& e) 
		{
            cout << "Exception caught: " << e.what() << endl;
            // Let user retry
        }
    }

    return 0;
}
