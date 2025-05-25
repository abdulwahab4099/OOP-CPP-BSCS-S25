/*
	struct vehicle 
	{ 
	int reg_id ;  char owner_name [30] ; char owner_gender [15];   
	}; vehicle V;   
structure definition is given above. 
[6] 
  
Create two binary files, vehicle1.rec and vehicle2.rec 
Store at least 20 records on each file. After the record has been 
successfully written, create another binary file combine.rec 
Now write “those records from file vehicle1.rec and 
vehicle2.rec whose owner names ends with character S  and owner gender is female” on file combine.rec 
In addition, display records of file combine.rec on monitor. 
*/


#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

struct vehicle 
	{ 
		int reg_id ;  
		char owner_name [30] ;
		char owner_gender [15];   
	}; vehicle V;

int main()
{
	string line;
	fstream f1,f2,f3;
	f1.open("vehicle1.rec", ios::out | ios::binary);
	f2.open("vehicle2.rec", ios::out | ios::binary);
	if(!f1)
	{
		cout<<"\nError in opening file 1 !";
	}
	if(!f2)
	{
		cout<<"\nError in opening file 2 !";
	}
	cout<<"\nWriting data in file 'vehicle1.rec':";
	if(f1)
	{
		for(int i=0;i<2;i++)
		{
			
			cin.ignore();
			cout<<"\nEnter Registration ID for record "<<i+1<<" :";
			cin>>V.reg_id;
			cin.ignore();
			cout<<"\nEnter owner name for record "<<i+1<<" :";
			gets(V.owner_name);
			
			cin.ignore();
			cout<<"\nEnter owner gender for record "<<i+1<<" :";
			gets(V.owner_gender);
			
			
			f1.write((char*)&V,sizeof(V));
			
		}
	}
	cout<<"\nData written to file vehicle1.rec.";
	cout<<"\nWriting data in file 'vehicle2.rec':";
	if(f2)
	{
		for(int i=0;i<2;i++)
		{
			
			cin.ignore();
			cout<<"\nEnter Registration ID for record "<<i+1<<" :";
			cin>>V.reg_id;
			cin.ignore();
			cout<<"\nEnter owner name for record "<<i+1<<" :";
			gets(V.owner_name);
			
			cin.ignore();
			cout<<"\nEnter owner gender for record "<<i+1<<" :";
			gets(V.owner_gender);
			
			
			f2.write((char*)&V,sizeof(V));
			
		}
	}
	cout<<"\nData written to file vehicle2.rec.";
	
	f1.close();
	f2.close();
	
	f1.open("vehicle1.rec",ios::in );
	f2.open("vehicle2.rec",ios::in );
	f3.open("combine.rec",ios::out | ios::in |ios::binary );
	if(!f3)
	{
		cout<<"\nError in opening file 'combine.rec' !";
	
	}
	int a;
	cout<<"\nWriting data to file 'combine.rec'"
	if(f3)
	{
		while(f1.read((char*)&V,sizeof(V)))
		{
			
			a=strlen(V.owner_name)	;
			if(V.owner_name[a-1]=='s')
			{
				if(V.owner_gender=="female" || V.owner_gender=="Female" || V.owner_gender=="FEMALE")
				{
					f3.write((char*)&V, sizeof(V));
				}
			}		
		}
		while(f2.read((char*)&V,sizeof(V)))
		{
		
			a=strlen(V.owner_name)	;
			if(V.owner_name[a-1]=='s')
			{
				if(V.owner_gender=="female" || V.owner_gender=="Female" || V.owner_gender=="FEMALE")
				{
					f3.write((char*)&V, sizeof(V));
				}
			}		
		}
		cout<<"\nData written in file 'combine.rec':";
		while(f3.read((char*)&V,sizeof(V)))
		{
			cout<<"\nRegistration ID: "<<V.reg_id<<"\t Owner Name: "<<V.owner_name<<"\t Owner Gender: "<<V.owner_gender;
		}
	}
	
	f1.close();
	f2.close();
	f3.close();
	
}