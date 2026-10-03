/*Pass by Pointer:The pass-by-pointer is very similar to the pass-by-reference method. The only difference is that we pass the raw pointers instead of reference to the function. 
It means that we pass the address of the argument to the function.*/
#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 5;
    int y = 10;
    cout<<"Before swap value of x ="<<x<<"\ty = "<<y<<endl;
    swap(&x, &y);
    cout<<"After swap value of x ="<<x<<"\ty = "<<y<<endl;
    return 0;
}