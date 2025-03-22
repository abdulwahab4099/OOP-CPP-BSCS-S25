/*
Assignment 2:

	Impliment the database program using file handling
	The functions include are
	>Add data
	>Display data
	>Modify data
	>Search data
	>Delete data
	>Sort data

*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
struct record
{
	int id;
	string name;
	float marks;
};

void add();
void display();
void modify(int);
void search(int);
void deletedata(int );
void sort();


int main()
{
	int choice, ID;
	do
	{
		cout<<"\nDatabase Menu:\n";
		cout<<"1. Add Data\n2. Display Data\n3. Modify Data\n4. Search Data\n5. Delete Data\n6. Sort Data\n7. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: add(); break;
			case 2: display(); break;
			case 3: 
			{
				cout<<"\nEnter ID to modify: "; 
			    cin>>ID; 
			    modify(ID); 
				break;
			}
				
			case 4:
			{
				cout<<"\nEnter ID to search: "; 
			    cin>>ID;
			    search(ID); 
				break;
			} 
			case 5:
			{
				cout<<"\nEnter ID to delete: "; 
			    cin>>ID;
			    deletedata(ID); 
				break;
			} 
			case 6: sort(); break;
			case 7: cout<<"\nExiting..."; break;
			default: cout<<"\nInvalid Input!";
			
		}
		
		
	} while (choice !=7);
	return 0;
}

/////////Function to add new record//////////
void add()
{
	ofstream file;
	file.open("database.txt", ios::app);
	record rec;
	cout<<"\nEnter ID:";
	cin>>rec.id;
	cout<<"\nEnter Name:";
	cin.ignore();
	getline(cin,rec.name);
	//cin>>rec.name;
	cout<<"\nEnter Marks:";
	cin>>rec.marks;
	file<<rec.id<<" "<<rec.name<<" "<<rec.marks<<endl;
	file.close();
	cout<<"Record added successfully!\n";
}

///////////Display function ////////////

void display()
{
	ifstream file;
	file.open("database.txt");
	record rec;
	cout<<"\nRecords in Database:\n";
	while(file>>rec.id>>rec.name>>rec.marks)
	{
		cout<<"ID:"<<rec.id <<", Name: "<<rec.name<<", Marks: "<<rec.marks<<endl;
	}
	file.close();
	
}

///////////Modify function ////////////

void modify(int search)
{
	ifstream file;
	file.open("database.txt");
	ofstream temp;
	temp.open("temp.txt");
	record rec;
	bool found=false;
	while(file>>rec.id>>rec.name>>rec.marks)
	{
		if(rec.id==search)
		{
			cout<<"\nEnter new Name:";
			cin.ignore();
			getline(cin,rec.name);
			//cin>>rec.name;
			cout<<"\nEnter new Marks:";
			cin>>rec.marks;
			found=true;
		}
		temp<<rec.id<<" "<<rec.name<<" "<<rec.marks<<endl;
	}
	
	file.close();
	temp.close();
	remove("database.txt");
	rename("temp.txt","database.txt");
	
	if(found)
	{
		cout<<"\nRecord updated successfully!";
		
	}
	else
	{
		cout<<"\nRecord not found!";
	}
}

///////////Search function ////////////
void search(int searchID)
{
	ifstream file;
	file.open("database.txt");
	record rec;
	bool found=false;
	while(file>>rec.id>>rec.name>>rec.marks)
	{
		if(rec.id==searchID)
		{
			cout<<"\nID:"<<rec.id<<", Name: "<<rec.name<<" Marks: "<<rec.marks<<endl;
			
			found=true;
			break;
		}
		
	}
	file.close();
	if(!found)
	{
		cout<<"\nRecord not found!\n";
	}
	
}

///////////Delete function ////////////
void deletedata(int deleteID)
{
	ifstream file;
	file.open("database.txt");
	ofstream temp;
	temp.open("temp.txt");
	record rec;
	bool found=false;
	
	while(file>>rec.id>>rec.name>>rec.marks)
	{
		if(rec.id==deleteID)
		{
			found=true;
			continue;
		}
		temp<<rec.id<<" "<<rec.name<<" "<<rec.marks<<endl;
	}
	file.close();
	temp.close();
	
	remove("database.txt");
	rename("temp.txt","database.txt");
	
	if(found)
	{
		cout<<"\nRecord deleted successfully!\n";
		
	}
	else
	{
		cout<<"\nRecord not found!";
	}
}

///////////Sort function ////////////

void sort()
{
	ifstream file;
	file.open("database.txt");
	record records[100];
	int count=0;
	while(file>>records[count].id>>records[count].name>>records[count].marks)
	{
		count++;
	} 
	file.close();
	
	//Bubble sort
	for(int i=0; i<count-1;i++)
	{
		for(int j=0;j<count-1;j++)
		{
			if(records[j].id>records[j+1].id)
			{
				swap(records[j],records[j+1]);
			}
		}
	}
	
	ofstream sortedFile;
	sortedFile.open("database.txt");
	for(int i=0;i<count;i++)
	{
		sortedFile<<records[i].id<<" "<<records[i].name<<" "<<records[i].marks<<endl;
	}
	sortedFile.close();
	cout<<"\nRecords sorted successfully!";
}
