// CPP code to illustrate using structure
#include <bits/stdc++.h>
using namespace std;

// creating structure mystruct
struct mystruct  {int x;	int y;	char c;	bool b;};
int main()
{	mystruct s;
	s.x = 5;
	s.y = 10;
	s.c = 'a';
	s.b = true;
	// data type must be same during casting as that of original
	// converting the pointer of 's' to, pointer of int type in 'p'.
	int* p = reinterpret_cast<int*>(&s);
	cout << *p << endl;
	p++;
	cout << *p << endl;
	p++;
	char* ch = reinterpret_cast<char*>(p);
	cout << *ch << endl;
	ch++;
	bool* n = reinterpret_cast<bool*>(ch);
	cout << *n << endl;
	cout << *(reinterpret_cast<bool*>(ch));
	return 0;
}

