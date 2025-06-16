
/*
Question1: 

Write a menu driven program in C++ that will do the following tasks 

A. Define a structure to store employee information (e.g., emp_ID, emp_name, emp_salary). Write a 
	program to create a binary file and store multiple employee records into it. 
B. Write a function find() to search for an employee record in a binary file based on the employee ID.  
C. Write a function Modify() to update an employee record in a binary file. 
D. Write a function Insert() to insert a new record at a specific position in a binary file. 
E. Write a function delete() to delete a record from a binary file based on a specific criterion (e.g., 
	employee ID). 
F. Write a function sort() to sort the records in a binary file based on a specific field (e.g., employee 
	salary). 
G. Note: use appropriate stream/ file handling parameter or other parameter where needed. 
*/


#include<iostream>
#include<string>
#include<cstring>
#include<fstream>

using namespace std;
int n=5;  //number of records

struct employee
{
    int emp_id;
    char emp_name[50];
    double salary;
};


void find(fstream& file);
void modify(fstream& file);
void insert(fstream &file);
void del(fstream &file);
void sort(fstream &file);
void display(fstream &file);
void store_record(fstream &file);

int main()
{
    fstream file;
    file.open("task.dat",ios::binary|ios::out);
    if(!file)
    {
        cout<<"Error in opening of file check path of file according to your pc \n ";
    }
    else 
    {
        store_record(file);
    }
    file.close();
    file.open("task.dat",ios::binary|ios::in);
    if(!file)
    {
        cout<<"File cannot be opened for reading mode \n ";
    }
    else 
    {
        display(file);

    }
    file.close();


bool check=1;
int num;


cout<<"If there is error in opening of above file please exit and check file path \n \n \n ";
do
{  
  
  cout<<"1:To find specific records from file\n2:To modify record on file\n3:To delete record from file\n4:To sort records on file\n5:To insert record on specific place\n6:To display records\n7:To exit \nEnter your choice = ";
  cin>>num;

  if(num==1)
  {
    file.open("task.dat",ios::binary|ios::in);
    if(!file)
    {
        cout<<"Error in opening of file please check file path and run again \n ";
    }
    else
    {
        find(file);
    }
    file.close();
  }
  else if(num==2)
  {
    file.open("task.dat",ios::binary|ios::in|ios::out);
    if(!file)
    {
        cout<<"Error in opening of file please check file path and run again \n ";
    }
    else
    {
        modify(file);

        file.close();
    }
    
  }

  else if(num==3)
  {
    file.open("task.dat",ios::binary|ios::in);
    if(!file)
    {
       cout<<"Error in opening of file please check file path and run again \n "; 
    }
    else
    {
        del(file);
    }
    file.close();
  }

  else if(num==4)
  {
    file.open("task.dat",ios::binary|ios::in|ios::out);
    if(!file)
    {
        cout<<"Error in opening of file \n";
    }
    else
    {
        sort(file);
    }
    file.close();
  }


else if(num==5)
{
    file.open("task.dat",ios::binary|ios::in|ios::out);
    if(!file)
    {
        cout<<"Error in opening file \n";
    }
    else
    {
        insert(file);
    }
    file.close();
}
else if(num==6)
  {
    file.open("task.dat",ios::binary|ios::in);
    if(!file)
    {
        cout<<"Error in opening of file please check file path and run again \n ";
    }
    else
    {
        display(file);
    }
    file.close();
  }
else if(num==7)
{
    check=0;
}
else
{
    cout<<"Please Enter valid choice \n ";
}


} while (check);

}



void store_record(fstream &file)
{
employee emp[n]={
                  {1,"",50000},
                  {2,"",30000},
                  {3,"",10000},
                  {4,"",60000},
                  {5,"",450000}
                 };
               
                 strcpy(emp[0].emp_name,"Abdul Wahab");
                 strcpy(emp[1].emp_name,"Babar Azam");
                 strcpy(emp[2].emp_name,"Imran Khan");
                 strcpy(emp[3].emp_name,"Zubair Anjum");
                 strcpy(emp[4].emp_name,"Muhammad Umair");



  for(int i=0;i<n;i++)
  {
    file.write((char*)&emp[i],sizeof(emp[i]));
  }               
}


void display(fstream &file)
{
    employee emp;
    while(file.read((char*)&emp,sizeof(emp)))
    {
    cout<<emp.emp_id<<"\t"<<emp.emp_name<<"\t"<<emp.salary<<endl;
    }
}

