#include <iostream> 
#include <conio.h> 
#include <cstring>
#include <string>
     using namespace std;  
     template<class T1, class T2>  
    class A   
    {  
         T1 a;  
         T2 b;  
         public:  
        A(T1 x,T2 y)  
       {  
           a = x;  
           b = y;  
        }  
           void display()  
          {  
                 std::cout << "Values of a and b are : " << a<<" ,"<<b<<std::endl;  
           }  
      };  
  
      int main()  
     {  
           A<int,float> d(5,6.5);  
           d.display(); 
		   
		   A<int,int> g(5,5) ;
            
           g.display();
           
           A<char,char> c('n','o');
           c.display();
           
           A<string, string> s("Abdul","Wahab");
           s.display();
           
        return 0;
     }  
