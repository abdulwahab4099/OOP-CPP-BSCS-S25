#include <iostream>
#include <cmath>
using namespace std;
 
class point {
  public:
    int x, y;

    //class constructor
    point(){}
    point(int x, int y) {
      this->x = x;
      this->y = y;
    }     
};

//function for overloading <
string operator< (const point p1, const point p2) {
  float d1 = hypot(p1.x, p1.y);
  float d2 = hypot(p2.x, p2.y);
  return d1 < d2? "true" : "false";
} 

//function for overloading >
string operator> (const point p1, const point p2) {
  float d1 = hypot(p1.x, p1.y);
  float d2 = hypot(p2.x, p2.y);
  return d1 > d2? "true" : "false";
}   

int main () {
  point p1(10, 15), p2(5, 25), p3(12, 14);

  cout<<"(p1 > p2) returns: "<<(p1 > p2)<<"\n";
  cout<<"(p1 < p3) returns: "<<(p1 < p3)<<"\n";
  return 0;
}
