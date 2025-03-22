#include <iostream>
using namespace std;

// Lab Task 3: Rectangle Class
class Rectangle {
private:
    double length, width; // Stores length and width of the rectangle
public:
    Rectangle() : length(0.0), width(0.0) {} // Default constructor
    Rectangle(double l, double w) : length(l), width(w) {} // Parameterized constructor
    double calculateArea() { return length * width; } // Calculate area
    double calculatePerimeter() { return 2 * (length + width); } // Calculate perimeter
};

int main() {
    // Testing Rectangle class
    Rectangle r1; // Default constructor
    Rectangle r2(4.0, 3.0); // Parameterized constructor with length 4.0 and width 3.0
    
    cout << "Rectangle 1 Area: " << r1.calculateArea() << ", Perimeter: " << r1.calculatePerimeter() << endl;
    cout << "Rectangle 2 Area: " << r2.calculateArea() << ", Perimeter: " << r2.calculatePerimeter() << endl;
    
    return 0;
}

