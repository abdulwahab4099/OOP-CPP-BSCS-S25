#include <iostream>
using namespace std;

// Lab Task 4: Box Class
class Box {
private:
    double length, width, height; // Stores dimensions of the box
public:
    Box() : length(0.0), width(0.0), height(0.0) {} // Default constructor
    Box(double l, double w, double h) : length(l), width(w), height(h) {} // Parameterized constructor
    double calculateVolume() { return length * width * height; } // Calculate volume
    double calculateSurfaceArea() { return 2 * (length * width + width * height + height * length); } // Calculate surface area
};

int main() {
    // Testing Box class
    Box b1; // Default constructor
    Box b2(2.0, 3.0, 4.0); // Parameterized constructor with dimensions 2.0 x 3.0 x 4.0
    
    cout << "Box 1 Volume: " << b1.calculateVolume() << ", Surface Area: " << b1.calculateSurfaceArea() << endl;
    cout << "Box 2 Volume: " << b2.calculateVolume() << ", Surface Area: " << b2.calculateSurfaceArea() << endl;
    
    return 0;
}

