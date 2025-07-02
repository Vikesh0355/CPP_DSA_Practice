/*Accessing Private member function of class: We can access private member function within the class, inside another public member functions */

#include <iostream>
using namespace std;

class employee
{
private:
int id;
char name[20];
float sal;
void getemp() /*Private member function*/
{
    cout<<"Enter the employee id, name and Sal"<<endl;
    cin>>id>>name>>sal;
}
public:
void putemp()
{
    getemp();
    cout<<"Employee Name = "<<name<<endl;
    cout<<"Employee ID = "<<id<<endl;
    cout<<"Employee salary = "<<sal<<endl;
}
    
}emp;

int main() {
  emp.putemp();
  //emp.getemp();  /*Restricted to access private member function outside class*/
  return 0;
}

/*  g++ -std=c++14 Private_MemFunc.cpp -o Private_MemFunc -pthread */
/* ./Private_MemFunc  */