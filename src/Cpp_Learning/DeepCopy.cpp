/* In deep-copy, a new object is created by copying all variables values and allocating separate memory for dynamically allocated variables*/
/* Both the original and copied object store their data in different memory locations*/
/* Chnage made to one object do not affect the other because a custom copy constructor is used*/

#include <iostream>
using namespace std;

class Sample
{
    public:
    int* x;
    Sample(int val)
    {
        x = new int,
        *x = val;
    }
    /* Custom copy constructor for Deep copy*/
    Sample(const Sample& obj)
    {
       x = new int ; /* Allocate new memory on the heap*/
       *x = *(obj.x); /* Copy the actual value not the pointer*/
    }
    /* Destructor to prevent memory leaks*/
    ~ Sample()
    {
        delete x;
    }
};

int main()
{
    Sample obj1(10);
    Sample obj2 = obj1; /* Now calls the deep copy constructor*/
    *obj2.x  = 50;
    cout <<*obj1.x <<endl; /* output: 10 remain unaffected*/
    cout<<*obj2.x << endl; /* output 50*/
    return 0;
}