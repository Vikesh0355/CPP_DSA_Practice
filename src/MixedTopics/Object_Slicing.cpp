/*Object Slicing: When a derived class object is assigned to a base class object in C++, the derived class object’s extra attributes are sliced off (not considered) to generate the base class object; 
and this whole process is termed object slicing.*/
#include <iostream>
using namespace std;

class Base
{
    public:
    int x;
    Base(int val) : x(val) {}
    virtual void display() { // Make display virtual to allow polymorphism
        cout << "Base class x = " << x << endl;
    }
};

class Derived : public Base {
public:
    int y;
    Derived(int val1, int val2) : Base(val1), y(val2) {}
    void display() override { // Override display in the derived class
        cout << "Derived class x = " << x << ", y = " << y << endl;
    }
};

/* int main()
{
    Derived d(10, 20);
    Base b = d; // Object slicing occurs here
    b.display(); // Only Base class part is displayed
    return 0;
} */

/*To avoid object slicing, you can use pointers or references to the base class instead of creating a copy of the derived class object*/

int main()
{
    Derived d(10, 20);
    Base* b = &d; // Use a pointer to avoid slicing
    b->display(); // Calls Derived's display method

    return 0;
}  
/*  g++ -std=c++14 Object_Slicing.cpp -o Object_Slicing -pthread */
/* ./Object_Slicing  */