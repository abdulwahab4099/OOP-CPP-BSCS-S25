#include <iostream>
using namespace std;
int main()
{
	void centimize(double* );
	double var=10.0;
	cout<<"Variable:"<<var<<" inches\n";
	centimize(&var);
	cout<<"Variable:"<<var<<" centimeters\n";
	
	return 0;
}
void centimize(double* ptr)
{
	*ptr *=2.54;
}