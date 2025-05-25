#include <iostream>
using namespace std;
int main()
{
	void centimize(double* );
	double var=10.0;
	cout<<"Variable:"<<var<<" inches\n";
	double *ptr = &var;
	centimize(ptr);
	cout<<"Variable:"<<var<<" centimeters\n";
	
	return 0;
}
void centimize(double* ptr1)
{
	*ptr1 *=2.54;
}