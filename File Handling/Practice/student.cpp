#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int size=3;

struct Student
{
	string name;
	char grade;
};

int main()
{
	string n;
	char c;
	Student student[size];
	fstream f;
	f.open("Student.txt", ios::in | ios::out |ios::trunc);
	if(f)
	{
		for(int i=0;i<size;i++)
		{
			cout<<"\nEnter name of student"<<i+1<<" :";
			cin.ignore();
			cin>>student[i].name;
			n=student[i].name;
			f<<n;
			cout<<"\tEnter grade of student"<<i+1<<" :";
			cin>>student[i].grade;
			c=student[i].grade;
			f<<"\t"<<c<<"\n";
		}
		
	}
	
	
	f.close();
}