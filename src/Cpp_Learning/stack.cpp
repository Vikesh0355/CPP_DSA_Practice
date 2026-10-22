/* A stack stores multiple elements in a specific order, called LIFO. Unlike vectors, elements in the stack are not accessed by index numbers. 
Since elements are added and removed from the top, you can only access the element at the top of the stack. */

// Create a stack of strings called cars
stack<string> cars;

// Example 
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<string> cars;
    cars.push("Volvo");
    cars.push("BMW");
    cars.push("Ford");
    cars.push("Mazda");
    cout<<cars.top()<<endl; /*Output: Mazda*/
    // Change the value of the top element
   cars.top() = "Tesla";
   // Access the top element
    cout << cars.top()<<endl;  // Now outputs "Tesla" instead of "Mazda"
    // Remove the last added element (Mazda)
   cars.pop();
   // Access the top element (Now Ford)
   cout << cars.top()<<endl;

   /* get the size of stack */
   cout << cars.size();
   /* check if the stack is empty*/
   cout<<cars.empty();
    return 0;
}

/* Note: .top() lets you access and overwrite the top element of a C++ stack while .push let you to add new element on the top */