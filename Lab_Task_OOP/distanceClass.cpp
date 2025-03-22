#include <iostream>
using namespace std;

// Lab Task 1: Distance Class
class Distance {
private:
    int feet; // Stores feet part of distance
    double inches; // Stores inches part of distance

    // Ensures inches are less than 12 and adjusts feet accordingly
    void simplify() {
        if (inches >= 12) {
            feet += static_cast<int>(inches) / 12;
            inches = static_cast<int>(inches) % 12 + (inches - static_cast<int>(inches));
        }
    }

public:
    Distance() : feet(0), inches(0.0) {} // Default constructor
    Distance(int f, double i) : feet(f), inches(i) { simplify(); } // Parameterized constructor
    Distance(double totalFeet) : feet(static_cast<int>(totalFeet)), inches((totalFeet - feet) * 12) {} // Conversion constructor

    double toTotalInches() { return feet * 12 + inches; } // Convert distance to inches
    void addDistance(Distance other) { // Add another distance
        feet += other.feet;
        inches += other.inches;
        simplify();
    }
    void display() { cout << feet << " feet and " << inches << " inches" << endl; } // Display distance
};

int main() {
    // Testing Distance class
    Distance d1;
    Distance d2(3, 15);
    Distance d3(4.5);
    cout << "Total inches of d1: " << d1.toTotalInches() << endl;
    cout << "Total inches of d2: " << d2.toTotalInches() << endl;
    d2.addDistance(d3);
    d2.display();
    return 0;
}

