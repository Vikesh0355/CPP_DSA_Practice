/*Abstraction means exposing only the essential features of an object while hiding the complex implementation details.*/
#include <iostream>
using namespace std;

class Shape
{
    public:
    virtual void draw() = 0; // abstract method
};

class Circle : public Shape 
{
    public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

int main()
{
    Shape* s = new Circle();
    s->draw();  // No need to know how it's drawn
    delete s;
}

/*  g++ -std=c++14 DataAbstraction.cpp -o DataAbstraction -pthread */
/* ./DataAbstraction  */