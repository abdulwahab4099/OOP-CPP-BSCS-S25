#include <iostream>
using namespace std;

class A {
public:
	int a;
	A() // constructor
	{
		a = 10;
	}
	
	void show()
	{
		cout<<"\nFrom A.";
	}
};

class B : public virtual A {
};

class C : public virtual A {
};

class D : public B, public C {
};

int main()
{
	D object; // object creation of class d
	cout << "a = " << object.a << endl;
	object.show();

	return 0;
}

