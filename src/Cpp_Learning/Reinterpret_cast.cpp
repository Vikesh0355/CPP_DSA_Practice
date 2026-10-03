/*Reinterpret_cast
It is used to convert a pointer of some data type into a pointer of another data type, even if the data types before and after conversion are different.*/
/* It doesn’t have any return type. It simply converts the pointer type.*/

#include <iostream>
using namespace std;

int main()
{
    int* p = new int(50);
    char* ch = reinterpret_cast<char*>(p);
    cout<<*p<<endl;
    cout<<*ch<<endl;
    cout<<p<<endl;
    cout<<static_cast<void*>(ch)<<endl;
    return 0;
}