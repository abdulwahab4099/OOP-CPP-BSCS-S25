// CPP Program to demonstrate the relation between
// Inheritance and Friendship
// friend function is not inherited
#include <iostream>
using namespace std;

// Parent Class
class A 
{
protected:
	int x;

public:
	A() { x = 0; }
	friend void show();
};

// Child Class
class B : public A {
private:
	int y;

public:
	B() { y = 0; }
};

void show()
{
	B b;
	cout << "The default value of A::x = " << b.x;

	// Can't access private member declared in class 'B'
	cout << "The default value of B::y = " << b.y;
}

int main()
{
	show();
	getchar();
	return 0;
}

