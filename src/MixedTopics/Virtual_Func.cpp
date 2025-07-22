/*A virtual function in C++ is a member function in a base class that you expect to be overridden in derived classes. 
It allows for runtime polymorphism, meaning the function that gets called is determined by the type of the object being pointed to, not the type of the pointer.*/


#include <iostream>
using namespace std;

class Base 
{
    public:
    virtual void func() 
    {
        cout << "I am in base" << endl;
    }
};

class derived : public Base 
{
    public:
    void func() override 
    {
        cout << "I am in derived class" << endl;
    }
};

/*override:. compiler  will check the base class to see if there is a virtual function with this exact signature in derived class. And if there is not, the compiler will show an error.*/

/* class derived : public Base {
public:
    // did a silly mistake by putting
    // an argument "int a"
    void func(int a) override //compiler error it detects due to override keyword
    {
        cout << "I am in derived class" << endl;
    }
}; */

int main()
{
    derived d;
    Base* bptr = &d;

    bptr->func();           // Calls derived::func()
    d.Base::func();         // Explicitly calls base::func() using derived object

    cout << "Compiled successfully" << endl;
    return 0;
}


/*  g++ -std=c++14 Virtual_Func.cpp -o Virtual_Func -pthread*/
/* ./Virtual_Func  */