//template class
#include <iostream>  
using namespace std;  
template<class T>  
class A   
{  
    public:  
//    T num1 = 11.2;  
//    T num2 = 20.5;  
    T num1 = 'a';  
    T num2 = 'b';
    void add()  
    {  
        cout<< "Addition of num1 and num2 : " << num1+num2<<endl;  
    }  
      
};  
  
int main()  
{  
    //A<int> d;  
    //A<float> d; 
    A<char> d; 
    d.add();  
    return 0;  
}  
