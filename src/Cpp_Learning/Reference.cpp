/*Differnecee between Reference and pointer*/
/*1. Same Memory Address
2. Reassignment is not possible with reference pointer
3. Null Value
4. Arithmatic operation
5. Indirection  */
#include <iostream>
using namespace std;
int main()
{
   int i=10;
   int &r =i;
   int *p = &i; 
   cout<<"Address of r="<<&r<<endl; /*Here r and i have same address pont 1.*/
   cout<<"Address of i="<<&i<<endl;
   cout<<"Address of p="<<&p<<endl;
   cout<<"value of p = "<<*p<<endl;
   int var =90;
   //r= var; /*Not correct point 2*/
    r = 20; /* But updating the actual value through reference variable is possible"
    cout<<"Now update value of i = "<<i<<endl;
    cout<<"Now update value of i = "<<i<<endl;
   //int &v = NULL; /*Not allowed point 3*/
   p++; /*Allowed*/
  // r++ ;/*Not allowed point 4.*/
 // (&r)++; /*Allowed*/
  int** ptr = &p;
 // int** f = &r /*Not allowed point 5.*/
  return 0;
}