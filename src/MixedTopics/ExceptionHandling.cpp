/*********Exception Handling in C++**************/
#include <iostream>
using namespace std;
class Vikesh
{
    public:
    void func(int a, int b)
    {
    
        try
        {
            cout<<"Enter two numbers"<<endl;
            cin>>a>>b;
            if(!b) throw 0;
            cout<<"Integer Division="<<a/b;
        }
        catch(int x)
        {
            cout<<"Division by zero"<<endl;
        }
    }
};

int main()
{
    Vikesh v;
    v.func(10, 0);
    return 0; 
}

/*  g++ -std=c++14 ExceptionHandling.cpp -o ExceptionHandling -pthread */
/* ./ExceptionHandling  */