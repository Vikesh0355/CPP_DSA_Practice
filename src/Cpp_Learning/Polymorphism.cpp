/* Polymorphism in C++ is the ability of a single interface or function name to represent different behaviors. */
/* Polymorphism
│
├── Compile-time polymorphism
│   ├── Function overloading
│   └── Operator overloading
│
└── Run-time polymorphism
    └── Function overriding using virtual functions */

/* Compile Time Polymorphism: function overloading */

#include <iostream>
using namespace std;

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};

int main()
{
    Calculator c;

    cout << c.add(10, 20) << endl;
    cout << c.add(10, 20, 30) << endl;
}


/* 2. Run-time polymorphism

This is more important when learning inheritance.

It happens when a base-class pointer/reference calls an overridden function of a derived class.

We use the virtual keyword. */

#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound() override
    {
        cout << "Cat meows" << endl;
    }
};

int main()
{
    Animal* animal;

    Dog dog;
    Cat cat;

    animal = &dog;
    animal->sound();

    animal = &cat;
    animal->sound();
    return 0;
}