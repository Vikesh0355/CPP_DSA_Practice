/*If the base class doesn't have a virtual destructor, deleting a derived class object through a base pointer causes undefined behavior — 
often resulting in only the base destructor being called, leading to resource leaks.*/
#include <iostream>
using namespace std;

class Base 
{
    public:
    Base() { cout << "Base constructor\n"; }
    virtual ~Base() { cout << "Base destructor\n"; } // virtual destructor
};

class Derived : public Base
{
    public:
    Derived() { cout << "Derived constructor\n"; }
    ~Derived() { cout << "Derived destructor\n"; }
};

int main() 
{
    Base* b = new Derived(); // Polymorphic deletion
    delete b; // Ensures Derived's destructor is called
    return 0;
}

/*  g++ -std=c++14 VirtualDestructor.cpp -o VirtualDestructor -pthread */
/* ./VirtualDestructor  */