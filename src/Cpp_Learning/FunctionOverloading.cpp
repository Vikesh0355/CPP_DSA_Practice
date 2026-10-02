/*Function overloading allows multiple functions to have the same name, as long as their parameters are different in type or number:*/
#include <iostream>
using namespace std;

int plusfunc(int x, int y) {
   return x+y;
}

double plusfunc(double x, double y) {
   return x+y;
}

int main()
{
    int result1 = plusfunc(1, 3);
    double result2 = plusfunc(3.14, 4.56);
    cout<<"result: "<<result1<<endl;
    cout<<"result2: "<<result2<<endl;
    return 0;
}