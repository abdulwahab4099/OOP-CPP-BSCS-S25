/*

 Q1. Abstract Class and Pure Virtual Function
 
 
 Define an abstract class Shape that contains a pure virtual function double area().
 Then, implement two classes Circle and Rectangle that inherit from Shape. Each class
 should override the area() function and return the correct result.
 • For Circle, accept radius and calculate area using the formula πr2.
 • For Rectangle, accept length and width and calculate area.
 • Create objects of both types in main() and display the computed areas.
 
 
*/

#include <iostream>
#include <cmath>
using namespace std;
class shape
{
	public:
    // Pure virtual function
    virtual double area() const = 0;
    // Virtual destructor
    virtual ~shape() {}
    
};

// circle class inherits from Shape
class circle : public shape {
private:
    double radius;

public:
    circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }
};

// rectangle class inherits from Shape
class rectangle : public shape 
{
private:
    double length, width;

public:
    rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }
};


// Main function
int main() {
    circle c(5.0);          // radius = 5
    rectangle r(4.0, 6.0);  // length = 4, width = 6

    cout << "Area of Circle: " << c.area() << endl;
    cout << "Area of Rectangle: " << r.area() << endl;

    return 0;
}
