#include <iostream>
using namespace std;

// Lab Task 2: Circle Class
class Circle {
private:
    double radius; // Stores radius of the circle
public:
    Circle() : radius(0.0) {} // Default constructor
    Circle(double r) : radius(r) {} // Parameterized constructor
    double calculateArea() { return 3.14 * radius * radius; } // Calculate area
    double calculateCircumference() { return 2 * 3.14 * radius; } // Calculate circumference
};

int main() {
    // Testing Circle class
    Circle c1; // Default constructor
    Circle c2(5.0); // Parameterized constructor with radius 5.0
    
    cout << "Circle 1 Area: " << c1.calculateArea() << ", Circumference: " << c1.calculateCircumference() << endl;
    cout << "Circle 2 Area: " << c2.calculateArea() << ", Circumference: " << c2.calculateCircumference() << endl;
    
    return 0;
}

