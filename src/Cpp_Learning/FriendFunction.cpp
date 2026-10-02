/*Normally, private members of a class can only be accessed using public methods like getters and setters. But in some cases, you can use a special function called a friend function to access them directly.

A friend function is not a member of the class, but it is allowed to access the class's private data:*/

#include <iostream>
using namespace std;

class Employee
{
    private:
    int salary;
    public:
    Employee(int salary)
    {
        this->salary = salary; /* assigned the salary value via constructor */
    }
    /* Declare the friend function */
     friend void displaySalary(Employee Emp);  
};

void displaySalary(Employee Emp)
{
    cout<<"Employee Salary = "<<Emp.salary;
}

int main()
{
    Employee Emp(50000);
    displaySalary(Emp);
    return 0;
}

/*Example Explained
The friend function displaySalary() is declared inside the Employee class but defined outside of it.
Even though displaySalary() is not a member of the class, it can still access the private member salary.
In the main() function, we create an Employee object and call the friend function to print its salary. */