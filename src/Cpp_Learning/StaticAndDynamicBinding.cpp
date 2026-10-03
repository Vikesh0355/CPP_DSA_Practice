/*What is Static and Dynamic Binding in c++*/
/*Ans: This is functioin call mechanism determined at compile time or run time*/
/*If function calling is known at compile time then => static binding*/
/*If function call is known at run time then=> dynamic binding*/

/*static Binding e.g*/
#include <iostream>

class Base {
public:
    void display()
    {
        std::cout << "Base class display function" << std::endl;
    }
};

class Derived : public Base
{
   public:
    void display() {
        std::cout << "Derived class display function" << std::endl;
    }
};

int main() {
    Base b;
    Derived d;

    b.display(); // Calls Base::display
    d.display(); // Calls Derived::display

    return 0;
}


/***DYNAMIC BINDING******/
#include <iostream>

class Base {
public:
    virtual void display() {
        std::cout << "Base class display function" << std::endl;
    }
    virtual ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        std::cout << "Derived class display function" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    b->display(); // Calls Derived::display due to dynamic binding

    delete b;
    return 0;
}