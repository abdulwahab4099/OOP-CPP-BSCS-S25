#include <iostream>
using namespace std;


class MyClass {
public:
    bool value;

    MyClass(bool value) : value(value) {}

    bool operator!() {
        return !value;
    }
};

int main() {
    MyClass obj1(true);
    MyClass obj2(false);

    cout << "!obj1: " << !obj1.value << endl; // Output: !obj1: false
    cout << "!obj2: " << !obj2.value << endl; // Output: !obj2: true

    return 0;
}
