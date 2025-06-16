#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

double calculateArea(double length, double width)
{
    if (length <= 0 || width <= 0)
    {
        throw std::invalid_argument("Length and width must be greater than zero.");
    }
    return length * width;
}

int main()
{
    double length, width;

    try
    {
        cout << "Enter length of rectangle: ";
        cin >> length;
        cout << "Enter width of rectangle: ";
        cin >> width;

        double area = calculateArea(length, width);
        cout << "Area of rectangle: " << area << endl;
    }
    catch (const std::invalid_argument &e)
    {
        cout << "Invalid input: " << e.what() << endl;
        cout << "Using absolute values for calculation." << endl;

        // Extension part: calculate using absolute values
        double area = abs(length) * abs(width);
        cout << "Area of rectangle using absolute values: " << area << endl;
    }

    return 0;
}