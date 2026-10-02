/* protected, is similar to private, but it can also be accessed in the inherited class:*/
#include <iostream>
using namespace std;

class Employee
{
    protected:
    int salary;
    
};
class programmer: public Employee
{
    public:
    int bonus;
    void setSalary(int s)
    {
        salary = s;
    }
    void getSalary()
    {
        cout<<"Salary of the Employee: "<<salary<<endl;
    }
};

int main()
{
    programmer vikesh;
    vikesh.setSalary(1000);
    vikesh.getSalary();
    return 0;
}