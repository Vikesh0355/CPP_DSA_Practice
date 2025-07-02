/*Static cast in c++*/
/*1. it performs implicit conversion between types*/

#include <iostream>
using namespace std;

int main()
{
    cout<<"Hello World\n";
    float f =6.5;
    int v;
    v= f;
    cout<<"after implicit conversion v ="<<v<<endl;
    v = static_cast<int>(f);
    cout<<"after static_cast conversion v ="<<v<<endl;
    return 0;
}

/*  g++ -std=c++14 Static_cast1.cpp -o Static_cast1 -pthread */
/* ./Static_cast1  */