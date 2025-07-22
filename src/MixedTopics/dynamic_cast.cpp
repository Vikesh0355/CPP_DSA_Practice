/*dynamic_cast in c++*/
/* synatx: dynamic_cast<new_type>(expression) */

/*1. dynamic_cast is used at run time to find out correct down cast*/
/*Note:*/
//Need atleast one virtual function in Base class
//if the cast is successful, dynamic_cast returns a value of type new_type
//if the cast fails and new_type is pointer type, it returns a null pointer
//If the cast fails and new_type is reference type, it throws exception that matches a handler of type std:bas_cast. 
#include <iostream>
using namespace std;

class Base 
{
    virtual void print()
    {
        cout<<"Base"<<endl;
    }
};

class Derived1:public Base
{
    void print()
    {
        cout<<"Derived1"<<endl;
    }
};
class Derived2:public Base
{
    void print()
    {
        cout<<"Derived2"<<endl;
    }
};

int main()
{
  Derived1  d1;
  Base*bp = dynamic_cast<Base*>(&d1);
  Derived2 *dp2 = dynamic_cast<Derived2*>(bp);
  if(dp2 == nullptr)
  cout<<"NULL"<<endl;
  else
  cout<<"Not Null"<<endl;
  return 0;
} 

/*  g++ -std=c++14 dynamic_cast.cpp -o dynamic_cast -pthread */
/* ./dynamic_cast  */