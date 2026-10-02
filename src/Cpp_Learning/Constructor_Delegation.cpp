/*Constructor delegation: Calling a constructor inside another constructor*/
#include <iostream>
#include <string.h>
using namespace std;

class A
{
    int x, y ,z;
    public:
    A()
    {
        x =0;
        y =0;
        z =0;
    }
    A(int y, int z):A() /*Constructor delegation*/
    {
       this->y = y;
       this->z = z;
    }
    void show()
    {
        cout<<"x = "<<x<<"\t y = "<<y<<"\tz= "<<z<<endl;
    }
};
int main()
{
    A obj(3, 5);
    obj.show();
    return 0;
}

/*  g++ -std=c++14 Constructor_Delegation.cpp -o Constructor_Delegation -pthread */
/* ./Constructor_Delegation  */