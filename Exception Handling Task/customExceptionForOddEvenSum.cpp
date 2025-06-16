/*
	Custom Exception for Odd-Even Sum

 Define a custom exception OddNumberException(inheritingfromstd::exception)
 with message "Oddnumbers notallowed!". Write a function int
 sumEvenNumbers (inta, intb) that:
 •Returns a+b only if both numbers are even
 •Throws OddNumberException if either number is odd
 • In main(),handle the exception and print the sum of absolute values as fallback
*/

#include <iostream>
#include <stdexcept>
using namespace std;

// Custom exception class for odd numbers
class OddNumberException : public std::exception {
public:
    // Override what() to provide error message
    const char* what() const noexcept override {
        return "Odd numbers not allowed!";
    }
};

// Calculator class for summing even numbers
class Calculator {
public:
    // Function to sum two numbers if both are even
    int sumEvenNumbers(int a, int b) {
        if (a % 2 != 0 || b % 2 != 0) {
            throw OddNumberException();
        }
        return a + b;
    }
};

int main() {
    int a, b;
    Calculator calc;

    while (true) {
        // Get input for a
        cout << "Enter first number (a): ";
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Enter a number." << endl;
            continue;
        }

        // Get input for b
        cout << "Enter second number (b): ";
        cin >> b;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Enter a number." << endl;
            continue;
        }

        try {
            // Attempt to sum even numbers
            int sum = calc.sumEvenNumbers(a, b);
            cout << "Sum of " << a << " + " << b << " = " << sum << endl;
            break; // Exit on success
        }
        catch (const OddNumberException& e) {
            // Handle odd number exception
            cout << e.what() << endl;
            // Fallback: sum absolute values
            int abs_a = (a < 0) ? -a : a;
            int abs_b = (b < 0) ? -b : b;
            int fallback_sum = abs_a + abs_b;
            cout << "Fallback sum (|a| + |b|): " << fallback_sum << endl;
            // Continue to retry
        }
        catch (...) {
            // Catch any unexpected errors
            cout << "An unexpected error occurred. Please try again." << endl;
        }
    }

    return 0;
}