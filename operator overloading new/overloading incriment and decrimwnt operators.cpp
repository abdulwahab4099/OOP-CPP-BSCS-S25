#include <iostream>
using namespace std;
class Counter {
private:
    int value;
public:
    Counter(int value = 0) : value(value) {}

    // Prefix increment
    Counter& operator++() {
        ++value;
        return *this;
    }

    // Postfix increment
    Counter operator++(int) {
        Counter temp = *this;
        ++value;
        return temp;
    }

    // Prefix decrement
    Counter& operator--() {
        --value;
        return *this;
    }

    // Postfix decrement
    Counter operator--(int) {
        Counter temp = *this;
        --value;
        return temp;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    Counter c1(5);
    cout << "Initial value: " << c1.getValue() << endl; // Output: 5

    Counter c2 = ++c1;
   cout << "Prefix increment: " << c1.getValue() << " " << c2.getValue() << endl; // Output: 6 6

    Counter c3 = c1++;
    cout << "Postfix increment: " << c1.getValue() << " " << c3.getValue() << endl; // Output: 7 6

    Counter c4 = --c1;
    cout << "Prefix decrement: " << c1.getValue() << " " << c4.getValue() << endl; // Output: 6 6

    Counter c5 = c1--;
    cout << "Postfix decrement: " << c1.getValue() << " " << c5.getValue() << endl; // Output: 5 6

    return 0;
}
