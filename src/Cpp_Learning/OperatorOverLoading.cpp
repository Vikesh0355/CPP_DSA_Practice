/*****operator overloading: The concept of defining operators to work with objects and structure variables is known as operator overloading*/
/***E.g Without overloading == operator ****/
/*syntax
returnType operator symbol (arguments) {
    ... .. ...
}  */

/*Example: Overloading unary operators */
#include <iostream>
using namespace std;

class Distance
{
  int feet, inch;
  public:
  Distance(int f, int i)
  {
    this->feet = f;
    this->inch = i;
  }  
  /* Overloading - operator to perform decrement operation of distance object*/
  void operator-()
  {
    feet--;
    inch--;
    cout<<" feet and inchs updated values are "<<feet<<"\t"<<inch<<endl;
  }
} ;

int main()
{
  Distance d1(8, 9);
  /* Use (-) unary operator by single operand*/ 
  -d1;
  return 0; 
}
