/*Constructor: Constructor in C++ is a special method that is invoked automatically at the time an object of a class is created. It is used to initialize the data members of new objects generally. The constructor in C++ has the same name as the class or structure */
#include <iostream>
using namespace std;
class Test
{
    int a, b;
    public:
    Test() /*Default constructor*/
    {
        a = 10;
        b = 20;
    }
    void show()
    {
        cout<<"a ="<<a<<endl;
        cout<<"b ="<<b<<endl;
    }
};


int main() 
{
    Test t; /*Here the constrcutor Test will be invoked*/
    t.show();

    return 0;
}

/*  g++ -std=c++14 Constructor.cpp -o Constructor -pthread */
/* ./Constructor  */