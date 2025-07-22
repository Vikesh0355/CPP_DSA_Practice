/* In C++, a reference is an alias (another name) for an existing variable. References are not new variables; 
they refer directly to the original variable’s memory.*/

/*Reference Data Type*/
#include <iostream>
using namespace std;
void swap( int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// Driver Code
int main()
{
  int a =20, b= 30;
  swap(a, b);
  cout<<"a ="<<a<<"\t b= "<<b<<endl;
  return 0;
}

/*  g++ -std=c++14 Reference.cpp -o Reference -pthread */
/* ./Reference  */