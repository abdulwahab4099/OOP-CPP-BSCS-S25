/*
Question2:
 
Define a structure to store student information (e.g., st_ID, st_name, st_averageMarks). Write a program 
to create a binary file stu.dat and store multiple student records into it. Suppose the grading criteria is as 
follows :

averageMarks      
Greater than or equal to 80     
Greater than or equal to 60 but less than 80  
Greater than or equal to 50 but less than 60  
Less than 50       
Grade 
A 
B 
C 
F 

Now create a separate file gradeA.dat, and store only those student records on that file who got A grade 
also find how many students got A grade.   Similarly 
create separate files gradeB.dat, gradeC.dat, and gradeF.dat and store only those student records  on 
those file who got B grade, C grade and F grade also find how many students got B grade, C grade and F 
grade. 
Also display data of gradeF.dat file on the monitor as well.
*/





#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<conio.h>


using namespace std;
int n=10;
struct student 
{
    int st_id;
    char st_name[50];
    float st_avgMarks;
};

void store_record(fstream &file);


int main()
{
    student st;
   fstream file;
   int a,b,c,f;
   a=b=c=f=0;
   file.open("stu.dat",ios::binary|ios::out);
   if(!file)
   {
    cout<<"Sorry! File cannot be opened check file path and try again \n";
   }
   else
   {
     store_record(file);
     cout<<"Records stored on file successfully \n";
   }
   file.close();
    fstream A,B,C,F;
    file.open("stu.dat",ios::binary|ios::in);
    if(!file)
    {
        cout<<"check opening of file in reading mode \n";
    }
    A.open("gradeA.dat",ios::binary|ios::out);
    if(!A)
    {
        cout<<"GradeA file cannot be opened check path \n";
    }
    else
    {
        cout<<"GradeA.dat opened \n";
    }
    B.open("gradeB.dat",ios::binary|ios::out);
    if(!B)
    {
        cout<<"Grade B file cannot be opened \n";
    }
    else
    {
        cout<<"GradeB.dat opened \n ";
    }
    C.open("gradeC.dat",ios::binary|ios::out);
    if(!C)
    {
        cout<<"GradeC.dat cannot be opened \n ";
    }
    else
    {
        cout<<"GradeC.dat opened \n";
    }
    F.open("gradeF.dat",ios::binary|ios::out);
    if(!F)
    {
        cout<<"GradeF.dat cannot be opened \n";

    }
    else
    {
        cout<<"GradeF.dat opened successfully \n";
    }
   cout<<"If  GradeA.dat ,  GradeB.dat  , GradeC.dat ,  GradeF.dat are opened successfully press 'Enter' to continue otherwise exit program and check Error in opening of these files \n ";
   getch();
   while(file.read((char*)&st,sizeof(st)))
   {
      if(st.st_avgMarks>=80)
      {
        A.write((char*)&st,sizeof(st));
        a++;
      }
      else if(st.st_avgMarks>=60)
      {
        B.write((char*)&st,sizeof(st));
        b++;
      }
      else if(st.st_avgMarks>=50)
      {
        C.write((char*)&st,sizeof(st));
        c++;
      }
      else
      {
        F.write((char*)&st,sizeof(st));
        f++;
      }
   }

   cout<<"Number of students who got A grade = "<<a<<endl;
   cout<<"Number of students who got B Grade = "<<b<<endl;
   cout<<"Number of students who got C Grade = "<<c<<endl;
   cout<<"Number of student who got F Grade = "<<f<<endl;
   A.close();
   B.close();
   C.close();
   F.close();

   F.open("gradeF.dat",ios::binary|ios::in);
   if(!F)
   {
    cout<<"Sorry GradeF.dat cannot be opened in reading mode \n ";
   }
   else
   {
    while(F.read((char*)&st,sizeof(st)))
    {
        cout<<st.st_id<<"\t"<<st.st_name<<"\t"<<st.st_avgMarks<<endl;
    }
   }
   F.close();
   return 0;

   }




void store_record(fstream &file)
{
    student st[n] ={
                      {1,"",45},
                      {2,"",89},
                      {3,"",68},
                      {4,"",23},
                      {5,"",70},
                      {6,"",61},
                      {7,"",58},
                      {8,"",48},
                      {9,"",55},
                      {10,"",36}
                     };
    strcpy(st[0].st_name,"Abdul Wahab");
    strcpy(st[1].st_name,"Abdul Raheem");
    strcpy(st[2].st_name,"Muhammad Wahaj");
    strcpy(st[3].st_name,"Zubair Anjum");
    strcpy(st[4].st_name,"Umair Lateef");
    strcpy(st[5].st_name,"Muhammad KaramDad");
    strcpy(st[6].st_name,"Ahmad Akhlaq");
    strcpy(st[7].st_name,"Mahnoor");
    strcpy(st[8].st_name,"Babar Azam");
    strcpy(st[9].st_name,"Amna AbaidUllah");

    for(int j=0;j<n;j++)
    {
        file.write((char*)&st[j],sizeof(st[j]));
    }


}