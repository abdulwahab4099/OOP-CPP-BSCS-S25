/*
		Area of Rectangle with Standard Exception

 Write a function double calculateArea(double length, double width) that:
 • Computes area (length ×width)
 • Throws std::invalid_argument if either input ≤ 0
 • In main(), handle the exception and prompt for valid inputs
 • Extension: If inputs are invalid, compute area using absolute values (|length|×|width|)


*/

#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

class Rectangle 
{
	public:
	    double calculateArea(double length, double width) {
	        if (length <= 0 || width <= 0) 
			{
	            cout << "Warning: Invalid input. Using fallback with absolute values.\n";
	            return abs(length) * abs(width);
	        }
	        return length * width;
	    }
};

int main() 
{
    double length, width;
    Rectangle rect;

    while (true) 
	{
        cout << "Enter length: ";
        cin >> length;
        if (cin.fail()) 
		{
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Enter a valid number.\n";
            continue;
        }

        cout << "Enter width: ";
        cin >> width;
        if (cin.fail()) 
		{
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Enter a valid number.\n";
            continue;
        }

        try 
		{
            if (length <= 0 || width <= 0)
                throw invalid_argument("Error: Dimensions must be positive.");

            double area = rect.calculateArea(length, width);
            cout << "Area: " << area << endl;
            break;
        } catch (const invalid_argument& e) 
		{
            cout << e.what() << endl;
            double area = rect.calculateArea(length, width);  // fallback inside method
            cout << "Fallback Area: " << area << endl;
            break; // or continue if you want retry
        }
    }

    return 0;
}
