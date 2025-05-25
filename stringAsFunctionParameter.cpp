#include <iostream>
using namespace std;
int main()
{
	void displaystr(char*);
	
	char str[]="Today is Sunday.";
	displaystr(str);
}

void displaystr(char* ps)
{
	while(*ps)
	{
		cout<<*ps++<<endl;
	}
}