#include <iostream>
using namespace std;
class T_ONE {
   public: int n1;
};
 
class T_TWO : virtual public T_ONE {
   public: int n2;
};
 
class T_THREE : virtual public T_ONE {
   public: int n3;
};
 
class T_FOUR : public T_TWO, public T_THREE {
   public: int n4;
};
int main() {
   T_FOUR obj;
   //obj.n1 = 40; 
   obj.n1 = 30; 
   obj.n2 = 60;
   obj.n3 = 70;
   obj.n4 = 80;
   cout<< " T_ONE : "<< obj.n1;	
   cout<< " T_TWO : "<< obj.n2;
   cout<< " T_THREE: "<< obj.n3;
   cout<< " T_FOUR: "<< obj.n4;
}
