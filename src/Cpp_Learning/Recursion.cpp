/*Recursion is the technique of making a function call itself.*/
#include <iostream>
using namespace std;
 int factorial(int n)
 {
    if(n>1)
    {
       return n* factorial(n-1);

    }
    else
    {
        return 1;
    }
 }

 int main()
 {
    cout<<"Factorial of 5 is: "<<factorial(5);
    return 0;
 }