/*The meaning of Encapsulation, is to make sure that "sensitive" data is hidden from users.

To achieve this, you must declare class variables/attributes as private (cannot be accessed from outside the class).

If you want others to read or modify the value of a private member, you can provide public get and set methods. */
#include <iostream>
using namespace std;

class Vikesh
{
    private:
    int salary;
    public:
    /* Setter method*/
    void setSalary(int s)
    {
        salary = s;
    }
    int getSalary()  /* getter method*/
    {
       return salary; 
    }
};

int main()
{
    Vikesh Vm;
    Vm.setSalary(10000);
    int result=  Vm.getSalary();
    cout<<"salary is : "<<result<<endl;
    return 0;
}