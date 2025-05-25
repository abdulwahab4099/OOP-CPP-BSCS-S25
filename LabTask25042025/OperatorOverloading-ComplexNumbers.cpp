/*
 Q3. Operator Overloading– Complex Numbers
 
 Write a class Complex with real and imaginary parts as data members.
 Overload the following operators:
• +to add two complex numbers
 •-to subtract one complex number from another
 • *to multiply two complex numbers
 Create two objects of Complex, take input for each, and display the results of the three
 operations.
*/


#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Input function
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    // Display function
    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i" << endl;
    }

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload * operator
    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }
};

// Main function
int main() {
    Complex c1, c2;

    cout << "Enter first complex number:\n";
    c1.input();

    cout << "\nEnter second complex number:\n";
    c2.input();

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    cout << "\nSum: ";
    sum.display();

    cout << "Difference: ";
    diff.display();

    cout << "Product: ";
    prod.display();

    return 0;
}
