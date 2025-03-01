/*
Lab Task
Function with default arguments
*/

#include <iostream>
#include <new>
#include <string>
#include <cstring>
using namespace std;

//void nam(string name){
//	cout<<"name is ::"<<name;
//}
//
//int main(){
//	nam("abbas");
//	nam("xyzz");
//}
void printStudentDetails (char name[], int rollNo=0, char grade='N', double marks=0.0 );
void printStudentDetails (char name[], int rollNo , char grade, double marks)
{
	cout<<"Name of the student:"<<name;
	cout<<"\nStudent Roll No:"<<rollNo;
	cout<<"\nStudent Grade:"<<grade;
	cout<<"\nStudent marks:"<<marks;
}
int main()
{
	double marks;
	int rollNo;
	char grade;
	char name[50];
	
	cout<<"Enter name of the student:";
	cin.getline(name,50);
	
	//cout<<"\nEnter Roll Number:";
	//cin>>rollNo;
	
	//cout<<"\nEnter grade:";
	//cin>>grade;
	
	//cout<<"\nEnter marks:";
	//cin>>marks;
	printStudentDetails(name);
	
	return 0;
}

