/* In shallow copy, all variables values are copied, but dynamically allocated memory addresses are shared between objects.*/
/* Both objects points to the same heap memory, so chnage made through one object affect the other */
/* This can lead to run time error like dangling pointers and double deletion, so it doesn#t create an independent copy*/

/* Example: Shallow copy */
#include<iostream>
using namespace std;

class Sample
{
    public:
    int *x;
    sample(int val)
    {
        x = new int; // create a new variable of int type in heap
        *x = val;
    }
};

int main()
{
    Sample obj1(10); // original variables
    Sample obj2 = obj1; // Shallow copy

    *obj2.x = 50; // modify copied object

    cout <<*obj1.x<<endl;
    cout <<*obj2.x<<endl;
    return 0;
} 

/* What Wrong here in shallow copy? */
1. Shared heap memory(Aliasing):
=> By default, C++ generate a member wise copy constructor when you write Sample obj2 = obj1; . This copies the value of the pointer x, meaning both obj1.x and obj2.x points to the same memory address on the heap 
2.Uintended Side effects:
=> When you execute *obj2.x = 50; you are modifying the value stored at that shared memory address. Consequently *obj1.x will chnage as well. Both print statement will be 50. Which is usually not what you want when copying an object
3. Missing Resource Management(Rule of Three)
=> Because the class manages a raw pointer with dynamic memory, it lack a destructore to clean the heap memory, which would lead to memory leak. If you  added a destrcutor 
without custome copy constructor , you would face a double free error(Both objects trying to delete the same memory address when they go out of scope)