void find(fstream& file)
{
    int id;
    bool found=0 ;
    employee emp;
    cout<<"Enter id to find record = ";
    cin>>id;
    while(file.read((char*)&emp,sizeof(emp)))
    {
        if(id==emp.emp_id)
        {
            cout<<emp.emp_id<<"\t"<<emp.emp_name<<"\t"<<emp.salary<<endl;
            found=1;
            break;
        }
    }
    if(found)
    {
        cout<<"Record has been found and displayed \n ";
    }
    else
    {
        cout<<"Sorry record cannot be found \n";
    }
}



void modify(fstream& file)
{
    employee emp;
int id;

int position;
bool found=0;
cout<<"Enter employee id to modify records = ";
cin>>id;
while(file.read((char*)&emp,sizeof(emp)))
{
      if(id==emp.emp_id)
      {
        position=file.tellg();
        cout<<"Enter name of employ = ";
        cin.ignore();
        cin.getline(emp.emp_name,50);
        cout<<"Enter id of employee = ";
        cin>>emp.emp_id;
        cout<<"Enter salary of employee = ";
        cin>>emp.salary;
        int t=position-sizeof(emp);
        file.seekp(t,ios::beg);
        file.write((char*)&emp,sizeof(emp));
        found =1;
        break;
       
      }
}

if(found)
{
    cout<<"Records has been modified \n";

}
else
{
    cout<<"Sorry record cannot be found in file \n";
}

}


 void del(fstream &file)
 {
    employee emp;
    fstream temp;
    int id;
    bool found=0;
    cout<<"Enter id of employee to delete record = ";
    cin>>id;
    temp.open("temp.dat",ios::binary|ios::out);
    if(!temp)
    {
        cout<<"Error in opening file check again \n";
    }
    else
    {
        while(file.read((char*)&emp,sizeof(emp)))
        {
            if(id!=emp.emp_id)
            {
                temp.write((char*)&emp,sizeof(emp));
            }
            else
            {
                found=1;
            }
        }

    }

    if(found)
    {
        file.close();
        temp.close();
        remove("task.dat");
        rename("temp.dat","F:\\OOP Program\\After Git Hub\\task.dat");
        cout<<"Record deleted from file successfully \n ";
        n--;

    }
    else
    {
        cout<<"Record cannot be found in file \n ";
    }
 }


 void sort(fstream &file)
 {
    employee emp;
    employee *ar;
    ar=new employee[n];
    int i=0;
    while(file.read((char*)&emp,sizeof(emp)))
    {
       strcpy(ar[i].emp_name,emp.emp_name);
       ar[i].emp_id=emp.emp_id;
       ar[i].salary=emp.salary;
       i++;    
    }
    employee temp;
    for(int j=0; j<i-1;j++)
    {
        for(int k=0;k<i-1-j;k++)
        {
            if(ar[k].salary>ar[k+1].salary)
            {
                temp=ar[k];
                ar[k]=ar[k+1];
                ar[k+1]=temp;

            }
        }
    }

    file.clear();
    file.seekp(0,ios::beg);
    for(int j=0;j<i;j++)
    {
        file.write((char*)&ar[j],sizeof(ar[j]));
    }
 }

 void insert(fstream &file)
 {
     employee emp;
    fstream temp;
    int pos;
    int current=1;
    bool found=0;
    cout<<"Enter position to add record = ";
    cin>>pos;
    if(pos>1&pos<n+1)
    {
    temp.open("temp.dat",ios::binary|ios::out);
    if(!temp)
    {
        cout<<"Error in opening file check again \n";
    }
    else
    {
        while(file.read((char*)&emp,sizeof(emp)))
        {
        
            if(pos==current)
            {
                employee emp1;
            	cout<<"Enter Name of employee = ";
            	cin.ignore();
            	cin.getline(emp1.emp_name,50);
            	cout<<"Enter id of employee = ";
            	cin>>emp1.emp_id;
            	cout<<"Enter salary of employee = ";
            	cin>>emp1.salary;
                temp.write((char*)&emp1,sizeof(emp1));

                  found=1;
            }
            	temp.write((char*)&emp,sizeof(emp));
              
            
            current++;
        }

    }

    if(found)
    {
        file.close();
        temp.close();
        remove("task.dat");
        rename("temp.dat","task.dat");
        cout<<"Record inserted from file successfully \n ";
        n++;

	}
}
else
{
	cout<<"Your enterd position is incorrect \n";
     temp.close();
}
    
}