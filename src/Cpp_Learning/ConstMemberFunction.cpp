#include <iostream>
using namespace std;

/* A function becomes const when the const keyword is used in the function declaration. The idea of const function is not to allow  them  to modify the object on which they are called */

class Test
{
    int a, b;
    public:
    void read()
    {
        a = 10;
        b = 20;
    }
    void show() const
    {
       // a = 30; /*Not allowed a is declared const here*/
      //  b = 40; /*Not allowed b is declared const here*/
        cout <<" a ="<<a<<"\tb = "<<b<<endl;
        
    }
};
int main()
{
    Test t;
    t.read();
    t.show();
    return 0;
}