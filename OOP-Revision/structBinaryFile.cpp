#include <iostream>
#include <fstream>

using namespace std;
struct Car 
{ 
	int reg_id; char color[30]; char owner_name[30];
};
Car c;

int main()
{
	fstream f1,f2;
	f1.open("A.rec", ios::out | ios::binary);
	f2.open("B.rec", ios::out | ios::binary);
	
	if(f1)
	{
		for(int i=0;i<3;i++)
		{
			cout<<"\nEnter Registration ID:"; cin>>c.reg_id;
			cout<<"\nEnter Color of Car:"; cin>>c.color;
			cout<<"\nEnter Owner name:"; cin>>c.owner_name;
		}
		f1.write((char*)&c,sizeof(Car));
	}
	else
	{
		cout<<"Error with file opening!!";
	}
	f1.close();
}